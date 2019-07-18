#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Jun 29 09:11:02 2019

@author: Patrick Bucher
"""

import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

from statsmodels.formula.api import ols
from statsmodels.stats.anova import anova_lm

containers = pd.DataFrame({
        'Typ': np.repeat(['T1', 'T2', 'T3', 'T4'], [6, 6, 6, 6]),
        'Druckfestigkeit': [655.5, 788.3, 734.3, 721.4, 679.1, 699.4,
                            789.2, 772.5, 786.9, 686.1, 732.1, 774.8,
                            737.1, 639.0, 696.3, 671.7, 717.2, 727.1,
                            535.1, 628.7, 542.4, 559.0, 586.9, 520.0]})

sns.stripplot(x='Typ', y='Druckfestigkeit', data=containers)
plt.xlabel('Typ')
plt.ylabel('Druckfestigkeit')
plt.show()

sns.boxplot(x='Typ', y='Druckfestigkeit', data=containers)
plt.xlabel('Typ')
plt.ylabel('Druckfestigkeit')
plt.show()

fit = ols('Druckfestigkeit~Typ', data=containers).fit()
print(fit.summary())
print(fit.params)

print(anova_lm(fit))