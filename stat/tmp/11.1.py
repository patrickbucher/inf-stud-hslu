#!/usr/bin/env python3

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def extract_kanton(cars, kanton):
    cars_kanton = pd.DataFrame(cars.loc[kanton, '1990':])
    cars_kanton['Year'] = pd.DatetimeIndex(cars_kanton.index)
    cars_kanton.set_index('Year', inplace=True)
    return cars_kanton

cars = pd.read_csv('pw-electric.csv', sep=',', skiprows=2, header=0,
                   encoding='utf-8', index_col=0)

#cars_lu = pd.DataFrame(cars.loc['Luzern', '1990':])
#cars_lu['Year'] = pd.DatetimeIndex(cars_lu.index)
#cars_lu.set_index('Year', inplace=True)

cars_lu = extract_kanton(cars, 'Luzern')
cars_zh = extract_kanton(cars, 'Zürich')

# linearer Vergleich (wenig aussagekräftig)
ax = cars_lu.plot()
cars_zh.plot(ax=ax)
plt.xlabel('Jahr')
plt.ylabel('Anzahl Elektro-Autos')
plt.show()

# logarithmischer Delta-Vergleich (aussagekräftiger)
cars_lu['Luzern'] = np.log(cars_lu['Luzern'].astype('float')) - np.log(cars_lu['Luzern'].shift(1).astype('float'))
cars_zh['Zürich'] = np.log(cars_zh['Zürich'].astype('float')) - np.log(cars_zh['Zürich'].shift(1).astype('float'))
ax2 = cars_lu.plot()
cars_zh.plot(ax=ax2)
plt.xlabel('Jahr')
plt.ylabel('Elektro-Autos (logarithmiert, shifted)')
plt.show()
