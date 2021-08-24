#!/usr/bin/env python
import rospy
from cv_bridge.boost.cv_bridge_boost import getCvType
from sensor_msgs.msg import Image   
import cv_bridge
import argparse
import os
import random
import cv2
import numpy as np
recognizer = cv2.face.createLBPHFaceRecognizer()    
recognizer.load('/home/s503/catkin_ws/src/trainner.yml')
cascade_path = ("/usr/share/opencv4/haarcascades/haarcascade_frontalface_default.xml") 
face_cascade = cv2.CascadeClassifier(cascade_path)

names = ['Eric','Tim','user1','user2','user3']

class image:
    def __init__(self):
        self.cv_image = 0
        self.confidence = 0
        self.idnum = 0
        self.idum = 0
        self.x = 0
        self.y = 0
        self.w = 0
        self.h = 0
    def rgb_callback(self, data):
        bridge = cv_bridge.CvBridge()
        self.cv_image = cv2.resize(bridge.imgmsg_to_cv2(data, "bgr8"), (608,608))
        frame = np.array(self.cv_image, dtype = np.uint8)
        grey = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        faces = face_cascade.detectMultiScale(
            grey, 
            scaleFactor = 1.2, 
            minNeighbors = 5,  
            minSize = (40,60),
            )
        for(self.x,self.y,self.w,self.h) in faces:
                cv2.rectangle(self.cv_image,(self.x,self.y),(self.x+self.w,self.y+self.h),(0,255,0), 2)
                self.idnum, self.confidence = recognizer.predict(grey[self.y:self.y+self.h,self.x:self.x+self.w])
                if confidence < 100:
                    self.idum = names[self.idnum]
                    self.confidence = format(round(100-self.confidence))
                else:
                    self.idum = "unknown"
                    self.confidence = format(round(100-self.confidence))


    
def main():
    re = image()
    font = cv2.FONT_HERSHEY_SIMPLEX
    rospy.init_node("show_img")
    rospy.Subscriber("/kinect2/hd/image_color", Image, re.rgb_callback)
    
    while True:
        cv2.putText(re.cv_image,str(re.idum),(re.x+5,re.y-5),font,1,(0,0,255),1)
        cv2.putText(re.cv_image,str(re.confidence),(re.x+re.w,re.y+re.h),font,1,(0,0,0),1)
        cv2.namedWindow('Inference', cv2.WINDOW_NORMAL)
        cv2.imshow('Inference', re.cv_image)
        cv2.waitKey(10)
        if 0xFF == ord("q"):
            break
        
  

if __name__ == "__main__":
    main()
