#!/usr/bin/python3

import numpy as np

circle_radius = 1
circle_diameter = circle_radius * 2
square_surface = circle_diameter ** 2

for n in [10, 100, 1000, 10**4, 10**5, 10**6, 10**7, 10**8]:
    sample = np.random.ranf(size=(2, n)) * 2 - 1.0
    xs = sample[0]
    ys = sample[1]
    distances = np.sqrt(xs ** 2 + ys ** 2)
    within_circle = distances[distances <= 1.0].size
    pi_approx = within_circle/distances.size * square_surface
    print('π(n = {:9d}) ≈ {:6.5f}'.format(n, pi_approx))
