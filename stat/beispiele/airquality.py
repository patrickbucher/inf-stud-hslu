#!/usr/bin/python3

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from pandas.plotting import lag_plot

airquality = pd.read_csv('airquality.csv', sep=';', decimal=',')
airquality_copy = airquality.copy()

airquality_copy['Time'] = airquality_copy['Time'].str.replace('.', '-')
datetime = pd.to_datetime(airquality_copy['Date'] + ' ' + airquality_copy['Time']).dt.tz_convert(None)
airquality_copy['Date'] = pd.DatetimeIndex(datetime)
airquality_copy.set_index('Date', inplace=True)

airquality_copy = airquality_copy[airquality_copy['T'] > -20]
airquality_q4 = airquality_copy.loc['2004-3-10':'2004-3-30', 'T']
airquality_q4.plot()
plt.show()

airquality_copy.boxplot('T', by='Time')
plt.show()

plt.subplot(121)
lag_plot(airquality_q4)
plt.subplot(122)
lag_plot(airquality_q4, 10)
plt.show()
