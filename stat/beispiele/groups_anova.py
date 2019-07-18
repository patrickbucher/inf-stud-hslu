#!/usr/bin/python3

import numpy as np
import pandas as pd
import scipy.stats as st

from statsmodels.formula.api import ols
from statsmodels.stats.anova import anova_lm

df = pd.DataFrame({
    'HC': np.repeat(['5%', '10%', '15%', '20%'], [6, 6, 6, 6]),
    'Strength': [7, 8, 15, 11, 9, 10, 12, 17, 13, 18, 19, 15, 14, 18, 19, 17,
        16, 18, 19, 25, 22, 23, 18, 20]
})

fit = ols('Strength~HC', data=df).fit()
print(fit.summary())
print(fit.params)
fit_pred = fit.get_prediction()
print(fit_pred.conf_int())
print(anova_lm(fit))
