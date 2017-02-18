#ifndef EXOSKELETON_H_INCLUDED
#define EXOSKELETON_H_INCLUDED

#include "Stimulation.h"

namespace ARAIG {
    class Exoskeleton : public Stimulation {
        std::string exoskeleton_name;
        usint intensity, duration;
    public:
        Exoskeleton(std::string& name, usint intsty, usint secs);
        void display(std::ostream& ostr) const;
        std::string get_name() const { return exoskeleton_name; }
    };
}

#endif // EXOSKELETON_H_INCLUDED
