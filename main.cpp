#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

void compAdd();
void compSub();
void compMul();
void compDiv();
int testGnuplot();

int main()
{
    fstream in;
    fstream out;
    int i = 0;
    size_t findedString = 0;
    string relA = "", imA = "", relB = "", imB = "", token="", graph="", operation="";
    in.open("dane_projekt_1.csv", fstream::in);
    if (in.fail()) {
        cout<<"\nCannot open\n\n";
    } else {
        getline(in, token, '\n'); // skip header
        ++i;
        while(i == 2) {
            ++i;
            getline(in, token, ',');
            getline(in, relA, ',');
            getline(in, imA, ',');
            getline(in, relB, ',');
            getline(in, imB, ',');
            getline(in, graph, ',');
            getline(in, operation, ',');
            switch(operation) {
                case '+': cout << "Addition \n"; compAdd(); break;
                case '-': cout << "Subtraction \n"; compSub(); break;
                case '*': cout << "Multiplication \n"; compMul(); break;
                case '/': cout << "Division \n"; compDiv(); break;
                default: return 0; break;
            }
        }
        in.close();
    }
    cout << "\n\n";
    return 0;
}

void compAdd()
{
    int relA = 0, imA = 0, relB = 0, imB = 0;
    if (imA + imB < 0) {
        cout << relA + relB << " " << imA + imB << "i \n";
    } else {
        cout << relA + relB << " + " << imA + imB << "i \n";
    }
}

void compSub()
{
    int relA = 0, imA = 0, relB = 0, imB = 0;
    if (imA - imB < 0) {
        cout << relA - relB << " " << imA - imB << "i \n";
    } else {
        cout << relA - relB << " + " << imA - imB << "i \n";
    }
}

void compMul()
{
    int relA = 0, imA = 0, relB = 0, imB = 0, res1 = 0, res2 = 0, res3 = 0, res4 = 0;
    res1 = relA * relB;
    res2 = imA * imB;
    res3 = relA * imB;
    res4 = imB * relB;
    if (res3 + res4 > 0) {
        cout << res1 - res2 << " + " << res3 + res4 << "i \n";
    } else {
        cout << res1 - res2 << " " << res3 + res4 << "i \n";
    }
}

void compDiv()
{
    int relA = 0, imA = 0, relB = 0, imB = 0, res1 = 0, res2 = 0, res3 = 0, res4 = 0;
    res1 = relA * relB;  //ac
    res2 = imA * imB; //bd
    res3 = relA * imB; //ad
    res4 = imB * relB; //bc
    if (res4 - res3 > 0) {
        cout << res1 + res2 << " + " << res4 - res3 << "i \n------------------------\n" << pow(relB, 2) << " + " << pow(imB, 2);
    } else {
        cout << res1 + res2 << " " << res4 - res3 << "i \n------------------------\n" << pow(relB, 2) + pow(imB, 2);
    }
}

int testGnuplot() {
    int i;
    cout << "Checking if CMD is available... \n";
    if (system(NULL)) cout << "Ok \n";
        else exit (EXIT_FAILURE);
    cout << "Executing command plot...\n";
    i = system("gnuplot");
    cout << "The value returned was: " << i << ".\n";
    if (i = 1)
    {
        cout << "\nGnuplot is not available - please install it before using this program\n";
        return 1;
    }
    else
    {
        cout << "\nGnuplot is available - continue to use it";
        return 0;
    }
}

