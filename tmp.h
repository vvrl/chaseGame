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













ostream& operator<<(ostream& out, const Arena& a) {
    cout << "\033[2J\033[1;1H";
    cout << "   ";
    for (int i = 0; i < a.w; i++) cout << i + 1 << " ";
    cout << "\n  ";
    for (int i = 0; i < a.w + 1; i++) cout << "--";
    cout << "\n";
    for (int i = 0; i < a.l; i++) {
        if ((i + 1) / 10 == 0) cout << i + 1 << " |";
        else cout << i + 1 << "|";
        if (a.prey->location.y == i + 1 && a.predator->location.y == i + 1) {
            if (a.prey->location.x > a.predator->location.x) {
                for (int j = 1; j < a.predator->location.x; j++) {
                    cout << "  ";
                }
                cout << "Х ";
                for (int j = a.predator->location.x + 1; j < a.prey->location.x; j++) {
                    cout << "  ";
                }
                cout << "Ж ";
                for (int j = a.prey->location.x + 1; j <= a.w; j++) {
                    cout << "  ";
                }
            }
            else if (a.predator->location.x > a.prey->location.x) {
                for (int j = 1; j < a.prey->location.x; j++) {
                    cout << "  ";
                }
                cout << "Ж ";
                for (int j = a.prey->location.x + 1; j < a.predator->location.x; j++) {
                    cout << "  ";
                }
                cout << "Х ";
                for (int j = a.predator->location.x + 1; j <= a.w; j++) {
                    cout << "  ";
                }
            }
            else if (a.predator->location.x == a.prey->location.x) {
                for (int j = 1; j < a.predator->location.x; j++) cout << "  ";
                cout << "Х ";
                for (int j = a.predator->location.x; j < a.w; j++) cout << "  ";
            }
        }
        else if (a.prey->location.y == i + 1) {
            for (int j = 1; j < a.prey->location.x; j++) cout << "  ";
            cout << "Ж ";
            for (int j = a.prey->location.x; j < a.w; j++) cout << "  ";
        }
        else if (a.predator->location.y == i + 1) {
            for (int j = 1; j < a.predator->location.x; j++) cout << "  ";
            cout << "Х ";
            for (int j = a.predator->location.x; j < a.w; j++) cout << "  ";
        }
        else if (a.prey->location.y != i + 1 && a.predator->location.y != i + 1) {
            for (int j = 0; j < a.w; j++) cout << "  ";
        }
        cout << "|\n";
    }
    cout << "  ";
    for (int i = 0; i < a.w + 1; i++) cout << "--";
    cout << "\n";
    return out;
}







void Predator::AutoMove(const Arena& ar, int z) {
    int q;
    int a;
    if (z == 0) {
        q = rand() % 4;
        a = rand() % 5 + 1;
    }
    else {
        int s = 0;
        cout << "Куда идти?\n0-вверх 1-вправо 2-вниз 3-влево" << endl;
        cin >> q;

        do {
            cout << "На сколько? (1-5)" << endl;
            cin >> a;
            if (1 <= a && a <= 5) s = 1;
        } while (s != 1);
    }

    switch (q) {
    case 0:
        if (location.y >= (a)) {
            location.y -= a;
        }
        else cout << "Выход за пределы" << endl;
        break;
    case 1:
        if (location.x <= (ar.w - a)) {
            location.x += a;
        }
        else cout << "Выход за пределы" << endl;
        break;
    case 2:
        if (location.y <= (ar.l - a)) {
            location.y += a;
        }
        else cout << "Выход за пределы" << endl;
        break;
    case 3:
        if (location.x >= (a)) {
            location.x -= a;
        }
        else cout << "Выход за пределы" << endl;
        break;
    }
}




bool check (const Prey& prey, const Predator& predator) {
    
    if (prey.location.x == predator.location.x && abs(prey.location.y - predator.location.y) <= 5) {
        return 1;
    }
    else if (prey.location.y == predator.location.y && abs(prey.location.x - predator.location.x) <= 5) {
        return 1;
    }
    else return 0;
}








bool check1 (const Prey& prey, const Predator& predator) {
    if ((prey.location.x == predator.location.x) && (prey.location.y == predator.location.y)) return 1;
    else return 0;
}