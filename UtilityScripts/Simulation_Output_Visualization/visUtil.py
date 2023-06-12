import sys
import json
import numpy as np

def getArgs():
  indexes = False
  shoulders = False
  shldrLen = 0
  flagCnt = 1
  outpath = "output.gif"
  peds = ""
  obs = ""
  xMin = -1
  yMin = -1
  xMax = 25
  yMax = 4
  fps = 10

  for arg in sys.argv[1::]:
    if arg == '-idx':
      indexes = True
      flagCnt += 1
    elif arg == '-shldr':
      shldrLen = float(sys.argv[flagCnt + 1])
      shoulders = True
      flagCnt += 2
    elif arg == '-out':
      outpath = sys.argv[flagCnt + 1]
      flagCnt += 2
    elif arg == '-peds':
      peds = sys.argv[flagCnt + 1]
      flagCnt += 2
    elif arg == '-obs':
      obs = sys.argv[flagCnt + 1]
      flagCnt += 2
    elif arg == '-xDim':
      dims = sys.argv[flagCnt + 1].split(',')
      xMin = float(dims[0])
      xMax = float(dims[1])
      flagCnt += 2
    elif arg == '-yDim':
      dims = sys.argv[flagCnt + 1].split(',')
      yMin = float(dims[0])
      yMax = float(dims[1])
      flagCnt += 2
    elif arg == '-fps':
      fps = float(sys.argv[flagCnt + 1])
      flagCnt += 2
    else:
      if (arg[0] == '-'):
        print(f'Unknown Flag: {arg}')
        exit(-1)
    

  if peds == "" or obs == "":
    print("The Flags -peds and -obs Are Required")
    exit(-1)

  return dict(
    indexes  = indexes,
    shoulders= shoulders,
    shldrLen = shldrLen,
    outpath  = outpath,
    peds     = peds,
    obs      = obs,
    xMin     = xMin,
    xMax     = xMax,
    yMin     = yMin,
    yMax     = yMax,
    fps = fps,
  )


def getObs(obs):
  obsCoords = json.load(open(obs))
  obsX = []
  obsY = []
  for obj in obsCoords["obstacle"]:
    obsX.append(float(obj["x"]))
    obsY.append(float(obj["y"]))

  return (obsX, obsY)

def getPeds(peds):
    return json.load(open(peds))["timesteps"]


def getPoints(timestep):
  pointsX = []
  pointsY = []
  for key in timestep:
    pointsX.append(key["x"])
    pointsY.append(key["y"])

  return (pointsX, pointsY)

def makeColors(pedCoords):
    return np.random.rand(len(pedCoords["0"]), 3)

def plotShoulders(pointsX, pointsY, shldrLen, colors, ax):
  for index in range(0, len(pointsX)):
    x = pointsX[index]
    y = pointsY[index]
    ax.plot([x-shldrLen, x+shldrLen], [y, y], color=colors[index], linestyle='-', linewidth=0.5)
    ax.plot([x, x], [y-shldrLen, y+shldrLen], color=colors[index], linestyle='-', linewidth=0.5)

def plotIndexes(pointsX, pointsY, pedColors, ax):
  for index in range(0, len(pointsX)):
    ax.text(pointsX[index], pointsY[index], index, fontsize=5, c=pedColors[index])


percent = 0

def printProgressBar (iteration, total, prefix="Saving", animating=False):
    if not animating:
      percent = ("{0:." + str(1) + "f}").format(100 * (iteration / float(total)))

    filledLength = int(100 * iteration // total)
    bar = '█' * filledLength + '-' * (100 - filledLength)
    print(f'\r{prefix.ljust(9, " ")} :  |{bar}| {percent}%', end = "\r")
    if iteration == total:
        print()
