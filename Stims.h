#ifndef STIMS_H_INCLUDED
#define STIMS_H_INCLUDED

#include "Stimulation.h"

namespace ARAIG {
    class Stims : public Stimulation {
        std::string stim_name;
        locations location;
        usint intensity, frequency, duration;
    public:
        Stims(std::string& name, locations area, usint intsty, usint frqncy, usint secs);
        void display(std::ostream& ostr) const;
        std::string get_name() const { return stim_name; }
    };
}

#endif // STIMS_H_INCLUDED
