#ifndef PEDESTRIAN_RACE_STATUS
#define PEDESTRIAN_RACE_STATUS

//Indicates whether a passender is in a race for the aisle with another pedestrian
enum PedestrianRaceStatus {
    IN_RACE, WINNER, LOOSER, NO_RACE
    };
typedef PedestrianRaceStatus RaceStatus;

#endif