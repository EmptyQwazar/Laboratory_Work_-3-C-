#include "lab3.h"

int readInt() {
    int val = 0;
    while (!(std::cin >> val)) {
        std::cout << "Ошибка! Введите целое число: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    return val;
}

// РЕАЛИЗАЦИЯ КЛАССА coordinate

coordinate::coordinate(int x, int y) {
    this->x = x;
    this->y = y;
}

int coordinate::getX() const {
    return this->x;
}

int coordinate::getY() const {
    return this->y;
}

void coordinate::setX(int x) {
    this->x = x;
}

void coordinate::setY(int y) {
    this->y = y;
}

std::string coordinate::toString() const {
    return "{" + std::to_string(this->x) + ";" +
        std::to_string(this->y) + "}";
}

void coordinate::print() const {
    std::cout << this->toString() << std::endl;
}

// РЕАЛИЗАЦИЯ КЛАССА line

line::line(coordinate* start, coordinate* end) {
    this->start = start;
    this->end = end;
    this->ownsStart = false;
    this->ownsEnd = false;
}

line::line(const coordinate& start, const coordinate& end) {
    this->start = new coordinate(start.getX(), start.getY());
    this->end = new coordinate(end.getX(), end.getY());
    this->ownsStart = true;
    this->ownsEnd = true;
}

line::line(int x1, int y1, int x2, int y2) {
    this->start = new coordinate(x1, y1);
    this->end = new coordinate(x2, y2);
    this->ownsStart = true;
    this->ownsEnd = true;
}

line::~line() {
    if (this->ownsStart && this->start != nullptr) {
        delete this->start;
    }
    if (this->ownsEnd && this->end != nullptr) {
        delete this->end;
    }
}

coordinate* line::getStart() const {
    return this->start;
}

coordinate* line::getEnd() const {
    return this->end;
}

void line::setStart(coordinate* newStart) {
    if (this->ownsStart && this->start != nullptr) {
        delete this->start;
    }
    this->start = newStart;
    this->ownsStart = false;
}

void line::setEnd(coordinate* newEnd) {
    if (this->ownsEnd && this->end != nullptr) {
        delete this->end;
    }
    this->end = newEnd;
    this->ownsEnd = false;
}

void line::setStart(int x, int y) {
    if (this->start != nullptr) {
        this->start->setX(x);
        this->start->setY(y);
    }
}

void line::setEnd(int x, int y) {
    if (this->end != nullptr) {
        this->end->setX(x);
        this->end->setY(y);
    }
}

int line::getLength() const {
    double dx = static_cast<double>(
        this->end->getX() - this->start->getX()
        );
    double dy = static_cast<double>(
        this->end->getY() - this->start->getY()
        );
    return static_cast<int>(std::round(
        std::sqrt(dx * dx + dy * dy)
    ));
}

std::string line::toString() const {
    return "Линия от " + this->start->toString() +
        " до " + this->end->toString();
}

void line::print() const {
    std::cout << this->toString() << std::endl;
}


// РЕАЛИЗАЦИЯ КЛАССА student


student::student(const std::string& name, int* grades,
    int count, bool owns) {
    this->name = name;
    this->grades = grades;
    this->gradesCount = count;
    this->ownsGrades = owns;
}

student::~student() {
    if (this->ownsGrades && this->grades != nullptr) {
        delete[] this->grades;
    }
}

int* student::getGrades() const {
    return this->grades;
}

int student::getGradesCount() const {
    return this->gradesCount;
}

void student::setGradesShallow(int* newGrades, int count) {
    if (this->ownsGrades && this->grades != nullptr) {
        delete[] this->grades;
    }
    this->grades = newGrades;
    this->gradesCount = count;
    this->ownsGrades = false;
}

void student::setGradesDeep(const int* sourceGrades, int count) {
    if (this->ownsGrades && this->grades != nullptr) {
        delete[] this->grades;
    }
    this->gradesCount = count;
    if (count > 0 && sourceGrades != nullptr) {
        this->grades = new int[count];
        for (int i = 0; i < count; ++i) {
            this->grades[i] = sourceGrades[i];
        }
        this->ownsGrades = true;
    }
    else {
        this->grades = nullptr;
        this->ownsGrades = false;
    }
}

void student::setGradeAt(int index, int value) {
    if (index >= 0 && index < this->gradesCount &&
        this->grades != nullptr) {
        this->grades[index] = value;
    }
}

std::string student::toString() const {
    std::string res = this->name + ": [";
    for (int i = 0; i < this->gradesCount; ++i) {
        res += std::to_string(this->grades[i]);
        if (i + 1 < this->gradesCount) {
            res += ", ";
        }
    }
    res += "]";
    return res;
}

void student::print() const {
    std::cout << this->toString() << std::endl;
}

// функции заданий

void task1() {
    std::cout << std::endl
        << "--- Задание 1 (Задача 1: Точка координат) ---"
        << std::endl;
    std::cout << "Создаем 3 точки с разными координатами."
        << std::endl;

    for (int i = 1; i <= 3; ++i) {
        std::cout << "Точка " << i << " - введите X: ";
        int x = readInt();
        std::cout << "Точка " << i << " - введите Y: ";
        int y = readInt();

        coordinate coor(x, y);
        std::cout << "Текстовое представление точки " << i << ": ";
        coor.print();
    }


}

void task2() {
    std::cout << std::endl
        << "--- Задание 2 (Задача 1: Прямая) ---"
        << std::endl;

    coordinate p1Start(1, 3);
    coordinate p1End(23, 8);
    line line1(&p1Start, &p1End);

    coordinate p2Start(5, 10);
    coordinate p2End(25, 10);
    line line2(&p2Start, &p2End);

    line line3(line1.getStart(), line2.getEnd());

    std::cout << "Исходные линии (п. 1-3):" << std::endl;
    std::cout << "1) "; line1.print();
    std::cout << "2) "; line2.print();
    std::cout << "3) "; line3.print();

    std::cout << std::endl
        << "Пункт 4. Изменим координаты 1-й и 2-й линий так, "
        << "чтобы 3-я тоже изменилась:" << std::endl;
    std::cout << "Введите новый X начала Линии 1: ";
    int newX1 = readInt();
    std::cout << "Введите новый Y начала Линии 1: ";
    int newY1 = readInt();
    line1.setStart(newX1, newY1);

    std::cout << "Введите новый X конца Линии 2: ";
    int newX2 = readInt();
    std::cout << "Введите новый Y конца Линии 2: ";
    int newY2 = readInt();
    line2.setEnd(newX2, newY2);

    std::cout << "После изменения (Линия 3 автоматически обновилась):"
        << std::endl;
    std::cout << "1) "; line1.print();
    std::cout << "2) "; line2.print();
    std::cout << "3) "; line3.print();

    std::cout << std::endl
        << "Пункт 5. Изменим координаты Линии 1 так, "
        << "чтобы Линия 3 НЕ изменилась:" << std::endl;
    std::cout << "Введите X нового независимого начала Линии 1: ";
    int indX = readInt();
    std::cout << "Введите Y нового независимого начала Линии 1: ";
    int indY = readInt();

    coordinate newIndependentStart(indX, indY);
    line1.setStart(&newIndependentStart);

    std::cout << "После перепривязки начала Линии 1 к новой точке "
        << "(Линия 3 осталась прежней):" << std::endl;
    std::cout << "1) "; line1.print();
    std::cout << "2) "; line2.print();
    std::cout << "3) "; line3.print();


}

void task3() {
    std::cout << std::endl
        << "--- Задание 3 (Задача 1: Студент) ---"
        << std::endl;

    int vasyaGrades[3] = { 3, 4, 5 };
    student vasya("Вася", vasyaGrades, 3, false);
    std::cout << "1) Создан студент Вася:" << std::endl;
    vasya.print();

    student petya("Петя", nullptr, 0, false);
    petya.setGradesShallow(vasya.getGrades(), vasya.getGradesCount());

    petya.setGradeAt(0, 5);
    std::cout << std::endl
        << "2-3) Скопировали оценки Пете и заменили "
        << "первую оценку Пети на 5:" << std::endl;
    vasya.print();
    petya.print();
    std::cout << "Объяснение: так как поле оценок Пети получило адрес "
        << "того же массива в памяти," << std::endl
        << "что и у Васи, "
        << "изменение оценки Пети изменило и оценку Васи."
        << std::endl;

    student andrey("Андрей", nullptr, 0, false);
    andrey.setGradesDeep(vasya.getGrades(), vasya.getGradesCount());

    std::cout << std::endl
        << "4) Создан Андрей с глубокой копией оценок Васи."
        << std::endl;
    std::cout << "Введите новую первую оценку для Васи "
        << "(чтобы проверить независимость оценок Андрея): ";
    int newVasyaGrade = readInt();
    vasya.setGradeAt(0, newVasyaGrade);

    std::cout << "Результат после изменения оценки Васи:" << std::endl;
    vasya.print();
    andrey.print();


}

void task4() {
    std::cout << std::endl
        << "--- Задание 4 (Задачи 1 и 2: Создаем Точку и Линию) ---"
        << std::endl;

    std::cout << "Задача 4.1 (Точки только с двумя координатами X и Y):"
        << std::endl;
    coordinate c1(3, 5);
    coordinate c2(25, 6);
    coordinate c3(7, 8);
    c1.print();
    c2.print();
    c3.print();

    std::cout << std::endl
        << "Задача 4.2 (Создание Линий по точкам и по 4 числам):"
        << std::endl;
    line l1(1, 3, 23, 8);
    line l2(coordinate(5, 10), coordinate(25, 10));
    line l3(l1.getStart(), l2.getEnd());

    std::cout << "Линия 1: "; l1.print();
    std::cout << "Линия 2: "; l2.print();
    std::cout << "Линия 3: "; l3.print();


}

void task5() {
    std::cout << std::endl
        << "--- Задание 5 (Задача 3: Длина Линии) ---"
        << std::endl;

    line l(coordinate(1, 1), coordinate(10, 15));
    std::cout << "Создана линия: ";
    l.print();
    std::cout << "Длина этой линии (целое число): "
        << l.getLength() << std::endl;

    std::cout << std::endl << "Проверка на пользовательской линии:"
        << std::endl;
    std::cout << "Введите X1: "; int x1 = readInt();
    std::cout << "Введите Y1: "; int y1 = readInt();
    std::cout << "Введите X2: "; int x2 = readInt();
    std::cout << "Введите Y2: "; int y2 = readInt();

    line userLine(x1, y1, x2, y2);
    userLine.print();
    std::cout << "Длина пользовательской линии: "
        << userLine.getLength() << std::endl;


}
