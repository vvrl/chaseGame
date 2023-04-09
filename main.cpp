#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <cstdlib>

#include "Characters.h"
#include "Arena.h"

using namespace std;


int main() {

    system("chcp 1251");

    srand(time(NULL));

    Prey prey("prey", Point2D(5, 8), false);
    Predator predator("predator", Point2D(3, 9), false);

    Arena arena(10, 10, &prey, &predator);

    cout << arena;

    for (int i = 0; i <= 2; i++) {
        arena.clearStep();

        Point2D prevPreyLocation(prey.getLocation());
        Point2D prevPredLocation(predator.getLocation());

        prey.autoMove();
        predator.autoMove();

        if (arena.checkOverRun())
        {
            prey.moveTo(prevPreyLocation);
            predator.moveTo(prevPredLocation);
        }

        if (arena.checkPosition()) {
            cout << arena;
            system("chcp 65001");
            cout << "Хищник победил!" << endl;
            return 0;
        }

        
        cout << arena;
         
        system("timeout /t 1");
        
        //system("cls");    //перезапись консоли
    }
    system("chcp 65001");
    cout << "Жертва победила" << endl;
    return 0;
}