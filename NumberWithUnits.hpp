#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

namespace ariel
{
    class NumberWithUnits
    {
    private:
        double num;
        string units;

    public:
        NumberWithUnits(double, string);

        //read_units function
        static void read_units(ifstream &units_file);

        //Accounting operators:
        friend NumberWithUnits operator+(const NumberWithUnits &num1, const NumberWithUnits &num2);
        friend NumberWithUnits operator+(const NumberWithUnits &num1);
        NumberWithUnits &operator+=(const NumberWithUnits &num1);
        friend NumberWithUnits operator-(const NumberWithUnits &num1, const NumberWithUnits &num2);
        friend NumberWithUnits operator-(const NumberWithUnits &num1);
        NumberWithUnits &operator-=(const NumberWithUnits &num1);

        //Comparative operators
        bool operator>(const NumberWithUnits &num1) const;
        bool operator>=(const NumberWithUnits &num1) const;
        bool operator<(const NumberWithUnits &num1) const;
        bool operator<=(const NumberWithUnits &num1) const;
        bool operator==(const NumberWithUnits &num1) const;
        bool operator!=(const NumberWithUnits &num1) const;

        //Increase and Decrease by 1
        NumberWithUnits &operator++();         // ++a
        NumberWithUnits &operator--();         // --a
        const NumberWithUnits operator++(int); // a++
        const NumberWithUnits operator--(int); // a--

        //Multiplication
        friend NumberWithUnits operator*(const NumberWithUnits &num1, double n);
        friend NumberWithUnits operator*(double n, const NumberWithUnits &num1);

        //Input and Output
        friend ostream &operator<<(ostream &output, const NumberWithUnits &n);
        friend istream &operator>>(istream &input, NumberWithUnits &n);
    };
}