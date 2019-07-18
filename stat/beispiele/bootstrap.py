#!/usr/bin/env python3

import numpy as np

# 1. Sample der Länge n
sample = np.array([30, 37, 36, 43, 42, 43, 43, 46, 41, 42])
n = sample.size

# 2. x Ziehungen aus diesem Sample mit Zurücklegen
x = 20
bootstrap_data = np.random.choice(sample, n*x, replace=True)
bootstrap_samples = np.reshape(bootstrap_data, (n, x))

# 3. Das arithmetische Mittel der Spalten berechnen
columns_means = bootstrap_samples.mean(axis=0)

# 4. Die arithmetischen Mittel der Spalten aufsteigend sortieren
np.sort(columns_means)

# 5. Die Quantile am Rand gemäss gegebenem Vertrauensintervall nehmen
a = 0.05
lower, upper = a/2, 1-a/2
confidence_interval = np.percentile(columns_means, q=[lower, upper])
print(confidence_interval)

# Interpretation: Die Daten liegen mit einer Wahrscheinlichkeit von 1-a
# (hier: 95%) im gefundenen Bereich.

# "richtiger Bootstrap"
n = 100
sample = np.random.normal(loc=40, scale=5, size=n)
x = 20
bootstrap_data = np.random.choice(sample, n*x, replace=True)
bootstrap_samples = np.reshape(bootstrap_data, (n, x))
columns_means = bootstrap_samples.mean(axis=0)
# Differenz zwischen simuliertem und gemessenem arithmetischen Mittel!
delta_mean = columns_means - sample.mean()
a = 0.05
lower, upper = a/2, 1-a/2
bounds = np.percentile(delta_mean, q=[lower, upper])
confidence_interval = sample.mean() - [bounds[1], bounds[0]]
print(confidence_interval)
