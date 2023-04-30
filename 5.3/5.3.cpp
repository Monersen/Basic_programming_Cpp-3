#include <iostream>

using namespace std;

class Figure {
public:
    Figure() : Figure(0, "Фигура") {}

    int getSidesCount() {
        return sides_count;
    }

    virtual void printInfo() {

        cout << endl << name << ":" << endl;

        if (check())
            cout << "Правильная" << endl;
        else
            cout << "Неправильная" << endl;

        cout << "Колличество сторон: " << sides_count << endl;
    }

protected:
    int sides_count;
    string name;

    Figure(int s, string _name)
        : sides_count(s)
        , name(_name)
    {}

    virtual bool check() {
        return sides_count == 0 ? true : false;
    }
};

class Triangle : public Figure {

public:
    Triangle(int a, int b, int c, int A, int B, int C)
        : Figure(3, "Треугольник")
        , sides{ a, b, c }
        , angles{ A, B, C }
    {}

    void printInfo() override {
        Figure::printInfo();

        cout << "Стороны:";
        getSides();

        cout << "\nУглы:";
        getAngles();

        cout << endl;
    }

    void getSides() {
        int i = 0;
        for (char c = 'a'; c <= 'c'; ++c && ++i)
            cout << c << "=" << sides[i] << " ";
    }

    void getAngles() {
        int i = 0;
        for (char c = 'A'; c <= 'C'; ++c && ++i)
            cout << c << "=" << angles[i] << " ";
    }

protected:
    int sides[3];
    int angles[3];

    virtual bool check() override {
        int angles_sum = 0;

        for (int i = 0; i < sides_count; ++i)
            angles_sum += angles[i];

        return sides_count == 3 && angles_sum == 180 ? true : false;
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
        name = "Прямоугольный треугольник";
    }
};

class IsosTriangle : public Triangle {
public:
    IsosTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
        name = "Равнобедренный треугольник";
    }
};

class EquilTriangle : public Triangle {
public:
    EquilTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }

protected:
    virtual bool check() {
        return true;
    }
};

class Quadrilateral : public Figure {

public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
        : Figure(4, "Четырёхугольник")
        , sides{ a, b, c, d }
        , angles{ A, B, C, D }
    {}

    void printInfo() override {
        Figure::printInfo();

        cout << "Стороны:";
        getSides();

        cout << "\nУглы:";
        getAngles();

        cout << endl;
    }

    void getSides() {
        int i = 0;
        for (char c = 'a'; c <= 'd'; ++c && ++i)
            cout << c << "=" << sides[i] << " ";
    }

    void getAngles() {
        int i = 0;
        for (char c = 'A'; c <= 'D'; ++c && ++i)
            cout << c << "=" << angles[i] << " ";
    }

protected:
    int sides[4];
    int angles[4];

    virtual bool check() override {
        int angles_sum = 0;
        for (int i = 0; i < sides_count; ++i)
            angles_sum += angles[i];

        return sides_count == 4 && angles_sum == 360 ? true : false;
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(int a, int b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {
        name = "Прямоугольник";
    }
};

class Square : public Quadrilateral {
public:
    Square(int a) : Quadrilateral(a, a, a, a, 90, 90, 90, 90) {
        name = "Квадрат";
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, a, b, A, B, A, B) {
        name = "Параллелограмм";
    }
};

class Rhombus : public Quadrilateral {
public:
    Rhombus(int a, int A, int B) : Quadrilateral(a, a, a, a, A, B, A, B) {
        name = "Ромб";
    }
};

void printInfo(Figure* base) {
    base->printInfo();
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

    Figure fig;
    printInfo(&fig);

    Triangle tri(10, 20, 30, 50, 60, 70);
    RightTriangle riTri1(10, 20, 30, 50, 60);
    RightTriangle riTri2(10, 20, 30, 50, 40);
    IsosTriangle isosTri(10, 20, 50, 60);
    EquilTriangle equTri(30);

    printInfo(&tri);
    printInfo(&riTri1);
    printInfo(&riTri2);
    printInfo(&isosTri);
    printInfo(&equTri);

    Quadrilateral qua(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rec(10, 20);
    Square squ(20);
    Parallelogram par(20, 30, 30, 40);
    Rhombus rom(30, 30, 40);

    printInfo(&qua);
    printInfo(&rec);
    printInfo(&squ);
    printInfo(&par);
    printInfo(&rom);

    return 0;
}