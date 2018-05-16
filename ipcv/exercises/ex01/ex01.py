#!/usr/bin/python3

import cv2
import numpy as np

import matplotlib as mpl
from matplotlib import pyplot as plt

mpl.rcParams['figure.dpi'] = 200

# Aufgabe 1
image = cv2.imread('../images/lena_std.tif')
plt.imshow(image)
plt.show()

image_mirror_vert = cv2.flip(image, 0)
image_mirror_hor = cv2.flip(image, 1)
plt.subplot(1, 2, 1)
plt.imshow(image_mirror_vert)
plt.subplot(1, 2, 2)
plt.imshow(image_mirror_hor)
plt.show()

# Aufgabe 2
image_gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
plt.imshow(image_gray, cmap='gray')
plt.show()

# Aufgabe 3
b, g, r = cv2.split(image)
image_red = r
image_green = g
image_blue = b
plt.subplot(1, 3, 1)
plt.imshow(image_red, cmap='gray')
plt.subplot(1, 3, 2)
plt.imshow(image_green, cmap='gray')
plt.subplot(1, 3, 3)
plt.imshow(image_blue, cmap='gray')
plt.show()

image_new = np.stack([r, g, b], axis=-1)
plt.imshow(image_new)
plt.show()

# Aufgabe 4
line = image_gray[200, :]
plt.plot(line)
plt.show()
# Legt man das Bild und den Plot mit gleicher Breite exakt untereinander,
# sieht man, dsas optische Übergänge (Hintergrund/Hut) jeweils mit grossen
# Ausschlägen im Plot übereinstimmen. Bei Flächen (Haut, Hintergrund)
# oszilliert die Kurve jeweils leicht, da eine Fläche in der realen Welt
# nie wirklich einfarbig ist.

# Aufgabe 5
einstein = cv2.imread('../images/EinsteinLowContrast.tif')
einstein_gray = cv2.cvtColor(einstein, cv2.COLOR_BGR2GRAY)
plt.imshow(einstein, cmap='gray')
plt.show()

colors = einstein_gray.flatten().tolist() # r = g = b
min = min(colors)
max = max(colors)
print('min: {}, max: {}'.format(min, max))

hist = cv2.calcHist([einstein_gray], [0], None, [256], [0, 256])
plt.plot(hist)
plt.show()

einstein_equal = cv2.equalizeHist(einstein_gray)
hist2 = cv2.calcHist([einstein_equal], [0], None, [256], [0,256])
plt.subplot(1, 2, 1)
plt.plot(hist2)
plt.subplot(1, 2, 2)
plt.imshow(np.stack([einstein_equal, einstein_equal, einstein_equal], axis=2))
plt.show()

# Aufgabe 6
def f(x):
    darker = x.copy()
    darker[:, :] = darker[:, :] - 80
    return darker

plt.subplot(2,2,1)
plt.imshow(einstein_gray, cmap='gray')
hist = cv2.calcHist([einstein_gray], [0], None, [256], [0, 256])
plt.subplot(2,2,3)
plt.plot(hist)

result = f(einstein_gray)
plt.subplot(2,2,2)
plt.imshow(result, cmap='gray')
hist2 = cv2.calcHist([result], [0], None, [256], [0, 256])
plt.subplot(2,2,4)
plt.plot(hist2)
plt.show()
