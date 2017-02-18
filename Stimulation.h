#ifndef STIMULATION_H_INCLUDED
#define STIMULATION_H_INCLUDED

#include <string>
#include <iostream>
#include <iomanip>

namespace ARAIG {
    enum locations {abs, front, back, traps}; // May need to change the name
    typedef unsigned short usint;

    class Stimulation {
        std::string stimulation_type;
    protected:
        Stimulation(const std::string& input) { stimulation_type = input; }
    public:
        virtual void display(std::ostream& ostr) const = 0;
        virtual std::string get_name() const = 0;
    };
}

#endif // STIMULATION_H_INCLUDED
