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


---

## Smart Traffic Signal Optimization System

### Overview
This project simulates a smart traffic signal control system for a city with multiple intersections. Each intersection dynamically selects the optimal road to receive a green signal based on traffic density and safety constraints.

### Key Features
- City modeled as multiple intersections with incoming roads
- Greedy scheduling using **Priority Queue**
- **Emergency vehicle priority override** (ambulance/fire/police)
- Real-time decision-making simulation
- Implemented using efficient **C++ STL** data structures

### How It Works
1. Each intersection is treated as an independent control unit.
2. Roads are prioritized based on the number of waiting vehicles.
3. If an emergency vehicle is detected on any road, it immediately gets a green signal.
4. Otherwise, the road with maximum congestion is selected.

### Tech Stack
- Language: **C++**
- Data Structures: Vectors, Priority Queue
- Algorithms: Greedy Strategy
