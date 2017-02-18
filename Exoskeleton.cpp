#include "Exoskeleton.h"

namespace ARAIG {
    Exoskeleton::Exoskeleton(std::string& name, usint intsty, usint secs) : Stimulation(std::string("exoskeleton"))
    {
        if(!name.empty() && (intsty >= 0 && intsty <= 100) && secs >= 0)
        {
            exoskeleton_name = name;
            intensity = intsty;
            duration = secs;
        } else {
            throw std::string("Object Not Created! Please make sure input file has all the required fields and intensity is between 0%-100%");
        }
    }

    void Exoskeleton::display(std::ostream& ostr) const
    {
        ostr << exoskeleton_name << std::endl;
        ostr << "     Type = exoskeleton" << std::endl;
        ostr << "     Intensity = " << intensity << std::endl;
        ostr << "     Duration = " << duration << std::endl;
    }
}
