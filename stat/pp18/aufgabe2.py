#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jul  2 09:27:28 2019

@author: patrick.bucher
"""

import numpy as np
import pandas as pd
import scipy.stats as st

data = pd.read_csv('Schiedsrichter_Lebenserwartung.txt', sep=' ', header=None)
dead = data[data[1] == 0]

# a)
diff = dead[0] - dead[2]
diff_std = diff/diff.std()/np.sqrt(diff.size)
print('size', diff.size)
diff_mean = diff.mean()
diff_std = diff.std()

tval = st.ttest_1samp(a=diff, popmean=0).statistic
print('t', tval)
pval = st.t.cdf(x=tval, df=diff.size-1)
print('p', pval)

# c)

interval = st.t.interval(alpha=0.99, loc=diff_mean, scale=diff_std/np.sqrt(diff.size), df=diff.size-1)
print('interval', interval)

interval = st.t.interval(alpha=0.99, df=diff.size-1)
print('interval', interval)

# d)

p = st.wilcoxon(diff, correction=True).pvalue
print(p)

# e)
alive = data[data[1] == 1]
print(alive[0].mean())
print(alive[0].std())
print(alive[0].std()/alive[0].mean())