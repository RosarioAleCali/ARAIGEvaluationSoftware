#include "Profile.h"

namespace ARAIG {
    Profile::Profile(const char* profile_file, std::ostream& os, ARAIG_Sensors& config) : ostr(os)
    {
        std::string tmp_line, tmp;
        size_t pos;
        std::ifstream p_file(profile_file, std::ios::in);

        if(!p_file)
            throw std::string("Error, unable to open the profile configuration file!");

        // Get Student Info
        getline(p_file, tmp_line);
        pos = tmp_line.find(",");
        s_fname = tmp_line.substr(0,pos);
        pos++;
        tmp_line.erase(0,pos++);
        pos = tmp_line.find(",");
        s_lname = tmp_line.substr(0,pos);
        pos++;
        tmp_line.erase(0,pos++);
        s_number = tmp_line.substr(0,(tmp_line.length()-1));

        // Get Instructor Info
        getline(p_file, tmp_line);
        pos = tmp_line.find(",");
        i_fname = tmp_line.substr(0,pos);
        pos++;
        tmp_line.erase(0,pos++);
        pos = tmp_line.find(",");
        i_lname = tmp_line.substr(0,pos);
        pos++;
        tmp_line.erase(0,pos++);
        e_number = tmp_line.substr(0,(tmp_line.length()-1));

        // Get Student Calibration
        getline(p_file, tmp_line);
        pos = tmp_line.find(",");
        tmp = tmp_line.substr(0,pos);
        pos++;
        tmp_line.erase(0,pos++);
        calibration.max = stoi(tmp);
        calibration.min = stoi(tmp_line);

        // Get Tasks
        while(std::getline(p_file, tmp_line))
        {
            try {
                ToRun.push_back(config.getTask(tmp_line));
            } catch (const std::string& msg) {
                std::cerr << msg << std::endl;
            }
        }
        p_file.close();
    }

    void Profile::displayToRun(std::ostream& ostr)
    {
        ostr << "Tasks to Run:" << std::endl;
        for(size_t i = 0; i < ToRun.size(); i++)
            ToRun[i].dump(ostr);
    }

    void Profile::displayCompleted(std::ostream& ostr)
    {
        ostr << "Tasks Completed: ";
        if(Completed.size() == 0)
            ostr << "0" << std::endl;
        else {
            ostr << std::endl;
            for(size_t i = 0; i < Completed.size(); i++)
                Completed[i].dump(ostr);
        }
    }

    void Profile::displayNextTask(std::ostream& ostr)
    {
        ostr << "Next Task:" << std::endl;
        ToRun[0].execute(ostr);
    }

    void Profile::displayLastCompleted(std::ostream& ostr)
    {
        ostr << "Last Completed Task: ";
        if(Completed.size() == 0)
            ostr << "There are no completed tasks yet!" << std::endl;
        else {
            ostr << std::endl;
            Completed.back().execute(ostr);
        }
    }

    void Profile::run()
    {
        usint input;
        bool continue_ = true;

        while(continue_)
        {
            if(!ToRun.empty()){
                std::cout << "------------------ Flight Plan ------------------" << std::endl;
                std::cout << " " << ToRun.size() << " Tasks availables, " << Completed.size() << " Tasks completed." << std::endl;
                std::cout << "-------------------------------------------------" << std::endl;
                std::cout << " 1 - Run Task(s)" << std::endl;
                std::cout << " 2 - Exit" << std::endl;
                std::cout << "-------------------------------------------------" << std::endl;
                std::cout << "Choose an option: ";
                std::cin >> input;
                std::cout << std::endl;
                if(!std::cin.fail()) {
                    if(input == 1){
                        std::cout << "How many tasks do you want to execute? ";
                        std::cin>>input;
                        system("clear");

                        if(!std::cin.fail()) {
                            std::cin.ignore(50,'\n');
                            if(input > 0 && input <= ToRun.size()){
                                for(usint i = 0; i < input; i++)
                                {
                                    ToRun[0].execute(std::cout);
                                    Completed.push_back(std::move(ToRun[0]));
                                    ToRun.erase(ToRun.begin());
                                    std::cout << "\nPress any key to continue ... "<<std::endl;
                                    std::cin.get();
                                    if(i==(input-1))
                                        system("clear");
                                }
                            } else if(input > ToRun.size()) {
                                usint i = ToRun.size();
                                for(usint j = 0; j < i; j++){
                                ToRun[0].execute(std::cout);
                                Completed.push_back(std::move(ToRun[0]));
                                ToRun.erase(ToRun.begin());
                                std::cout << "\nPress any key to continue ... " << std::endl;
                                std::cin.get();
                                }
                            } else
                                throw "Input must be greater then 0!";
                        } else
                            throw std::string("Insert digits only");
                    } else if (input == 2) {
                        continue_ = false;
                    } else {
                        std::cout << "Error: Incorrect Option Selected!" << std::endl;
                        std::cout << "\nPress any key to continue ... ";
                        std::cin.get();
                        system("clear");
                    }
                } else {
                    throw std::string("Invalid choice, Input digits only");
                }
            } else {
                system("clear");
                throw std::string("The Flight Plan has been Successfully Executed!");
                continue_=1;
            }
        }
    }

    void Profile::generateReport()
    {
        ostr << "Student   :" << std::setw(10) << std::right << s_fname << " " << std::setw(10) << std::right << s_lname << " - " << s_number << std::endl;
        ostr << "Instructor:" << std::setw(10) << std::right << i_fname << " " << std::setw(10) << std::right << i_lname << " - " << e_number << std::endl;
        ostr << "Student Calibration:" << std::endl;
        ostr << "MAX = " << calibration.max << std::endl;
        ostr << "MIN = " << calibration.min << std::endl;
        for(usint i = 0; i < Completed.size(); i++)
            Completed[i].execute(ostr);
    }
}
