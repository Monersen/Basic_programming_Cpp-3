#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;


class address
{
public:
    address();
    address(string city_1, string street_1, int house_1, int flat_1);
    string get_output_address();

private:
    string city;
    string street;
    int house;
    int flat;

};

address::address() {
    city = "Нет города";
    street = "Нет улицы";
    house = 0;
    flat = 0;
}


address::address(string city_1, string street_1, int house_1, int flat_1)
{
    city = city_1;
    street = street_1;
    house = house_1;
    flat = flat_1;
}

string address::get_output_address()
{
    return city + ", " + street + ", " + to_string(house) + ", " + to_string(flat);
}

int main(int argc, char** argv)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream fin("in.txt");
    ofstream fout("out.txt");
    if (fin.is_open())
    {

        int f_arr_size;
        fin >> f_arr_size;
        address* arrAddress = new address[f_arr_size];
        for (int i = 0; i < f_arr_size; i++)
        {
            string c, s;
            int h, f;
            fin >> c;
            fin >> s;
            fin >> h;
            fin >> f;
            address point(c, s, h, f);
            arrAddress[i] = point;
        }


        if (fout.is_open())
        {
            fout << f_arr_size << endl;
            for (int i = f_arr_size - 1; i >= 0; i--)
            {
                fout << arrAddress[i].get_output_address() << endl;
            }
            fout.close();
        }


        delete[] arrAddress;
        fin.close();

    }
    else
    {
        cout << "Файл не найден!" << endl;
    }

    return 0;
}