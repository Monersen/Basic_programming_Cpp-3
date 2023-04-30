#include <string>
#include <Windows.h>
#include <iostream>

using namespace std;


class Figure 
{
public:
    Figure() { set_sides_count(0); name = "Фигура"; } 
    int get_sides_count() { return sides_count; }
    string get_name() { return name; }  
protected:
    void set_sides_count(int a) { sides_count = a; }
    string name;
private:
    int sides_count; 
};
class Triangle : public Figure
{
public:
    Triangle() { set_sides_count(3); name = "Треугольник"; }  
};
class Quadrangle : public Figure
{
public:
    Quadrangle() { set_sides_count(4); name = "Четырехугольник"; }
};

int main(int argc, char** argv)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //setlocale(LC_ALL, "Russian");

    Figure f;
    Triangle t;
    Quadrangle q;

    cout << "Количество сторон: " << endl;
    cout << f.get_name() << ": " << f.get_sides_count() << endl;
    cout << t.get_name() << ": " << t.get_sides_count() << endl;
    cout << q.get_name() << ": " << q.get_sides_count() << endl;
}
