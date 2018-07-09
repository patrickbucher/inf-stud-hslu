#!/usr/bin/Rscript

library(ggplot2)

measurements <- read.csv(file = 'ultraschall.csv', header = TRUE, stringsAsFactors = TRUE, sep = ';')
measurements$row <- 1:nrow(measurements)

by_hand <- data.frame(value= measurements$by_hand, type = 'handgemessen', n = measurements$row)
mean <- data.frame(value = measurements$mean, type = 'Ultraschall (mean)', n = measurements$row)
median <- data.frame(value= measurements$median, type = 'Ultraschall (median)', n = measurements$row)

points <- data.frame(value = c(), type = c(), n = c())
points <- rbind(by_hand, points)
points <- rbind(mean, points)
points <- rbind(median, points)

plot <-
    ggplot(points, aes(x = n, y = value, color = type, shape = type)) +
    geom_point(alpha = 0.8, size = 2) +
    labs(title = 'Distanzmessung: von Hand und per Ultraschallsensor') +
    xlab('Messung') +
    ylab('Distanz [cm]') +
    labs(color = 'Messart', shape = 'Messart') +
    scale_x_continuous(breaks = measurements$row)

ggsave(filename = 'ultraschall.png', plot = plot, device = 'png')
