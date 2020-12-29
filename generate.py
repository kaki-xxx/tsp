#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import random

MAX_X = 1000
MAX_Y = 1000

n = 17

print(n)

for i in range(n):
    x = random.randint(0, MAX_X)
    y = random.randint(0, MAX_Y)
    print(x, y)
