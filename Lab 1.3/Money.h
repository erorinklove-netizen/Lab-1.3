#pragma once
#include <string>

class Money
{
private:
    int b500;
    int b200;
    int b100;
    int b50;
    int b20;
    int b10;
    int b5;
    int b2;
    int b1;
    int c50;
    int c25;
    int c10;
    int c5;
    int c2;
    int c1;

    long long ToKopecks() const;
    void FromKopecks(long long kopecks);

public:
    int GetB500() const { return b500; }
    int GetB200() const { return b200; }
    int GetB100() const { return b100; }
    int GetB50() const { return b50; }
    int GetB20() const { return b20; }
    int GetB10() const { return b10; }
    int GetB5() const { return b5; }
    int GetB2() const { return b2; }
    int GetB1() const { return b1; }
    int GetC50() const { return c50; }
    int GetC25() const { return c25; }
    int GetC10() const { return c10; }
    int GetC5() const { return c5; }
    int GetC2() const { return c2; }
    int GetC1() const { return c1; }

    bool SetB500(int value);
    bool SetB200(int value);
    bool SetB100(int value);
    bool SetB50(int value);
    bool SetB20(int value);
    bool SetB10(int value);
    bool SetB5(int value);
    bool SetB2(int value);
    bool SetB1(int value);
    bool SetC50(int value);
    bool SetC25(int value);
    bool SetC10(int value);
    bool SetC5(int value);
    bool SetC2(int value);
    bool SetC1(int value);

    bool Init(int b500, int b200, int b100, int b50, int b20, int b10, int b5, int b2, int b1,
        int c50, int c25, int c10, int c5, int c2, int c1);
    void Read();
    void Display() const;
    std::string toString() const;

    Money Add(const Money& other) const;
    Money Subtract(const Money& other) const;
    Money Multiply(double factor) const;
};