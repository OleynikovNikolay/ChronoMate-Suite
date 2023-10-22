/*
This headers declares Task class, its methods and its attributes.
*/
#include <iostream>
#include <ctime>

#ifndef TASK_H 
#define TASK_H

class Task{
public:
    Task(const std::string& name);

    void stop();
    std::string getName() const;
    std::time_t getStartTime() const;
    std::time_t getEndTime() const;
    std::time_t getElapsedTime() const;
    bool isStopped() const;

private:
    std::string taskName;
    std::time_t startTime;
    std::time_t endTime;
};

#endif // TASK_H