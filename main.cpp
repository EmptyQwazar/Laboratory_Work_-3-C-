#include <clocale>
#include <iostream>
#include "lab3.h"

int main() {
    std::setlocale(LC_ALL, "Russian");

    int choice = -1;
    while (choice != 0) {
        std::cout << std::endl << "=== МЕНЮ ЛАБОРАТОРНОЙ №3 (ВАРИАНТ 1) ==="
            << std::endl
            << "1. Задание 1 (Задача 1: Точка координат)" << std::endl
            << "2. Задание 2 (Задача 1: Прямая)" << std::endl
            << "3. Задание 3 (Задача 1: Студент)" << std::endl
            << "4. Задание 4 (Задачи 1 и 2: Создаем Точку и Линию)" 
            << std::endl
            << "5. Задание 5 (Задача 3: Длина Линии)" << std::endl
            << "0. Выход" << std::endl;

        std::cout << "Выбор: ";
        choice = readInt();

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        case 0: std::cout << "Выход." << std::endl; break;
        default: std::cout << "Неверный пункт." << std::endl; break;
        }
    }

    return 0;
}
