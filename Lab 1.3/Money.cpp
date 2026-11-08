#include "Money.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

long long Money::ToKopecks() const {
    return (long long)b500 * 50000 +
        (long long)b200 * 20000 +
        (long long)b100 * 10000 +
        (long long)b50 * 5000 +
        (long long)b20 * 2000 +
        (long long)b10 * 1000 +
        (long long)b5 * 500 +
        (long long)b2 * 200 +
        (long long)b1 * 100 +
        (long long)c50 * 50 +
        (long long)c25 * 25 +
        (long long)c10 * 10 +
        (long long)c5 * 5 +
        (long long)c2 * 2 +
        (long long)c1;
}

void Money::FromKopecks(long long kopecks) {
    if (kopecks < 0) kopecks = 0;

    b500 = (int)(kopecks / 50000); kopecks %= 50000;
    b200 = (int)(kopecks / 20000); kopecks %= 20000;
    b100 = (int)(kopecks / 10000); kopecks %= 10000;
    b50 = (int)(kopecks / 5000);  kopecks %= 5000;
    b20 = (int)(kopecks / 2000);  kopecks %= 2000;
    b10 = (int)(kopecks / 1000);  kopecks %= 1000;
    b5 = (int)(kopecks / 500);   kopecks %= 500;
    b2 = (int)(kopecks / 200);   kopecks %= 200;
    b1 = (int)(kopecks / 100);   kopecks %= 100;
    c50 = (int)(kopecks / 50);    kopecks %= 50;
    c25 = (int)(kopecks / 25);    kopecks %= 25;
    c10 = (int)(kopecks / 10);    kopecks %= 10;
    c5 = (int)(kopecks / 5);     kopecks %= 5;
    c2 = (int)(kopecks / 2);     kopecks %= 2;
    c1 = (int)(kopecks);
}

bool Money::SetB500(int v) { if (v >= 0) { b500 = v; return true; } b500 = 0; return false; }
bool Money::SetB200(int v) { if (v >= 0) { b200 = v; return true; } b200 = 0; return false; }
bool Money::SetB100(int v) { if (v >= 0) { b100 = v; return true; } b100 = 0; return false; }
bool Money::SetB50(int v) { if (v >= 0) { b50 = v; return true; } b50 = 0; return false; }
bool Money::SetB20(int v) { if (v >= 0) { b20 = v; return true; } b20 = 0; return false; }
bool Money::SetB10(int v) { if (v >= 0) { b10 = v; return true; } b10 = 0; return false; }
bool Money::SetB5(int v) { if (v >= 0) { b5 = v; return true; } b5 = 0; return false; }
bool Money::SetB2(int v) { if (v >= 0) { b2 = v; return true; } b2 = 0; return false; }
bool Money::SetB1(int v) { if (v >= 0) { b1 = v; return true; } b1 = 0; return false; }
bool Money::SetC50(int v) { if (v >= 0) { c50 = v; return true; } c50 = 0; return false; }
bool Money::SetC25(int v) { if (v >= 0) { c25 = v; return true; } c25 = 0; return false; }
bool Money::SetC10(int v) { if (v >= 0) { c10 = v; return true; } c10 = 0; return false; }
bool Money::SetC5(int v) { if (v >= 0) { c5 = v; return true; } c5 = 0; return false; }
bool Money::SetC2(int v) { if (v >= 0) { c2 = v; return true; } c2 = 0; return false; }
bool Money::SetC1(int v) { if (v >= 0) { c1 = v; return true; } c1 = 0; return false; }

bool Money::Init(int p500, int p200, int p100, int p50, int p20, int p10, int p5, int p2, int p1,
    int s50, int s25, int s10, int s5, int s2, int s1)
{
    return SetB500(p500) && SetB200(p200) && SetB100(p100) && SetB50(p50) &&
        SetB20(p20) && SetB10(p10) && SetB5(p5) && SetB2(p2) && SetB1(p1) &&
        SetC50(s50) && SetC25(s25) && SetC10(s10) && SetC5(s5) && SetC2(s2) && SetC1(s1);
}

void Money::Read()
{
    int p500, p200, p100, p50, p20, p10, p5, p2, p1, s50, s25, s10, s5, s2, s1;
    do {
        cout << "Vvedit kilkist kupyur ta monet:" << endl;
        cout << "  500 grn: "; cin >> p500;
        cout << "  200 grn: "; cin >> p200;
        cout << "  100 grn: "; cin >> p100;
        cout << "  50 grn:  "; cin >> p50;
        cout << "  20 grn:  "; cin >> p20;
        cout << "  10 grn:  "; cin >> p10;
        cout << "  5 grn:   "; cin >> p5;
        cout << "  2 grn:   "; cin >> p2;
        cout << "  1 grn:   "; cin >> p1;
        cout << "  50 kop.: "; cin >> s50;
        cout << "  25 kop.: "; cin >> s25;
        cout << "  10 kop.: "; cin >> s10;
        cout << "  5 kop.:  "; cin >> s5;
        cout << "  2 kop.:  "; cin >> s2;
        cout << "  1 kop.:  "; cin >> s1;
    } while (!Init(p500, p200, p100, p50, p20, p10, p5, p2, p1, s50, s25, s10, s5, s2, s1));
}

void Money::Display() const
{
    cout << toString() << endl;
}

string Money::toString() const
{
    long long totalKop = ToKopecks();
    long long hryvnias = totalKop / 100;
    long long kopecks = totalKop % 100;

    stringstream sout;
    sout << hryvnias << ",";
    if (kopecks < 10) sout << "0";
    sout << kopecks << " grn";
    return sout.str();
}

Money Money::Add(const Money& other) const
{
    Money res;
    long long sumKop = this->ToKopecks() + other.ToKopecks();
    res.FromKopecks(sumKop);
    return res;
}

Money Money::Subtract(const Money& other) const
{
    Money res;
    long long diffKop = this->ToKopecks() - other.ToKopecks();
    if (diffKop < 0) diffKop = 0;
    res.FromKopecks(diffKop);
    return res;
}

Money Money::Multiply(double factor) const
{
    Money res;
    long long multKop = (long long)round(this->ToKopecks() * factor);
    if (multKop < 0) multKop = 0;
    res.FromKopecks(multKop);
    return res;
}