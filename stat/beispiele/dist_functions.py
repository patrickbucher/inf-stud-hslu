#!/usr/bin/env python3

import numpy as np
from matplotlib import pyplot as plt
from scipy.stats import norm

# IQ distribution: median=100, std=15

# rvs: random variables
# - distribution known, but no values
iqs = norm.rvs(size=100000, loc=100, scale=15)
plt.hist(iqs, bins=100)
plt.show()

# cdf: cumulative density function
# - point on x axis known, but not probability (area)
# - reverse function of `ppf`
retard = norm.cdf(70, loc=100, scale=15)
gifted = 1 - norm.cdf(130, loc=100, scale=15)
print('P(retard)={:.2f}%, P(gifted)={:.2f}%'.format(retard * 100, gifted * 100))

# ppf: percent point function
# - probability (area) known, but not point on x axis
# - reverse function of `cdf`
a = norm.ppf(retard, loc=100, scale=15)
b = norm.ppf(1-gifted, loc=100, scale=15)
print('IQ retarded: {:.2f} and gifted: {:.2f}'.format(a, b))

# pdf: probability density function
# - density on location x (_not_ the probability!)
# - `pdf` calculates the y values, `cdf` the area in a specific range
# - areas can be calculated by summing up the y values with the x ranges (Riemann sum)
lower = 80
upper = 120
steps = 100
xs = np.linspace(start=lower, stop=upper, num=steps)
ys = norm.pdf(x=xs, loc=100, scale=15)
area = sum(ys * (upper-lower)/steps)
print('P(IQ [{:d},{:d}])={:.2f}%'.format(lower, upper, area * 100))
