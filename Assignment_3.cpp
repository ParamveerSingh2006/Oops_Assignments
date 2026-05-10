#include "headers.h"

class DummySwap
{
private:
    int first = 10;
    int second = 20;

public:
    void print_data()
    {
        cout << "First: " << first << endl;
        cout << "Second: " << second << endl;
    }

    friend void swap(DummySwap &obj);
};

void swap(DummySwap &obj)
{
    int temp = obj.first;
    obj.first = obj.second;
    obj.second = temp;
}

class DummyAdd
{
private:
    int first;

public:
    DummyAdd(int data) : first(data) {}

    void print_data()
    {
        cout << "First: " << first << endl;
    }

    friend int add_data(DummyAdd &obj1, DummyAdd &obj2);
};

int add_data(DummyAdd &obj1, DummyAdd &obj2)
{
    return obj1.first + obj2.first;
}

inline int cube(int x)
{
    return x * x * x;
}

class DummyAlter
{
private:
    int first;

public:
    DummyAlter(int data) : first(data) {}

    void print_data()
    {
        cout << "First: " << first << endl;
    }

    friend void alterDataByReference(DummyAlter &obj);
    friend void alterDataByValue(DummyAlter obj);
};

void alterDataByReference(DummyAlter &obj)
{
    obj.first = -1;
}

void alterDataByValue(DummyAlter obj)
{
    obj.first = -1;
    cout << "Object copy of test2 altered value: ";
    cout << obj.first << endl;
}

void ques_1()
{
    class Rectangle
    {
    private:
        int height;
        int width;

    public:
        Rectangle(int height, int width) : height(height), width(width) {}

        ~Rectangle() {}

        void printArea()
        {
            cout << "Area: " << width * height << endl;
        }
    };

    Rectangle red(20, 30);
    Rectangle *blue = new Rectangle(21, 10);

    red.printArea();
    blue->printArea();

    delete blue;
}

void ques_2()
{
    DummySwap test;

    test.print_data();
    swap(test);
    test.print_data();
}

void ques_3()
{
    DummyAdd test1(10), test2(20);

    cout << "Added Data: " << add_data(test1, test2) << endl;
}

void ques_5()
{
    class Rectangle
    {
    private:
        int height;
        int width;

    public:
        Rectangle(int height, int width) : height(height), width(width) {}

        ~Rectangle() {}

        void printArea()
        {
            cout << "Area: " << width * height << endl;
        }
    };

    Rectangle arr[5] = {Rectangle(10, 20), Rectangle(15, 25), Rectangle(20, 30), Rectangle(25, 35), Rectangle(30, 40)};

    for (Rectangle rect : arr)
    {
        rect.printArea();
    }
}

void ques_6()
{
    cout << "Cube of 3 is: " << cube(3) << endl;
}

void ques_7()
{
    DummyAlter test1(20), test2(20);

    alterDataByReference(test1);
    test1.print_data();

    alterDataByValue(test2);
    test2.print_data();
}

int main()
{
    ques_1();
    ques_2();
    ques_3();
    ques_5();
    ques_6();
    ques_7();

    return 0;
}