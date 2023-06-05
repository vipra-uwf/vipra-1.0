
# VIPRA Simulation Visualization

# visualize.py

`visualize.py` is used to view the output from a simulation run.

### Note: only works with the Calm module implementations

## Setup

### Requirements

- Python 3.7^

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
4. `-shldr *len*` : draws shoulders <sup> (axis aligned) </sup> on pedestrians *(default OFF)*
- `*len*` being half the total shoulder length
5. `-xDim *minX, maxX*` : sets the min and max X for the plot *(default: -1, 25)*
6. `-yDim *minY, maxY*` : sets the min and max Y for the plot *(default: -1, 4)*
