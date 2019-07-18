#!/usr/bin/python3

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from statsmodels.tsa.seasonal import seasonal_decompose

passengers = pd.read_csv('passengers.csv')
passengers['TravelDate'] = pd.DatetimeIndex(passengers['TravelDate'])
passengers.set_index('TravelDate', inplace=True)

passengers['Trend'] = passengers['Passengers'].rolling(window=12).mean()
passengers['Passengers'].plot()
passengers['Trend'].plot()

passengers['Season'] = passengers['Passengers'] - passengers['Trend']
passengers['Season'].plot()

plt.legend(['Data', 'Trend', 'Season'])
plt.show()

passengers_copy = passengers['Season'].values.reshape((12, 12))
average = np.nanmean(passengers_copy, axis=0)
passengers['Season_average'] = np.tile(A=average, reps=12)
passengers['Season_average'].plot()
plt.show()

passengers['Residual'] = passengers['Season'] - passengers['Season_average']
passengers['Residual'].plot()
plt.show()

seasonal_decompose(passengers['Passengers'], model='additive', freq=12).plot()
plt.show()
