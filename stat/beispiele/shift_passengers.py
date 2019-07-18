#!/usr/bin/python3

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

passengers = pd.read_csv('passengers.csv')
passengers['TravelDate'] = pd.DatetimeIndex(passengers['TravelDate'])
passengers.set_index('TravelDate', inplace=True)

passengers['s_+4'] = passengers['Passengers'].shift(+4)
passengers['s_-5'] = passengers['Passengers'].shift(-5)

passengers['Passengers'].plot()
passengers['s_+4'].plot()
passengers['s_-5'].plot()
plt.legend(['Original', 'Right Shift', 'Left Shift'])
plt.show()
