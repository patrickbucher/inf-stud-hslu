#!/usr/bin/python3

import cv2
import numpy as np

import matplotlib as mpl
from matplotlib import pyplot as plt
mpl.rcParams['figure.dpi']= 200

# Aufgabe 1
image = cv2.imread('../images/Figuren.png')
plt.imshow(image)
plt.show()

struct = cv2.getStructuringElement(cv2.MORPH_CROSS, (3, 3))
plt.imshow(struct, cmap='gray')
plt.show()

image_dilate = cv2.dilate(image, struct,iterations=10)
plt.imshow(image_dilate)
plt.show()

image_erode = cv2.erode(image, struct, iterations=10)
plt.imshow(image_erode)
plt.show()

# Aufgabe 2
image_open = cv2.morphologyEx(image, cv2.MORPH_OPEN, struct)
plt.imshow(image_open)
plt.show()

image_close = cv2.morphologyEx(image, cv2.MORPH_CLOSE, struct)
plt.imshow(image_close)  
plt.show()

# Aufgabe 3
nr_kugeln = 0
kugeln = cv2.imread('../images/Kugeln.jpg')

kugeln = cv2.cvtColor(kugeln, cv2.COLOR_BGR2GRAY)

strct = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (3, 3))

kugeln = cv2.erode(kugeln, strct, iterations=3)
plt.subplot(1,2,1)
plt.imshow(kugeln, cmap='gray')
kugeln = cv2.dilate(kugeln, strct, iterations=20)
plt.subplot(1,2,2)
plt.imshow(kugeln, cmap='gray')
plt.show()

ret, thresh = cv2.threshold(kugeln, 127, 255, 0)
im2, contours, hierarchy = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

nr_kugeln = len(contours)

print('Anzahl Kugeln: {}'.format(nr_kugeln))
