Network Packet Routing Simulation using Dijkstra's Algorithm

Project Overview
This project simulates how data packets travel across a network using Dijkstra’s Shortest Path Algorithm. It allows users to create a network graph, add connections (edges), and find the shortest path from a source node to all other nodes.

The simulation visually shows how routing decisions are made step-by-step.



Features
- Add nodes and weighted edges dynamically
- Display the network graph
- Simulate packet routing using Dijkstra’s algorithm
- Show shortest distances from source node
- Display actual path taken by packets
- Step-by-step visualization with delay (real-time feel)



 Technologies Used
- C++
- Standard Template Library (STL)
- Chrono & Thread libraries (for simulation delay)



 Algorithm Used
### Dijkstra’s Algorithm
- Used to find the shortest path from a source node to all other nodes
- Works efficiently for graphs with non-negative weights
- Time Complexity: O(V²) (in this implementation)



How It Works
1. User enters number of nodes
2. Adds edges with weights (distance/cost)
3. Displays graph (optional)
4. Runs Dijkstra algorithm from a source node
5. System calculates:
   - Shortest distance
   - Optimal path



 How to Run

### Step 1: Compile
bash g++ main.cpp -o router 

### Step 2: Run
bash ./router 



 Sample Menu
1. Add Edge 2. Show Graph 3. Run Dijkstra (Route Packets) 4. Exit



Example Output
- Visiting nodes step-by-step
- Updating shortest distances
- Final shortest path and cost



 Real-World Applications
- Internet routing protocols
- GPS navigation systems
- Network optimization
- Traffic management systems



 Limitations
- Does not support negative edge weights
- Uses simple implementation (can be optimized using priority queue)



Future Enhancements
- GUI-based visualization
- Use priority queue for better performance
- Support directed graphs
- Add real-time network scenarios



 Author
Mydhili (B.Tech Student)
keerthi sree
charanya
varshitha
tanvi sri



License
This project is for educational purpo
