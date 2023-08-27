#include <string>
#include "include/gridTraveler.hpp"
#include "include/fibApp.hpp"
#include "include/canSumApp.hpp"
#include "include/howSumApp.hpp"
#include "include/bestSumApp.hpp"
#include "include/canConstructApp.hpp"

int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        return EXIT_FAILURE;
    }
    auto arg1 = std::stoi(argv[1]);
    return fibApp::fibApp(arg1);
    //return gridTravelerApp::gridTravelerApp();
    //return canSumApp::canSumApp();
    //return howSumApp::howSumApp();
    //return bestSumApp::bestSumApp();
    //return canConstructApp::canConstructApp();
}
