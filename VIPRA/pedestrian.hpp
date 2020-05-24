#ifndef PEDESTRIAN_HPP
#define PEDESTRIAN_HPP

#include <vector>

class pedestrian
{
    public:
        pedestrian();

        void setNearestNeighbor(double, double);

        void setPedestrianGoal(int);
        void setDesiredVelocity(double);
        void setVelocityXDirection(double);
        void setVelocityYDirection(double);
        void setPedestrianMass(double);

        void setForceOfPropulsion(double);

        std::vector<double> getNearestNeighbor();

        int getPedestrianGoal();
        double getDesiredVelocity();
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
