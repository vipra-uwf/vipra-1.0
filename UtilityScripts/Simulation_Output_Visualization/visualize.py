import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation, PillowWriter
import numpy as np

from visUtil import getArgs, plotDif, getPeds, getObs, makeColors, printProgressBar, getPoints, prepPlot, plotObs, plotShoulders, plotPeds, plotIndexes, printProgressBar, printProgressBar

args = getArgs()

pedCoords = getPeds(args['peds'])
difCoords = getPeds(args['dif']) if args['dif'] else None
[obsX, obsY] = getObs(args['obs']);
pedColors = makeColors(pedCoords, args['pedColor'])
timestepCnt = len(pedCoords)

fig,ax = plt.subplots()

def animate(i):
  printProgressBar(int(i), timestepCnt, 'Animating')
  [pointsX, pointsY] = getPoints(pedCoords[i])
  [compX, compY] = getPoints(difCoords[i]) if args['dif'] else None
  dif = True if args['dif'] else False

  prepPlot(args['xDim'], args['yDim'], args['bckColor'], ax)
  obstacles = plotObs(obsX, obsY, args['obsColor'], ax)
  plotShoulders(args['shoulders'], pointsX, pointsY, args['shldrLen'], pedColors, ax, dif, args['difalpha'])
  points = plotPeds(pointsX, pointsY, pedColors, ax) if not args['dif'] else plotDif(pointsX, pointsY, compX, compY, pedColors, ax, args['difalpha'])
  plotIndexes(args['indexes'], pointsX, pointsY, args['idxColor'], pedColors, ax, dif, args['difalpha'])    
  
  return points, obstacles


ani = FuncAnimation(fig, animate, frames=pedCoords, blit=True)
ani.save(args['outpath'], dpi=300, writer=PillowWriter(fps=args['fps']), progress_callback=printProgressBar)
printProgressBar(timestepCnt, timestepCnt, 'Done')