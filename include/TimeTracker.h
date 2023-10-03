/*
This header declares TimeTracker class, its methods and its attributes.
*/
#include "Task.h"

#ifndef TIME_TRACKER_H
#define TIME_TRACKER_H

class TimeTracker {
public:
    void startTracking(const std::string& taskName);
    void stopTracking(const std::string& taskName);
    void displayReport();
    void saveReportToFile(const std::string& filename);

private:
    std::vector<Task> tasks;
};
#endif // TIME_TRACKER_H