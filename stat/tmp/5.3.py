#!/usr/bin/python3

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import scipy.stats as st

iron = pd.read_csv('ironF3.dat', sep=' ', index_col=False)

iron.plot(kind='box')
plt.show()

iron_log = np.log(iron)
iron_log.plot(kind='box')
plt.show()

st.probplot(iron['medium'], plot=plt)
plt.show()

mean = iron['medium'].mean()
std = iron['medium'].std()
print('F~N({:.3f}, {:.3f}²)'.format(mean, std))
p = 1 - st.norm.cdf(x=10, loc=mean, scale=std)
print('P(X>10)={:.3f}'.format(p))

medium_log = pd.Series(np.log(iron['medium']))
mean = medium_log.mean()
std = medium_log.std()
print('F~N({:.3f}, {:.3f}²)'.format(mean, std))
p = 1 - st.norm.cdf(x=np.log(10), loc=mean, scale=std)
print('P(X>10)={:.3f}'.format(p))
