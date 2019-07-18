#!/usr/bin/python3

import pandas as pd
import scipy.stats as st

h0_median = 70
sample = pd.Series([71, 69, 67, 68, 73, 72, 71, 71, 68, 72, 69, 72])

# a)
positives = sample[sample > h0_median]
p = st.binom_test(x=positives.size, n=sample.size, p=0.5, alternative='less')
print('a) p={:.2f}'.format(p))

# b)
p = st.wilcoxon(sample - h0_median, correction=True).pvalue
print('b) p={:.2f}'.format(p))
