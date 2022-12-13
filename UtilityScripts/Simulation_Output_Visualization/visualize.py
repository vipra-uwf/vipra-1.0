import json
import sys
import os
import matplotlib
import matplotlib.pyplot as plt
import imageio

if(len(sys.argv) != 3):
    print("USAGE: python3 visualizer.pyz *pedestrian_trajectory.json* *obstacle_set.json*")
    exit(-1)


peds = open(sys.argv[1])
obs = open(sys.argv[2])

data = json.load(peds)
obstacles = json.load(obs)

obsX = []
obsY = []

for obj in obstacles["obstacles"]:
    obsX.append(float(obj["x"]))
    obsY.append(float(obj["y"]))


ax = plt.gca()

maxStep = len(data["timesteps"])

with imageio.get_writer('output.gif', mode='I') as writer:
    for step in data["timesteps"]:
        plt.pause(0.05)
        plt.cla()
        ax.set_ylim(-5, 5)
        ax.set_xlim(-5, 30)
        ax.autoscale(False)
        plt.title(step)
        pointsX = []
        pointsY = []
        for key in data["timesteps"][step]:
            pointsX.append(key["x"])
            pointsY.append(key["y"])
        plt.scatter(obsX, obsY, 1)
        plt.scatter(pointsX, pointsY, 2)
        plt.savefig(f'{step}.png')
        image = imageio.v2.imread(f'{step}.png')
        writer.append_data(image)
        os.remove(f'{step}.png')
        