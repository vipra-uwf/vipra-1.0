{
    "id": "Xz59g1o8HcsnMJlKaiYw00wZ19rB7P",
    "name": "calm_goals",
    "description": "TODO",
    "params": [
        {
            "name": "endGoalType",
            "type": "string",
            "description": "Type of Object that All Pedestrians Attempt to move towards",
            "multiple": false
        },
        {
            "name": "goalRange",
            "type": "float",
            "description": "Range from a goal a pedestrian needs to reach before considered reaching a goal",
            "multiple": false
        },
        {
            "name": "gridSize",
            "type": "float",
            "description": "Size of grids for pathfinding",
            "multiple": false
        },{
            "name": "closestObstacle",
            "type": "float",
            "description": "Closest a grid can be to an obstacle without being considered not traversable",
            "multiple": false
        }
    ],
    "className": "CalmGoals",
    "type": "goals"
}