#include <iostream>
#include <string>
#include <Windows.h>
 

using namespace std;


class Figure
{
protected:
    string name = "Фигура"; 
    int num_of_sides = 0;

public:
    string get_name() { return name; };
    int get_sides() { return num_of_sides; }
    virtual bool check() { return true; }
    virtual void print_info() {
        cout << get_name() << ":" << endl;
        if (check()) { cout << "Правильная" << endl; }
        else { cout << "Неправильная" << endl; }
        cout << "Количество сторон: " << get_sides() << endl;
    };

};

class Triangle : public Figure
{
public:
    Triangle() { a = b = c = 0; A = B = C = 0; }
    Triangle(int a_, int b_, int c_, int A_, int B_, int C_) 
    {
        a = a_;
        b = b_;
        c = c_;
        A = A_;
        B = B_;
        C = C_;
        name = "Треугольник";
        num_of_sides = 3;
    }
   
    bool check() override {
        if (A + B + C == 180) { return true; }
        else { return false; }
    }
    
    void print_info() override {
        Figure::print_info();
        cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << endl;
        cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << endl;
        cout << endl;
    }
   
    int get_a() { return a; };
    int get_b() { return b; };
    int get_c() { return c; };
    int get_A() { return A; };
    int get_B() { return B; };
    int get_C() { return C; };

protected:
    int a, b, c;
    int A, B, C;
};

class RightTriangle : public Triangle
{
public:
    RightTriangle(int a_, int b_, int c_, int A_, int B_)
    {
        a = a_;
        b = b_;
        c = c_;
        A = A_;
        B = B_;
        C = 90;
        name = "Прямоугольный треугольник";
        num_of_sides = 3;
    }
    
    bool check() override {
        if (Triangle::check() && C == 90) { return true; }
        else { return false; }
    }

};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int size_ac, int b_, int size_AC, int B_)
    {
        a = c = size_ac;
        b = b_;
        A = C = size_AC;
        B = B_;
        name = "Равнобедренный треугольник";
        num_of_sides = 3;
    }
    
    bool check() override {
        if (Triangle::check() && a == b && A == C) { return true; }
        else { return false; }
    }

};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(int sizes)
    {
        a = b = c = sizes;
        A = B = C = 60;
        name = "Равносторонний треугольник";
        num_of_sides = 3;
    }
    
    bool check() override {
        if (Triangle::check() && a == b && a == c && b == c && A == 60 && B == 60 && C == 60) { return true; }
        else { return false; }
    }
};

class Quadrangle : public Figure
{
public:
    Quadrangle() { a = b = c = d = 0; A = B = C = D = 0; }
    Quadrangle(int a_, int b_, int c_, int d_, int A_, int B_, int C_, int D_) 
    {
        a = a_;
        b = b_;
        c = c_;
        d = d_;
        A = A_;
        B = B_;
        C = C_;
        D = D_;
        name = "Четырехугольник";
        num_of_sides = 4;
    }
    
    bool check() override {
        if (A + B + C + D == 360) { return true; }
        else { return false; }
    }
    
    void print_info() override {
        Figure::print_info();
        cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << endl;
        cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << endl;
        cout << endl;
    }
    
    int get_a() { return a; };
    int get_b() { return b; };
    int get_c() { return c; };
    int get_d() { return d; };
    int get_A() { return A; };
    int get_B() { return B; };
    int get_C() { return C; };
    int get_D() { return D; };

protected:
    int a, b, c, d;
    int A, B, C, D;
};

class RectangleF : public Quadrangle
{
public:
    RectangleF(int a_, int b_) {
        a = c = a_;
        b = d = b_;
        A = B = C = D = 90;
        name = "Прямоугольник";
        num_of_sides = 4;
    }
   
    bool check() override {
        if (Quadrangle::check() && a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90) { return true; }
        else { return false; }
    }
};

class Square : public Quadrangle
{
public:
    Square(int a_) {
        a = c = b = d = a_;
        A = B = C = D = 90;
        name = "Квадрат";
        num_of_sides = 4;
    }
  
    bool check() override {
        if (Quadrangle::check() && a == c && b == d && a == b && A == 90 && B == 90 && C == 90 && D == 90) { return true; }
        else { return false; }
    }
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int a_, int b_, int A_, int B_) {
        a = c = a_;
        b = d = b_;
        A = C = A_;
        B = D = B_;
        name = "Параллелограмм";
        num_of_sides = 4;
    }
   
    bool check() override {
        if (Quadrangle::check() && a == c && b == d && A == C && B == D) { return true; }
        else { return false; }
    }
};

class Rhomb : public Quadrangle
{
public:
    Rhomb(int a_, int A_, int B_) {
        a = c = b = d = a_;
        A = C = A_;
        B = D = B_;
        name = "Ромб";
        num_of_sides = 4;
    }
  
    bool check() override {
        if (Quadrangle::check() && a == c && b == d && a == b && A == C && B == D) { return true; }
        else { return false; }
    }
};



int main(int argc, char** argv)
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
  //  setlocale(LC_ALL, "Russian");

  
    Figure f;
    f.print_info();
    cout << endl;   
    Triangle t(10, 20, 30, 50, 60, 70);
    t.print_info();  
    RightTriangle rt(10, 20, 30, 50, 60);
    rt.print_info();
    IsoscelesTriangle i(10, 20, 50, 60);
    i.print_info();
    EquilateralTriangle e(30);
    e.print_info();
    Quadrangle q(10, 20, 30, 40, 50, 60, 70, 80);
    q.print_info();
    RectangleF rf(10, 20);
    rf.print_info();
    Square s(20);
    s.print_info();
    Parallelogram p(20, 30, 30, 40);
    p.print_info();
    Rhomb romb(30, 30, 40);
    romb.print_info();

    return 0;
}