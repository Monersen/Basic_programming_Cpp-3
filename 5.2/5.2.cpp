#include <iostream>
#include <string>

using namespace std;

class Figure {
private:
    string name;


protected:
    Figure(string name) {
        this->name = name;
    }

    virtual void print_sides() {

    }

    virtual void print_angles() {

    }
public:
    void print() {
        cout << name << ":" << endl;
        cout << "Стороны: ";
        print_sides();
        cout << endl;
        cout << "Углы: ";
        print_angles();
    }

};

class Triangle : public Figure {
public:
    Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC, string nameTriangle) : Figure(nameTriangle) {
        this->sideA = sideA;
        this->sideB = sideB;
        this->sideC = sideC;

        this->angleA = angleA;
        this->angleB = angleB;
        this->angleC = angleC;
    }

protected:
    void print_sides() override {
        cout << "a = " << sideA << " b = " << sideB << " c = " << sideC;
    }

    void print_angles() override {
        cout << "A = " << angleA << " B = " << angleB << " C = " << angleC;
    }

    int sideA, sideB, sideC;
    int angleA, angleB, angleC;
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int sideA, int sideB, int sideC, int angleA, int angleB, string nameTriangle) : Triangle(sideA, sideB, sideC, angleA, angleB, 90, nameTriangle) {}

protected:
    void print_sides() override {
        cout << "a = " << sideA << " b = " << sideB << " c = " << sideC;
    }

    void print_angles() override {
        cout << "A = " << angleA << " B = " << angleB << " C = " << angleC;
    }

};

class Isosceles : public Triangle {
public:
    Isosceles(int sideA, int sideB, int angleA, int angleB, string nameTriangle) : Triangle(sideA, sideB, sideA, angleA, angleB, angleA, nameTriangle) {}

protected:
    void print_sides() override {
        cout << "a = " << sideA << " b = " << sideB << " c = " << sideC;
    }

    void print_angles() override {
        cout << "A = " << angleA << " B = " << angleB << " C = " << angleC;
    }
};

class Equilateral : public Isosceles {
public:
    Equilateral(int sideA, string nameTriangle) : Isosceles(sideA, sideA, 60, 60, nameTriangle) {}

protected:
    void print_sides() override {
        cout << "a = " << sideA << " b = " << sideB << " c = " << sideC;
    }

    void print_angles() override {
        cout << "A = " << angleA << " B = " << angleB << " C = " << angleC;
    }

};

class Quadrilateral : public Figure {
public:
    Quadrilateral(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD, string nameQuadrilateral) : Figure(nameQuadrilateral) {
        this->sideA = sideA;
        this->sideB = sideB;
        this->sideC = sideC;
        this->sideD = sideD;

        this->angleA = angleA;
        this->angleB = angleB;
        this->angleC = angleC;
        this->angleD = angleD;
    }

protected:
    void print_sides() override {
        cout << "a = " << sideA << " b = " << sideB << " c = " << sideC << " d = " << sideD;
    }

    void print_angles() override {
        cout << "A = " << angleA << " B = " << angleB << " C = " << angleC << " D = " << angleD;
    }

    int sideA, sideB, sideC, sideD;
    int angleA, angleB, angleC, angleD;
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int sideA, int sideB, int angleA, int angleB, string nameQuadrilateral) : Quadrilateral(sideA, sideB, sideA, sideB, angleA, angleB, angleA, angleB, nameQuadrilateral) {}

protected:
    void print_sides() override {
        cout << "a = " << sideA << " b = " << sideB << " c = " << sideC << " d = " << sideD;
    }

    void print_angles() override {
        cout << "A = " << angleA << " B = " << angleB << " C = " << angleC << " D = " << angleD;
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int sideA, int angleA, int angleB, string nameQuadrilateral) : Parallelogram(sideA, sideA, angleA, angleB, nameQuadrilateral) {}

protected:
    void print_sides() override {
        cout << "a = " << sideA << " b = " << sideB << " c = " << sideC << " d = " << sideD;
    }

    void print_angles() override {
        cout << "A = " << angleA << " B = " << angleB << " C = " << angleC << " D = " << angleD;
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(int sideA, int sideB, string nameQuadrilateral) : Parallelogram(sideA, sideB, 90, 90, nameQuadrilateral) {}

protected:
    void print_sides() override {
        cout << "a = " << sideA << " b = " << sideB << " c = " << sideC << " d = " << sideD;
    }

    void print_angles() override {
        cout << "A = " << angleA << " B = " << angleB << " C = " << angleC << " D = " << angleD;
    }
};

class Square : public Rhombus {
public:
    Square(int sideA, string nameQuadrilateral) : Rhombus(sideA, 90, 90, nameQuadrilateral) {}

protected:

    void print_sides() override {
        cout << "a = " << sideA << " b = " << sideB << " c = " << sideC << " d = " << sideD;
    }

    void print_angles() override {
        cout << "A = " << angleA << " B = " << angleB << " C = " << angleC << " D = " << angleD;
    }
};

void print(Figure& figure) {
    figure.print();
    cout << endl;
    cout << endl;
}

int main(int argc, char** argv) {
    
    setlocale(LC_ALL, "Russian");

    Triangle trian(10, 20, 30, 50, 60, 70, "Треугольник");
    RightTriangle right(10, 20, 30, 50, 60, "Прямоугольный треугольник");
    Isosceles isos(10, 20, 50, 60, "Равнобедренный треугольник:");
    Equilateral equil(10, "Равносторонний треугольник:");
    Quadrilateral quad(10, 20, 30, 40, 50, 60, 70, 80, "Четырёхугольник:");
    Rectangle rect(10, 20, "Прямоугольник:");
    Square square(20, "Квадрат:");
    Parallelogram parall(20, 30, 30, 40, "Параллелограмм:");
    Rhombus rhombus(30, 30, 40, "Ромб:");

    print(trian);
    print(right);
    print(isos);
    print(equil);
    print(quad);
    print(rect);
    print(square);
    print(parall);
    print(rhombus);

   
    return 0;
}