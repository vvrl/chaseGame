#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "Point2D.h"

class Prey;
class Predator;
class Arena;

using namespace std;











ostream& operator<<(ostream& out, const Predator& p) {
    out << "Имя хищника - " << p.name << "\nКоординаты хищника - " << p.location << endl;
    return out;
}




















//void Predator::AutoMove(const Arena& ar, int z) {
//    int q;
//    int a;
//    if (z == 0) {
//        q = rand() % 4;
//        a = rand() % 5 + 1;
//    }
//    else {
//        int s = 0;
//        cout << "Куда идти?\n0-вверх 1-вправо 2-вниз 3-влево" << endl;
//        cin >> q;
//
//        do {
//            cout << "На сколько? (1-5)" << endl;
//            cin >> a;
//            if (1 <= a && a <= 5) s = 1;
//        } while (s != 1);
//    }
//
//    switch (q) {
//    case 0:
//        if (location.y >= (a)) {
//            location.y -= a;
//        }
//        else cout << "Выход за пределы" << endl;
//        break;
//    case 1:
//        if (location.x <= (ar.w - a)) {
//            location.x += a;
//        }
//        else cout << "Выход за пределы" << endl;
//        break;
//    case 2:
//        if (location.y <= (ar.l - a)) {
//            location.y += a;
//        }
//        else cout << "Выход за пределы" << endl;
//        break;
//    case 3:
//        if (location.x >= (a)) {
//            location.x -= a;
//        }
//        else cout << "Выход за пределы" << endl;
//        break;
//    }
//}




