**CALM Boarding**


This code can run a parameter sweep of boarding procedure for one of the following airplanes:


- To use Boeing 757-200 with 182 seats, please uncomment lines 357 and 415 in the Simulation.cpp file and also uncomment lines 16 and 21 in the DataStructure.h file.

- To use Airbus A320 with 144 seats, please uncomment lines 358 and 416 in the Simulation.cpp file and also uncomment lines 17 and 22 in the DataStructure.h file.

- To use Boeing 757-200 with 201 seats, please uncomment lines 359 and 417 in the Simulation.cpp file and also uncomment lines 18 and 23 in the DataStructure.h file.

- To use CRJ-200 with 50 seats, please uncomment lines 360 and 418 in the Simulation.cpp file and also uncomment lines 19 and 24 in the DataStructure.h file. 



To set the number of parameter combinations (number of simulations in the parameter sweep) you can modify the line 61 of main.cpp

This code uses a msater-worker approach to dynamically balance the load between MPI-ranks. Also, we use a LDS-based sequence (there are up to 15000 rows already in the sequences.txt file) for sweeping the parameter space.