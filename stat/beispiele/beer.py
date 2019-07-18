#!/usr/bin/python3

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

beer = pd.read_csv('beer.csv', sep=';', header=0)
beer_copy = beer.copy()
print(beer_copy.head())

beer_copy['Quarter'] = pd.DatetimeIndex(beer['Quarter'])
beer_copy.set_index('Quarter', inplace=True)
print(beer_copy.head())
print(beer_copy.describe())

beer_copy.plot()
plt.xlabel('Quarter')
plt.ylabel('Production (Megalitres)')
plt.show()

beer_copy.loc['1980-9':'1990-3',:].plot()
plt.xlabel('Quarter')
plt.ylabel('Production (Megalitres)')
plt.show()
