#!/usr/bin/python3

import cv2
import numpy as np

import matplotlib as mpl
from matplotlib import pyplot as plt

mpl.rcParams['figure.dpi'] = 200

image = cv2.imread('../images/lena_std.tif')
#plt.imshow(image)
#plt.show()

image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
#plt.imshow(image_rgb)
#plt.show()

print(image_rgb[0, 0]) # RGB value at pixel (0,0)
print(image_rgb[0, 0, 0]) # Red value (same pixel)

# y=100:200, x=350:400
image_rgb[100:200, 350:400] = [255, 255, 255]
#plt.imshow(image_rgb)
#plt.show()

image_bw = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
image_gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

image_bw[image_gray <= 128] = [0, 0, 0]
image_bw[image_gray > 128] = [255, 255, 255]
plt.imshow(image_bw)
plt.show()
