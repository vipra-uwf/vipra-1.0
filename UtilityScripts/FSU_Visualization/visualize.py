import json
import sys
import os
import matplotlib
import matplotlib.pyplot as plt
import imageio


def readObs(obs):
  lines = obs.readlines()
  obsX = []
  obsY = []

  for line in lines:
    if line.startswith('16'):
      coords = line.split()
      obsX.append(float(coords[1]))
      obsY.append(float(coords[2]))
  return obsX, obsY

def readPeds(peds):
  lines = peds.readlines()
  data = {"timesteps": {}}

  currTS = -1

  for line in lines:
    if line.startswith("  144"):
      currTS = currTS + 1
      data["timesteps"][str(currTS)] = []
    if line.startswith('C'):
      coords = line.split()
      data["timesteps"][str(currTS)].append({"x": float(coords[1]), "y": float(coords[2])})
  return data



if(len(sys.argv) != 3):
    print("USAGE: python3 visualizer.pyz *animfile.xyz* *coords.d_coordinates.txt*")
    exit(-1)

peds = open(sys.argv[1])
obs = open(sys.argv[2])

data = readPeds(peds)
obsX, obsY = readObs(obs)

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
        