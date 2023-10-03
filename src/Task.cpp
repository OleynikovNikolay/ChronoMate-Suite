#include "../include/Task.h"

Task::Task(const std::string& name)
: taskName(name), startTime(std::time(0)), endTime(0){}

void Task::stop() {
    if (!isStopped()) {
        endTime = std::time(0);
    }
}

std::string Task::getName() const {
    return taskName;
}

std::time_t Task::getStartTime() const {
    return startTime;
}

std::time_t Task::getEndTime() const {
    return endTime;
}

std::time_t Task::getElapsedTime() const {
    if (isStopped()) {
        return endTime - startTime;
    } else {
        return std::time(0) - startTime;
    }
}

bool Task::isStopped() const {
    return endTime != 0;
}

