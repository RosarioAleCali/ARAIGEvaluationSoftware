#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Profile.h"
#include "ARAIG_Sensors.h"
#include "Task.h"
#include "Exoskeleton.h"
#include "Stims.h"
#include "Stimulation.h"

int main(int argc, char** argv) {
        if (argc != 5) {
         std::cerr << "\n***Incorrect number of arguments***\n";
         return 1;
        }

        ARAIG::usint input;
        bool continue_ = true;

        try {
            system("clear");
            ARAIG::ARAIG_Sensors configuration(argv[1],argv[2]);
            std::ofstream output_file (argv[4], std::ofstream::out|std::ofstream::trunc);
            ARAIG::Profile profile(argv[3], output_file, configuration);
            while(continue_)
            {
                system("clear");
                std::cout << "------------------ ARAIG Evaluation Control Software v1.0 ------------------" << std::endl;
                std::cout << "----------------------------------------------------------------------------" << std::endl;
                std::cout << " 1 - Display Flight Plan" << std::endl;
                std::cout << " 2 - Display Completed Tasks" << std::endl;
                std::cout << " 3 - Display Next Task in Flight Plan" << std::endl;
                std::cout << " 4 - Display Last Task Completed" << std::endl;
                std::cout << " 5 - Run Flight Plan" << std::endl;
                std::cout << " 6 - Generate Report" << std::endl;
                std::cout << " 7 - Exit" << std::endl;
                std::cout << "----------------------------------------------------------------------------" << std::endl;
                std::cout << " Choose an option: ";
                std::cin >> input;
                std::cout << std::endl;
                if(!std::cin.fail() && (input >= 0 && input <= 7)) {
                    std::cin.ignore(50,'\n');
                    switch(input) {
                        case 1:
                            system("clear");
                            profile.displayToRun(std::cout);
                            std::cout << "\nPress any key to continue ... ";
                            std::cin.get();
                            break;
                        case 2:
                            system("clear");
                            profile.displayCompleted(std::cout);
                            std::cout << "\nPress any key to continue ... ";
                            std::cin.get();
                            break;
                        case 3:
                            system("clear");
                            profile.displayNextTask(std::cout);
                            std::cout << "\nPress any key to continue ... ";
                            std::cin.get();
                            break;
                        case 4:
                            system("clear");
                            profile.displayLastCompleted(std::cout);
                            std::cout << "\nPress any key to continue ... ";
                            std::cin.get();
                            break;
                        case 5:
                            system("clear");
                            try {
                                profile.run();
                            } catch(const std::string& msg) {
                                std::cerr << msg << std::endl;
                            }
                            std::cout << "\nPress any key to continue ... ";
                            std::cin.get();
                            break;
                        case 6:
                            system("clear");
                            profile.generateReport();
                            std::cout << "Report generated!" << std::endl;
                            std::cout << "\nPress any key to continue ... ";
                            std::cin.get();
                            break;
                        case 7:
                            system("clear");
                            continue_ = false;
                            break;
                    }
                }
            }
            output_file.close();
        } catch (const std::string& msg) {
                std::cerr << msg << std::endl;
            }
        return 0;
}
