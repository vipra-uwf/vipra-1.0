import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation, PillowWriter, FFMpegFileWriter
import numpy as np

from visUtil import getArgs, plotDif, getPeds, getObs, makeColors, printProgressBar, getPoints, prepPlot, plotObs, plotShoulders, plotPeds, plotIndexes, printProgressBar, printProgressBar

args = getArgs()

pedCoords = getPeds(args['peds'])
difCoords = getPeds(args['dif'])
[obsX, obsY] = getObs(args['obs']);
pedColors = makeColors(len(pedCoords["timesteps"][0]["pedestrians"]), args)
timestepCnt = len(pedCoords["timesteps"])

fig,ax = plt.subplots()


def animate(i):
  printProgressBar(i, timestepCnt, 'Animating')
  [pointsX, pointsY] = getPoints(pedCoords["timesteps"][i])
  [compX, compY] = getPoints(difCoords[i]) if args['dif'] else [[], []]

  prepPlot(ax, args)
  obstacles = plotObs(obsX, obsY, ax, args)
  plotShoulders(pointsX, pointsY, pedColors, ax, args)
  points = plotPeds(pointsX, pointsY, pedColors, ax, args) if not args['dif'] else plotDif(pointsX, pointsY, compX, compY, pedColors, ax, args)
  plotIndexes(pointsX, pointsY, pedColors, ax, args)
  
  return points, obstacles


ani = FuncAnimation(fig, animate, frames=timestepCnt, blit=True)
ani.save(args['outpath'], dpi=300, writer=FFMpegFileWriter(fps=args['fps']), progress_callback=printProgressBar)
printProgressBar(timestepCnt, timestepCnt, 'Done')