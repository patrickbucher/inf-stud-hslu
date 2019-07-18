#!/usr/bin/python3

import matplotlib.pyplot as plt
import numpy as np
import scipy.stats as st

for k, v in {'norm': st.norm.rvs, 't': st.t.rvs, 'chi2': st.chi2.rvs}.items():
    p = 0
    for i in [10, 20, 50, 100]:
        p += 1
        if k == 'norm':
            x = v(size=i)
        else:
            x = v(size=i, df=20)
        plt.subplot(220 + p)
        st.probplot(x, plot=plt)
        plt.title('{:s} n={:d}'.format(k, i))
    plt.show()
