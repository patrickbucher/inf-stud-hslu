#!/usr/bin/python3

import numpy as np
import pandas as pd
import seaborn as sns
import scipy.stats as st

from matplotlib import pyplot as plt

from statsmodels.formula.api import ols
from statsmodels.stats.anova import anova_lm

meat = pd.DataFrame({
    'Treatment': np.repeat(['Kommerziell', 'Vakuum', 'Gemischt', 'CO2'], [3, 3, 3, 3]),
    'meat_id': [7.66, 6.98, 7.80, 5.26, 5.44, 5.80, 7.41, 7.33, 7.04, 3.51, 2.91, 3.66]
})

sns.stripplot(x='Treatment', y='meat_id', data=meat)
plt.xlabel('Verpackungsmethode')
plt.ylabel('Logarithmus Bakterienzahl')

fit = ols('meat_id~Treatment', data=meat).fit()
print(fit.params)

fit_pred = fit.get_prediction()
print(fit_pred.conf_int())
print(anova_lm(fit))

plt.show()
