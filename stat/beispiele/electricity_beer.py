#!/usr/bin/python3

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

beer = pd.read_csv('beer.csv', sep=';', header=0)
electricity = pd.read_csv('electricity.csv', sep=';')

combined = beer.copy()
combined['kilowatt'] = electricity['Kilowatt']
combined['Quarter'] = pd.DatetimeIndex(combined['Quarter'])
combined.set_index('Quarter', inplace=True)
combined.plot(subplots=True)
plt.show()
