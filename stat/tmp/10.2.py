#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Jun 29 09:31:35 2019

@author: paedu
"""

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns

from statsmodels.formula.api import ols
from statsmodels.stats.anova import anova_lm

df = pd.DataFrame({
        'Behandlung': np.repeat(['A', 'B', 'C', 'D'], [4, 6, 6, 8]),
        'Koagulationszeit': [62, 60, 63, 59,
                             63, 67, 71, 64, 65, 66,
                             68, 66, 71, 67, 68, 68,
                             56, 62, 60, 61, 63, 64, 63, 59]})

sns.stripplot(x='Behandlung', y='Koagulationszeit', data=df)
plt.xlabel('Behandlung')
plt.ylabel('Koagulationszeit')
plt.show()

sns.boxplot(x='Behandlung', y='Koagulationszeit', data=df)
plt.xlabel('Behandlung')
plt.ylabel('Koagulationszeit')
plt.show()

fit = ols('Koagulationszeit~Behandlung', data=df).fit()
print(fit.params)

print(anova_lm(fit))
