#ifndef PEDESTRIAN_HPP
#define PEDESTRIAN_HPP

#include <vector>

//typedef primitives to make easier to change later

class Pedestrian
{
    public:
        Pedestrian();

        void setNearestNeighbor(double, double);

        //the goal should be x,y coordinates
        void setPedestrianGoal(int);
        //setDesiredSpeed or make setDesiredVelocity and send in speed and direction
        void setDesiredVelocity(double);
        //refactor to set velocity direction as one function so can be overloaded later
        void setVelocityXDirection(double);
        void setVelocityYDirection(double);
        void setPedestrianMass(double);

        void setForceOfPropulsion(double);

        std::vector<double> getNearestNeighbor();

        int getPedestrianGoal();
        double getDesiredVelocity();
        //change velocity to be a struct type
        double getVelocityXDirection();
        double getVelocityYDirection();
        double getPedestrianMass();

        double getForceOfPropulsion();


    private:
        //store nearest neighbor in x, y format
        std::vector<double> nearestNeighbor;

        //goal for ped, stored as 1 for positive y value, -1 for negative y value, 0 for in isle
        int goal;
        double desiredVelocity;
        double velocityXDirection;
        double velocityYDirection;
        double mass;

        double forceOfPropulsion;

};

#endif // PEDESTRIAN_HPP
