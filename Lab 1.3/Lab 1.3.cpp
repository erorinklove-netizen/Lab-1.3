#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include "Money.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    cout << "=== DEMONSTRATION OF MONEY CLASS ===" << endl << endl;

    cout << "1. Entering the first object (m1) from keyboard:" << endl;
    Money m1;
    m1.Read();
    cout << "Object m1: ";
    m1.Display();
    cout << endl;

    cout << "2. Creating the second object (m2) using Init():" << endl;
    Money m2;
    m2.Init(0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0);
    cout << "Object m2: " << m2.toString() << endl << endl;

    cout << "3. Arithmetic operations:" << endl;
    Money mSum = m1.Add(m2);
    cout << "m1 + m2 = " << mSum.toString() << endl;

    Money mSub = m1.Subtract(m2);
    cout << "m1 - m2 = " << mSub.toString() << endl;

    double factor = 1.5;
    Money mMult = m1.Multiply(factor);
    cout << "m1 * " << factor << " = " << mMult.toString() << endl << endl;

    cout << "4. Creating dynamic object:" << endl;
    Money* pMoney = new Money();
    pMoney->Init(2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    cout << "Dynamic object: " << pMoney->toString() << endl;
    delete pMoney;
    cout << endl;

    cout << "5. Working with an array of objects:" << endl;
    Money arr[2];
    arr[0].Init(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    arr[1].Init(0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);

    for (int i = 0; i < 2; i++) {
        cout << "arr[" << i << "] = " << arr[i].toString() << endl;
    }

    cout << "\nProgram finished successfully." << endl;
    return 0;
}