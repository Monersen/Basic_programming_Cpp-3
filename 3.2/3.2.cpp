#include <iostream>
#include <windows.h>
using namespace std;

class Counter {
private:

    int count;

public:


    Counter(int a) {
        count = a;
    }

    void print_count() {
        cout << "Count: " << count << endl;
    }
    void increment() {
        this->count += 1;
    }
    void decrement() {
        this->count -= 1;
    }
};

int main()
{
    //setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string input;
    int start = 1;

    cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    cin >> input;

    if (input == "да") {
        cout << "Введите начальное значение счётчика: ";
        cin >> start;
    }

    Counter counter(start);

    do {
        cout << "Введите команду ('+', '-', '=' или 'x'): ";
        cin >> input;
        if (input == "+") {
            counter.increment();

        }
        if (input == "-") {
            counter.decrement();

        }
        if (input == "=") {
            counter.print_count();
        }
    } while (input != "x");

    cout << "До свидания!";

}