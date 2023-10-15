import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation, PillowWriter, FFMpegFileWriter
import numpy as np
import importlib

helpers = importlib.import_module('visUtil')

args = helpers.getArgs()

if (args['overrides']):
  overrides = importlib.import_module(args['overrides'])
  for name, entity in helpers.__dict__.items():
    if not name.startswith('__'):
        if hasattr(overrides, name):
          setattr(helpers, name, getattr(overrides, name))


pedCoords = helpers.getPeds(args['peds'])
difCoords = helpers.getPeds(args['dif'])
[obsX, obsY] = helpers.getObs(args['obs']);
pedColors = helpers.makeColors(pedCoords, args)
timestepCnt = len(pedCoords["timesteps"])

fig,ax = plt.subplots()


def animate(i):
  helpers.printProgressBar(i, timestepCnt, 'Animating')
  [pointsX, pointsY] = helpers.getPoints(pedCoords["timesteps"][i])
  [compX, compY] = helpers.getPoints(difCoords[i]) if args['dif'] else [[], []]

  helpers.prepPlot(ax, args)
  obstacles = helpers.plotObs(obsX, obsY, ax, args)
  helpers.plotShoulders(pointsX, pointsY, pedColors, ax, args)
  points = helpers.plotPeds(pointsX, pointsY, pedColors, ax, args) if not args['dif'] else helpers.plotDif(pointsX, pointsY, compX, compY, pedColors, ax, args)
  helpers.plotIndexes(pointsX, pointsY, pedColors, ax, args)
  
  return points, obstacles


ani = FuncAnimation(fig, animate, frames=timestepCnt, blit=True)
ani.save(args['outpath'], dpi=300, writer=FFMpegFileWriter(fps=args['fps']), progress_callback=helpers.printProgressBar)
printProgressBar(timestepCnt, timestepCnt, 'Done')