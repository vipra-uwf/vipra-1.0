/**
 * Implementation of Simulation class. Objects of this class represents a deplaning simulation with specified parameters
 *
 * @author  Mehran Sadeghi Lahijani <sadeghil@cs.fsu.edu>
 * 
 */

#include "Simulation.h"

using namespace std;


#include <sys/time.h>


double    Simulation::microtime(void)
{
  struct timeval t;

  gettimeofday(&t, 0);

  return 1.0e6*t.tv_sec + (double) t.tv_usec;
}

double    Simulation::get_microtime_resolution(void)
{
  double time1, time2;

  time1 = microtime();
  do
  {
    time2 = microtime();
  } while(time1==time2);

  return time2-time1;
}


Simulation::Simulation(){
}


Simulation::Simulation(Numeric mean_t, Numeric stddev_t, Numeric t_Intersection_Distance_Threshold, Numeric t_Intersection_Speed_Coefficient, Numeric t_Aligning_Speed_Coefficient, Numeric t_Toward_Aisle_Speed_Coefficient, Numeric t_Release_Threshold, int index){
    mean=mean_t;
    stddev=stddev_t;
    output_index = index;
    Intersection_Distance_Threshold= t_Intersection_Distance_Threshold;
    Intersection_Speed_Coefficient=t_Intersection_Speed_Coefficient;
    Aligning_Speed_Coefficient=t_Aligning_Speed_Coefficient;
    Toward_Aisle_Speed_Coefficient=t_Toward_Aisle_Speed_Coefficient;
    Release_Threshold = t_Release_Threshold;
}
int Simulation::getOutputIndex(){
    return output_index;
}
void Simulation::setOutputIndex(int output_index_t){
    output_index= output_index_t;
}
Numeric Simulation::getMean(){
    return mean;
}
Numeric Simulation::getStddev(){
    return stddev;
}
void Simulation::setMean(Numeric mean_t){
    mean=mean_t;
}
void Simulation::setStddev(Numeric stddev_t){
    stddev=stddev_t;
}





/**
 * Computing the separation distance between two passengers
 *
 * @param main_position The position of the main passenger. Main passenger is the passenger for whom we want to compute the propulsion
 * @param main_aim_t The aim of the main passenger
 * @param sec_position The position of the seconadry passenger. Secondary passengers all those among whom we want to find the nearest passenger to the main passenger
 * @param sec_aim_t The aim of the secondary passenger
 *
 * @return a Numeric that is the separation distance between the main and the secondary passenger. The separation distance is the distance between main and secondary passenger in the main passenger's direction of movement
 **/
Numeric Simulation::getSeparation(const Numeric& main_position_x, const Numeric& main_position_y, const Aim& main_aim_t, const Numeric& sec_position_x, const Numeric& sec_position_y, const Aim& sec_aim_t){
  
    
  if(main_aim_t == DOWN_TO_AISLE && fabs(sec_position_x - main_position_x)<(Numeric)0.1f){
        return main_position_y - sec_position_y;
  }else if((main_aim_t == UP_TO_AISLE) && fabs(sec_position_x - main_position_x)<(Numeric)0.1f){
        return sec_position_y - main_position_y;
  }else if((main_aim_t == TOWARD_EXIT) && fabs(sec_position_x - main_position_x)<(Numeric)0.15f){
        if(main_aim_t==sec_aim_t)
            return sec_position_y - main_position_y;
  }else if (main_aim_t==IN_AISLE && fabs(sec_position_y - main_position_y)<(Numeric)0.15f && (sec_aim_t==ALIGNING || sec_aim_t==IN_AISLE)){
        return sec_position_x - main_position_x;
  }else if(main_aim_t==ALIGNING){
    if(/*sec_aim_t==IN_AISLE && */sec_position_x<main_position_x){
        return (Numeric)0.75f;
    }
    else if((sec_position_x - main_position_x > (Numeric)-0.04f && sec_position_x - main_position_x<(Numeric)0.15f)){
        if(main_position_y>(Numeric)0.06f){
            return main_position_y - sec_position_y;
        }else if((main_position_y<-(Numeric)0.06f)){
            return sec_position_y - main_position_y;
        }
    }
  }  
    return (Numeric)100.0f;
}




/**
 * This function finds the nearest passenger to a passenger that is passed to it
 *
 * @param NID The ID of the nearest passenger
 * @param N_position_x The x coordinate of the position of the nearest passenger
 * @param N_position_y The y coordinate of the position of the nearest passenger
 * @param N_distance The actual distance to the nearest passenger
 * @param passenger_ID The ID of the passenger to whom we want to find the nearest passenger
 * @param passengers_t The datastructure that contains all passengers' data
 * @param exit_position The x coordinate of the plane's exit door
 * 
 **/

void Simulation::getNearestPassenger( int& NID, Numeric& N_position_x,  Numeric& N_position_y,  Numeric& N_distance, const int& passenger_ID, const Numeric& exit_position, const Passengers& passengers_t){
    NearestPassenger nearest_t;
    nearest_t.ID=-1;
    nearest_t.position_y=0;
    nearest_t.position_x = exit_position;
    nearest_t.distance=(Numeric)10.0f; // Just a big enough default value
    for(int i=0; i<NumberOfPassengers; ++i){
        if(passengers_t.aim[i]!=OUT && i!=passenger_ID){
            Numeric separation;
            //= getSeparation(passengers_t.position_x[passenger_ID], passengers_t.position_y[passenger_ID], passengers_t.aim[passenger_ID], passengers_t.position_x[i], passengers_t.position_y[i], passengers_t.aim[i]);
            
            if(passengers_t.aim[passenger_ID] == DOWN_TO_AISLE && fabs(passengers_t.position_x[i] - passengers_t.position_x[passenger_ID])<(Numeric)0.1f){
                separation =  passengers_t.position_y[passenger_ID] - passengers_t.position_y[i];
              }else if((passengers_t.aim[passenger_ID] == UP_TO_AISLE) && fabs(passengers_t.position_x[i] - passengers_t.position_x[passenger_ID])<(Numeric)0.1f){
                    separation =  passengers_t.position_y[i] - passengers_t.position_y[passenger_ID];
              }else if((passengers_t.aim[passenger_ID] == TOWARD_EXIT) && fabs(passengers_t.position_x[i] - passengers_t.position_x[passenger_ID])<(Numeric)0.15f){
                    if(passengers_t.aim[passenger_ID]==passengers_t.aim[i])
                        separation =  passengers_t.position_y[i] - passengers_t.position_y[passenger_ID];
              }else if (passengers_t.aim[passenger_ID]==IN_AISLE && fabs(passengers_t.position_y[i] - passengers_t.position_y[passenger_ID])<(Numeric)0.15f && (passengers_t.aim[i]==ALIGNING || passengers_t.aim[i]==IN_AISLE)){
                    separation =  passengers_t.position_x[i] - passengers_t.position_x[passenger_ID];
              }else if(passengers_t.aim[passenger_ID]==ALIGNING){
                if(passengers_t.position_x[i]<passengers_t.position_x[passenger_ID]){
                    separation =  (Numeric)0.75f;
                }
                else if((passengers_t.position_x[i] - passengers_t.position_x[passenger_ID] > (Numeric)-0.04f && passengers_t.position_x[i] - passengers_t.position_x[passenger_ID]<(Numeric)0.15f)){
                    if(passengers_t.position_y[passenger_ID]>(Numeric)0.06f){
                        separation =  passengers_t.position_y[passenger_ID] - passengers_t.position_y[i];
                    }else if((passengers_t.position_y[passenger_ID]<-(Numeric)0.06f)){
                        separation =  passengers_t.position_y[i] - passengers_t.position_y[passenger_ID];
                    }
                }
              }else{
                separation =  (Numeric)100.0f;
              }  
                


            if (separation<nearest_t.distance && separation>0){
                nearest_t.distance=separation;
                nearest_t.position_x=passengers_t.position_x[i];
                nearest_t.position_y=passengers_t.position_y[i];
                nearest_t.ID=i;
            }
        }//END if initial conditions
    }//End for cell
    NID= nearest_t.ID;
    N_position_x = nearest_t.position_x;
    N_position_y = nearest_t.position_y;
    N_distance = nearest_t.distance;

}

/**
 * Decreasing the maximum desired speed of a passenger based on the position of the nearest passenger
 *
 * @param desired_speed_t The maximum desired speed of the passenger
 * @param distance The actual distance to the nearest entity
 * @param coeff A coefficient that will be multiplied in the maximum desired speed in some cases
 *
 * @return a Numeric that is the desired speed of the passenger
 **/
Numeric Simulation::DecreaseSpeed(const Numeric& coeff, const Numeric& distance, const Numeric& desired_speed){

  Numeric a=2.111f, b=0.366f, c=0.966f;
  return coeff*Numeric(c-exp(-a * (distance-b))) * desired_speed;

}


/**
 * Compute the Propulsive force for a passenger.
 *
 * @param aim The current state/aim of the passenger
 * @param N_position_y The y coordinate of the position of the nearest passenger
 * @param mass The mass of the passenger
 * @param velocity_x Velocity of the passenger in the x direction
 * @param velocity_y Velocity of the passenger in the y direction
 * @param time_step The reaction time for getting reaching the desired speed
 * @param desired_speed The maximum desired speed that a passenger wants to reach
 * @param force_x The self-repulsion force that passenger receives in the x direction
 * @param force_y The self-repulsion force that passenger receives in the y direction
 * 
 */
void Simulation::Propulsive_Force(const Aim & aim, const Numeric& position_y, const Numeric& mass, const Numeric& velocity_x, const Numeric& velocity_y, const Numeric& time_step, const Numeric& desired_speed, Numeric& force_x, Numeric& force_y){
    Numeric e1_x=0.0f, e1_y=0.0f, new_velocity_x, new_velocity_y;
    if(aim==DOWN_TO_AISLE){
        e1_y = -1;
        //e1.x=0; e1.y=-1;
    }else if(aim==UP_TO_AISLE){
        e1_y = 1;
        //e1.x=0; e1.y=1;
    }else if(aim==ALIGNING){
      if(position_y>(Numeric)0.06f){
            e1_x=0.5f;
            e1_y=-0.9f; //0.9~sqrt(3)/2
            //e1.x=0.5; e1.y=-0.5*sqrt(3);
      }else if(position_y<-(Numeric)0.06f){
            e1_x= 0.5f;
            e1_y= 0.9f;
            //e1.x=0.5; e1.y=0.5*sqrt(3);
        }
    }else if(aim==IN_AISLE){
        /********ALIGNMENT********/
        /* Passengers should move on almost a line in the center of aisle*/
      if(position_y>(Numeric)0.05f){
            e1_x=0.5f;
            e1_y=-0.9f; //0.9~sqrt(3)/2
            //e1.x=0.5; e1.y=-0.5*sqrt(3);
      }else if(position_y<(Numeric)-0.05f){
            //e1.x=0.5; e1.y=0.5*sqrt(3);
            e1_x=0.5f;
            e1_y=0.9f; //0.9~sqrt(3)/2
        }else{
            //e1.x=1; e1.y=0;
            e1_x=1.0f;
        }
        /**************************/
    }else if(aim==TOWARD_EXIT){
        //e1.x=0; e1.y=1;
        e1_y= 1;
    }
    new_velocity_x = e1_x * (desired_speed);
    new_velocity_y = e1_y * (desired_speed);
    
    force_x = (new_velocity_x - velocity_x) * mass/time_step;
    //cout<<desired_speed<<" & "<<new_velocity_x<<" & "<<velocity_x<<" & "<<force_x<<endl;
    force_y = (new_velocity_y - velocity_y) * mass/time_step;
}



/**
 * Computing the separation distance between a passenger and an obstacle
 *
 **/
Numeric Simulation::getObsSeparation(const Numeric & main_position_x, const Numeric & main_position_y, const Aim& main_aim_t, const Numeric & obs_position_x, const Numeric & obs_position_y){
  if(main_aim_t == DOWN_TO_AISLE && fabs(obs_position_x - main_position_x)<(Numeric)0.05f){
        return main_position_y - obs_position_y;
  }else if((main_aim_t == UP_TO_AISLE) && fabs(obs_position_x - main_position_x)<(Numeric)0.05f){
        return obs_position_y - main_position_y;
  }else if((main_aim_t == TOWARD_EXIT) && fabs(obs_position_x - main_position_x)<(Numeric)0.05f){
        return obs_position_y - main_position_y;
  }else if (main_aim_t==IN_AISLE && fabs(obs_position_y - main_position_y)<(Numeric)0.05f){
        return obs_position_x - main_position_x;
    }
  return (Numeric)10.0f;
}


/**
 * Update the velocity and the position of a passenger using Euler solver.
 *
 **/

void Simulation::EulerMethod(const RaceStatus& race_status, const Numeric& force_x, const Numeric& force_y, const Numeric& mass, Numeric& velocity_x, Numeric& velocity_y, Numeric& position_x, Numeric& position_y, const Aim& aim, const Numeric& seat_position_x, const Numeric& desired_speed, const Numeric& delta){
    Numeric Speed, new_velocity_x, new_velocity_y, new_position_x, new_position_y;
    /*updating the velocity using Euler method*/
    new_velocity_x=(force_x * (Numeric)(delta/mass) + velocity_x);
    new_velocity_y=(force_y * (Numeric)(delta/mass) + velocity_y);

    if(race_status==WINNER && new_velocity_x<0){
        velocity_x = velocity_x * 0.1f;
        velocity_y = velocity_y * 0.1f;
        position_x = (velocity_x * delta) + position_x;
        position_y = (velocity_y * delta) + position_y;
    }else{
        velocity_x = new_velocity_x;
        velocity_y = new_velocity_y;
        
        Speed = (velocity_x * velocity_x) + (velocity_y * velocity_y); 
        /*updating the position using Euler method*/

        if(Speed<=(desired_speed*desired_speed)){
            new_position_x = (velocity_x * delta) + position_x;
            new_position_y = (velocity_y * delta) + position_y;
            
        }else{
            new_position_x = (velocity_x * (desired_speed/(Speed+0.01)) * delta) + position_x;
            new_position_y = (velocity_y * (desired_speed/(Speed+0.01)) * delta) + position_y;
        }


       
        position_x = new_position_x;
        position_y = new_position_y;
    }
}



/**
 * Split a string by a char delimeter
 *
 * @param s The string to be splitted.
 *
 * @param delim The delimeter for splitting string
 *
 * @param elems The container for splitted strings
 *
 */
void Simulation::split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

/**
 * Read input file and set position of passengers and obstacles.
 *
 * @param passengersmap_t Passengers' map of <ID, Passenger>
 * @param plane_t the plane object
 * @param obstacles_t Obstacles' container.
 * @param xyz_obs this vector contains the content of obstacles file (position of physical obstacles in the plane)
 *
 **/
vector<Numeric> Simulation::Initialize(Passengers &passengers_t, Obstacles &obstacles_t, vector<string>& xyz_obs, vector<pair<int, int> >& arrangement, ofstream& output){
    
    std::default_random_engine gen;
    std::normal_distribution<Numeric> ND(mean, stddev);

    Numeric tmpPosition_x, tmpPosition_y;
    vector<Numeric> sim_params;
    int index=0, obs_index=0;
    char coord_file[128];

    //sprintf(coord_file, "coord_757_200_182.d_coordinates.txt");
    sprintf(coord_file, "coord_A320_144.d_coordinates.txt");
    //sprintf(coord_file, "coord_B757_200_201.d_coordinates.txt");
    //sprintf(coord_file, "coord_CRJ_200_50.d_coordinates.txt");
    ifstream coords (coord_file);
    string line;
    
    multimap<Numeric, Numeric> positions_map;
    vector<string> tmp;
    stringstream buffer_stream;

    if (coords.is_open()){
        buffer_stream << coords.rdbuf();
        coords.close();
    }else{
        output<<"Error in reading coordinates file!\n";
    }

    while (getline (buffer_stream,line) ){
        if(index==0){ 
            split(line, '|', tmp);
            for(int i=0; i<int(tmp.size());i++){
                
                if (tmp[i].find('@')!=std::string::npos){
                    vector<string> pair;
                    split(tmp[i], '@', pair);
                    arrangement.push_back(make_pair(atoi(pair[0].c_str()), atoi(pair[1].c_str())));
                }else{
                    sim_params.push_back((Numeric)atof(tmp[i].c_str()));
                }
                
            }
            index++;
        }else if(index==1){

            split(line, '|', tmp);
            for(int i=0; i<int(tmp.size());i++){
                sim_params.push_back((Numeric)(atof(tmp[i].c_str())));
            }
            index++;
        }
        else{
            split(line, ' ', tmp);
            tmpPosition_x=(Numeric)(atof(tmp[1].c_str()));
            tmpPosition_y= (Numeric)(atof(tmp[2].c_str()));
            if(tmp[0]=="13"){
                positions_map.insert(make_pair(tmpPosition_x, tmpPosition_y));
            }else if(tmp[0]=="16"){
                obstacles_t.positions_x[obs_index]=tmpPosition_x;
                obstacles_t.positions_y[obs_index++]=tmpPosition_y;
            }
            index++;
        }
        tmp.clear();
    }
        
    char xyz[128];
    
    //sprintf(xyz, "xyz_obs_0");
    sprintf(xyz, "xyz_obs_1");
    //sprintf(xyz, "xyz_obs_2");
    //sprintf(xyz, "xyz_obs_4");
    stringstream xyz_buff_stream;
    ifstream xyz_file(xyz);
    if(xyz_file.is_open()){
        xyz_buff_stream << xyz_file.rdbuf();
        xyz_file.close();
    }else{
      output<<"Error in openning xyz_obstacles.txt!\n";
    }
    string xyz_line;
    while(getline(xyz_buff_stream, xyz_line)){
        xyz_obs.push_back(xyz_line);
    }
      


    /*initializing the passengers, determining the initial aim and the priority of passengers*/
    Numeric row=positions_map.begin()->first;
    Numeric tmpPriority=-1;
    //Numeric priority;
    Numeric position_x;
    Numeric position_y;
    int ID=0;
    for(multimap<Numeric,Numeric>::iterator itr=positions_map.begin(); itr!=positions_map.end(); ++itr){
        Aim initial_aim;
        if(itr->second > 0){
            initial_aim=DOWN_TO_AISLE;
        }else{
            initial_aim=UP_TO_AISLE;
        }
        position_x=Numeric(itr->first);
        position_y=Numeric(itr->second);
        if(itr->first != row){
            row = itr->first;
            tmpPriority--;
        }
        //priority = tmpPriority;
        //passengersmap_t.insert(make_pair(priority,ID));

        passengers_t.mass[ID] = (Numeric)1.0f;
        passengers_t.priority[ID] = tmpPriority;
        passengers_t.waitTime[ID] = (Numeric)0.0f;
        passengers_t.inPlane[ID] = true;
        passengers_t.aim[ID] = initial_aim;
        passengers_t.position_x[ID] = position_x;
        passengers_t.position_y[ID] = position_y;
        passengers_t.velocity_x[ID] = (Numeric)0.0f;
        passengers_t.velocity_y[ID] = (Numeric)0.0f;
        passengers_t.acceleration_x[ID] = (Numeric)0.0f;
        passengers_t.acceleration_y[ID] = (Numeric)0.0f;
        passengers_t.seat_position_x[ID] = position_x;
        passengers_t.seat_position_y[ID] = position_y;
        passengers_t.has_released[ID] = false;
        passengers_t.ID[ID] = ID;//Redundant!
        
        passengers_t.race_position_x[ID] = (Numeric)-100.0f;
        passengers_t.race_position_y[ID] = (Numeric)-100.0f;
        passengers_t.race_opID[ID] = -10;
        passengers_t.race_is_finished[ID] = true;
        passengers_t.race_counter[ID] = 0;
        passengers_t.race_status[ID] = NO_RACE;
        passengers_t.force_x[ID] = Numeric(0.0f);
        passengers_t.force_y[ID] = Numeric(0.0f);
        passengers_t.nearest_ID[ID] = -10;
        passengers_t.nearest_position_x[ID] = (Numeric)-100.0f;
        passengers_t.nearest_position_y[ID] = (Numeric)-100.0f;
        passengers_t.nearest_distance[ID] = (Numeric)100.0f;

        Numeric speed = ND(gen);
        while(speed<(Numeric)0.7 || speed>(Numeric)1.6){
            speed = ND(gen);
        }
        passengers_t.desiredSpeed[ID++] = speed;

    }
    //plane_t = Plane(plane_params[0], Numeric(plane_params[1]), Numeric(plane_params[2]), arrangement, obstacles_t);
    

    return sim_params;
}



/**
 * Initializing the permissions of moving in aisle for different rows
 *
 * @param holds this vector contains an integer for each row, except the first row, specifying the number of passengers in the front row that have not yet left 
 * @param aisle_permission which is used for granting the permission of moving in aisle to the passengers
 * @param arrangement specifies the seat arrangment of the plane
 *
 **/

void Simulation::initializePermissions(int* holds, bool* aisle_permission, const vector<pair<int, int> >& arrangement){
    int Total_Number_Of_Rows=0, index=0;

    for (int i = arrangement.size()-1; i>=0 ; --i){
        Total_Number_Of_Rows+=arrangement[i].first;
        for(int j=0; j<arrangement[i].first; ++j){
            holds[index]= arrangement[i].second;
            aisle_permission[index++] =false;
        }
    }
    aisle_permission[Total_Number_Of_Rows-1]=true;
}






/**
 * Checking if the passenger's path is blocked by an obstacle
 *
 * @param passenger_t the passenger whose path we are going to check
 * @param obstacles a const reference to the container of obstacles
 *
 * @return boolean indicating weather or not the path is blocked
 **/

bool Simulation::blockedPath(const int& passenger_ID, const Obstacles& obstacles_t, const Passengers& passengers_t){
    const int UL = NumberOfObstacles;
    bool flag = false;
    for(int i=0; i<UL; ++i){
        Numeric separation= getObsSeparation(passengers_t.position_x[passenger_ID], passengers_t.position_y[passenger_ID], passengers_t.aim[passenger_ID], obstacles_t.positions_x[i], obstacles_t.positions_y[i]);
        
        if(separation<Numeric(0.04f) && separation>Numeric(0.0f)){
            flag = true;
        }
    }
    return flag;
}






/****Race Detection
 * Race is the situation in which to passengers try to get in to the aisle,
 * but neither one can move becaue they have reached the stop_threshold. 
 * If the speed and the magnitude of the propulsion that a passenger receives
 * is less than 0.0001 for 1.5 s in real-world time, this is a race.
 * In this case one of the passengers will be randomly chosen to be the winner and
 * can get to the aisle. The other one can move after that.
 *
 ***/

void Simulation::raceDetection(Passengers& passengers, const int& ID, const Numeric& time_step, ofstream& output){
    Numeric speed = ((passengers.velocity_x[ID] * passengers.velocity_x[ID]) + (passengers.velocity_y[ID] * passengers.velocity_y[ID]));
    Numeric force_mag = ((passengers.force_x[ID] * passengers.force_x[ID]) + (passengers.force_y[ID] * passengers.force_y[ID]));
    if(speed<(Numeric)0.0001 && force_mag<(Numeric)0.0001){
        if(passengers.race_status[ID]==NO_RACE){
            int NID = passengers.nearest_ID[ID];
            if(NID>=0){
                if(passengers.race_status[NID]==NO_RACE && passengers.nearest_ID[NID]==ID){
                    
                    passengers.race_status[ID]=IN_RACE;
                    passengers.race_counter[ID]=1;
                    passengers.race_opID[ID]=NID;
                    passengers.race_position_x[ID]=passengers.position_x[ID];
                    passengers.race_position_y[ID]=passengers.position_y[ID];
                    passengers.race_is_finished[ID]=false;


                    passengers.race_status[NID]=IN_RACE;
                    passengers.race_counter[NID]=1;
                    passengers.race_opID[NID]=ID;
                    passengers.race_position_x[NID]=passengers.position_x[NID];
                    passengers.race_position_y[NID]=passengers.position_y[NID];
                    passengers.race_is_finished[NID]=false;

                }
            }else{
                output<<"ERROR 1: Passenger was not found: "<<NID<<" for "<<ID<<"\n";
            }
            
        }else if(passengers.race_status[ID]==IN_RACE){ //Already in race
            if(passengers.race_opID[ID]==passengers.nearest_ID[ID]){
                passengers.race_counter[ID]= (passengers.race_counter[ID]+1);
            }else{
                //cout<<"OPONNENT CHANGED!\n";
                int NID = passengers.nearest_ID[ID];
                int previous_opponent_ID = passengers.race_opID[ID];
                if(NID>=0 && previous_opponent_ID>=0){
                
                    if(passengers.race_status[NID]==NO_RACE){
                        passengers.race_counter[ID]=1;
                        passengers.race_opID[ID]=NID;
                        passengers.race_position_x[ID]=passengers.position_x[ID];
                        passengers.race_position_y[ID]=passengers.position_y[ID];
                        passengers.race_is_finished[ID]=false;

                        passengers.race_status[NID]=IN_RACE;
                        passengers.race_counter[NID]=1;
                        passengers.race_opID[NID]=ID;
                        passengers.race_position_x[NID]=passengers.position_x[NID];
                        passengers.race_position_y[NID]=passengers.position_y[NID];
                        passengers.race_is_finished[NID]=false;

                        passengers.race_status[previous_opponent_ID]=NO_RACE;
                        passengers.race_opID[previous_opponent_ID]=-10;
                        passengers.race_is_finished[previous_opponent_ID]=true;

                    }else{
                        //new opponent is in race
                        //cout<<"New opponent is in race!\n";
                    }
                }else{
                    output<<"ERROR 2: Passenger was not found!\n";
                }
            }
            if(passengers.race_counter[ID]==(int)(1.5/time_step) && passengers.race_status[ID]==IN_RACE){
                //decide on the winner/looser
                int OpID = passengers.race_opID[ID];
                
                if(OpID>=0) { 
                    if(passengers.priority[ID] < passengers.priority[OpID]){

                        
                        passengers.race_status[ID]=WINNER;
                        passengers.race_status[OpID]=LOOSER;
                    }else if(passengers.priority[ID]>passengers.priority[OpID]){
                        passengers.race_status[OpID]=WINNER;
                        passengers.race_status[ID]=LOOSER;
                    }else{
                        if(passengers.aim[OpID]==UP_TO_AISLE || passengers.aim[OpID]==DOWN_TO_AISLE){
                            passengers.race_status[ID]=WINNER;
                            passengers.race_status[OpID]=LOOSER;
                        }
                        else if(passengers.aim[ID]==ALIGNING){
                            if(passengers.aim[OpID]==ALIGNING){

                                if(fabs(passengers.position_y[ID]) < fabs(passengers.position_y[OpID])){
                                    passengers.race_status[ID]=WINNER;
                                    passengers.race_status[OpID]=LOOSER;
                                }else if(fabs(passengers.position_x[ID]) > fabs(passengers.position_x[OpID])){
                                    passengers.race_status[OpID]=WINNER;
                                    passengers.race_status[ID]=LOOSER;
                                }else{
                                    if(passengers.position_x[ID] > passengers.position_x[OpID]){
                                        passengers.race_status[ID]=WINNER;
                                        passengers.race_status[OpID]=LOOSER;
                                    }else if(passengers.position_x[ID] < passengers.position_x[OpID]){
                                        passengers.race_status[OpID]=WINNER;
                                        passengers.race_status[ID]=LOOSER;
                                    }else{
                                        if(rand()%2==0){
                                            //Winner
                                            passengers.race_status[ID]=WINNER;
                                            passengers.race_status[OpID]=LOOSER;
                                        }else{
                                            //Looser
                                            passengers.race_status[OpID]=WINNER;
                                            passengers.race_status[ID]=LOOSER;
                                        }
                                    }
                                }
                            }else{
                                if(passengers.position_x[OpID] < passengers.position_x[ID]){
                                    passengers.race_status[ID]=WINNER;
                                    passengers.race_status[OpID]=LOOSER;
                                }else{
                                    passengers.race_status[OpID]=WINNER;
                                    passengers.race_status[ID]=LOOSER; 
                                }
                                
                            }

                        }else if(passengers.aim[OpID]==ALIGNING){
                            if(passengers.position_x[ID] < passengers.position_x[OpID]){
                                passengers.race_status[OpID]=WINNER;
                                passengers.race_status[ID]=LOOSER;
                            }else{
                                passengers.race_status[ID]=WINNER;
                                passengers.race_status[OpID]=LOOSER;
                            }
                            

                        }else{
                            if(passengers.position_x[ID] > passengers.position_x[OpID]){
                                passengers.race_status[ID]=WINNER;
                                passengers.race_status[OpID]=LOOSER;
                            }else if(passengers.position_x[ID] < passengers.position_x[OpID]){
                                passengers.race_status[OpID]=WINNER;
                                passengers.race_status[ID]=LOOSER;
                            }else{
                                if(rand()%2==0){
                                //Winner
                                passengers.race_status[ID]=WINNER;
                                passengers.race_status[OpID]=LOOSER;
                                }else{
                                    //Looser
                                    passengers.race_status[OpID]=WINNER;
                                    passengers.race_status[ID]=LOOSER;
                                    //passenger.setWaitTime(1000);
                                }
                            }
                        }
                    }
  
                }else{
                    output<<"ERROR 3: Passenger was not found!\n";
                }
            }/*End if enough wait in race*/
        }//End if already in race
        else if(passengers.race_status[ID]==WINNER){
            //winner is blocked
            int first_looser = passengers.race_opID[ID];
            int NID = passengers.nearest_ID[ID]; //itr
            if(NID>=0 && first_looser>=0){
                if(passengers.race_status[NID]==WINNER){
                    int second_looser= passengers.race_opID[NID];
                    if(second_looser>=0){

                        passengers.race_counter[ID]=1;
                        passengers.race_status[ID]=IN_RACE;
                        passengers.race_opID[ID]=NID;
                        passengers.race_position_x[ID]=passengers.position_x[ID];
                        passengers.race_position_y[ID]=passengers.position_y[ID];
                        passengers.race_is_finished[ID]=false;


                        passengers.race_counter[NID]=1;
                        passengers.race_status[NID]=IN_RACE;
                        passengers.race_opID[NID]=ID;
                        passengers.race_position_x[NID]=passengers.position_x[NID];
                        passengers.race_position_y[NID]=passengers.position_y[NID];
                        passengers.race_is_finished[NID]=false;

                        passengers.race_status[first_looser]=NO_RACE;
                        passengers.race_opID[first_looser]=-10;
                        passengers.race_is_finished[first_looser]=true;

                        passengers.race_status[second_looser]=NO_RACE;
                        passengers.race_opID[second_looser]=-10;
                        passengers.race_is_finished[second_looser]=true;

                    }else{
                        output<<"ERROR 5: Passenger was not found!\n";
                    }
                }else if(passengers.race_status[NID]==NO_RACE){

                    passengers.race_counter[ID]=1;
                    passengers.race_status[ID]=IN_RACE;
                    passengers.race_opID[ID]=NID;
                    passengers.race_position_x[ID]=passengers.position_x[ID];
                    passengers.race_position_y[ID]=passengers.position_y[ID];
                    passengers.race_is_finished[ID]=false;


                    passengers.race_counter[NID]=1;
                    passengers.race_status[NID]=IN_RACE;
                    passengers.race_opID[NID]=ID;
                    passengers.race_position_x[NID]=passengers.position_x[NID];
                    passengers.race_position_y[NID]=passengers.position_y[NID];
                    passengers.race_is_finished[NID]=false;

                    passengers.race_status[first_looser]=NO_RACE;
                    passengers.race_opID[first_looser]=-10;
                    passengers.race_is_finished[first_looser]=true;                    

                }else{
                    //cout<<"Winner is still blocked! "<<itr->second.getRaceStatus() <<"\n";
                }
            }else{
                output<<"ERROR 4: Passenger was not found!\n";
            }

            
        }//end if winner
    }/*End if race condition*/
    else if(passengers.nearest_distance[ID] > 5 && passengers.race_status[ID] != NO_RACE){
        int opponent = passengers.race_opID[ID];
        if(opponent >=0){

            passengers.race_status[ID]=NO_RACE;
            passengers.race_opID[ID]=-10;
            passengers.race_position_x[ID]=passengers.position_x[ID];
            passengers.race_position_y[ID]=passengers.position_y[ID];
            passengers.race_is_finished[ID]=true;


            passengers.race_status[opponent]=NO_RACE;
            passengers.race_opID[opponent]=-10;
            passengers.race_is_finished[opponent]=true;

        }else{
            output<<"ERROR 6: Passenger was not found!\n";

        }
    }
}


/**
 * Updating the member data of a specific passenger after updating its velocity and position
 *
 * 
 **/

void Simulation::UpdatePassenger(Aim &p_aim, const Numeric& p_position_x, const Numeric& p_position_y, const Numeric& luggage_location_y, int& p_wait_time, bool& has_released, const Numeric& p_seat_position_x, const Numeric& p_seat_position_y, int*  holds, const int& priority, bool*  aisle_permission, const Numeric& plane_exit_x, const Numeric& plane_exit_y, RaceStatus& p_race_status, int& OpID, bool& p_race_finished, Numeric& race_position_x, Numeric& race_position_y, RaceStatus& op_race_status, int& op_race_OpID, bool& op_race_is_finished, Numeric& op_race_position_x, Numeric& op_race_position_y, const int& ID, const Numeric& time_step, int& numberOfPassengersInPlane, const Numeric& Release_Threshold, ofstream& output){
  if((p_aim==DOWN_TO_AISLE)&&(p_position_y<luggage_location_y-(Numeric)0.2f)){
    /*passenger has moved down enough toward aisle*/
    p_aim = ALIGNING;
    /*time to wait for baggage loading*/
    p_wait_time = ((int)(5.0f/time_step)+rand()%((int)(7.0f/time_step)));
    
  }else if((p_aim==UP_TO_AISLE)&&(p_position_y> (-1*luggage_location_y) + (Numeric)0.2f)){
    /*passenger has moved up enough toward aisle*/
    p_aim = ALIGNING;
    /*time to wait for baggage loading*/
    p_wait_time = (((int)(5.0f/time_step))+rand()%((int)(7.0f/time_step)));
    
    }else if(p_aim==ALIGNING){
        if(fabs(p_position_y)<=(Numeric)0.06f){
          p_aim = IN_AISLE;
        }
    }else if(p_aim==IN_AISLE){
        if(!has_released && p_position_x-p_seat_position_x>Release_Threshold){
          /*Passenger has moved more than "Release_Threshold" in the aisle and has not yet released the hold.
    	So, it is time to release the hold and check to see if it is the last hold. In that case, we have to get aisle permission to the next row*/
            has_released = (true);
            holds[-1*int(priority)-1]--;
            if(holds[-1*int(priority)-1]==0 && (-1*int(priority)-2)>=0){
                aisle_permission[-1*int(priority)-2]=true;
            }
        }
        if(p_position_x > plane_exit_x+(Numeric)0.05f){
          /*Time to urn toward the exit door*/
            p_aim = (TOWARD_EXIT);
            if( !has_released){
                has_released = (true);
                holds[-1*int(priority)-1]--;
                if(holds[-1*int(priority)-1]==0){
                    aisle_permission[-1*int(priority)-2]=true;
                }
            }
        }
            /*Checking to see the winner has moved enough in the aisle so that we can remove the looser tag from the looser passenger*/
        if(p_race_status==WINNER && OpID != -10 && !(p_race_finished)){

            if(OpID>=0){
                if(p_position_x - race_position_x >1 && op_race_status==LOOSER){
                    op_race_status = NO_RACE;
                    op_race_OpID = -10;
                    op_race_is_finished = true;
                    p_race_status = NO_RACE;
                    //HERE!
                    OpID=-10;
                    p_race_finished=true;
                }
            }
        }
      }else if((p_aim==TOWARD_EXIT)&&(p_position_y > plane_exit_y+(Numeric)0.5f)){
        /*
        Passenger has reached the exit door
        */
        --numberOfPassengersInPlane;
        //output<<"Passenger "<<ID<<" Exited! "<<numberOfPassengersInPlane<<" Remaining\n";
        p_aim =OUT;
        
    }
}




/**
 * Writing the position of all passengers to the output file
 *
 * @param passengers_t Passengers' map of <ID, Passenger>
 * @param n The number of this output call.
 * @param output file output stream 
 * @param xyz_obs the vector containing the content of obstacles file
 *
 **/
void Simulation::WriteOutput(const Passengers & passengers_t, int n, ofstream& output, const vector<string>& xyz_obs, int id){
    
    ofstream ofs;
    ofs << fixed;
    ofs << setprecision(3);
    char anim[128];
    sprintf(anim, "animfile_%d", id);
    ofs.open(anim, ofstream::out | ofstream::app);
    const int obs_size= xyz_obs.size();
    if(ofs.is_open()){
        const int coord_count = xyz_obs.size() + NumberOfPassengers;
        const int UL=NumberOfPassengers;
        ofs << "  " << coord_count << "\n   " << (n)*250 << "\n";
        for(int its=0; its<UL; ++its){
            
            //converting meter to inches
            double x_pos = passengers_t.position_x[its]*39.3701f;
            double y_pos = passengers_t.position_y[its]*39.3701f;
            
            stringstream streamy;
            streamy << fixed << setprecision(3) << x_pos;
            string x = streamy.str();
            
            streamy.str("");
            streamy << y_pos;
            string y = streamy.str();
            
            ofs << "C";
            const int xl = 12 - x.length();
            for(int i = 0; i < xl; i++){
                ofs << " ";
            }
            ofs << x;
            const int yl = 12 - y.length();
            for(int i = 0; i < yl; i++){
                ofs << " ";
            }
            ofs << y << "       0.000\n";
        }
        for(int i=0; i< obs_size; ++i){
          ofs << xyz_obs[i] << '\n';
        }
        
        ofs.close();
        //output<<"Output was written!\n";
    }else{
        output<<"Error in openning animfile.xyz!\n";
    }
    
}




void Simulation::checkBehind(int ID, Passengers& passengers){
    const int UL = NumberOfPassengers;
    for(int n=0; n<UL; ++n){
        if (passengers.ID[n]!=ID){
            if(fabs(passengers.position_y[passengers.ID[n]]-passengers.position_y[ID])<0.1f && passengers.position_x[ID]<= passengers.position_x[passengers.ID[n]]+ 0.15f ){
                passengers.force_x[ID]=0.0f;
                passengers.force_y[ID]=0.0f;
                passengers.velocity_x[ID]=0.0f;
                passengers.velocity_y[ID]=0.0f;
                //break;
            }
        }
    }
}


/**
 * Running the simulation
 *
 * @param output file output stream
 *
 * @return an integer specifying the status of the simulation
 **/

int Simulation::Run(ofstream& output, int ID) {
    /*units are in meter*/
    //Vector2D zero;
    //printf("Timer resolution = %g micro seconds\n", get_microtime_resolution());

    //double time1 = microtime();
  Numeric Luggage_Y, Exit_X, Exit_Y, Reaction_Time, Time_Step, Output_Iteration, Number_Of_Outputs, Toward_Aisle_Stop_Threshold, In_Aisle_Stop_Threshold, Aligning_Stop_Threshold, previousPassengersInPlane=NumberOfPassengers;
    
    int Outputindex=0;
    //std::vector<Vector2D> obstacles;
    //Passengers_Map passengers_map;
    Passengers passengers;
    Obstacles obstacles;
    //Vector2D Exit_Position;
    //Vector_Vec2D forces;
    //vector<NearestPassenger> nearest_passengers;
    vector<string> xyz_obs;
    vector<Numeric> parameters;

    srand (6);
    vector<pair<int, int> > arrangement;
    /*Reading input file, initializing passengers and obstacles and constant-value parameters*/
    parameters = Initialize(passengers, obstacles, xyz_obs, arrangement, output);
    /*for(int ss=0; ss<NumberOfPassengers; ++ss){
        cout<<passengers.position_x[ss]<<", "<<passengers.position_y[ss]<<endl;
    }*/
    //setDesiredSpeeds(passengers_map);
    //if(parameters.size()==parameters[0]){
    int index=0;

    Luggage_Y = parameters[index++];
    Exit_X = parameters[index++];
    Exit_Y = parameters[index++];
    Aligning_Stop_Threshold=parameters[index++];
    Toward_Aisle_Stop_Threshold=parameters[index++];
    In_Aisle_Stop_Threshold=parameters[index++];
    Reaction_Time=parameters[index++];
    Time_Step=parameters[index++];
    Output_Iteration=parameters[index++];
    Number_Of_Outputs=parameters[index];




    //cout<<"Thresholds: "<<Aligning_Stop_Threshold<<", "<<Toward_Aisle_Stop_Threshold<<", "<<In_Aisle_Stop_Threshold<<", RT: "<<Reaction_Time<<", TS: "<<Time_Step<<", OI: "<<Output_Iteration<<", NO: "<<Number_Of_Outputs<<"\n";
    //cout<<"Plane parameters:\n Luggage_Location: "<<Luggage_Y<<", Exit_Position: "<<plane.getExitDoor()<<"\n";
    
    //NearestPassenger nearest_passengers[NumberOfPassengers];
    int numberOfPassengersInPlane=NumberOfPassengers;
    

    
    /*The passengers in the head row, have the aisle permission and after each of them moves 1 meter in aisle, he/she will release this hold
     When all the passengers of this aisle have released the hold, passengers of the next row will get the permission*/
    //Vector2D tmp;

    int Total_Number_Of_Rows=0;
    for (int i = arrangement.size()-1; i>=0 ; --i){
        Total_Number_Of_Rows+=arrangement[i].first;
    }
    int* holds = new int[Total_Number_Of_Rows];
    bool* aisle_permission = new bool[Total_Number_Of_Rows];

    initializePermissions(holds, aisle_permission, arrangement);

    
    //Main loop:
    clock_t begin = clock();
    int i=0, iteration_counter=0;
    /* A few variables for debugging purposes:*/
    int kk=0, jj=0;
    /**/
    Numeric cutoff_threshold = (Numeric)2.0f;
    
    while(numberOfPassengersInPlane>0){
        i=0;
        /*DEBUG:*/
         kk=0;
         jj++;
         /****/
        iteration_counter++;
        
        for(i=0; i<NumberOfPassengers; ++i){
            
            /*DEBUG:*/
             kk++;
             /***/
            
            if(passengers.aim[i]!=OUT){

                if((passengers.waitTime[i]==0 && passengers.race_status[i]!=LOOSER) &&  ((passengers.aim[i]!=IN_AISLE && passengers.aim[i]!=ALIGNING )|| 
                    (((passengers.position_x[i]-passengers.seat_position_x[i])<(Numeric)0.45f /*&& (i.getPosition().getX()-i.getSeatPosition().getX())>(Numeric)-0.25f)*/|| 
                        (aisle_permission[-1*int(passengers.priority[i])-1]))))) {
                    
                    /**
                     Finding the nearest passenger to this passenger and updating the desired speed of that passenger based on that.
                     **/


                    getNearestPassenger(passengers.nearest_ID[i], passengers.nearest_position_x[i], passengers.nearest_position_y[i], passengers.nearest_distance[i], i, Exit_X, passengers);


                    
                }//END IF Permission
            }//End if Aim OUT

            //i++;
        }//END FOR Passengers_map (NEW)
        i=0;
        for(i=0; i<NumberOfPassengers; ++i){
            
            if(passengers.aim[i]!=OUT){

                if( (passengers.waitTime[i]==0 && passengers.race_status[i]!=LOOSER) &&  ((passengers.aim[i]!=IN_AISLE && passengers.aim[i]!=ALIGNING )|| 
                    (((passengers.position_x[i]-passengers.seat_position_x[i])<(Numeric)0.45f /*&& (i.getPosition().getX()-i.getSeatPosition().getX())>(Numeric)-0.25f)*/|| 
                        (aisle_permission[-1*int(passengers.priority[i])-1] ))))) {
                    

                    Numeric DesiredSpeed;
                    bool obs_block=blockedPath(i, obstacles, passengers);
                        if(obs_block && passengers.nearest_distance[i]>0.1f){
                            passengers.nearest_distance[i]=0.1f;
                        }
                    //cout<<"+++++++++++"<<passengers.nearest_ID[i]<<", "<<passengers.nearest_distance[i]<<endl;
                        if(passengers.race_status[i]==WINNER && passengers.nearest_ID[i]==passengers.race_opID[i]){
                            
			  DesiredSpeed =DecreaseSpeed((Numeric)1.1f, passengers.nearest_distance[i], passengers.desiredSpeed[i]);
                            
                        }else if(passengers.aim[i]==ALIGNING){
			  DesiredSpeed =DecreaseSpeed(Aligning_Speed_Coefficient, passengers.nearest_distance[i], passengers.desiredSpeed[i]);
                        }else if(passengers.aim[i]==UP_TO_AISLE || passengers.aim[i]==DOWN_TO_AISLE ){
			  DesiredSpeed =DecreaseSpeed(Toward_Aisle_Speed_Coefficient, passengers.nearest_distance[i], passengers.desiredSpeed[i]);
                        }
                        else
			  DesiredSpeed =DecreaseSpeed(1.0f, passengers.nearest_distance[i], passengers.desiredSpeed[i]);
                    

                        if(passengers.aim[i]==IN_AISLE && passengers.position_x[i]+ Intersection_Distance_Threshold>Exit_X){ //PP1
                    
                            Propulsive_Force(passengers.aim[i], passengers.position_y[i], passengers.mass[i], passengers.velocity_x[i], passengers.velocity_y[i], Reaction_Time, DesiredSpeed*Intersection_Speed_Coefficient, passengers.force_x[i], passengers.force_y[i]); //PP2

                            //EulerMethod(passengers.race_status[i], passengers.force_x[i], passengers.force_y[i], passengers.mass[i], passengers.velocity_x[i], passengers.velocity_y[i], passengers.position_x[i], passengers.position_y[i], passengers.aim[i], passengers.seat_position_x[i], passengers.desiredSpeed[i], Time_Step);
                    
                        }else{

                            Propulsive_Force(passengers.aim[i], passengers.position_y[i], passengers.mass[i], passengers.velocity_x[i], passengers.velocity_y[i], Reaction_Time, DesiredSpeed, passengers.force_x[i], passengers.force_y[i]); //PP2
                            if(fabs(passengers.position_y[i])<0.15f && passengers.velocity_x[i]<=0.0f && passengers.force_x[i]<0.0f){
                                checkBehind(i, passengers);
                            }   
                        }

                    EulerMethod(passengers.race_status[i], passengers.force_x[i], passengers.force_y[i], passengers.mass[i], passengers.velocity_x[i], passengers.velocity_y[i], passengers.position_x[i], passengers.position_y[i], passengers.aim[i], passengers.seat_position_x[i], passengers.desiredSpeed[i], Time_Step);
                    if(passengers.aim[i]!=DOWN_TO_AISLE && passengers.aim[i]!=UP_TO_AISLE){
		      raceDetection(passengers, i, Time_Step, output);
                    }/*End if Aligning*/
                    
                    /*DEBUG:
                     if((passengers.ID[i]>=numberOfPassengersInPlane-5) && jj%5==0){ 
                         cout<<passengers.ID[i]<<": "<<passengers.position_x[i]<<", "<<passengers.position_y[i]<<" | Nearest: "<<passengers.nearest_position_x[i]<<", "<<passengers.nearest_position_y[i]<<" | distance: "<<passengers.nearest_distance[i]<<" | NID: "<<passengers.nearest_ID[i]<<" | Force: "<<passengers.force_x[i]<<", "<<passengers.force_y[i]<<" | Velocity: "<<passengers.velocity_x[i]<<", "<<passengers.velocity_y[i]<<"  | Aim: "<<passengers.aim[i]<<" | Race: "<<passengers.race_status[i]<<" | WaitTime: "<<passengers.waitTime[i]<<" & "<<passengers.priority[i]<<", ArrIdx: "<<passengers.arr_index_in_grid[i];
                         if(passengers.race_status[i]!=NO_RACE){
                            cout<<" | Opponent: "<<passengers.race_opID[i]<<" | Race counter: "<<passengers.race_counter[i]<<endl;
                         }else{
                            cout<<endl;
                         }
                     }**/
                    
                    
                }//END IF Permission
                else if(passengers.waitTime[i]!=0){
                    passengers.waitTime[i] = passengers.waitTime[i]-1;
                    passengers.velocity_x[i]=0;
                    passengers.velocity_y[i]=0;
                }
                else{
                    passengers.force_x[i]=(Numeric)0.0f;
                    passengers.force_y[i]=(Numeric)0.0f;
                    passengers.velocity_x[i]=(Numeric)0.0f;
                    passengers.velocity_y[i]=(Numeric)0.0f;
                }
                
                if(passengers.aim[i]!=OUT){
                    /*DEBUG:
                     if((i>=numberOfPassengersInPlane-5) && jj%5==0){ 
                         cout<<passengers.ID[i]<<": "<<passengers.position_x[i]<<", "<<passengers.position_y[i]<<" | Nearest: "<<passengers.nearest_position_x[i]<<", "<<passengers.nearest_position_y[i]<<" | distance: "<<passengers.nearest_distance[i]<<" | NID: "<<passengers.nearest_ID[i]<<" | Force: "<<passengers.force_x[i]<<", "<<passengers.force_y[i]<<" | Velocity: "<<passengers.velocity_x[i]<<", "<<passengers.velocity_y[i]<<"  | Aim: "<<passengers.aim[i]<<" | Race: "<<passengers.race_status[i]<<" | WaitTime: "<<passengers.waitTime[i]<<" & "<<passengers.priority[i]<<", ArrIdx: "<<passengers.arr_index_in_grid[i];
                         if(aisle_permission[-1*int(passengers.priority[i])-1])
                            cout<<"\npermission is granted!\n";
                        else
                            cout<<"\npermission denied!\n";
      
       
                         if(passengers.race_status[i]!=NO_RACE){
                            cout<<" | Opponent: "<<passengers.race_opID[i]<<" | Race counter: "<<passengers.race_counter[i]<<endl;
                         }else{
                            cout<<endl;
                         }
                     }**/
                    UpdatePassenger(passengers.aim[i], passengers.position_x[i], passengers.position_y[i], Luggage_Y, passengers.waitTime[i], passengers.has_released[i], passengers.seat_position_x[i], passengers.seat_position_y[i], holds, passengers.priority[i], aisle_permission, Exit_X, Exit_Y, passengers.race_status[i], passengers.race_opID[i], passengers.race_is_finished[i], passengers.race_position_x[i], passengers.race_position_y[i], passengers.race_status[passengers.race_opID[i]], passengers.race_opID[passengers.race_opID[i]], passengers.race_is_finished[passengers.race_opID[i]], passengers.race_position_x[passengers.race_opID[i]], passengers.race_position_y[passengers.race_opID[i]], i, Time_Step, numberOfPassengersInPlane, Release_Threshold, output);
                }//END IF aim!=Out
                passengers.force_x[i]=0;
                passengers.force_y[i]=0;
            }//End if Aim OUT
            passengers.force_x[i]=0;
            passengers.force_y[i]=0;
            //i++;   
        }//END FOR PassengersMap

        if(Outputindex%int(Output_Iteration)==Output_Iteration-2){
	  WriteOutput(passengers, 1+Outputindex/Output_Iteration, output, xyz_obs, ID);
	  if(Outputindex%10000==Output_Iteration-2){
            if(previousPassengersInPlane<NumberOfPassengers && previousPassengersInPlane == numberOfPassengersInPlane\
	       ){
              printf("%d STUCK, remaining: %d\n", ID, numberOfPassengersInPlane);
              numberOfPassengersInPlane = 0;
            }
            previousPassengersInPlane = numberOfPassengersInPlane;
          }
	}
        Outputindex++;
        if(Outputindex>Output_Iteration*(Number_Of_Outputs-1)){
            return 1;
        }
    }
    clock_t end = clock();
    delete aisle_permission;
    delete holds;
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    output<<"Elapsed Time: "<<elapsed_secs <<"(s)"<<endl;
    output<<"Physical time: "<<(Numeric)(iteration_counter*Time_Step)<<" (s) = "<<(Numeric)(iteration_counter*Time_Step)/60.0f<<" minutes"<<endl;

    return 0;
}

