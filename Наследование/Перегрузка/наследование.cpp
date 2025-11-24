#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

class igra {
protected:
    string nazvanie;
    string zhanr;
public:
    virtual void display() = 0;
    string result;
    igra() {
        nazvanie = "";
        zhanr = "";
    }
    ~igra() {};
};

class nastolnayaigra: public igra {
private:
    string igroki;
    string god;
public:
    nastolnayaigra() {
        igroki = "";
        god = "";
    }
    ~nastolnayaigra() {};
    void vvod() {
        cout << "Введите название: ";
        getline(cin, nazvanie);
        cout << "Введите Жанр: ";
        getline(cin, zhanr);
        cout << "Введите количество игроков: ";
        getline (cin, igroki);
        cout << "Введите год выпуска: ";
        getline (cin, god);
    }
    void display(){
        result = "Название: " + nazvanie + "\nЖанр: " + zhanr + "\nКоличество игроков: " + igroki + "\nГод выпуска: " + god + "\n";
    }
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    ofstream MyFile("Игры.txt", ios::app);
    ifstream File("Игры.txt");
    string s;
    while (getline(File, s)) {
        cout << s << endl;
    }
    File.close();
    cout << "_________________________________________________\n";
    string flag1 = "1";
    while (flag1 != "0") {
            MyFile << "_________________________________________________\n";
            MyFile << "Настольная игра\n";
            nastolnayaigra igra1;
            igra1.vvod();
            igra1.display();
            MyFile << igra1.result;
            cout << "Введите 0 что бы выйти или любое другое число что бы остаться: ";
            getline(cin, flag1);
    }
    cout << "Все данные храняться в файле Игры.txt";
    MyFile.close();
    return 0;
}