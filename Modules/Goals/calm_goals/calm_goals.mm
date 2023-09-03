{
    "id": "Xz59g1o8HcsnMJlKaiYw00wZ19rB7P",
    "name": "calm_goals",
    "description": "TODO",
    "params": [
        {
            "name": "endGoalType",
            "type": "string",
            "description": "Type of Object that All Pedestrians Attempt to move towards, available options depend on obstacle map used"
        },
        {
            "name": "goalRange",
            "type": "float",
            "description": "Range from a goal a pedestrian needs to reach before considered reaching a goal"
        },
        {
            "name": "gridSize",
            "type": "float",
            "description": "Size of grids for pathfinding"
        },
        {
            "name": "closestObstacle",
            "type": "float",
            "description": "Closest a grid can be to an obstacle without being considered not traversable"
        }
    ],
    "className": "CalmGoals",
    "type": "goals"
}