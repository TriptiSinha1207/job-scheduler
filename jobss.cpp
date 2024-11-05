#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

struct Job {
    int arrivalTime;
    int coresRequired;
    int memoryRequired; // in GB
    int executionTime;  // in hours
    int grossValue() const {
        return coresRequired * memoryRequired * executionTime;
    }
};
struct WorkerNode {
    int id;
    int availableCores = 24;
    int availableMemory = 64; // in GB
};

class JobScheduler {
private:
    vector<WorkerNode> workerNodes;
    queue<Job> jobQueue;
    int totalJobsProcessed = 0;
    int totalCPUUtilization = 0;
    int totalMemoryUtilization = 0;

public:
    JobScheduler(int numWorkers) {
        for (int i = 0; i < numWorkers; ++i) {
            workerNodes.push_back({i});
        }
 }

    void addJob(const Job& job) {
        jobQueue.push(job);
    }

    void scheduleJobs(int currentHour) {
        int queueSize = jobQueue.size();
        for (int i = 0; i < queueSize; ++i) {
            Job job = jobQueue.front();
            jobQueue.pop();

            if (allocateJob(job)) {
                totalJobsProcessed++;
                totalCPUUtilization += job.coresRequired;
                totalMemoryUtilization += job.memoryRequired;
            } else {
                jobQueue.push(job);
            }
        }
  }

    bool allocateJob(const Job& job) {
        for (auto& worker : workerNodes) {
            if (worker.availableCores >= job.coresRequired &&
                worker.availableMemory >= job.memoryRequired) {
                worker.availableCores -= job.coresRequired;
                worker.availableMemory -= job.memoryRequired;
                return true;
            }
        }
        return false;
    }

    void printStatistics() {
        cout << "Total Jobs Processed: " << totalJobsProcessed << endl;
        cout << "Total CPU Utilization: " << totalCPUUtilization << " Cores" << endl;
cout << "Total Memory Utilization: " << totalMemoryUtilization << " GB" << endl;
    }

    void generateCSV(const string& filename) {
        ofstream file(filename);
        file << "Jobs Processed,CPU Utilization,Memory Utilization\n";
        file << totalJobsProcessed << "," << totalCPUUtilization << "," << totalMemoryUtilization << "\n";
        file.close();
    }
};

int main() {
    JobScheduler scheduler(128);

    scheduler.addJob({0, 2, 4, 1});
    scheduler.addJob({0, 4, 8, 2});
    scheduler.addJob({0, 1, 2, 1});
    scheduler.addJob({0, 6, 16, 3});
 for (int hour = 0; hour < 24; ++hour) {
        scheduler.scheduleJobs(hour);
    }

    scheduler.printStatistics();
    scheduler.generateCSV("scheduler_stats.csv");

    return 0;
}

