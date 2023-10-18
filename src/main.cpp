#include <iostream>
#include "../include/TimeTracker.h"
#include "../include/Task.h"

int main(){

    bool applicationRunning = true; 

    TimeTracker tracker;

    while(applicationRunning){
        std::cout << "Time tracking options:" << std::endl;
        std::cout << "1. Start Tracking. " << std::endl;
        std::cout << "2. Stop Tracking. " << std::endl;
        std::cout << "3. Display Report. "<< std::endl;
        std::cout << "4. Save Time Report to File. " << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Choose an option." << std::endl;

        int choice;
        if(!(std::cin >> choice)){
            std::cout << "Invalid option. Choose a valid option." << std::endl;
            std::cin.clear();   
            std::cin.ignore(); 
            continue;
        };

        switch(choice){
            case 1: {
                std::string taskName;

                std::cout << "Enter the task name. " << std::endl;
                std::cin.ignore();

                std::getline(std::cin, taskName);
                tracker.startTracking(taskName);
                break;
            }
            case 2: {                
                std::string taskName;

                std::cout << "Enter task name to stop tracking: ";
                std::cin.ignore();

                std::getline(std::cin, taskName);
                tracker.stopTracking(taskName);
                break;
            }
            case 3: {
                tracker.displayReport();
                break;
            }
            case 4: {
                std::string fileName; 

                std::cout << "Enter the path of the file to save your report to. " << std::endl;
                std::cin.ignore();

                std::getline(std::cin, fileName);
                tracker.saveReportToFile(fileName);
                break;
            }
            case 5: {
                applicationRunning = false;
                break;
            }
            default:{
                std::cout << "Invalid option. Choose a valid option." << std::endl;
                break;
            }
        }
    }

    return 0;
}