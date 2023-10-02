#include <string>
#include <iostream>

int main(){

    bool applicationRunning = true; 

    while(applicationRunning){
        std::cout << "Time tracking options:" << std::endl;
        std::cout << "1. Start Tracking. " << std::endl;
        std::cout << "2. Stop Tracking. " << std::endl;
        std::cout << "3. Display Report. "<< std::endl;
        std::cout << "4. Save Time Report to File. " << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Choose an option." << std::endl;

        int choice;

        std::cin >> choice;

        switch(choice){
            case 1: {
                std::string taskName; 
                std::cout << "Enter the task name. " << std::endl;
                std::cin.ignore();
                std::getline(std::cin, taskName);
                break;
            }
            case 2: {
                // stop tracking
                break;
            }
            case 3: {
                //displaying report
                break;
            }
            case 4: {
                std::string fileName; 
                std::cout << "Enter the path of the file to save your report to. " << std::end;
                std::cin.ignore();
                std::getline(std::cin, fileName);
                // saving file to report
                break;
            }

            case 5: {
                applicationRunning = false;
                break;
            }

            default:{
                std::cout << "Invalid option. Choose a valid option." << std::endl;
            }

        }
    }

    return 0;
}