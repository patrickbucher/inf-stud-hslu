#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jul  2 12:15:48 2019

@author: paedu
"""

import numpy as np
import pandas as pd

from statsmodels.formula.api import ols
from statsmodels.stats.anova import anova_lm

df = pd.DataFrame({'Person': np.repeat(['P1', 'P2', 'P3', 'P4', 'P5'], 3),
                   'Wein': np.tile(['W1', 'W2', 'W3'], 5),
                   'Y': np.array([1, 7, 5, 0, 4, 0, 1, 6, 4, 1, 5, 2, 1, 8, 10])
                  })
fit = ols('Y~C(Person,Sum)+C(Wein,Sum)', data=df).fit()
print(anova_lm(fit))