#include <stdlib.h>
#include <iostream>
#include "Arena.h"

Arena::Arena(int l, int w, Prey* prey, Predator* predator) : prey(prey), predator(predator) {
    //�������� ��������� l w �� (1 �� 99)
    if ((l < 0 || l > 100) || (w < 0 || w > 100)) {
        std::cout << "�������� ������ ����� \n" << std::endl;
        exit(-1);
    }
    //�������� �� ���������� ������ � �������� ������� �����
    else if (prey->getLocation().getX()>l || prey->getLocation().getY() > w) {
        std::cout << "������ �� ��������� ����� \n" << std::endl;
        exit(-1);
    }
    //�������� �� ���������� ������� � �������� ������� �����
    else if (predator->getLocation().getX() > l || predator->getLocation().getY() > w) {
        std::cout << "������ �� ��������� ����� \n" << std::endl;
        exit(-1);
    }
    else {
        length = l;
        width = w;
    }
         
    /*length = l;
    width = w;*/

    // ���������� ������� ���� ��� ���������� �������� (�������, ����������)
    int shift_l = 3;
    int shift_w = 4;
    int stretch_w = 2;  // ������ ������ ���� (��� ��������� ������ ��� �����������)

    view_length = length + shift_l;
    view_width = width * stretch_w + shift_w;

    // ��������� ������ ��� ������ field �������� view_length x view_width
    field = new char* [view_length]();

    for (int i = 0; i < view_length; i++) {

        field[i] = new char[view_width]();

        for (int j = 0; j < view_width; j++)
        {
            field[i][j] = ' ';
        }
    }

    // ���������� ������� ������������� ��������� //

    // ������� � ������ ����� ����
    for (int j = 2; j < view_width; j++) {
        field[0][j] = '~';
        field[view_length - 2][j] = '~';

        // ��������� �����
        int cell_num = (j / 2);

        if (j >= view_width - 2) continue;

        if (cell_num > 9) {

            if ((j + 1) % 2 == 0) {
                field[view_length - 1][j + 1] = (cell_num % 10) + '0';
            }
            else field[view_length - 1][j + 1] = (cell_num / 10) + '0';

        }
        else {
            if ((j + 1) % 2 == 0) {
                field[view_length - 1][j + 1] = cell_num + '0';
            }
            else field[view_length - 1][j + 1] = ' ';
        }
    }

    // ����� � ������ ����� ����
    for (int i = 1; i < view_length - 2; i++) {

        field[i][2] = '|';
        field[i][view_width - 1] = '|';

        // ��������� �����            
        int y_coords = view_length - shift_l + 1;

        if (y_coords - i > 9) {
            int tmp = ((y_coords - i) / 10);
            field[i][0] = ((y_coords - i) / 10) + '0';
            field[i][1] = ((y_coords - i) % 10) + '0';
        }
        else field[i][1] = y_coords - i + '0';
    }
}

void Arena::clearStep() {
    // �������� ������
    int preyX = (prey->getLocation().getX() * 2) + 2;
    int preyY = prey->getLocation().getY() + 2;

    field[view_length - preyY][preyX] = ' ';
    field[view_length - preyY][preyX - 1] = ' ';

    // �������� �������
    int predX = (predator->getLocation().getX() * 2) + 2;
    int predY = predator->getLocation().getY() + 2;

    field[view_length - predY][predX] = ' ';
    field[view_length - predY][predX - 1] = ' ';
}

/*�������� ��������� �������� ��� �������� � ������ checkOverRun (length � width �������� �� view_length � view_width ��������������,
� ����� ����������� �������� �������� � 1 �� 3 ��-�� ������� ������������ ��������) */

bool Arena::checkOverRun() {
    int preyX = (prey->getLocation().getX() * 2) + 2;
    int preyY = prey->getLocation().getY() + 2;

    if (preyX > view_width || preyX < 3 || preyY > view_length || preyY < 3) return true;

    int predX = (predator->getLocation().getX() * 2) + 2;
    int predY = predator->getLocation().getY() + 2;

    if (predX > view_width || predX < 3 || predY > view_length || predY < 3) return true;

    return false;
}

 // �������� �� ��������� ������� ������� � ������
bool Arena::checkPosition() {
    if (prey->getLocation() == predator->getLocation()) return true;
    return false;
}

Arena::~Arena() {

    //TODO: ��������� ������������ ������������ ������
    for (int i = 0; i < length; i++) {

        delete[] field[i];
    }

    delete[] field;
}

std::ostream& operator<<(std::ostream& out, const Arena& a) {

    // ���������� ������
    int preyX = (a.prey->getLocation().getX() * 2) + 2;
    int preyY = a.prey->getLocation().getY() + 2;

    a.field[a.view_length - preyY][preyX] = ')';
    a.field[a.view_length - preyY][preyX - 1] = '(';

    // ���������� �������
    int predX = (a.predator->getLocation().getX() * 2) + 2;
    int predY = a.predator->getLocation().getY() + 2;

    a.field[a.view_length - predY][predX] = '*';
    a.field[a.view_length - predY][predX - 1] = '*';


    for (int i = 0; i < a.view_length; i++) {
        for (int j = 0; j < a.view_width; j++) {
            std::cout << a.field[i][j];
        }
        std::cout << "\n";
    }
    return out;
}