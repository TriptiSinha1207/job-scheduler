Supercomputer Job Scheduling Simulator
Overview
This project simulates job scheduling on a supercomputer with one master scheduler node and 128 worker nodes. Each worker node has 24 cores and 64 GB of RAM. Jobs from users are queued on the master node, which allocates these jobs to worker nodes based on specified queuing and node allocation policies. The simulation aims to analyze CPU and memory utilization per day across different policy combinations, outputting results to CSV files and visualizing data through bar graphs.

Features
Job Scheduling Policies:

Queue Policies:
FCFS (First-Come, First-Serve)
Smallest Job First (based on smallest gross value)
Short Duration First (based on execution time)
Worker Node Allocation Policies:
First Fit
Best Fit
Worst Fit
Resource Constraints:

Worker nodes can only execute jobs if they have sufficient cores and memory.
Jobs that can't be allocated are reinserted into the queue.
Output:

Daily average CPU and memory utilization for each combination of queuing and allocation policies.
CSV output with resource utilization data.
Bar graphs to visualize CPU and memory utilization.
Simulation Data
The simulation uses job data with attributes:

Arrival Time: When the job reaches the master node.
CPU Cores Required: Number of cores needed for execution.
Memory Required: GBs of memory needed for execution.
Execution Time: Time in hours the job will take.
To start, download the dataset here.

Installation
Clone the repository:
bash
Copy code
git clone https://github.com/yourusername/supercomputer-job-scheduling-simulator.git
Navigate to the project directory:
bash
Copy code
cd supercomputer-job-scheduling-simulator
Install the required Python packages:
bash
Copy code
pip install -r requirements.txt
Usage
Place the downloaded dataset file in the project directory.
Run the simulation:
bash
Copy code
python scheduler_simulation.py
View the output files for daily CPU and memory utilization data in CSV format.
Output
CSV Files: Detailed daily CPU and memory utilization for each combination of policies.
Graphs: Visualization of daily utilization data, stored in the graphs directory.
Results
The program provides average CPU and memory utilization per day across different policy combinations, allowing you to compare the impact of each scheduling and allocation approach on resource efficiency.

License
This project is licensed under the MIT License.
