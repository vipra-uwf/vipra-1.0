import sys
import json
from matplotlib.lines import Line2D

import numpy
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle

# expects input to be json with
# {
#   "quads": [
#   {"x", "y"}
#   ],
#   "paths": [
#     [
#       {"x", "y"}
#     ]
#   ]
# }


points = open(sys.argv[1])
peds = open(sys.argv[2])
obs = open(sys.argv[3])

data = json.load(points)

fig, ax = plt.subplots()

# for obj in data["quads"]:
#   size = float(obj["size"])
#   x = float(obj["x"]) - size/2
#   y =  float(obj["y"]) - size/2
#   ax.add_patch( Rectangle((x, y), size, size, fill=(not obj["trav"])))
#   c = numpy.random.rand(3,)

for ped in json.load(peds)["pedestrians"]:
  ax.scatter(float(ped["x"]), float(ped["y"]), 2, color="red")

for ob in json.load(obs)["obstacle"]:
  ax.scatter(float(ob["x"]), float(ob["y"]), 2, color="purple")

for obj in data["Paths"]:
  lastx = -1
  lasty = -1
  c = numpy.random.rand(3,)
  for i in obj["points"]:
    print(i)
    x = i["x"]
    y = i["y"]
    if (lastx != -1 and lasty != -1):
      ax.add_line(Line2D((lastx, x), (lasty, y), color=c))
    lastx = x
    lasty = y

ax.add_patch(Rectangle((3 - .025, 21.5 - .025), .05, .05, facecolor="blue"))
plt.title("test")
plt.xlim([0, 30])
plt.ylim([0, 30])

plt.show()