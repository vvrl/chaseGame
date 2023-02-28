#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "tmp.h"

using namespace std;


int main() {
    system("chcp 65001");

    int z;
    cout << "Enter a name for your prey: ";
    string name, name1;
    cin >> name;
    cout << "Enter a name for your predator: ";
    cin >> name1;
    Prey prey(name, Point2D(1, 1));
    Predator predator(name1, Point2D(7, 1));
    cout << "За кого хотите играть? (0-жертва, 1-хищник)" << endl;
    cin >> z;

    Arena arena(10, 10, &prey, &predator);
    cout << arena << endl;

    while (1) {
        if (z == 0) {
            if (check(prey, predator)) {
                predator.MoveTo(prey.getx(), prey.gety());
                cout << arena;
                cout << "\n!!!!!! ХИЩНИК ПОБЕДИЛ !!!!!!" << endl;
                return 0;
            }
            else {
                prey.AutoMove(arena, z);
                predator.AutoMove(arena, z);
                cout << arena << endl;
            }
        }
        else {
            if (check1(prey, predator)) {
                cout << "\n!!!!!! ХИЩНИК ПОБЕДИЛ !!!!!!" << endl;
                return 0;
            }
            else {
                prey.AutoMove(arena, z);
                predator.AutoMove(arena, z);
                cout << arena << endl;
            }
        }
    }

    return 0;
}