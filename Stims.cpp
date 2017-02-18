#include "Stims.h"

namespace ARAIG {
    Stims::Stims(std::string& name, locations area, usint intsty, usint frqncy, usint secs) : Stimulation(std::string("stim"))
    {
        if(!name.empty() && (area >= 0 && area <= 3) && (intsty >= 0 && intsty <= 100) && frqncy >= 0 && secs >= 0)
        {
            stim_name = name;
            location = area;
            intensity = intsty;
            frequency = frqncy;
            duration = secs;
        } else {
            throw std::string("Object Not Created! Please make sure input file has all the required fields, location in 'abs', 'front', 'back' or 'traps' and intensity is between 0%-100%");
        }
    }

    void Stims::display(std::ostream& ostr) const
    {
        ostr << stim_name << std::endl;
		ostr << "     Type = stim" << std::endl;
		ostr << "     Location = ";
		switch(location){
            case abs:
                ostr<<"abs"<<std::endl;
                break;
            case front:
                ostr<<"front"<<std::endl;
                break;
            case back:
                ostr<<"back"<<std::endl;
                break;
            case traps:
                ostr<<"traps"<<std::endl;
                break;
        }
		ostr << "     Intensity = " << intensity << std::endl;
		ostr << "     Frequency = " << frequency << std::endl;
		ostr << "     Duration = " << duration << std::endl;
    }
}
