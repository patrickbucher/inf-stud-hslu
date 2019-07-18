#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul  1 13:48:49 2019

@author: paedu
"""

import pandas as pd
import scipy.stats as st
from statsmodels.tsa.seasonal import seasonal_decompose

print(1 - st.norm.cdf(x=115, loc=100, scale=32.1))
print(1 - st.norm.cdf(x=115, loc=100, scale=36.6))
print(1 - st.norm.cdf(x=115, loc=100, scale=30.2))
print(1 - st.norm.cdf(x=115, loc=100, scale=37.9))

rain = pd.read_csv('rainDay.txt', sep=' ', header=None)
rain['date'] = pd.DatetimeIndex(rain[1])
rain.set_index('date', inplace=True)
print(rain)

numbers = pd.Series([1, 3, 4, 5, 6, 10, 23, 46])
numbers.sort_values()
print(numbers.quantile(q=0.2, interpolation='nearest'))