
# VIPRA Simulation Visualization

# visualize.py

`visualize.py` is used to view the output from a simulation run.

## Setup

### Requirements

- Python 3.7^

- FFmpeg

- `pip` Modules:
  - `json`
  - `sys`
  - `os`
  - `numpy`
  - `matplotlib`


## Running

`python3 visualize.py *flags*`

### Flags

1. **REQUIRED** `-peds *sim output path*` : sets the path to the simulation output *(no default)*
2. **REQUIRED** `-obs *obstacle map path*` : sets the path to the obstacle map *(no default)*
3. `-outpath *output gif path*` : sets the path for the output gif *(default ./output.gif)*
3. `-idx` : prints the pedestrians index next to their position *(default OFF)*
4. `-idxClr` : colors pedestrian indexes to their color *(default OFF)*
5. `-shldr *len*` : draws shoulders <sup> (axis aligned) </sup> on pedestrians *(default OFF)*
- `*len*` being half the total shoulder length
6. `-xDim *minX, maxX*` : sets the min and max X for the plot *(default: -1, 25)*
7. `-yDim *minY, maxY*` : sets the min and max Y for the plot *(default: -1, 4)*
8. `-fps *fps*` : sets the fps of the output Gif *(default 10)*
9. `-pedClr` : sets each pedestrian a different color *(default OFF)*
10. `-obsClr *color*` : sets the color of obstacles *(default k)*
11. `-bckClr *color*` : sets the color of the background *(default w)*
12. `-dif *sim output filepath*` : shows differences between sim runs
13. `-difalpha *0.0-1.0*` : sets the alpha for dif *(default 0.25)*
14. `-diflines` : draws lines between pedestrians that have a dif *(default OFF)*
15. `-dlmax *float*` : scales dif line alpha by max distance *(default OFF)*

**color options: https://matplotlib.org/stable/tutorials/colors/colors.html**