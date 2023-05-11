import json
import sys
import os
import matplotlib
import matplotlib.pyplot as plt
import csv
import numpy as np
import math

#Implements speed density relationship
#Uses formulas 8 and 10 from CALM Paper 
#https://journals.plos.org/plosone/article?id=10.1371/journal.pone.0229690#sec009

#THIS VISUALIZATION REQUIRES MATPLOTLIB_LABEL_LINES
#pip install matplotlib-label-lines


if(len(sys.argv) != 2):
    print("USAGE: python3 visualizer.pyz *pedestrian_trajectory.json* *obstacle_set.json*")
    exit(-1)


def Hashing(keyvalue):
    return hash(keyvalue) % len(HashTable)

def insert(Hashtable, keyvalue, value):
      
    hash_key = Hashing(keyvalue)
    Hashtable[hash_key].append(value)

def getAverage(HashTable, keyvalue):
    hash_key = Hashing(keyvalue)
    average = 0
    for i in range(0, len(HashTable[hash_key])):
        average = average + HashTable[hash_key][i]
    
    average = average / len(HashTable[hash_key])
    return average

def display_hash(hashTable):
    for i in range(len(hashTable)):
        print(i, end = " ")
        for j in hashTable[i]:
            print("-->", end = " ")
            print(j, end = " ") 
        print()

#Hash table used for averaging speeds from multiple timesteps with same density
HashTable = [[] for _ in range(100)]

speedDensityFile = open(sys.argv[1])
speeds = []
densities = []

with open(sys.argv[1], 'r') as csv_file:
    csv_reader = csv.reader(csv_file)
    line_count = 0
    for row in csv_reader:
        speeds.append(float(row[1]))
        densities.append(float(row[0]))
        insert(HashTable, float(row[0]), float(row[1]))


speedMeans = []

for density in densities:
    if len(HashTable[Hashing(density)]) != 0:
        speedMeans.append(getAverage(HashTable, Hashing(density)))
    

empericalDensity = np.linspace(0.05, 10, 941)
#Formula 10 from CALM paper
empericalForumlaCALMPaperVelocity = 1.34*(1 - pow(math.e, ((-1 * 1.913) * ((1 / empericalDensity) - (1 / 5.4)))))
empericalForumlaMinVelocity = 0.8*(1 - pow(math.e, ((-1 * 1.913) * ((1 / empericalDensity) - (1 / 5.4)))))
empericalForumlaMaxVelocity = 1.2*(1 - pow(math.e, ((-1 * 1.913) * ((1 / empericalDensity) - (1 / 5.4)))))

plt.xlim(0, 3)
plt.ylim(0, 1.2)
plt.xlabel("Density")
plt.ylabel("Velocity")
plt.grid()
plt.plot(densities, speeds, 'o')
plt.plot(densities, speedMeans, 'o', 'y', label = 'Mean')
plt.plot(empericalDensity, empericalForumlaCALMPaperVelocity, 'r', label = 'Paper Velocity')
plt.plot(empericalDensity, empericalForumlaMinVelocity, 'b', label = 'Min Velocity')
plt.plot(empericalDensity, empericalForumlaMaxVelocity, 'g', label = 'Max Velocity')
plt.legend()
plt.show()


