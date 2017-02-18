#ifndef ARAIG_SENSORS_H_INCLUDED
#define ARAIG_SENSORS_H_INCLUDED

#include <fstream>
#include <memory>
#include "Task.h"

namespace ARAIG {
    class ARAIG_Sensors {
		Task* tasks;
		Stimulation** stimulations;
		usint tasks_size, stims_size;
    public:
        ARAIG_Sensors(const char* stims_file, const char* task_file);
        void dump(std::ostream& ostr) const;
        Task& getTask(std::string& name);
        usint get_tasks_size() { return tasks_size; }
        ~ARAIG_Sensors();
    };
}

#endif // ARAIG_SENSORS_H_INCLUDED
