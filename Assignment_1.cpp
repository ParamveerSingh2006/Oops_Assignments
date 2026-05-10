#include "headers.h"

static double operation(double a, double b, char operation)
{
    switch (operation)
    {
    case '+':
        return a + b;

    case '-':
        return a - b;

    case '*':
        return a * b;

    case '/':
        if (b == 0)
        {
            cout << "Divide by 0 Error" << endl;
            return 0;
        }
        else
            return a / b;
        break;

    default:
        cout << "Unknown Operand" << endl;
        break;
    }

    return 0;
}

static float celcius_to_farenheit(float celcius)
{
    return ((9 * celcius) / 5.0) + 32;
}

static int late_fee(int days)
{
    if (days <= 5)
    {
        return 0;
    }

    if (days > 5 || days <= 10)
    {
        return 5;
    }

    if (days >= 30)
    {
        return -1;
    }

    return 0;
}

void ques_1()
{
    cout << "Hello World";
}

void ques_2()
{
    int first;
    double second;
    char third;

    cout << "Enter a Integer" << endl;
    cin >> first;

    cout << "Enter a decimal" << endl;
    cin >> second;

    cout << "Enter a character" << endl;
    cin >> third;

    cout << first << endl;
    cout << second << endl;
    cout << third << endl;
}

void ques_3()
{
    cout << operation(12, 6, '/');
}

void ques_4()
{
    cout << celcius_to_farenheit(32);
}

void ques_5()
{
    cout << "Hello World\n Hello World" << endl;
    cout << "Hello World\t Hello World" << endl;
    cout << "Hello World\b Hello World" << endl;
    cout << "Hello World\n Hello World" << endl;
}

void ques_6()
{
    int i = 0;

    i++;

    i += 5;

    i -= 3;

    cout << i << endl;
}

void ques_7()
{
    int a, b;

    cin >> a;
    cin >> b;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << a << endl;
    cout << b << endl;
}

void ques_8()
{
    int days;
    cin >> days;

    switch (late_fee(days))
    {
    case 0:
        cout << "Your fine is 50 paise";
        break;

    case 5:
        cout << "Your fine is 5 rupees";
        break;

    case -1:
        cout << "Your membership has been cancelled!!";
        break;

    default:
        cout << "Issue with input";
        break;
    }
}

void ques_10()
{
    int input;

    cout << "Enter a Integer: ";
    cin >> input;

    for (int i = 2; i <= sqrt(input); i++)
    {
        if (input % i == 0)
        {
            cout << "It is Composite: " << i;
            return;
        }
    }

    cout << "It is Prime";
}

int main()
{
    ques_1();
    ques_2();
    ques_3();
    ques_4();
    ques_5();
    ques_6();
    ques_7();
    ques_8();
    ques_10();

    return 0;
}