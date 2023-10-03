#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include "../include/TimeTracker.h"
#include "../include/Task.h"

// starting tracking -  creating instance of class Task with default constructor std::time(0) as startTime
// tasks is container vector of Task Class instances
void TimeTracker::startTracking(const std::string& taskName){
    for (Task& task: tasks){
        if (task.getName() == taskName){
            std::cerr << "Task with this name is already registered. Choose another name." << std::endl;
            return;
        }
    }
    
    tasks.emplace_back(taskName);
    std::cout << "Task tracked: " << taskName << ".\n" << std::endl; 
}

// looping through tasks container and stoping the instance
void TimeTracker::stopTracking(const std::string& taskName){
    for (Task& task: tasks){
        if (task.getName() == taskName && !task.isStopped()){
            task.stop(); 
            std::cout << "Stopped tracking task: " << taskName << ".\n" << std::endl;
            return;
        }
    }
    std::cout << "No active task found with the name: " << taskName << ".\n" << std::endl;
}

// displaying registered tasks
void TimeTracker::displayReport() {
    std::cout << "Time Tracking Report:" << std::endl;
    for (const Task& task: tasks) {
        time_t tStartTime = task.getStartTime();
        time_t tEndTime = task.getEndTime();
        
        std::string strEndTime;

        if (tEndTime == 0) {
            strEndTime = "Running...";
        } else {
            struct tm* timeinfo;
            timeinfo = localtime(&tEndTime);
            char buffer[80];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
            strEndTime = buffer;
        }

        std::cout << "Task: " << task.getName() << ", Elapsed Time: " << task.getElapsedTime() << " seconds, Start Time: " << ctime(& tStartTime) << ", End Time: " << strEndTime << ".\n" << std::endl;
    }
}

void TimeTracker::saveReportToFile(const std::string& filename) {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()){
        std::cerr << "File could not be opened\n" << std::endl;
        return;
    }

    for (const Task& task : tasks) {
        time_t tStartTime = task.getStartTime();
        time_t tEndTime = task.getEndTime();

        std::string strEndTime;

        if (tEndTime == 0) {
            strEndTime = "Running...";
        } else {
            struct tm* timeinfo;
            timeinfo = localtime(&tEndTime);
            char buffer[80];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
            strEndTime = buffer;
        }

        outputFile << "Task: " << task.getName() << ", Elapsed Time: " << task.getElapsedTime() << " seconds, Start Time: " << ctime(& tStartTime) << ", End Time: " << ctime(& tEndTime) << ".\n" << std::endl;
    }

    outputFile.flush();

    outputFile.close();
    if (outputFile.fail()){
        std::cerr << "File could not be closed.\n" << std::endl;
        return;
    }

    std::cout << "Report saved to " << filename << ".\n" << std::endl;
}