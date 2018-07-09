from datetime import datetime
import logging
import os

file_level = logging.DEBUG
term_level = logging.INFO

log_name = 'silisloth'
dir_name = 'log'

if not os.path.exists(dir_name):
    os.makedirs(dir_name)

iso_date = datetime.now().isoformat().replace(':', '.')
file_name = '{}/{}_{}.log'.format(dir_name, log_name, iso_date)

file_handler = logging.FileHandler(file_name)
file_handler.setLevel(file_level)

console_handler = logging.StreamHandler()
console_handler.setLevel(term_level)

fmt = logging.Formatter('[%(asctime)s] [%(levelname)s] [%(name)s] %(message)s')
file_handler.setFormatter(fmt)
console_handler.setFormatter(fmt)


def instance(level=logging.DEBUG):
    return instance(log_name, level)


def instance(name, level=logging.DEBUG):
    logger = logging.getLogger(name)
    logger.setLevel(level)
    logger.addHandler(console_handler)
    logger.addHandler(file_handler)
    return logger
