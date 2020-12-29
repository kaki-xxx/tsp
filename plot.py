#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import subprocess
from subprocess import PIPE

import matplotlib.pyplot as plt

target_dir = "./graph/100-cities"

for i in range(1, 11):
    proc = subprocess.run(["./test.sh", "mst", f"100", f"{i}"], stdout=PIPE)
    output = proc.stdout.decode().splitlines()
    n = int(output[0])
    output = output[1:]

    x = [0] * (n+1)
    y = [0] * (n+1)
    for j in range(n):
        x[j], y[j] = map(int, output[j].split())
    x[-1] = x[0]
    y[-1] = y[0]

    fig = plt.figure()
    ax = fig.add_subplot(1, 1, 1)
    ax.scatter(x, y)
    ax.plot(x, y)
    fig.savefig(f"{target_dir}/{i}.png")
