#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

class Elevator {
    bool turn;
    int floor;

public:
    Elevator() {
        floor = 1;
        turn = true;
    }
    void setTurn(bool on) {
        turn = on;
    }
    int View() {
        return floor;
    }

    bool Power() {
        return turn;
    }
    void setFloor(int f) {
        floor = f;
    }
};

void main() {

    setlocale(0, "");
    srand(time(NULL));
    int on = 0;
    int change;
    int up = 0;
    int floor_ = 0;
    Elevator el;
    do {
        Sleep(1000);
        system("cls");
        cout << "Выберите действие:\n";
        
        cout << "[1] - Посмотреть на каком этаже лифт.\n[2] - Проверить работает ли лифт?\n[3] - Вызвать лифт.\n[4] - Переключить свет.\n";
        cout <<"[5] - menu exit.\n";
        cin >> change;
        switch (change) {
        case 1:
            cout << "Сейчас лифт на " << el.View() << " этаже.";
            break;
        case 2:
            cout << "Лифт - "; if (el.Power() == true) {
                cout << "Работает.\n";
            }
            else {
                cout << "Не работает.\n";
            }
            break;
        case 3:
            if (el.Power() == false) {
                cout << "Лифт не едет.\n";
            }
            else {
                cout << "Куда едем?\n";
                cout << "[1] - Вверх\n[2] - Вниз\n";
                cin >> up;
                if (el.View() == 2) {
                    cout << "Лифт на первом этаже, едем Вверх.\n";
                    up = 1;
                }
                switch (up) {
                case 1:
                    cout << "На какой этаж подымаемся ? (1-10)\n";
                    cin >> floor_;
                    if (floor_ == el.View()) {
                        cout << "Вы на текущем этаже.\n";
                    }
                    else {
                        el.setFloor(floor_);
                    }
                    cout << "Лифт поехал."; Sleep(250); cout << "."; Sleep(250); cout << ".\nПриехали.";
                    break;
                case 2:
                    cout << "На какой этаж спускаемся ?(1-10)\n";
                    cin >> floor_;
                    if (floor_ == el.View()) {
                        cout << "Вы на текущем этаже.\n";
                    }
                    else {
                        el.setFloor(floor_);
                        cout << "Лифт поехал."; Sleep(250); cout << "."; Sleep(250); cout << ".\nПриехали.";
                    }
                    break;
                }

            }

            break;
        case 4:
            cout << "Включить Свет ?\n[1] - Да.\n[2] - Нет.\n";
            cin >> on;
            switch (on) {
            case 1:
                if (el.Power() == true) {
                    cout << "Свет был включен.\n";
                }
                else {
                    el.setTurn(true);
                    cout << "Свет включен.\n";
                }
                break;
            case 2:
                if (el.Power() == false) {
                    cout << "Свет был выключен.\n";
                }
                else {
                    el.setTurn(false);
                    cout << "Свет выключен.\n";
                }
                break;
            default:
                el.setTurn(false);
                break;
            }
            break;
        default:
            cout << "\nВыход.\n";
            change = 5;
            break;
        }
    } while (change < 5);
}
