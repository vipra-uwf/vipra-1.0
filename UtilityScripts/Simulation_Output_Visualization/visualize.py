import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation, PillowWriter
import numpy as np

import visUtil as util

args = util.getArgs()

pedCoords = util.getPeds(args['peds']) 
[obsX, obsY] = util.getObs(args['obs']);
pedColors = util.makeColors(pedCoords, args['pedColor'])
timestepCnt = len(pedCoords)

fig,ax = plt.subplots()

def animate(i):
    util.printProgressBar(int(i), timestepCnt, 'Animating')
    ax.clear()
    ax.set_xlim(args['xMin'], args['xMax'])
    ax.set_ylim(args['yMin'], args['yMax'])
    ax.autoscale(False)
    
    [pointsX, pointsY] = util.getPoints(pedCoords[i])
    obstacles = ax.scatter(obsX, obsY, 1, c=args['obsColor'])
    points = ax.scatter(pointsX, pointsY, 2, pedColors)

    if args['shoulders']:
      util.plotShoulders(pointsX, pointsY, args['shldrLen'], pedColors, ax)
    if args['indexes']:
      util.plotIndexes(pointsX, pointsY, args['idxColor'], pedColors, ax)

    return points, obstacles


ani = FuncAnimation(fig, animate, frames=pedCoords, blit=True)
ani.save(args['outpath'], dpi=300, writer=PillowWriter(fps=args['fps']), progress_callback=util.printProgressBar)
util.printProgressBar(timestepCnt, timestepCnt, 'Done')