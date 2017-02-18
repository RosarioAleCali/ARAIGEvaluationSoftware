#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

#include <list>
#include <iterator>
#include "Stims.h"
#include "Exoskeleton.h"

namespace ARAIG {
    class Task {
        std::string task_name;
        std::list<Stimulation*> task_stimulations;
    public:
        Task() { task_name.clear(); task_stimulations.clear(); }
        Task(std::string& name) { task_name = name; task_stimulations.clear(); }
        Task(const Task& source);
        Task& operator=(const Task& source);
        Task(Task&& source);
        Task&& operator=(Task&& source);
        Task& operator+=(Stimulation* source);
        std::string get_name() { return task_name; }
        Stimulation* operator[](usint i);
        void del_stimulation(const std::string& nm);
        void dump(std::ostream& ostr) const;
        void execute(std::ostream& ostr) const;
        ~Task();
    };
}

#endif // TASK_H_INCLUDED
