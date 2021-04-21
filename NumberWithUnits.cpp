#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "NumberWithUnits.hpp"
using namespace std;

namespace ariel
{
    NumberWithUnits::NumberWithUnits(double n, string u) : num(n), units(u) {}
    //read_units function
    void NumberWithUnits::read_units(ifstream &units_file)
    {
        string s;
    }

    //Accounting operators:
    NumberWithUnits operator+(const NumberWithUnits &num1, const NumberWithUnits &num2)
    {
        return NumberWithUnits{0, ""};
    }
    NumberWithUnits operator+(const NumberWithUnits &num1)
    {
        return NumberWithUnits(0, "");
    }
    
    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &num1)
    {
        return *this;
    }
    NumberWithUnits operator-(const NumberWithUnits &num1, const NumberWithUnits &num2)
    {
        return NumberWithUnits{0, ""};
    }
    NumberWithUnits operator-(const NumberWithUnits &num1)
    {
        return NumberWithUnits(0, "");
    }
    NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &num1)
    {
        return *this;
    }

    //Comparative operators

    bool NumberWithUnits::operator>(const NumberWithUnits &num1) const
    {
        return true;
    }
    bool NumberWithUnits::operator>=(const NumberWithUnits &num1) const
    {
        return true;
    }
    bool NumberWithUnits::operator<(const NumberWithUnits &num1) const
    {
        return true;
    }

    bool NumberWithUnits::operator<=(const NumberWithUnits &num1) const
    {
        return true;
    }
    bool NumberWithUnits::operator==(const NumberWithUnits &num1) const
    {
        return true;
    }
    bool NumberWithUnits::operator!=(const NumberWithUnits &num1) const
    {
        return true;
    }

    //Increase and Decrease by 1
    const NumberWithUnits NumberWithUnits::operator++(int) //a++
    {
        return *this;
    }
    NumberWithUnits &NumberWithUnits::operator++() //++a
    {
        return *this;
    }
    const NumberWithUnits NumberWithUnits::operator--(int) //a--
    {
        return *this;
    }
    NumberWithUnits &NumberWithUnits::operator--() //--a
    {
        return *this;
    }

    //Multiplication
    NumberWithUnits operator*(const NumberWithUnits &num1, const double n)
    {
        return NumberWithUnits(0, "");
    }
    NumberWithUnits operator*(const double n, const NumberWithUnits &num1)
    {
        return NumberWithUnits(0, "");
    }

    //Input and Output
    ostream &operator<<(std::ostream &output, const NumberWithUnits &n)
    {
        output << n.num << "[" << n.units << "]";
        return output;
    }
    istream &operator>>(std::istream &input, NumberWithUnits &n)
    {
        string s;
        input >> n.num >> s >> n.units;
        return input;
    };
}