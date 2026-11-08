#include "pch.h"
#include "CppUnitTest.h"
#include "../Money.h"

#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MoneyTests
{
    TEST_CLASS(MoneyTests)
    {
    public:

        TEST_METHOD(TestInitAndGetters)
        {
            Money m;
            bool res = m.Init(0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);

            Assert::IsTrue(res);
            Assert::AreEqual(1, m.GetB100());
            Assert::AreEqual(2, m.GetC50());
            Assert::AreEqual(0, m.GetB500());
        }

        TEST_METHOD(TestSettersValidation)
        {
            Money m;
            bool valid = m.SetB500(5);
            Assert::IsTrue(valid);
            Assert::AreEqual(5, m.GetB500());

            bool invalid = m.SetB500(-3);
            Assert::IsFalse(invalid);
            Assert::AreEqual(0, m.GetB500());
        }

        TEST_METHOD(TestToString)
        {
            Money m;
            m.Init(0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0);

            std::string expected = "1,50 grn";
            Assert::AreEqual(expected, m.toString());
        }

        TEST_METHOD(TestAdd)
        {
            Money m1, m2;
            m1.Init(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            m2.Init(0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0);

            Money sum = m1.Add(m2);
            Assert::AreEqual(std::string("150,50 grn"), sum.toString());
        }

        TEST_METHOD(TestSubtract)
        {
            Money m1, m2;
            m1.Init(0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            m2.Init(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

            Money diff = m1.Subtract(m2);
            Assert::AreEqual(std::string("100,00 grn"), diff.toString());
        }

        TEST_METHOD(TestMultiply)
        {
            Money m;
            m.Init(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

            Money mult = m.Multiply(1.5);
            Assert::AreEqual(std::string("150,00 grn"), mult.toString());
        }
    };
}