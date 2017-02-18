#include "Task.h"

namespace ARAIG {
    Task::Task(const Task& source)
    {
        task_name = source.task_name;
        task_stimulations = std::list<Stimulation*>(source.task_stimulations);
    }

    Task& Task::operator=(const Task& source)
    {
        if(this != &source) {
            task_name = source.task_name;
            task_stimulations = std::list<Stimulation*>(source.task_stimulations);
        } else {
            task_name.clear();
            task_stimulations.clear();
        }
        return *this;
    }

    Task::Task(Task&& source)
    {
        task_name = source.task_name;
        task_stimulations = std::list<Stimulation*>(source.task_stimulations);
        source.task_name.clear();
        source.task_stimulations.clear();
    }

    Task&& Task::operator=(Task&& source)
    {
        if(this != &source) {
            task_name = source.task_name;
            task_stimulations = std::list<Stimulation*>(source.task_stimulations);
            source.task_name.clear();
            source.task_stimulations.clear();
        } else {
            task_name.clear();
            task_stimulations.clear();
        }
        return std::move(*this);
    }

    Task& Task::operator+=(Stimulation* source)
    {
        task_stimulations.push_back(source);
        return *this;
    }

    Stimulation* Task::operator[](usint i)
    {
        if (task_stimulations.size() > i)
        {
            std::list<Stimulation*>::iterator it = task_stimulations.begin();
            std::advance(it, i);
            return *it;
        } else
            throw std::string("Stimulation requested is not it Task");
    }

    void Task::del_stimulation(const std::string& nm)
    {
        for(std::list<Stimulation*>::iterator it = task_stimulations.begin(); it != task_stimulations.end(); it++)
        {
            if((*it)->get_name() == nm) {
                task_stimulations.erase(it);
                break;
            }
        }
    }

    void Task::dump(std::ostream& ostr) const
    {
        ostr << "TASK - " << task_name << std::endl;
        for(std::list<Stimulation*>::const_iterator i = task_stimulations.begin(); i != task_stimulations.end(); i++) {
            ostr << "       ";
            ostr << (*i)->get_name() << std::endl;
        }
    }

    void Task::execute(std::ostream& ostr) const
    {
        ostr << "TASK: " << task_name << std::endl;
        for(std::list<Stimulation*>::const_iterator i = task_stimulations.begin(); i != task_stimulations.end(); i++) {
            (*i)->display(ostr);
        }
    }

    Task::~Task()
    {
        for(size_t x = 0; x < task_stimulations.size(); x++) {
            task_stimulations.front() = nullptr;
            task_stimulations.pop_front();
        }
    }
}
