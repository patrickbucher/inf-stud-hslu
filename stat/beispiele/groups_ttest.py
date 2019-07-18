#!/usr/bin/python3

import numpy as np
import pandas as pd
import scipy.stats as st
import seaborn as sns
from matplotlib import pyplot as plt

df = pd.DataFrame({
    'HC': np.repeat(['5%', '10%', '15%', '20%'], [6, 6, 6, 6]),
    'Strength': [7, 8, 15, 11, 9, 10, 12, 17, 13, 18, 19, 15, 14, 18, 19, 17,
        16, 18, 19, 25, 22, 23, 18, 20]
})

per5 = df.loc[df['HC'] == '5%', 'Strength']
per10 = df.loc[df['HC'] == '10%', 'Strength']
per15 = df.loc[df['HC'] == '15%', 'Strength']
per20 = df.loc[df['HC'] == '20%', 'Strength']

print('p(5/10)={:.3f}'.format(st.ttest_ind(per5, per10)[1]))
print('p(5/15)={:.3f}'.format(st.ttest_ind(per5, per15)[1]))
print('p(5/20)={:.3f}'.format(st.ttest_ind(per5, per20)[1]))

print('p(10/15)={:.3f}'.format(st.ttest_ind(per10, per15)[1]))
print('p(10/20)={:.3f}'.format(st.ttest_ind(per10, per20)[1]))

print('p(15/20)={:.3f}'.format(st.ttest_ind(per15, per20)[1]))

sns.stripplot(x='HC', y='Strength', data=df)
plt.xlabel('Hartholzkonzentration')
plt.ylabel('Reissfestigkeit')
plt.show()

sns.boxplot(x='HC', y='Strength', data=df)
plt.xlabel('Hartholzkonzentration')
plt.ylabel('Reissfestigkeit')
plt.show()
