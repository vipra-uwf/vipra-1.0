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
            "name": "pathingType",
            "type": "string",
            "description": "Which Pathfinding Method to use, currently (Astar, Disembark)",
            "multiple": false
        },
        {
            "name": "quadSize",
            "type": "float",
            "description": "Minimum Size for quad tree quads",
            "multiple": false
        },{
            "name": "closestObstacle",
            "type": "float",
            "description": "Closest a Quad can be to an obstacle without being considered not traversable",
            "multiple": false
        }
    ],
    "className": "CalmGoals",
    "type": "goals"
}