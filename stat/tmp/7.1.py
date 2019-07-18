#!/usr/bin/python3

import numpy as np

sample = np.loadtxt('oldfaithful.txt')
n = sample.size
nboot = 1000

interval = 95
lower = (100 - interval) / 2
upper = 100 - lower

tmp_data = np.random.choice(sample, n*nboot, replace=True)
bootstrap_sample = np.reshape(tmp_data, (n, nboot))
col_means = np.mean(bootstrap_sample, axis=0)

# a) bootstrap

# simple bootstrap
np.sort(col_means)
boundaries = np.percentile(col_means, q=[lower, upper])
print('simple bootstrap: [{:.3f},{:.3f}]: {}'.format(lower, upper, boundaries))

# "real" bootstrap
mean_diff = sample.mean() - col_means
np.sort(mean_diff)
boundaries = np.percentile(mean_diff, q=[lower, upper])
ci = sample.mean() - [boundaries[1], boundaries[0]]
print('"real" bootstrap: [{:.3f},{:.3f}]: {}'.format(lower, upper, ci))

# b) median bootstrap
col_medians = np.median(bootstrap_sample, axis=0)
np.sort(col_medians)
median_diff = np.median(sample, axis=0) - col_medians
boundaries = np.percentile(median_diff, q=[lower, upper])
ci = np.median(sample) - [boundaries[1], boundaries[0]]
print('median bootstrap: [{:.3f},{:.3f}]: {}'.format(lower, upper, ci))

# c) P(|x_mean - mean| > 5)
diffs = np.abs(col_means - sample.mean())
bigger_five = diffs[diffs > 5]
p = bigger_five.size / diffs.size
print(p)
