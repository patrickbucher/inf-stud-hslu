#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul  1 11:06:26 2019

@author: patrick.bucher@stud.hslu.ch (ibbucher)
"""

import pandas as pd
import scipy.stats as st
import matplotlib.pyplot as plt

data = pd.read_csv('widerstaende.txt', sep=' ')

mean_a = data['Methode A'].mean()
mean_b = data['Methode B'].mean()
mean_diff = mean_b - mean_a
print(mean_diff)

var_diff = (data['Methode A'] - data['Methode B']).var()
print(var_diff)

rejection = st.t.ppf(q=[0.025, 0.975], loc=0, scale=var_diff**0.5/30**0.5, df=29)
print(rejection)

p = st.t.cdf(x=mean_diff, loc=0, scale=var_diff**0.5/30**0.5, df=29)
print(p)

x = data['Methode A'] - data['Methode B']
st.probplot(x, plot=plt)
p = st.wilcoxon(x, correction=True)
print(p.pvalue)

interval = st.t.interval(alpha=0.95, df=39, loc=mean_diff, scale=var_diff**0.5/30**0.5)
print(interval)

p = st.ttest_1samp(a=(data['Methode A'] - data['Methode B']), popmean=0)
print(p.pvalue)