/**
 * Implementation of Simulation class. Objects of this class passengers a specific simulation with specified parameters
 *
 * @author  Mehran Sadeghi Lahijani <sadeghil@cs.fsu.edu>
 *
 */

#include "Simulation.h"

using namespace std;

Simulation::Simulation()
{
}



Simulation::Simulation(Numeric mean_t, Numeric stddev_t, Numeric t_Intersection_Distance_Threshold, Numeric t_Intersection_Speed_Coefficient, Numeric t_Aligning_Speed_Coefficient, Numeric t_Toward_Aisle_Speed_Coefficient, Numeric t_Release_Threshold)
{
  mean=mean_t;
  stddev=stddev_t;

  Intersection_Distance_Threshold= t_Intersection_Distance_Threshold;
  Intersection_Speed_Coefficient=t_Intersection_Speed_Coefficient;
  Aligning_Speed_Coefficient=t_Aligning_Speed_Coefficient;
  Toward_Aisle_Speed_Coefficient=t_Toward_Aisle_Speed_Coefficient;
  Release_Threshold = t_Release_Threshold;
}
int Simulation::getOutputIndex()
{
  return output_index;
}
void Simulation::setOutputIndex(int output_index_t)
{
  output_index= output_index_t;
}
Numeric Simulation::getMean()
{
  return mean;
}
Numeric Simulation::getStddev()
{
  return stddev;
}
void Simulation::setMean(Numeric mean_t)
{
  mean=mean_t;
}
void Simulation::setStddev(Numeric stddev_t)
{
  stddev=stddev_t;
}

/*****************************************************************************************/
/**********************Section 2: Force Computation Functions*****************************/
/*****************************************************************************************/

/**
 * Computing the separation distance between two passengers
 *
 * @param main_position_t The position of the main passenger. Main passenger is the passenger for whom we want to compute the propulsion
 * @param main_aim_t The aim of the main passenger
 * @param sec_position_t The position of the seconadry passenger. Secondary passengers all those among whom we want to find the nearest passenger to the main passenger
 * @param sec_aim_t The aim of the secondary passenger
 *
 * @return a Numeric that is the separation distance between the main and the secondary passenger. The separation distance is the distance between main and secondary passenger in the main passenger's direction of movement
 **/
Numeric Simulation::getSeparation(const Numeric& main_position_x, const Numeric& main_position_y, const Aim& main_aim_t, const Numeric& sec_position_x, const Numeric& sec_position_y, const Aim& sec_aim_t)
{
  if(main_aim_t == DOWN_TO_AISLE && fabs(sec_position_x - main_position_x)<(Numeric)0.1f)
  {
    return main_position_y - sec_position_y;
  }
  else if((main_aim_t == UP_TO_AISLE) && fabs(sec_position_x - main_position_x)<(Numeric)0.1f)
  {
    return sec_position_y - main_position_y;
  }
  else if((main_aim_t == TOWARD_EXIT) && fabs(sec_position_x - main_position_x)<(Numeric)0.15f)
  {
    if(main_aim_t==sec_aim_t)
    {
      return sec_position_y - main_position_y;
    }
  }
  else if(main_aim_t==IN_AISLE && fabs(sec_position_y - main_position_y)<(Numeric)0.15f && (sec_aim_t==ALIGNING || sec_aim_t==IN_AISLE))
  {
    return sec_position_x - main_position_x;
  }
  else if(main_aim_t==ALIGNING)
  {
    if(sec_position_x<main_position_x)
    {
      return (Numeric)0.75f;
    }
    else if((sec_position_x - main_position_x > (Numeric)-0.04f && sec_position_x - main_position_x<(Numeric)0.15f))
    {
      if(main_position_y>(Numeric)0.06f)
      {
        return main_position_y - sec_position_y;
      }
      else if((main_position_y<-(Numeric)0.06f))
      {
        return sec_position_y - main_position_y;
      }
    }
  }
    return (Numeric)100.0f;
}




/**
 * Finding the nearest passenger to passenger_t in a specific cell
 *
 * @param cell The cell in which we need to search for the nearest passenger
 * @param passenger_t reference to the passenger that we are going to find the nearest passenger to him/her
 * @param nearest_t reference to the NearestPassenger object to modify if a closer passenger is found
 *
 **/
void Simulation::getNearestInCell(const vector<int>& cell, const  int& passenger_ID, NearestPassenger& nearest_t, Passengers& passengers_t)
{
  for(int i=0; i<cell.size(); ++i)
  {
    if(passengers_t.aim[cell[i]]!=OUT && cell[i]!=passenger_ID)
    {
      Numeric separation= getSeparation(passengers_t.position_x[passenger_ID], passengers_t.position_y[passenger_ID], passengers_t.aim[passenger_ID], passengers_t.position_x[cell[i]], passengers_t.position_y[cell[i]], passengers_t.aim[cell[i]]);

      if (separation<nearest_t.distance && separation>0)
      {
        nearest_t.distance=separation;
        nearest_t.position_x=passengers_t.position_x[cell[i]];
        nearest_t.position_y=passengers_t.position_y[cell[i]];
        nearest_t.ID=cell[i];
      }
    }
  }
}

/**
 * Finding the the passenger with the least distance from a specific passenger  in the plane
 *
 * @param passenger_t The main passenger
 * @param passengers_t the grid of passengers
 * @param passengersmap_t The map of all passengers
 * @param exit_position Location of the exit door
 * @param y_dim second dimension of the passengers grid
 *
 * @return a NearestPassenger struct, which contains the ID, position and the distance of nearest passenger
 **/
void Simulation::getNearestPassenger(Numeric& NID, Numeric& N_position_x, Numeric& N_position_y, Numeric& N_distance, const int& passenger_ID, vector<int> *& passengers_grid_t, const Numeric& exit_position, const int& y_dim, Passengers& passengers_t, const int& grid_size)
{
  NearestPassenger nearest;
  nearest.ID=-1;
  nearest.position_y=0;
  nearest.position_x = exit_position;
  nearest.distance=(Numeric)10.0f; // Just a big enough default value

  int index=passengers_t.arr_index_in_grid[passenger_ID];
  getNearestInCell(passengers_grid_t[index], passenger_ID, nearest, passengers_t);

  if(index<grid_size-1 && passengers_grid_t[index+1].size()>0)
  {
    getNearestInCell(passengers_grid_t[index+1], passenger_ID, nearest, passengers_t);
  }
  if(index>0 && passengers_grid_t[index-1].size()>0)
  {
    getNearestInCell(passengers_grid_t[index-1], passenger_ID, nearest, passengers_t);
  }
  if(index-y_dim>=0)
  {
    if(passengers_grid_t[index-y_dim].size()>0)
    {
      getNearestInCell(passengers_grid_t[index-y_dim], passenger_ID, nearest, passengers_t);
    }
    if(passengers_grid_t[index-y_dim+1].size()>0)
    {
      getNearestInCell(passengers_grid_t[index-y_dim+1], passenger_ID, nearest, passengers_t);
    }
    if(index-y_dim-1>=0 && passengers_grid_t[index-y_dim-1].size()>0)
    {
      getNearestInCell(passengers_grid_t[index-y_dim-1], passenger_ID, nearest, passengers_t);
    }
  }
  if(index+y_dim<grid_size)
  {
    if(passengers_grid_t[index+y_dim].size()>0)
    {
      getNearestInCell(passengers_grid_t[index+y_dim], passenger_ID, nearest, passengers_t);
    }
    if(passengers_grid_t[index+y_dim-1].size()>0)
    {
      getNearestInCell(passengers_grid_t[index+y_dim-1], passenger_ID, nearest, passengers_t);
    }
    if(index+y_dim+1<grid_size && passengers_grid_t[index+y_dim+1].size()>0)
    {
      getNearestInCell(passengers_grid_t[index+y_dim+1], passenger_ID, nearest, passengers_t);
    }
  }

  NID= nearest.ID;
  N_position_x = nearest.position_x;
  N_position_y = nearest.position_y;
  N_distance = nearest.distance;
}

/**
 * Decreasing the maximum desired speed of a passenger based on the position of the nearest passenger
 *
 * @param desired_speed_t The maximum desired speed of the passenger
 * @param stop_threshold The distance to the nearest passenger at which the speed of main passenger should be zero
 * @param distance the actual distance between the main passenger and the nearest passenger to him/her
 *
 * @return a Numeric that is the desired speed of the passenger
 **/
Numeric Simulation::DecreaseSpeed(const Numeric& coeff, const Numeric& distance, const Numeric& cell_width)
{
  Numeric a = (Numeric)-0.0109f * cell_width + (Numeric)2.475f;
  Numeric b = (Numeric)-2.645f + (Numeric)2.78f * cos(cell_width * (Numeric)0.004704f) + (Numeric)0.3758f * sin(cell_width * (Numeric)0.004704f);
  Numeric c = (Numeric)0.8539f * pow(cell_width, (Numeric)0.03416);

  return coeff*Numeric(c-exp(-a * (distance-b)));
}


/**
 * Compute the Propulsive force for a passenger.
 *
 * @param p A passenger object.
 * @param time_step The reaction time for getting reaching the desired speed
 * @param desired_speed The maximum desired speed that a passenger wants to reach
 *
 * @return A 2D vector which is the propulsive force. We determine e1 (direction of desired velocity) which is a unit vector in the desired direction of motion of a passenger.
 maxDesiredSpeed (magnitude of desired velocity) is the desired velocity of the passenger p, that is computed considering the position of the nearest passenger in his/her way.
 So propulsive force is given by @f$ ((Passenger's mass)/timestep)(desired velocity - (passenger's current velocity)) @f$ */
void Simulation::Propulsive_Force(const Aim & aim, const Numeric& position_y, const Numeric& mass, const Numeric& velocity_x, const Numeric& velocity_y, const Numeric& time_step, const Numeric& desired_speed, Numeric& force_x, Numeric& force_y)
{
  Numeric e1_x=0.0f, e1_y=0.0f, new_velocity_x, new_velocity_y;
  if(aim==DOWN_TO_AISLE)
  {
    e1_y = -1;
  }
  else if(aim==UP_TO_AISLE)
  {
    e1_y = 1;
  }
  else if(aim==ALIGNING)
  {
    if(position_y>(Numeric)0.06f)
    {
      e1_x=0.5f;
      e1_y=-0.9f;
    }
    else if(position_y<-(Numeric)0.06f)
    {
      e1_x= 0.5f;
      e1_y= 0.9f;
    }
  }
  else if(aim==IN_AISLE)
  {
      /********ALIGNMENT********/
      /* Passengers should move on almost a line in the center of aisle*/
    if(position_y>(Numeric)0.05f)
    {
      e1_x=0.5f;
      e1_y=-0.9f;
    }
    else if(position_y<(Numeric)-0.05f)
    {
      e1_x=0.5f;
      e1_y=0.9f;
    }
    else
    {
      e1_x=1.0f;
    }
  }
  else if(aim==TOWARD_EXIT)
  {
    e1_y= 1;
  }

  new_velocity_x = e1_x * (desired_speed);
  new_velocity_y = e1_y * (desired_speed);

  force_x = (new_velocity_x - velocity_x) * mass/time_step;
  force_y = (new_velocity_y - velocity_y) * mass/time_step;

  //cout<<desired_speed<<" & "<<new_velocity_x<<" & "<<velocity_x<<" & "<<force_x<<endl;
}



/**
 * Computing the separation distance between a passenger and an obstacle
 *
 * @param main_position_t The position of the passenger.
 * @param main_aim_t The aim of the passenger
 * @param obs_position_t The position of the obstacle.
 *
 * @return a Numeric that is the separation distance between the passenger and the obstacle. The separation distance is the distance between them in the main passenger's direction of movement
 **/
Numeric Simulation::getObsSeparation(const Numeric & main_position_x, const Numeric & main_position_y, const Aim& main_aim_t, const Numeric & obs_position_x, const Numeric & obs_position_y)
{
  if(main_aim_t == DOWN_TO_AISLE && fabs(obs_position_x - main_position_x)<(Numeric)0.05f)
  {
    return main_position_y - obs_position_y;
  }
  else if((main_aim_t == UP_TO_AISLE) && fabs(obs_position_x - main_position_x)<(Numeric)0.05f)
  {
    return obs_position_y - main_position_y;
  }
  else if((main_aim_t == TOWARD_EXIT) && fabs(obs_position_x - main_position_x)<(Numeric)0.05f)
  {
    return obs_position_y - main_position_y;
  }
  else if (main_aim_t==IN_AISLE && fabs(obs_position_y - main_position_y)<(Numeric)0.05f)
  {
    return obs_position_x - main_position_x;
  }

  return (Numeric)10.0f;
}


/**
 * Update the velocity and the position of a passenger.
 *
 * @param p A reference to a passenger object.
 * @param delta The timestep that will be used in Euler method
 * @param force The propulsion that is computed for this passenger
 * @param Desired_Speed the maximum desired speed of the passenger
 *
 **/
void Simulation::EulerMethod(const RaceStatus& race_status, const Numeric& force_x, const Numeric& force_y, const Numeric& mass, Numeric& velocity_x, Numeric& velocity_y, Numeric& position_x, Numeric& position_y, const Aim& aim, const Numeric& seat_position_x, const Numeric& desired_speed, const Numeric& delta)
{
  Numeric Speed, new_velocity_x, new_velocity_y, new_position_x, new_position_y;
  /*updating the velocity using Euler method*/
  new_velocity_x=(force_x * (Numeric)(delta/mass) + velocity_x);
  new_velocity_y=(force_y * (Numeric)(delta/mass) + velocity_y);

  if(race_status==WINNER && new_velocity_x<0)
  {
    velocity_x = velocity_x * 0.1f;
    velocity_y = velocity_y * 0.1f;
    position_x = (velocity_x * delta) + position_x;
    position_y = (velocity_y * delta) + position_y;
  }
  else
  {
    velocity_x = new_velocity_x;
    velocity_y = new_velocity_y;

    Speed = (velocity_x * velocity_x) + (velocity_y * velocity_y);

    /*updating the position using Euler method*/
    if(Speed<=(desired_speed*desired_speed))
    {
      new_position_x = (velocity_x * delta) + position_x;
      new_position_y = (velocity_y * delta) + position_y;
    }
    else
    {
      new_position_x = (velocity_x * (desired_speed/(Speed+0.01)) * delta) + position_x;
      new_position_y = (velocity_y * (desired_speed/(Speed+0.01)) * delta) + position_y;
    }

    position_x = new_position_x;
    position_y = new_position_y;
  }
}


/*****************************************************************************************/
/**************************Section 4: Some Useful Functions*******************************/
/*****************************************************************************************/
/**
 * Split a string by a char delimeter
 * @param s The string to be splitted.
 * @param delim The delimeter for splitting string
 * @param elems The container for splitted strings
 */
void Simulation::split(const string &s, char delim, vector<string> &elems)
{
  stringstream ss;
  ss.str(s);
  string item;
  while (getline(ss, item, delim))
  {
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
vector<Numeric> Simulation::Initialize(Passengers &passengers_t, Obstacles &obstacles_t, Plane &plane_t, vector<string>& xyz_obs)
{
  std::default_random_engine gen;
  std::normal_distribution<Numeric> ND(mean, stddev);

  Numeric tmpPosition_x, tmpPosition_y;
  vector<Numeric> sim_params, plane_params;
  int index=0, obs_index=0;
  char coord_file[128];
  sprintf(coord_file, "coord_A320_144.d_coordinates.txt");
  ifstream coords (coord_file);
  string line;
  vector<pair<int, int> > arrangement;
  multimap<Numeric, Numeric> positions_map;
  vector<string> tmp;
  stringstream buffer_stream;

  if (coords.is_open())
  {
    buffer_stream << coords.rdbuf();
    coords.close();
  }
  else
  {
    cout<<"Error in reading coordinates file!\n";
  }

  while (getline(buffer_stream,line))
  {
    if(index==0)
    {
      split(line, '|', tmp);
      for(int i=0; i<int(tmp.size());i++)
      {
        if (tmp[i].find('@')!=std::string::npos)
        {
          vector<string> pair;
          split(tmp[i], '@', pair);
          arrangement.push_back(make_pair(atoi(pair[0].c_str()), atoi(pair[1].c_str())));
        }
        else
        {
          plane_params.push_back((Numeric)atof(tmp[i].c_str()));
        }
      }
      index++;
    }
    else if(index==1)
    {
      split(line, '|', tmp);
      for(int i=0; i<int(tmp.size());i++)
      {
        sim_params.push_back((Numeric)(atof(tmp[i].c_str())));
      }
      index++;
    }
    else
    {
      split(line, ' ', tmp);
      tmpPosition_x=(Numeric)(atof(tmp[1].c_str()));
      tmpPosition_y= (Numeric)(atof(tmp[2].c_str()));
      if(tmp[0]=="13")
      {
        positions_map.insert(make_pair(tmpPosition_x, tmpPosition_y));
      }
      else if(tmp[0]=="16")
      {
        obstacles_t.positions_x[obs_index]=tmpPosition_x;
        obstacles_t.positions_y[obs_index++]=tmpPosition_y;
      }
      index++;
    }
    tmp.clear();
  }

  char xyz[128];
  sprintf(xyz, "xyz_obs_1");
  stringstream xyz_buff_stream;
  ifstream xyz_file(xyz);
  if(xyz_file.is_open())
  {
    xyz_buff_stream << xyz_file.rdbuf();
    xyz_file.close();
  }
  else
  {
    cout<<"Error in openning xyz_obstacles.txt!\n";
  }
  string xyz_line;
  while(getline(xyz_buff_stream, xyz_line))
  {
    xyz_obs.push_back(xyz_line);
  }

  /*initializing the passengers, determining the initial aim and the priority of passengers*/
  Numeric row=positions_map.begin()->first;
  Numeric tmpPriority=-1;
  Numeric priority;
  Numeric position_x;
  Numeric position_y;
  int ID=0;

  for(multimap<Numeric,Numeric>::iterator itr=positions_map.begin(); itr!=positions_map.end(); ++itr)
  {
    Aim initial_aim;
    if(itr->second > 0)
    {
      initial_aim=DOWN_TO_AISLE;
    }
    else
    {
      initial_aim=UP_TO_AISLE;
    }
    position_x=Numeric(itr->first);
    position_y=Numeric(itr->second);
    if(itr->first != row)
    {
      row = itr->first;
      tmpPriority--;
    }
    priority = tmpPriority;

    passengers_t.mass[ID] = (Numeric)1.0f;
    passengers_t.priority[ID] = tmpPriority;
    passengers_t.waitTime[ID] = 0.0f;
    passengers_t.inPlane[ID] = true;
    passengers_t.aim[ID] = initial_aim;
    passengers_t.position_x[ID] = position_x;
    passengers_t.position_y[ID] = position_y;
    passengers_t.velocity_x[ID] = 0.0f;
    passengers_t.velocity_y[ID] = 0.0f;
    passengers_t.acceleration_x[ID] = 0.0f;
    passengers_t.acceleration_y[ID] = 0.0f;
    passengers_t.seat_position_x[ID] = position_x;
    passengers_t.seat_position_y[ID] = position_y;
    passengers_t.has_released[ID] = false;
    passengers_t.ID[ID] = ID;//Redundant!
    passengers_t.arr_index_in_grid[ID] = -1;
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
    while(speed<0.7 || speed>1.6)
    {
      speed = ND(gen);
    }
    passengers_t.desiredSpeed[ID++] = speed;// * 10.0f;
  }
  plane_t = Plane(plane_params[0], Numeric(plane_params[1]), Numeric(plane_params[2]), arrangement, obstacles_t);

  return sim_params;
}

/**
 * Finding a passenger by ID
 *
 * @param psg_map Passengers' map of <ID, Passenger>
 * @param ID The ID of the passenger we are looking for.
 *
 **/
/*Passengers_Map::iterator Simulation::getPassengerByID(Passengers_Map& psg_map, int ID){

    for(Passengers_Map::iterator itr=psg_map.begin(); itr!=psg_map.end(); ++itr){
        if(itr->second.getID()==ID)
            return itr;
    }
    return psg_map.end();
}*/



/**
 * Initializing the permissions of moving in aisle for different rows
 *
 * @param holds this vector contains an integer for each row, except the first row, specifying the number of passengers in the front row that have not yet left
 * @param aisle_permission which is used for granting the permission of moving in aisle to the passengers
 * @param arrangement specifies the seat arrangment of the plane
 *
 **/
void Simulation::initializePermissions(vector<int> &holds, vector<bool> &aisle_permission, const vector<pair<int, int> >& arrangement)
{
    int Total_Number_Of_Rows=0;

    for (int i = arrangement.size()-1; i>=0 ; --i)
    {
      Total_Number_Of_Rows+=arrangement[i].first;
      for(int j=0; j<arrangement[i].first; ++j)
      {
        holds.push_back(arrangement[i].second);
        aisle_permission.push_back(false);
      }
    }
    aisle_permission[Total_Number_Of_Rows-1]=true;
}




/**
 * Checking if the passenger's path is blocked by an obstacle in a specific cell
 *
 * @param passenger the passenger whose path we are going to check
 * @param cell the cell whose obstacles we are going to check
 *
 * @return boolean indicating weather or not the path is blocked in that cell
 **/
bool Simulation::checkPathInCell(const vector<int>& cell, const int& passenger_ID, const Obstacles& obstacles_t, const Passengers& passengers_t)
{
  for(vector<int>::const_iterator itr=cell.begin(); itr!= cell.end(); ++itr)
  {
    Numeric distance=getObsSeparation(passengers_t.position_x[passenger_ID], passengers_t.position_y[passenger_ID], passengers_t.aim[passenger_ID], obstacles_t.positions_x[*itr], obstacles_t.positions_y[*itr]);
    if(distance<Numeric(0.04f) && distance>Numeric(0.0f))
    {
      return true;
    }
  }
  return false;
}



/**
 * Checking if the passenger's path is blocked by an obstacle
 *
 * @param passenger_t the passenger whose path we are going to check
 * @param obstacles a const reference to the container of obstacles
 *
 * @return boolean indicating weather or not the path is blocked
 **/
bool Simulation::blockedPath(const int& passenger_ID, const std::vector<int>* obstacles_grid_t, const int& y_dim, const Obstacles& obstacles_t, const Passengers& passengers_t, const int& grid_size)
{
  int index = passengers_t.arr_index_in_grid[passenger_ID];
  //cout<<"gs: "<<grid_size<<endl;
  bool flag= false;

  //cout<<"11\n";
  if(obstacles_grid_t[index].size()>0)
  {
    flag = checkPathInCell(obstacles_grid_t[index], passenger_ID, obstacles_t, passengers_t);
    if(flag==true)
    {
      return flag;
    }
  }
  //cout<<"22\n";
  if(index<grid_size-1 && obstacles_grid_t[index+1].size()>0)
  {
    flag = checkPathInCell(obstacles_grid_t[index+1], passenger_ID, obstacles_t, passengers_t);
    if(flag==true)
    {
      return flag;
    }
  }
  //cout<<"33\n";
  if(index>0 && obstacles_grid_t[index-1].size()>0)
  {
    flag = checkPathInCell(obstacles_grid_t[index-1], passenger_ID, obstacles_t, passengers_t);
    if(flag==true)
    {
      return flag;
    }
  }
  //cout<<"44\n";
  if(index-y_dim>=0)
  {
    if(obstacles_grid_t[index-y_dim].size()>0)
    {
      flag = checkPathInCell(obstacles_grid_t[index-y_dim], passenger_ID, obstacles_t, passengers_t);
      if(flag==true)
      {
        return flag;
      }
    }
    if(obstacles_grid_t[index-y_dim+1].size()>0)
    {
      flag = checkPathInCell(obstacles_grid_t[index-y_dim+1], passenger_ID, obstacles_t, passengers_t);
      if(flag==true)
      {
        return flag;
      }
    }
    if(index-y_dim>0 && obstacles_grid_t[index-y_dim-1].size()>0)
    {
      flag = checkPathInCell(obstacles_grid_t[index-y_dim-1], passenger_ID, obstacles_t, passengers_t);
      if(flag==true)
      {
        return flag;
      }
    }
  }
  //cout<<"55\n";
  if(index+y_dim<=grid_size-1)
  {
    if(obstacles_grid_t[index+y_dim].size()>0)
    {
      flag = checkPathInCell(obstacles_grid_t[index+y_dim], passenger_ID, obstacles_t, passengers_t);
      if(flag==true)
      {
        return flag;
      }
    }
    if(obstacles_grid_t[index+y_dim-1].size()>0)
    {
      flag = checkPathInCell(obstacles_grid_t[index+y_dim-1], passenger_ID, obstacles_t, passengers_t);
      if(flag==true)
      {
        return flag;
      }
    }
    if(index+y_dim<grid_size-1 && obstacles_grid_t[index+y_dim+1].size()>0)
    {
      flag = checkPathInCell(obstacles_grid_t[index+y_dim+1], passenger_ID, obstacles_t, passengers_t);
      if(flag==true)
      {
        return flag;
      }
    }
  }
  //cout<<"66\n";
  return false;
}


/****Race Detection
 * Race is the situation in which to passengers try to get in to the aisle,
 * but neither one can move becaue they have reached the stop_threshold.
 * If the speed and the magnitude of the propulsion that a passenger receives
 * is less than 0.0001 for 1500 iterations (1.5 s in physical time), this is a race.
 * In this case one of the passengers will be randomly chosen to be the winner and
 * can get to the aisle. The other one can move after that.
 *
 *
 * @param passenger the passenger whose race status is going to be checked
 * @param forces the force that this passenger has received in this iteration
 * @param index index of passenger in the forces vector
 * @param psg the nearest passenger to this passenger
 * @param passengers_map the map of all passengers
 *
 * @return boolean indicating weather or not the path is blocked
 ***/
void Simulation::raceDetection(Passengers& passengers, const int& ID, const Numeric& time_step)
{
  Numeric speed = ((passengers.velocity_x[ID] * passengers.velocity_x[ID]) + (passengers.velocity_y[ID] * passengers.velocity_y[ID]));
  Numeric force_mag = ((passengers.force_x[ID] * passengers.force_x[ID]) + (passengers.force_y[ID] * passengers.force_y[ID]));
  if(speed<0.0001 && force_mag<0.0001)
  {
    if(passengers.race_status[ID]==NO_RACE)
    {
      int NID = passengers.nearest_ID[ID];
      if(NID>=0)
      {
        if(passengers.race_status[NID]==NO_RACE)
        {
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
        }
        else
        {
          cout<<"ERROR 1: Passenger was not found: "<<NID<<" for "<<ID<<"\n";
        }
    }
    else if(passengers.race_status[ID]==IN_RACE)
    { //Already in race
      if(passengers.race_opID[ID]==passengers.nearest_ID[ID])
      {
        passengers.race_counter[ID]= (passengers.race_counter[ID]+1);
      }
      else
      {
        //cout<<"OPONNENT CHANGED!\n";
        int NID = passengers.nearest_ID[ID];
        int previous_opponent_ID = passengers.race_opID[ID];
        if(NID>=0 && previous_opponent_ID>=0)
        {
          if(passengers.race_status[NID]==NO_RACE)
          {
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
          }
          else
          {
            //cout<<"New opponent is in race!\n";
          }
        }
        else
        {
            cout<<"ERROR 2: Passenger was not found!\n";
        }
      }
      if(passengers.race_counter[ID]==(int)(1500*time_step) && passengers.race_status[ID]==IN_RACE)
      {
        //decide on the winner/looser
        int OpID = passengers.race_opID[ID];

        if(OpID>=0)
        {
          if(passengers.priority[ID] < passengers.priority[OpID])
          {
            passengers.race_status[ID]=WINNER;
            passengers.race_status[OpID]=LOOSER;
          }
          else if(passengers.priority[ID]>passengers.priority[OpID])
          {
            passengers.race_status[OpID]=WINNER;
            passengers.race_status[ID]=LOOSER;
          }
          else
          {
              if(passengers.aim[OpID]==UP_TO_AISLE || passengers.aim[OpID]==DOWN_TO_AISLE)
              {
                  passengers.race_status[ID]=WINNER;
                  passengers.race_status[OpID]=LOOSER;
              }
              else if(passengers.aim[ID]==ALIGNING)
              {
                  if(passengers.aim[OpID]==ALIGNING)
                  {
                    if(fabs(passengers.position_y[ID]) < fabs(passengers.position_y[OpID]))
                    {
                      passengers.race_status[ID]=WINNER;
                      passengers.race_status[OpID]=LOOSER;
                    }
                    else if(fabs(passengers.position_x[ID]) > fabs(passengers.position_x[OpID]))
                    {
                      passengers.race_status[OpID]=WINNER;
                      passengers.race_status[ID]=LOOSER;
                    }
                    else
                    {
                      if(passengers.position_x[ID] > passengers.position_x[OpID])
                      {
                        passengers.race_status[ID]=WINNER;
                        passengers.race_status[OpID]=LOOSER;
                      }
                      else if(passengers.position_x[ID] < passengers.position_x[OpID])
                      {
                        passengers.race_status[OpID]=WINNER;
                        passengers.race_status[ID]=LOOSER;
                      }
                      else
                      {
                        if(rand()%2==0)
                        {
                          //Winner
                          passengers.race_status[ID]=WINNER;
                          passengers.race_status[OpID]=LOOSER;
                        }
                        else
                        {
                          //Looser
                          passengers.race_status[OpID]=WINNER;
                          passengers.race_status[ID]=LOOSER;
                        }
                      }
                    }
                  }
                  else
                  {
                    if(passengers.position_x[OpID] < passengers.position_x[ID])
                    {
                      passengers.race_status[ID]=WINNER;
                      passengers.race_status[OpID]=LOOSER;
                    }
                    else
                    {
                      passengers.race_status[OpID]=WINNER;
                      passengers.race_status[ID]=LOOSER;
                    }
                  }
                }
                else if(passengers.aim[OpID]==ALIGNING)
                {
                  if(passengers.position_x[ID] < passengers.position_x[OpID])
                  {
                    passengers.race_status[OpID]=WINNER;
                    passengers.race_status[ID]=LOOSER;
                  }
                  else
                  {
                    passengers.race_status[ID]=WINNER;
                    passengers.race_status[OpID]=LOOSER;
                  }
                }
                else
                {
                  if(passengers.position_x[ID] > passengers.position_x[OpID])
                  {
                      passengers.race_status[ID]=WINNER;
                      passengers.race_status[OpID]=LOOSER;
                  }
                  else if(passengers.position_x[ID] < passengers.position_x[OpID])
                  {
                    passengers.race_status[OpID]=WINNER;
                    passengers.race_status[ID]=LOOSER;
                  }
                  else
                  {
                    if(rand()%2==0)
                    {
                      //Winner
                      passengers.race_status[ID]=WINNER;
                      passengers.race_status[OpID]=LOOSER;
                    }
                    else
                    {
                      //Looser
                      passengers.race_status[OpID]=WINNER;
                      passengers.race_status[ID]=LOOSER;
                      //passenger.setWaitTime(1000);
                    }
                  }
                }
              }
        }
        else
        {
          cout<<"ERROR 3: Passenger was not found!\n";
        }
      }/*End if enough wait in race*/
    }//End if already in race
    else if(passengers.race_status[ID]==WINNER)
    {
      //winner is blocked
      int first_looser = passengers.race_opID[ID];
      int NID = passengers.nearest_ID[ID]; //itr
      if(NID>=0 && first_looser>=0)
      {
        if(passengers.race_status[NID]==WINNER){
          int second_looser= passengers.race_opID[NID];
          if(second_looser>=0)
          {
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

          }
          else
          {
            cout<<"ERROR 5: Passenger was not found!\n";
          }
        }
        else if(passengers.race_status[NID]==NO_RACE)
        {
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

        }
        else
        {
          //cout<<"Winner is still blocked! "<<itr->second.getRaceStatus() <<"\n";
        }
      }
      else
      {
        cout<<"ERROR 4: Passenger was not found!\n";
      }
    }//end if winner
  }/*End if race condition*/
  else if(passengers.nearest_distance[ID] > 5 && passengers.race_status[ID] != NO_RACE)
  {
    int opponent = passengers.race_opID[ID];
    if(opponent >=0)
    {
      passengers.race_status[ID]=NO_RACE;
      passengers.race_opID[ID]=-10;
      passengers.race_position_x[ID]=passengers.position_x[ID];
      passengers.race_position_y[ID]=passengers.position_y[ID];
      passengers.race_is_finished[ID]=true;

      passengers.race_status[opponent]=NO_RACE;
      passengers.race_opID[opponent]=-10;
      passengers.race_is_finished[opponent]=true;
    }
    else
    {
      cout<<"ERROR 6: Passenger was not found!\n";
    }
  }
}

/**
 * Updating the member data of a specific passenger after updating its velocity and position
 *
 * @param time_step The actual physical time of each iteration of the code
 * @param passenger The passenger to update
 * @param Luggage_Location The location of the luggage container in the plane
 * @param holds
 * @param aisle_permission
 * @param passengers_map the map of all passengers
 * @param Exit_Position position of the exit door
 * @param numberOfPassesgersInPlane number of passengers that have not yet left the plane
 * @param priority the row priority of the passenger
 * @param output file output stream
 *
 *
 **/
void Simulation::UpdatePassenger(Aim &p_aim, const Numeric& p_position_x, const Numeric& p_position_y, const Numeric& luggage_location_y, int& p_wait_time, bool& has_released, const Numeric& p_seat_position_x, const Numeric& p_seat_position_y, vector<int>& holds, const int& priority, vector<bool>& aisle_permission, const Numeric& plane_exit_x, const Numeric& plane_exit_y, RaceStatus& p_race_status, int& OpID, bool& p_race_finished, Numeric& race_position_x, Numeric& race_position_y, RaceStatus& op_race_status, int& op_race_OpID, bool& op_race_is_finished, Numeric& op_race_position_x, Numeric& op_race_position_y, const Numeric& ID, const Numeric& time_step, int& numberOfPassesgersInPlane, const Numeric& Release_Threshold, ofstream& output)
{
  if((p_aim==DOWN_TO_AISLE)&&(p_position_y<luggage_location_y-(Numeric)0.2f))
  {
    /*passenger has moved down enough toward aisle*/
    p_aim = ALIGNING;
    /*time to wait for baggage loading*/
    p_wait_time = ((int)(5.0f/time_step)+rand()%((int)(7.0f/time_step)));
  }
  else if((p_aim==UP_TO_AISLE)&&(p_position_y> (-1*luggage_location_y) + (Numeric)0.2f))
  {
    /*passenger has moved up enough toward aisle*/
    p_aim = ALIGNING;
    /*time to wait for baggage loading*/
    p_wait_time = (((int)(5.0f/time_step))+rand()%((int)(7.0f/time_step)));

  }
  else if(p_aim==ALIGNING)
  {
    if(fabs(p_position_y)<=(Numeric)0.06f)
    {
      p_aim = IN_AISLE;
    }
  }
  else if(p_aim==IN_AISLE)
  {
    if(!has_released && p_position_x-p_seat_position_x>Release_Threshold)
    {
      /*Passenger has moved more than "Release_Threshold" in the aisle and has not yet released the hold.
	     So, it is time to release the hold and check to see if it is the last hold. In that case,
       we have to get aisle permission to the next row*/
      has_released = (true);
      holds[-1*int(priority)-1]--;
      if(holds[-1*int(priority)-1]==0 && (-1*int(priority)-2)>=0)
      {
        aisle_permission[-1*int(priority)-2]=true;
      }
    }
    if(p_position_x > plane_exit_x+(Numeric)0.05f)
    {
      /*Time to turn toward the exit door*/
      p_aim = (TOWARD_EXIT);
      if( !has_released)
      {
        has_released = (true);
        holds[-1*int(priority)-1]--;
        if(holds[-1*int(priority)-1]==0)
        {
          aisle_permission[-1*int(priority)-2]=true;
        }
      }
    }
    /*Checking to see the winner has moved enough in the aisle so that we can remove the looser tag from the looser passenger*/
    if(p_race_status==WINNER && OpID != -10 && !(p_race_finished))
    {
      if(OpID>=0)
      {
        if(p_position_x - race_position_x >1 && op_race_status==LOOSER)
        {
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
  }
  else if((p_aim==TOWARD_EXIT)&&(p_position_y > plane_exit_y+(Numeric)0.5f))
  {
    /*
    Passenger has reached the exit door
    */
    --numberOfPassesgersInPlane;
    cout<<"Passenger "<<ID<<" Exited! "<<numberOfPassesgersInPlane<<" Remaining\n";
    p_aim =OUT;
  }
}




/**
 * Writing the position and velocity of all passengers to the output file
 *
 * @param passengers_t Passengers' map of <ID, Passenger>
 * @param n The number of this output call.
 * @param output file output stream
 * @param xyz_obs the vector containing the content of obstacles file
 *
 **/
void Simulation::WriteOutput(const Passengers & passengers_t, int n, ofstream& output, const vector<string>& xyz_obs)
{
  ofstream ofs;
  ofs << fixed;
  ofs << setprecision(3);
  char anim[128];
  sprintf(anim, "animfile.xyz");
  ofs.open(anim, ofstream::out | ofstream::app);

  if(ofs.is_open())
  {
    int coord_count = xyz_obs.size() + NumberOfPassengers;
    ofs << "  " << coord_count << "\n   " << (n)*250 << "\n";
    for(int its=0; its<NumberOfPassengers; ++its)
    {
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
      for(int i = 0; i < (12 - int(x.length())); i++)
      {
        ofs << " ";
      }
      ofs << x;

      for(int i = 0; i < (12 - int(y.length())); i++)
      {
        ofs << " ";
      }

      ofs << y << "       0.000\n";
    }
    for(int i=0; i< xyz_obs.size(); ++i)
    {
      ofs << xyz_obs[i] << '\n';
    }

    ofs.close();
    output<<"Output was written!\n";
  }
  else
  {
    cout<<"Error in openning animfile.xyz!\n";
  }
}


/**
 * Initializing passengers and obstacles grids
 *
 * @param passengers_grid the grid of passengers
 * @param passengers_map the map of all passengers
 * @param obstacles_t vector of all obstacles
 * @param obstacles_grid_t obstacles grid
 * @param cell_length length of each cell in the grid
 * @param cell_width width of each cell in the grid
 * @param y_dim second dimension of the grid
 * @param max_y maximum y in the position of passengers
 *
 **/
void Simulation::InitializeGrids(Passengers& passengers_t, vector<int> *& passengers_grid, const Obstacles& obstacles_t, vector<int>*& obstacles_grid_t, const Numeric& cell_length, const Numeric& cell_width, const int& y_dim, const Numeric& max_y)
{
  for(int it=0; it<NumberOfPassengers; ++it)
  {
    int index= int((passengers_t.position_x[it])/cell_length)*y_dim + int((passengers_t.position_y[it]+max_y)/cell_width);
    passengers_grid[index].push_back(it);
    passengers_t.arr_index_in_grid[it]=index;
  }
  for(int it=0; it<NumberOfObstacles; ++it)
  {
    int index= int((obstacles_t.positions_x[it])/cell_length)*y_dim + int((obstacles_t.positions_y[it]+max_y)/cell_width);
    obstacles_grid_t[index].push_back(it);
  }
}


/**
 * updating the grid of passengers after updating the position of passengers
 *
 * @param passengers_grid the grid of passengers
 * @param cell_length length of each cell in the grid
 * @param cell_width width of each cell in the grid
 * @param y_dim second dimension of the grid
 * @param max_y maximum y in the position of passengers
 * @param grid_size size of the passengers grid
 *
 **/
void Simulation::UpdatePassengersGrid(Passengers& passengers, vector<int> *& passengers_grid, vector<int> *& new_passengers_grid, const Numeric& cell_length, const Numeric& cell_width, const int& y_dim, const Numeric& max_y, const int& grid_size)
{

  for(int i=0; i<grid_size; ++i)
  {
    for(int j=0; j<passengers_grid[i].size(); ++j)
    {
      int new_index= int((passengers.position_x[passengers_grid[i][j]])/cell_length)*y_dim + int((passengers.position_y[passengers_grid[i][j]]+max_y)/cell_width);
      if(new_index>=0 && new_index<grid_size)
      {
        passengers.arr_index_in_grid[passengers_grid[i][j]] = new_index;
        new_passengers_grid[new_index].push_back(passengers_grid[i][j]);
      }
      else
      {
        cout<<"Bad index: "<<new_index<<", i:"<<i<<", j:"<<j<<", grid size: "<<grid_size<<", x:"<<passengers.position_x[passengers_grid[i][j]]<<", y:"<<passengers.position_y[passengers_grid[i][j]]<<", CL:"<<cell_length<<", CW:"<<cell_width<<", Ydim:"<<y_dim<<", MaxY:"<<max_y<<"\n";
      }
    }
  }
  swap(passengers_grid, new_passengers_grid);

  for(int grid_index=0; grid_index<grid_size; ++grid_index)
  {
    new_passengers_grid[grid_index].clear();
  }
}

/**
 * Set the maximum desired speeds of the passengers using a normal distribution
 * @param passengers_t the map of all passengers
 **/
/*
void Simulation::setDesiredSpeeds(Passengers_Map &passengers_t){
    std::default_random_engine gen;
    Numeric desiredSpeed;
    std::normal_distribution<Numeric> ND(mean, stddev);
    for(Passengers_Map::iterator itr = passengers_t.begin(); itr!=passengers_t.end(); ++itr){
        desiredSpeed = ND(gen);
        while(desiredSpeed<(Numeric)0.5f || desiredSpeed>(Numeric)2.0f){
            desiredSpeed= ND(gen);
        }
        itr->second.setDesiredSpeed(desiredSpeed);
    }
}*/

void Simulation::checkBehind(vector<int>& cell, Passengers& passengers, int i, int size)
{
  for(int n=0; n<size; ++n)
  {
    if (cell[n]!=i)
    {
      if(fabs(passengers.position_y[cell[n]]-passengers.position_y[i])<0.1f && passengers.position_x[i]<= passengers.position_x[cell[n]]+ 0.15f)
      {
        passengers.force_x[i]=0.0f;
        passengers.force_y[i]=0.0f;
        passengers.velocity_x[i]=0.0f;
        passengers.velocity_y[i]=0.0f;
        break;
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
int Simulation::Run(ofstream& output)
{
  //DECLARE SIMULATION VARIABLES
  Numeric Reaction_Time, Time_Step, Output_Iteration, Number_Of_Outputs, Toward_Aisle_Stop_Threshold, In_Aisle_Stop_Threshold, Aligning_Stop_Threshold;

  //DECLARE SIMULATION OBJECTS
  Passengers passengers;
  Obstacles obstacles;
  Plane plane;

  //DECLARE SIMULATION CONTAINERS
  vector<string> xyz_obs; //HOLDS OBSTACLE FILE CONTENTS
  vector<Numeric> parameters;

  //INITIALIZE PSEUDO-RANDOM NUMBER GENERATOR
  srand(6);

  //(reads and parses input file and sets positions of passengers and obstacles)
  //INITIALIZE PARAMETERS
  parameters = Initialize(passengers, obstacles, plane, xyz_obs);

  //INITIALIZING ITERATORS
  int Outputindex=0;
  int index=0;

  //(read in from a file)
  //INITIALIZE SIMULATION VARIABLES
  Aligning_Stop_Threshold=parameters[index++];
  Toward_Aisle_Stop_Threshold=parameters[index++];
  In_Aisle_Stop_Threshold=parameters[index++];
  Reaction_Time=parameters[index++];
  Time_Step=parameters[index++];
  Output_Iteration=parameters[index++];
  Number_Of_Outputs=parameters[index];

  //DECLARE AND INITIALIZE NUMBER OF PASSENGERS
  int numberOfPassesgersInPlane=NumberOfPassengers;

  //(exit doors have coordinates of (max(x), max(y)))
  //INITIALIZE EXIT DOOR COORDINATES
  Numeric max_x=plane.getExitDoorX()+5, max_y=(plane.getExitDoorY()+1)*2, cell_width=2.0f, cell_length=2.0f;

  //INITIALIZE GRID SIZE
  int grid_size = int((max_x/cell_length + 1) * (max_y/cell_width + 1));

  //(containers to hold the data about passengers and obstacles)
  //INITIALIZE GRIDS
  vector<int> *passengers_grid = new vector<int>[grid_size];
  vector<int> *new_passengers_grid = new vector<int>[grid_size];
  vector<int> *obstacles_grid = new vector<int>[grid_size];

  for(int grid_index=0; grid_index<grid_size; ++grid_index)
  {
    passengers_grid[grid_index]= vector<int>();
    obstacles_grid[grid_index] = vector<int>();
    new_passengers_grid[grid_index]= vector<int>();
  }

  InitializeGrids(passengers, passengers_grid, obstacles, obstacles_grid, cell_length, cell_width, (max_y/cell_width + 1), max_y);

  //DECLARE CONTAINERS THAT CONTROL AISLE PERMISSIONS
  vector<int> holds; //(contains an integer for each row, except the first row, specifying the number of passengers in the front row that have not left yet)
  vector<bool> aisle_permission; //(used in granting permission to move into the aisle for passengers)

  //INITIALIZE PERMISSIONS OF MOVING IN AISLE FOR DIFFERENT ROWS
  initializePermissions(holds, aisle_permission, plane.getSeatArrangement());

  //INITIALIZE CLOCK
  clock_t begin = clock();
  //INITIALIZE MAIN LOOP ITERATORS
  int i=0, iteration_counter=0;

  //MAIN LOOP: WHILE PASSENGERS STILL ON PLANE
  while(numberOfPassesgersInPlane>0)
  {
    i=0;
    iteration_counter++;

    //FOR EVERY PASSENGER - find nearest passenger
    for(i=0; i<NumberOfPassengers; ++i)
    {
      //IF PASSENGER IS NOT OUT OF THE PLANE
      if(passengers.aim[i]!=OUT)
      {
        //(if passenger is allowed to move)
        //IF (PASSENGER IS NOT IN AISLE) OR (PASSENGER IS IN AISLE AND HAS MOVED LESS THAN 0.45 METERS IN AISLE) OR (PASSENGERE IS IN AISLE AND HAS AISLE PERMISSION)
        if((passengers.waitTime[i]==0 && passengers.race_status[i]!=LOOSER) &&  ((passengers.aim[i]!=IN_AISLE && passengers.aim[i]!=ALIGNING )||
            (((passengers.position_x[i]-passengers.seat_position_x[i])<(Numeric)0.45f || (aisle_permission[-1*int(passengers.priority[i])-1])))))
        {
          //FIND NEAREST PASSENGER TO CURRENT PASSENGER AND UPDATE CURRENT PASSENGERS NEAREST PASSENGER
          getNearestPassenger(passengers.nearest_ID[i], passengers.nearest_position_x[i], passengers.nearest_position_y[i], passengers.nearest_distance[i], i, passengers_grid, plane.getExitDoorX(), (max_y/cell_width + 1), passengers, grid_size);
        }
      }
    }

    i=0;

    //FOR EVERY PASSENGER - find desired speed of each passenger based on:
    //their position in the plane,
    //their wait status for retreiving their luggage,
    //and if their path is blocked by obstacles or other passengers;
    //then update postition of passenger and detect if a race between two passengers will take place
    for(i=0; i<NumberOfPassengers; ++i)
    {
      //IF PASSENGER IS NOT OUT OF THE PLANE
      if(passengers.aim[i]!=OUT)
      {
        //(if the passenger is allowed to move)
        //IF (PASSENGER IS NOT IN AISLE) OR (PASSENGER IS IN AISLE AND HAS MOVED LESS THAN 0.45 METERS IN AISLE) OR (PASSENGER IS IN AISLE AND HAS AISLE PERMISSION)
        if((passengers.waitTime[i]==0 && passengers.race_status[i]!=LOOSER) && ((passengers.aim[i]!=IN_AISLE && passengers.aim[i]!=ALIGNING )||
            (((passengers.position_x[i]-passengers.seat_position_x[i])<(Numeric)0.45f || (aisle_permission[-1*int(passengers.priority[i])-1])))))
        {
          //IF PASSENGER IS STOPPED AND NEAREST PASSENGER IS TOO CLOSE
          if(passengers.velocity_x[i]<=0.0f && passengers.nearest_distance[i]<=0.1f)
          {
            //STOP CURRENT PASSENGERS MOVEMENT
            passengers.force_x[i]=0.0f;
            passengers.force_y[i]=0.0f;
            passengers.velocity_x[i]=0.0f;
            passengers.velocity_y[i]=0.0f;
          }
          else
          {
            //DECLARE SPEED VARIABLE
            Numeric DesiredSpeed;
            //CHECK IF CURRENT PASSENGERS PATH IS BLOCKED BY AN OBSTACLE
            bool obs_block=blockedPath(i, obstacles_grid, (max_y/cell_width + 1), obstacles, passengers, grid_size);

            //IF OBSTACLE IS BLOCKING AND NEAREST DISTANCE IS > 0.1
            if(obs_block && passengers.nearest_distance[i]>0.1f)
            {
              //SET CURRENT PASSENGERS NEAREST DISTANCE TO 0.1
              passengers.nearest_distance[i]=0.1f;
            }
            //IF PASSENGER WAS IN A RACE AND WON - (race winners have their movement speed increased by about 10%)
            if(passengers.race_status[i]==WINNER && passengers.nearest_ID[i]==passengers.race_opID[i])
            {
              //UPDATE SPEED OF CURRENT PASSENGER TO DESIRED SPEED BASED ON DISTANCE TO NEAREST PASSENGER
              //(DesiredSpeed - the fastest speed the passenger is allowed to move in this iteration.. used to compute the force)
              DesiredSpeed =DecreaseSpeed((Numeric)1.1f, passengers.nearest_distance[i], cell_width);
            }
            //IF PASSENGER IS ALIGNING (happens after baggage is unloaded and before reaching the center of the aisle)
            else if(passengers.aim[i]==ALIGNING)
            {
              //UPDATE SPEED OF CURRENT PASSENGER USING ALIGNING_SPEED_COEFFICIENT AND BASED ON THE DISTANCE TO THE NEAREST PASSENGER
              DesiredSpeed =DecreaseSpeed(Aligning_Speed_Coefficient, passengers.nearest_distance[i], cell_width);
            }
            //IF PASSENGER IS APPROACHING AISLE
            else if(passengers.aim[i]==UP_TO_AISLE || passengers.aim[i]==DOWN_TO_AISLE )
            {
              //UPDATE SPEED OF CURRENT PASSENGER USING TOWARD_AISLE_SPEED_COEFFICIENT
              DesiredSpeed =DecreaseSpeed(Toward_Aisle_Speed_Coefficient, passengers.nearest_distance[i], cell_width) ;
            }
            else
            {
              //UPDATE SPEED OF CURRENT PASSENGER USING 1.0 AS COEFFICIENT
              DesiredSpeed =DecreaseSpeed(1.0f, passengers.nearest_distance[i], cell_width);
            }

            //(when passengers approach a turn, they slow their speed)
            //IF PASSENGER IS IN THE AISLE AND PASSENGER IS NOT AT THE EXIT
            if(passengers.aim[i]==IN_AISLE && passengers.position_x[i]+ Intersection_Distance_Threshold>plane.getExitDoorX())
            {
              //UPDATE CURRENT PASSENGERS FORCE_X AND FORCE_Y USING INTERSECTION_SPEED_COEFFICIENT
              //(propulsion is need for deceleration)
              Propulsive_Force(passengers.aim[i], passengers.position_y[i], passengers.mass[i], passengers.velocity_x[i], passengers.velocity_y[i], Reaction_Time, DesiredSpeed*Intersection_Speed_Coefficient, passengers.force_x[i], passengers.force_y[i]);
            }
            else
            {
              //UPDATE CURRENT PASSENGERS FORCE_X AND FORCE_Y USING JUST THEIR DESIRED SPEED
              Propulsive_Force(passengers.aim[i], passengers.position_y[i], passengers.mass[i], passengers.velocity_x[i], passengers.velocity_y[i], Reaction_Time, DesiredSpeed, passengers.force_x[i], passengers.force_y[i]);

              //IF PASSENGER IS ALMOST IN THE CENTER OF THE AISLE AND PASSENGER IS ABOUT TO HAVE A NEGATIVE VELOCITY (which means going backwards)
              if(fabs(passengers.position_y[i])<0.15f && passengers.velocity_x[i]<=0.0f && passengers.force_x[i]<0.0f)
              {
                int index=passengers.arr_index_in_grid[i];
                //LOOKS BEHIND CURRENT PASSENGER TO SEE IF ANY PASSENGER/OBSTACLE WILL IMPEDE CURRENT PASSENGERS BACKWARD MOVEMENT
                checkBehind(passengers_grid[index], passengers, i, passengers_grid[index].size());
              }
            }

            //UPDATE VELOCITY AND POSITION OF PASSENGER
            EulerMethod(passengers.race_status[i], passengers.force_x[i], passengers.force_y[i], passengers.mass[i], passengers.velocity_x[i], passengers.velocity_y[i], passengers.position_x[i], passengers.position_y[i], passengers.aim[i], passengers.seat_position_x[i], passengers.desiredSpeed[i], Time_Step);

            //IF PASSENGER IS NOT APPROACHING AISLE
            if(passengers.aim[i]!=DOWN_TO_AISLE && passengers.aim[i]!=UP_TO_AISLE)
            {
              //CHECK FOR A RACE, DETERMINE WINNER
              raceDetection(passengers, i, Time_Step);
            }
          }
        }

        //waitTime != 0, waiting getting luggage
        else if(passengers.waitTime[i]!=0)
        {
          //DECREMENT WAIT TIME OF CURRENT PASSENGER
          //WHEN PASSENGERS REACH LUGGAGE CONTAINER, WE SET A WAIT TIME FOR EACH PASSENGER FOR GETTING THEIR LUGGAGE (7-12 SECONDS IN REAL TIME) -
          //DECREMENT TIME, WHEN IT REACHES 0, THAT MEANS THEY HAVE GOTTEN THEIR LUGGAGE
          passengers.waitTime[i] = passengers.waitTime[i]-1;
          //SET VELOCITY OF CURRENT PASSENGER TO ZERO
           //IF THEY ARE WAITING FOR LUGGAGE, THEY ARE NOT MOVING
          passengers.velocity_x[i]=0;
          passengers.velocity_y[i]=0;
        }
        else
        {
          //SET FORCE AND VELOCITY TO 0 FOR CURRENT PASSENGER
          //SOME PASSENGERS WHO WERE NOT ALLOWED TO MOVE (BACK ROWS) - CANNOT GET LUGGAGE OR MOVE
          //those who didnt pass the if statement cannot move
          passengers.force_x[i]=0.0f;
          passengers.force_y[i]=0.0f;
          passengers.velocity_x[i]=0.0f;
          passengers.velocity_y[i]=0.0f;
        }

        //IF THE PASSENGER IS NOT OUT OF THE PLANE, UPDATE PASSENGERS VALUES, DECREMENT NUMBER OF PASSENGERS
        if(passengers.aim[i]!=OUT)
        {
          //UPDATE PASSENGERS FIELDS
          UpdatePassenger(passengers.aim[i], passengers.position_x[i], passengers.position_y[i], plane.getLuggageY(), passengers.waitTime[i], passengers.has_released[i], passengers.seat_position_x[i], passengers.seat_position_y[i], holds, passengers.priority[i], aisle_permission, plane.getExitDoorX(), plane.getExitDoorY(), passengers.race_status[i], passengers.race_opID[i], passengers.race_is_finished[i], passengers.race_position_x[i], passengers.race_position_y[i], passengers.race_status[passengers.race_opID[i]], passengers.race_opID[passengers.race_opID[i]], passengers.race_is_finished[passengers.race_opID[i]], passengers.race_position_x[passengers.race_opID[i]], passengers.race_position_y[passengers.race_opID[i]], i, Time_Step, numberOfPassesgersInPlane, Release_Threshold, output);
        }

        //SET CURRENT PASSENGERS FORCE TO ZERO (because we want to recompute after each iteration)
        passengers.force_x[i]=0.0f;
        passengers.force_y[i]=0.0f;
      }

      //SET CURRENT PASSENGERS FORCE TO ZERO (because we want to recompute after each iteration)
      passengers.force_x[i]=0.0f;
      passengers.force_y[i]=0.0f;
    }

    //UPDATE PASSENGERS GRID
    UpdatePassengersGrid(passengers, passengers_grid, new_passengers_grid, cell_length, cell_width, (max_y/cell_width + 1), max_y, grid_size);

    //IF IT IS TIME TO WRITE TO FILE (every 250 iterations, specified previously by a parameter read in from a file)
    if(Outputindex%int(Output_Iteration)==Output_Iteration-2)
    {
      //WRITE CURRENT POSITION OF PASSENGERS EACH ITERATION TO FILE
      WriteOutput(passengers, 1+Outputindex/Output_Iteration, output, xyz_obs);
    }

    //INCREMENT OUTPUT INDEX
    Outputindex++;

    //IF SIMULATION DOES NOT PROGRESS
    if(Outputindex>Output_Iteration*(Number_Of_Outputs-1))
    {
      //EXIT SIMULATION
      return 1;
    }
  }

  //INITIALIZE END CLOCK OBJECT
  clock_t end = clock();
  //INITIALIZE AND CALCULATE SIMULATION ELAPSED TIME
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  //PRINT SIMULATION TIMES
  cout<<"Elapsed Time: "<<elapsed_secs <<"(s)"<<endl;
  cout<<"Physical time: "<<(Numeric)(iteration_counter*Time_Step)<<" (s) = "<<(Numeric)(iteration_counter*Time_Step)/60.0f<<" minutes"<<endl;
  //DEALLOCATE GRIDS
  delete [] passengers_grid;
  delete [] obstacles_grid;
  delete [] new_passengers_grid;
  return 0;
}
