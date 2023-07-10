# VIPRA Pathfinding

# Sections

### C. Creating the Map
### A. Astar

### N. Needs

---
# C. Creating the Map



# A. Astar 

Astar is a pathfinding algorithm that is used to find an optimal path from point A to point B, ours is modified to improve efficiency by adding in a breadcrumb approach. 

The algorithm is comprised of:
- determining start and end positions
- from start to finish:
    - check to see if current position is the end position
    - if it is, generate and return the path by using parent pointers
    - If it is not, check to see if the location exists as a key in a hash table
    - should it exist, add the hash table value into the priority queue
    - else evaluate each existing neighbor on the grid and add them to the priority queue.
- if no path was found print a warning and return an empty path. 

### Positioning on the Map

As discussed prior, the graph that the paths are developed on is comprised of simple GridPoints that contain a center VIPRA::f3d object, a vector of adj GridPoint* pointers and boolean variables for traversability and buffers. The center object is crucial as this gives relative position with x and y coordinates. 

In order to allow for more relationships on the graph, the struct AGridPoint was created with a GridPoint node to give it reference to the graph. Along with an AGridPoint* parent pointer, a variable to contain total distance from start, and another to contain total distance plus a heuristic, this struct allowed for the A Star approach to be viable.

Each newly found position during the algorithm is created with an AGridPoint* pointer to keep track of this data for later use, either during the algorithm or afterwards when creating the path. 

### Initial Start of the Algorithm

The function has three parameters: VIPRA::f3d start, VIPRA::f3d end, and the PathingGraph& graph. The start and end f3d objects are used to create GridPoints named first and last to denote the first and last points in the path generated, which is generated as a queue. 

A modified version of the standard priority queue was implemented to allow for the priority queue to sort based on total distance with the heuristic, so the next node being expanded was always the one with the least cost, leading to optimal path generation. The GridPoint first is added to this priority queue - open_list. This is followed by a pointer - AGridPoint* curr - that iterates through the open_list until it is empty or its inner node variable is equivalent to the GridPoint last. 

### Main Body of the Algorithm

While the loop is still iterating, the top of the priority queue is assigned to curr and popped off, in which curr is inserted into an unordered set closed_list, which serves the purpose of checking to see if that position has been explored before.

It then checks to see if curr exists in an unordered_map, defined by < GridPoint*, GridPoint*, GridPointHash >. The purpose of this map, named breadCrumbMap, is to allow the usage of a breadcrumb approach. A breadcrumb approach is where you lay down a marker to show where you have been before and where you went next. As there exists many pedestrians needing individualized paths to be created, each time the algorithm iterates over that same position, it has to recalculate everything including the neighbors and it's cost. Instead, adding in this breadCrumb map allows the algorithm to determine that a previous iteration had been in a specific position before and simply add the pre-established location to the priority queue instead of having to compute all of the neighbors again. 
This breadCrumbMap uses GridPoint objects as a way of storing the different positions rather than AGridPoint objects. The primary reason for this is that to hash AGridPoint objects, it involves unecessary information including parent and cost which don't help secure an absolute location on the graph. However for GridPoint objects, it requires hashing the coordinates and the neighbors which leads to more uniquely defined locations. The GridPointHash is the hash struct that summs up the hash of the f3d object, which is located in dimensions.hpp, the adjacent grid points as reinterpreted integers as pointes, and using the standard hash function for the two boolean variables. 

Should the position not be in the breadcrumb map, the curr variable's neighbors are expanded using a for loop. For each of these neighbors, it only expands them if the neighbor has yet to be visited by checking for membership the closed_list mentioned prior. 
When expanding the GridPoint nodes, it calculates the total distance from the start by adding the distance the curr node holds and the distance from the neighbor node center to the curr node center. It then uses another variable to store the total distance with heuristic using a cost function, to be discussed below, and using these variables it creates an AGridPoint object that stores the neighbor GridPoint as it's node, the curr Gridpoint as the parent, and the two variables for cost. 
It is possible for the same node to be added to the priority queue without those nodes being expanded, so if the open_list contains the newly made GridPoint neighbor, it updates what is already in the priority queue if it found a more optimal path. If it is not in the priority queue, it adds in the neighbor. 

### Cost Function

The cost function is the defining part of the A Star algorithm. This is the heuristic in play to guide the creation of paths more towards a desireable destination in a smooth manner. 
It takes in two GridPoint objects acting as a current position and a goal position. Then the manhattan distance is determined between the two by finding the sum of the absolute difference between the x coordinates and the y coordinates. The plane given at the time is one that includes a single goal with a single isle. In order to have pedestrains move towards the goal in a desirable manner, weights are assigned to the x and y values in order to positively influence moving horizontally down the isle instead of vertically up into the seating area. As moving up technically would make the pedestrain closer to the exit in the top right corner, the barriers in place would stop them, making that path take longer. Hence the necessity of weights to influence positive movement. 

### Creation of the Path 

At each iteration of the while loop, cycling through the open_list, the algorithm checks to see if the current node is equivalent to the GridPoint last in which case, it has reached the end goal. When this happens, the function constructPath is called with the start position and the curr GridPoint. The algorithm needs the curr GridPoint rather than the last GridPoint as curr is the one with the parent relationship that will lead back to start.

The function constructPath has two parameters being VIPRA::f3d start and AGridPoint* end (previously we passed in the AGridPoint named curr but for clarity, it is named as end here). It first creates a queue and three variables AGridPoint* iter, AGridPoint* prev and VIPRA::f3d diff. Iter serves the purpose of looping through all of the parent relationships, starting at end's parent. Prev is the node that is added to the path each iteration so that when iter == nullptr by pointing to first's parent, first still gets added to the path. Each iteration dif is reassigned the diference between iter's and prev's center nodes - if they are differnt that shows a slight turn or change in direction so it gets added to the path, else it gets skipped. This allows for straight lines in a single direction to be continuous. 
Within this loop, the breadcrumb map that was detailed above is filled. This function only gets called when an optimal path is created, so rather than adding random path segements into the hash map as the algorithm progressed, by including these additions in constructPath, only optimal path segments are added. Specifically these are added if it is not the first iteration and it only adds the nodes of type GridPoint rather than the AGridPoint objects as key value pairs, automatically calling the hash function when added. 
After it finishes recording the pathway into the queue path, it needs to reverse the queue. This is due to the algorithm running from start to goal, making the parent relationships get recorded from goal to start which is backwards. For this to be meaningful it is reversed by using a stack to hold temporary results and placed back into the queue in the proper order. This then returns the path and the algorithm terminates. 


# I. Issues

1. The cost function currently uses parameters to help guide the A Star algorithm to prioritize horizontal movement over vertical movement by hard coded values. These should be created with parameters instead. 
---