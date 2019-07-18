#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul  1 12:44:39 2019

@author: paedu
"""

import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

from statsmodels.formula.api import ols
from statsmodels.stats.anova import anova_lm

# b)
streams = pd.read_csv('stream.dat', sep=' ', header=0)

sns.boxplot(x='ZNGROUP', y='DIVERSITY', data=streams)
plt.show()

sns.stripplot(x='ZNGROUP', y='DIVERSITY', data=streams)
plt.show()

# c)
streams['ZNGROUP'] = streams['ZNGROUP'].apply(str)
fit = ols('DIVERSITY~ZNGROUP*STREAM', data=streams).fit()
print(fit.summary())
fit_pred = fit.get_prediction()
print(fit_pred.conf_int())
print(anova_lm(fit))