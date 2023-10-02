#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>

class TimeTracker {
public:
    explicit TimeTracker(const std::string& name)
    : taskName(name){};

    void startTracking(const std::string& taskName){
        std::time_t startTime = std::time(0);
        currentTask = taskName;
        taskInitialised = true;

        std::cout << "Task tracked: " << currentTask << std::endl; 
    }
    void stopTracking(const std::string & taskName){
        if (taskInitialised){
            std::time_t endTime = std::time(0);
            std::time_t timeElapsed = endTime - startTime; 
            tasks.push_back({currentTask, timeElapsed});
            taskInitialised = false;
        } else {
            std::cout << "No task has been tracked." << std::endl;
        }
    }

    void displayReport() {
        std::cout << "Time Tracking Report:" << std::endl;
        for (const auto& task : tasks) {
            std::cout << "Task: " << task.first << ", Time: " << task.second << " seconds." << std::endl;
        }
    }

    void saveReportToFile(const std::string& filename) {
        std::ofstream outputFile(filename);

        for (const auto& task : tasks) {
            outputFile << "Task: " << task.first << ", Time: " << task.second << " seconds." << std::endl;
        }

        outputFile.close();
        std::cout << "Report saved to " << filename << "." << std::endl;
    }

private:
    bool taskInitialised = false; 
    std::string taskName;
    std::time_t startTime;
    std::string currentTask;
    std::vector<std::pair<std::string, std::time_t>> tasks;
};