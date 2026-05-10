#include "headers.h"

void ques_1()
{
    class Rectangle
    {
    private:
        int height;
        int width;

    public:
        Rectangle() : height(0), width(0) {}

        Rectangle(int height, int width) : height(height), width(width) {}

        Rectangle(int size) : height(size), width(size) {}

        ~Rectangle() {}

        void printArea()
        {
            cout << "Area: " << width * height << endl;
        }
    };

    Rectangle red;
    Rectangle green(10);
    Rectangle blue(25, 15);

    red.printArea();
    green.printArea();
    blue.printArea();
}

void ques_2()
{
    class Rectangle
    {
    private:
        int height;
        int width;

    public:
        Rectangle() : height(0), width(0) {}

        Rectangle(int height, int width) : height(height), width(width) {}

        Rectangle(int size) : height(size), width(size) {}

        ~Rectangle() {}

        void printArea()
        {
            cout << "Area: " << width * height << endl;
        }
    };

    Rectangle arr[5] = {Rectangle(10), Rectangle(), Rectangle(20, 30), Rectangle(25, 35), Rectangle(30)};

    for (Rectangle rect : arr)
    {
        rect.printArea();
    }
}

void ques_3()
{
    cout << "Verification of Destructor Rules in C++" << endl;

    cout << endl
         << "(i) Name should begin with tilde (~) and must match class name." << endl;
    cout << "Example: ~Demo() is correct for class Demo." << endl;

    cout << endl
         << "(ii) There cannot be more than one destructor in a class." << endl;
    cout << "Example: ~Sample() is correct, but ~Sample(int x) is wrong." << endl;

    cout << endl
         << "(iii) Destructors do not allow any parameter." << endl;
    cout << "Example: ~Example() is correct, but ~Example(int x) is wrong." << endl;

    cout << endl
         << "(iv) Destructors do not have any return type." << endl;
    cout << "Example: ~Test() is correct, but void ~Test() or int ~Test() is wrong." << endl;

    class DemoDestructor
    {
    public:
        DemoDestructor()
        {
            cout << endl
                 << "Constructor called" << endl;
        }

        ~DemoDestructor()
        {
            cout << "Destructor called" << endl;
        }
    };

    DemoDestructor obj;
}

void ques_4()
{
    class Rectangle
    {
    private:
        int height;
        int width;

    public:
        Rectangle() : height(0), width(0) {}

        Rectangle(int height, int width) : height(height), width(width) {}

        Rectangle(int size) : height(size), width(size) {}

        ~Rectangle() {}

        void printArea()
        {
            cout << "Area: " << width * height << endl;
        }
    };

    int *myInt = new int;
    float *myFloat = new float;
    int *intArr = new int[5];
    Rectangle *myRect = new Rectangle(20, 14);
    Rectangle *arr = new Rectangle[5];

    delete myInt;
    delete myFloat;
    delete[] intArr;
    delete myRect;
    delete[] arr;
}

int main()
{
    ques_1();
    ques_2();
    ques_3();
    ques_4();

    return 0;
}