#ifndef PROFILE_H_INCLUDED
#define PROFILE_H_INCLUDED

#include <vector>
#include <sstream>
#include <limits>

#include "ARAIG_Sensors.h"

namespace ARAIG {
    class Profile {
        std::string s_fname, s_lname, i_fname, i_lname, s_number, e_number;
        struct cal {
            usint max;
            usint min;
        } calibration;
        std::vector<Task> ToRun;
        std::vector<Task> Completed;
        std::ostream& ostr;
    public:
        Profile(const char* profile_file, std::ostream& os, ARAIG_Sensors& config);
        void displayToRun(std::ostream& ostr);
        void displayCompleted(std::ostream& ostr);
        void displayNextTask(std::ostream& ostr);
        void displayLastCompleted(std::ostream& ostr);
        void generateReport();
        void run();
    };
}

#endif // PROFILE_H_INCLUDED
