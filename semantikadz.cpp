// semantikadz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Book 
{
    char* at;
    char* txt;
    int pages;
    int year;
public:
    Book() = default;
    Book(const char* _at, const char* _txt, int _pgs, int _y)
    {
        at = new char[strlen(_at) + 1];
        strcpy_s(at, strlen(_at) + 1, _at);
        txt = new char[strlen(_txt) + 1];
        strcpy_s(txt, strlen(_txt) + 1, _txt);
        pages = _pgs;
        year = _y;
    }
    Book& operator=(const Book& obj) = delete;
    Book(Book& obj) = delete;
    Book& operator=(Book&& obj)
    {
        at = obj.at;
        txt = obj.txt;
        pages = obj.pages;
        year = obj.year;
        obj.at = nullptr;
        obj.txt = nullptr;
        obj.pages = 0;
        obj.year = 0;
        return*this;
    }
    Book(Book&& obj)
    {
        at = obj.at;
        txt = obj.txt;
        pages = obj.pages;
        year = obj.year;
        obj.at = nullptr;
        obj.txt = nullptr;
        obj.pages = 0;
        obj.year = 0;
    }

    void Print() 
    {
        cout << at << endl << txt << endl << pages << endl << year << endl;
    }
};

int main()
{
    Book a("wassup", "wa", 51, 1);
    Book d = move(a);
    d.Print();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
