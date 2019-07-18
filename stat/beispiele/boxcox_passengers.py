#!/usr/bin/python3

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def boxcox(x, l):
    return np.log(x) if (l == 0) else (x**l-1/l)

passengers = pd.read_csv('passengers.csv')
passengers['TravelDate'] = pd.DatetimeIndex(passengers['TravelDate'])
passengers.set_index('TravelDate', inplace=True)

passengers['2'] = boxcox(passengers['Passengers'], 2)
passengers['0'] = boxcox(passengers['Passengers'], 0)
passengers['-0.5'] = boxcox(passengers['Passengers'], -0.5)

subplot_lambda = {1: '1', 2: '-0.5', 3: '2', 4: '0'}
for key in subplot_lambda:
    val = subplot_lambda[key]
    plt.subplot(220 + key)
    if val == '1':
        passengers['Passengers'].plot()
        plt.title('Original')
    else:
        passengers[val].plot()
        plt.title(val)
    plt.xlabel('')
plt.show()
