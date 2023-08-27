#include <iostream>
#include <ios>

#include "include/func.hpp"
#include "include/datelab.hpp"

void app1()
{
    std::string input = "Kappa";
    auto name = func::getName(input);

    std::cout << "Hello World! " << name << ":" << name.length() << "\n";

    datelab::daysres res;
    datelab::getDays(res);
    std::cout << res.start << "\n";
    std::cout << res.today << "\n";
    std::cout << res._days << "\n";
}