import json
import sys
import matplotlib
import matplotlib.pyplot as plt

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

for step in data:
   plt.pause(0.05)
   plt.cla()
   ax.set_ylim(-5, 5)
   ax.set_xlim(-5, 30)
   ax.autoscale(False)
   plt.title(step)
   pointsX = []
   pointsY = []
   for key in data[step]:
       pointsX.append(key["x"])
       pointsY.append(key["y"])
   plt.scatter(obsX, obsY, 1)
   plt.scatter(pointsX, pointsY, 2)

plt.show()