#!/usr/bin/env python3

import numpy as np
from scipy.stats import probplot
import matplotlib.pyplot as plt

x = np.array([24.4, 27.6, 27.8, 27.9, 28,5, 30.1, 30.1, 30.3, 31.7, 32.2, 32.8, 33.3, 33.5, 34.1, 34.6, 35.8, 35.9, 36.8, 37.1, 39.2, 39, 7])

probplot(x, plot=plt)
plt.show()
