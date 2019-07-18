#!/usr/bin/python3

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

passengers = pd.read_csv('passengers.csv')
print(passengers.head())

passengers['TravelDate'] = pd.DatetimeIndex(passengers['TravelDate'])
passengers.set_index('TravelDate', inplace=True)
print(passengers.head())

passengers.plot()
plt.xlabel('Reisedatum')
plt.ylabel('Anzahl Passagiere (in 1000)')
plt.show()
