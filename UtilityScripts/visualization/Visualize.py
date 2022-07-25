import json
import matplotlib.pyplot as plt

f = open('pedestrian_trajectory.json')

data = json.load(f)


ax = plt.gca()

for step in data:
    plt.pause(0.05)
    plt.cla()
    ax.set_ylim(-3, 3)
    ax.set_xlim(0, 26)
    ax.autoscale(False)
    plt.title(step)
    pointsX = []
    pointsY = []
    for key in data[step]:
        pointsX.append(key["x"])
        pointsY.append(key["y"])
    plt.scatter(pointsX, pointsY)

plt.show()