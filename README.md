# VIPRA

### Extension



---
### Virtual Classes

##### PedestrianSet

##### ObstacleSet (will be virtual soon)

##### EntitySetFactory
convert data types

##### Goals

##### PedestrianDynamicsModel

##### InputDataLoader

##### OutputDataWriter  

##### SimulationOutputHandler





---
### Types
When extending VIPRA source code, we encourage usage of our defined types. 

##### ENTITY_SET
This type is unstructured data read in from a file and is returned from 
all derived classes of InputDataLoader. The vector contains a unordered map 
of attributes for each element 
*e.g.* pedestrian or obstacle data
```
std::vector<std::unordered_map<std::string, std::string>>
```
##### SIM_PARAMS 
```
std::unordered_map<std::string, FLOATING_NUMBER>
```
##### SIM_CONFIG
```
std::unordered_map<std::string, std::string>
``` 


---
### Utility Scripts

#### Trajectory Visualization

Using the header-only C++ plotting library, [matplotlib-cpp](https://github.com/lava/matplotlib-cpp),
this script reads from a user-specified trajectory file, stores trajectory coordinates in vectors, 
then iterates over to display a 2D visualization (example video below)

<a href="http://www.youtube.com/watch?feature=player_embedded&v=twemPX9KuGk
" target="_blank"><img src="http://img.youtube.com/vi/twemPX9KuGk/0.jpg" 
alt="Trajectory Visualization" width="580" height="360" border="15" /></a>

###### Requirements:
- Linux
- Python 3.8.x
###### Limitations: 
- only supports 2D visualization 
- visualization preferences are currently "hard-coded" 
