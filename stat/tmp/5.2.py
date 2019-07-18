#!/usr/bin/python3

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import scipy.stats as st

values = np.array([0, 10, 11])
sim = pd.Series(np.random.choice(values, size=1000, replace=True))

plt.subplot(4, 2, 1)
sim.hist(bins=[0, 1, 10, 11, 12], edgecolor='black')
plt.title('Original')

plt.subplot(4, 2, 2)
st.probplot(sim, plot=plt)
plt.title('Normal Q-Q Plot')

i = 2
for n in [5, 10, 200]:
    sim_orig = np.random.choice(values, size=n*1000, replace=True)
    sim = pd.DataFrame(np.reshape(sim_orig, (n, 1000)))
    sim_mean = sim.mean()

    i += 1
    plt.subplot(4, 2, i)
    sim_mean.hist(edgecolor='black')
    plt.title('Mittelwerte von {:d} Beobachtungen'.format(n))

    i += 1
    plt.subplot(4, 2, i)
    st.probplot(sim_mean, plot=plt)
    plt.title('Normal Q-Q Plot')

    print('n={:d}: X~N({:.3f}, {:.3f}²)'.format(n, sim_orig.mean(), sim_orig.std()))

plt.show()
