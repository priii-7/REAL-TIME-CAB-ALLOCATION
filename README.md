#  Real-Time Cab Allocation using Graph Algorithms

##  Overview
This project simulates a real-time cab allocation system inspired by ride-hailing platforms like Uber.
The city is modeled as a weighted graph, and the nearest available driver is assigned to a rider using Dijkstra’s shortest path algorithm.


##  Key Features
- City modeled as a weighted graph (20 areas)
- Nearest driver selection using Dijkstra’s Algorithm
- Handles multiple rider requests
- Dynamically updates driver availability
- Simulates traffic using variable edge weights


##  Tech Stack
- Language: C++
- Data Structures: Graphs, Priority Queue, Vectors
- Algorithm: Dijkstra’s Shortest Path


##  How It Works
1. Each city area is represented as a node.
2. Roads between areas are represented as weighted edges.
3. Drivers are placed at different city locations.
4. For each rider request:
   - The nearest available driver is identified.
   - The driver is assigned and marked as busy.
   - Pickup distance is estimated using shortest path.
