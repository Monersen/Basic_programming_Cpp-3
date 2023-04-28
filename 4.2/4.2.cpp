#include <fstream>
#include <string>
#include <iostream>

using namespace std;


class address
{

private:
    string city;
    string street;
    int house;
    int flat;

public:
    address();
    address(string city_1, string street_1, int house_1, int flat_1);
    string get_output_address();
    string get_city() { return city; }

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


void sort(address* addresses, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
        {
            string s1 = addresses[i].get_city();
            string s2 = addresses[j].get_city();

            if (s1 > s2)
            {
                address temp = addresses[i];
                addresses[i] = addresses[j];
                addresses[j] = temp;
            }
        }
}

int main(int argc, char** argv)
{

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
        sort(arrAddress, f_arr_size);


        if (fout.is_open())
        {
            fout << f_arr_size << endl;
            for (int i = 0; i < f_arr_size; i++)
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