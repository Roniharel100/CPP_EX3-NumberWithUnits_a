#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <string>

using namespace ariel;
using namespace std;

ifstream units_file{"units.txt"};

TEST_CASE("operators +, +=, -, -=")
{
  // same types
  NumberWithUnits::read_units(units_file);
  NumberWithUnits a(3, "km");
  NumberWithUnits b(40, "m");
  NumberWithUnits c(10, "cm");

  NumberWithUnits d(0.5, "hour");
  NumberWithUnits e(30, "min");

  CHECK_EQ(a + b, NumberWithUnits{3.4, "km"});
  CHECK_EQ(d + e, NumberWithUnits{1, "hour"});

  NumberWithUnits temp1{8, "cm"};
  temp1 += c;
  CHECK_EQ(temp1, NumberWithUnits{18, "cm"});
  NumberWithUnits temp2{15, "min"};
  temp2 += e;
  CHECK_EQ(temp2, NumberWithUnits{45, "min"});

  CHECK_EQ(a - a, NumberWithUnits{0, "km"});
  CHECK_EQ(d - e, NumberWithUnits{0, "hour"});

  NumberWithUnits temp3{50, "m"};
  temp3 -= c;
  CHECK_EQ(temp3, NumberWithUnits{40, "cm"});
  NumberWithUnits temp4{1, "hour"};
  temp4 -= e;
  CHECK_EQ(temp4, NumberWithUnits{30, "min"});

  //different types
  CHECK_THROWS(a + d);
  CHECK_THROWS(c += d);
  CHECK_THROWS(b - e);
  CHECK_THROWS(a -= e);
}

TEST_CASE("operators ==, =!, <, >, <=, >=")
{
  // same types
  NumberWithUnits a(2, "km");
  NumberWithUnits b(2, "m");
  NumberWithUnits c(200, "cm");

  NumberWithUnits d(0.5, "hour");
  NumberWithUnits e(30, "min");

  NumberWithUnits f{30, "USD"};
  NumberWithUnits g{3, "ILS"};

  NumberWithUnits h{105, "kg"};
  NumberWithUnits i{25.4, "kg"};
  NumberWithUnits j{31.7, "ton"}; //317000 kg

  CHECK_EQ(b, c);
  CHECK_EQ(d, e);

  CHECK_NE(f, g);
  CHECK_NE(h, i);

  CHECK_LT(i, h);
  CHECK_LT(g, f);

  CHECK_GT(f, g);
  CHECK_GT(j, i);

  CHECK_LE(c, a);
  CHECK_LE(h, j);

  CHECK_GE(d, e);
  CHECK_GE(a, c);

  //different types
  CHECK_THROWS(a.operator==(j));
  CHECK_THROWS(b.operator==(i));

  CHECK_THROWS(c.operator!=(h));
  CHECK_THROWS(d.operator!=(g));

  CHECK_THROWS(e.operator<=(f));
  CHECK_THROWS(a.operator<=(d));

  CHECK_THROWS(d.operator>=(j));
  CHECK_THROWS(i.operator>=(g));

  CHECK_THROWS(h.operator<(a));
  CHECK_THROWS(c.operator<(d));

  CHECK_THROWS(h.operator>(b));
  CHECK_THROWS(e.operator>(a));
}

TEST_CASE(" + unary, - unary")
{
  NumberWithUnits a{32, "sec"};
  NumberWithUnits b{83.5, "ton"};
  NumberWithUnits c{99, "ILS"};
  NumberWithUnits d{72, "g"};

  CHECK_EQ(+a, NumberWithUnits{32, "sec"});
  CHECK_EQ(+b, NumberWithUnits{83.5, "kg"});

  CHECK_EQ(-c, NumberWithUnits{-99, "ILS"});
  CHECK_EQ(-d, NumberWithUnits{-72, "g"});
}

TEST_CASE("operators ++, --")
{
  NumberWithUnits a{10, "sec"};
  NumberWithUnits b{33, "kg"};

  CHECK_EQ(++a, NumberWithUnits{11, "sec"});
  CHECK_EQ(a++, NumberWithUnits{11, "sec"});
  CHECK_EQ(a, NumberWithUnits{12, "sec"});

  CHECK_EQ(++b, NumberWithUnits{34, "kg"});
  CHECK_EQ(b++, NumberWithUnits{34, "kg"});
  CHECK_EQ(b, NumberWithUnits{35, "kg"});
}

TEST_CASE("operators *")
{
  // same types

  NumberWithUnits a(0.5, "hour");
  NumberWithUnits b{30, "USD"};
  NumberWithUnits c{54, "ILS"};
  NumberWithUnits d{12, "kg"};
  NumberWithUnits e{16.5, "kg"};
  NumberWithUnits f{7, "ton"};

  CHECK_EQ(4 * a, NumberWithUnits{2, "hour"});
  CHECK_EQ(2.5 * b, NumberWithUnits{75, "USD"});
  CHECK_EQ(-3 * f, NumberWithUnits{-21, "ton"});

  CHECK_EQ(c * 2, NumberWithUnits{108, "ILS"});
  CHECK_EQ(d * 3.5, NumberWithUnits{42, "kg"});
  CHECK_EQ(e * -4, NumberWithUnits{66, "kg"});
}

TEST_CASE("operators << , >>")
{
  ostringstream output;
  NumberWithUnits a{5, "sec"};
  output << a;
  CHECK(output.str() == "5[sec]");

  istringstream input{"7[kg]"};
  NumberWithUnits b{9, "nim"};
  input >> b;
  CHECK(b == NumberWithUnits{7, "kg"});
}

TEST_CASE("illigals")
{
  CHECK_THROWS(NumberWithUnits(70, "KM"));
  CHECK_THROWS(NumberWithUnits(11, "cM"));
  CHECK_THROWS(NumberWithUnits(8, "Ils"));
  CHECK_THROWS(NumberWithUnits(60, "G"));
  CHECK_THROWS(NumberWithUnits(5, "hello"));
  CHECK_THROWS(NumberWithUnits(6, "hi"));
}
