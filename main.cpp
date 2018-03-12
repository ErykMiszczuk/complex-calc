#include <iostream>
#include <cmath>

using namespace std;

void compAdd();
void compSub();
void compMul();
void compDiv();

int main()
{
    int operation = 0;
    cout << "Welcome to complex calculator \n-----------------------------\n";
    cout << "What do you want to do now? \n(1) - Addition of two complex numbers\n(2) - Subtraction of two complex numbers\n(3) - Multiplication of two complex numbers\n(4) - Division of two complex numbers\nPlease enter number of math operation\n";
    cin >> operation;
    switch(operation) {
        case 1: cout << "Addition \n"; compAdd(); break;
        case 2: cout << "Subtraction \n"; compSub(); break;
        case 3: cout << "Multiplication \n"; compMul(); break;
        case 4: cout << "Division \n"; compDiv(); break;
        default: return 0; break;
    }
    cout << "\n\n";
    return 0;
}

void compAdd()
{
    int relA = 0, imA = 0, relB = 0, imB = 0;
    cout << "Number a real part:\n";
    cin >> relA;
    cout << "Number a imagine part:\n";
    cin >> imA;
    cout << "Number b real part:\n";
    cin >> relB;
    cout << "Number b imagine part:\n";
    cin >> imB;
    if (imA + imB < 0) {
        cout << relA + relB << " " << imA + imB << "i \n";
    } else {
        cout << relA + relB << " + " << imA + imB << "i \n";
    }
}

void compSub()
{
    int relA = 0, imA = 0, relB = 0, imB = 0;
    cout << "Number a real part:\n";
    cin >> relA;
    cout << "Number a imagine part:\n";
    cin >> imA;
    cout << "Number b real part:\n";
    cin >> relB;
    cout << "Number b imagine part:\n";
    cin >> imB;
    if (imA - imB < 0) {
        cout << relA - relB << " " << imA - imB << "i \n";
    } else {
        cout << relA - relB << " + " << imA - imB << "i \n";
    }
}

void compMul()
{
    int relA = 0, imA = 0, relB = 0, imB = 0, res1 = 0, res2 = 0, res3 = 0, res4 = 0;
    cout << "Number a real part:\n";
    cin >> relA;
    cout << "Number a imagine part:\n";
    cin >> imA;
    cout << "Number b real part:\n";
    cin >> relB;
    cout << "Number b imagine part:\n";
    cin >> imB;
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
    cout << "Number a real part:\n";
    cin >> relA;
    cout << "Number a imagine part:\n";
    cin >> imA;
    cout << "Number b real part:\n";
    cin >> relB;
    cout << "Number b imagine part:\n";
    cin >> imB;
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
