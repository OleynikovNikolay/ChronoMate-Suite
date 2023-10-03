#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include "../include/TimeTracker.h"
#include "../include/Task.h"

void TimeTracker::startTracking(const std::string& taskName){
    tasks.emplace_back(taskName);
    std::cout << "Task tracked: " << taskName << std::endl; 
}

void TimeTracker::stopTracking(const std::string& taskName){
    for (Task& task: tasks){
        if (task.getName() == taskName && !task.isStopped()){
            task.stop(); 
            std::cout << "Stopped tracking task: " << taskName << std::endl;
            return;
        }
    }
    std::cout << "No active task found with the name: " << taskName << std::endl;
}

void TimeTracker::displayReport() {
    std::cout << "Time Tracking Report:" << std::endl;
    for (const Task& task: tasks) {
        std::cout << "Task: " << task.getName() << ", Elapsed Time: " << task.getElapsedTime() << " seconds." << std::endl;
    }
}

void TimeTracker::saveReportToFile(const std::string& filename) {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()){
        std::cerr << "File could not be opened" << std::endl;
        return;
    }

    for (const Task& task : tasks) {
        outputFile << "Task: " << task.getName() << ", Elapsed Time: " << task.getElapsedTime() << " seconds." << std::endl;
    }

    outputFile.close();
    if (outputFile.fail()){
        std::cerr << "File could not be closed." << std::endl;
        return;
    }

    std::cout << "Report saved to " << filename << "." << std::endl;
}