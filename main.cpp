#include "TownsTSP.h"
#include "TownsATSP.h"
#include <ctime>
#include <fstream>

int main()
{

    std::string fileName[] = {"berlin52.tsp", "ch130.tsp", "a280.tsp"};
    int whichInstance = 0;
        TownsTSP towns = *(new TownsTSP());
        towns.loadMap(fileName[whichInstance]);



        double results = 0;
        int optCost = towns.getOptCost();

        double mistakes[1];
        for(int i = 0; i< 1; i++){


                towns.tabuSearch((int)(1.8*52));

                results = towns.routeCost(towns.solution);
                towns.resetSolution();

            double mistake = (results - optCost)/(double)optCost;
            mistake *= 100;
            mistakes[i] = mistake;
        }


    //std::fstream file;
    //std::string name = "test_results/test_tt_aspiration_berlin52.csv";
    //file.open(name, std::ios::out);
    //for(int i=0; i<100; i++)
      //  file << mistakes[i] << ";";
    //file.close();

    std::cout << "mistake : " << mistakes[0];
    return 0;
}