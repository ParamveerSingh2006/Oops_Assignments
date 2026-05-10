#include "headers.h"

void printstr(const char arr[])
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        cout << arr[i];
    }
}

class Test
{
public:
    static int val;
    void show();
};

void Test::show()
{
    cout << "Function declared outside class with scope" << endl;
}

int x = 15;
int Test::val = 10;

namespace First
{
    int value = 10;
    void display()
    {
        cout << "First namespace value = " << value << endl;
    }
}

namespace Second
{
    int value = 20;
    void display()
    {
        cout << "Second namespace value = " << value << endl;
    }
}

void ques_1()
{
    struct Student
    {
        char name[20];
        char degree[30];
        char hostel[10];
        int roll_no;
        float cgpa;

        void addDetails(const char n[], const char d[], const char h[], int r, float c)
        {
            strcpy(name, n);
            strcpy(degree, d);
            strcpy(hostel, h);
            roll_no = r;
            cgpa = c;
        }

        void updateDetails(const char n[], const char d[], const char h[], int r, float c)
        {
            addDetails(n, d, h, r, c);
        }

        void updateCGPA(float cgpa)
        {
            this->cgpa = cgpa;
        }

        void displayDetails()
        {
            cout << "Name: ";
            printstr(name);
            cout << endl;
            cout << "RollNo: " << roll_no << endl;
            cout << "Degree: ";
            printstr(degree);
            cout << endl;
            cout << "Hostel: ";
            printstr(hostel);
            cout << endl;
            cout << "cgpa: " << cgpa << endl;
        }
    };

    Student Nischey;
    Nischey.addDetails("Nishchey", "ENC", "HOSTEL-D", 1024150237, 9.2);
    Nischey.displayDetails();
}

void ques_2()
{
    class Student
    {
        char name[20];
        char degree[30];
        char hostel[10];
        int roll_no;
        float cgpa;

        void addDetails(const char n[], const char d[], const char h[], int r, float c)
        {
            strcpy(name, n);
            strcpy(degree, d);
            strcpy(hostel, h);
            roll_no = r;
            cgpa = c;
        }

    public:
        void updateDetails(const char n[], const char d[], const char h[], int r, float c)
        {
            addDetails(n, d, h, r, c);
        }

        void updateCGPA(float cgpa)
        {
            this->cgpa = cgpa;
        }

        void displayDetails()
        {
            cout << "Name: ";
            printstr(name);
            cout << endl;
            cout << "RollNo: " << roll_no << endl;
            cout << "Degree: ";
            printstr(degree);
            cout << endl;
            cout << "Hostel: ";
            printstr(hostel);
            cout << endl;
            cout << "cgpa: " << cgpa << endl;
        }
    };

    Student Nischey;
    Nischey.updateDetails("Nishchey", "ENC", "HOSTEL-D", 1024150237, 9.2);
    Nischey.displayDetails();
}

void ques_3()
{
    class Rectangle
    {
        int height, width;

    public:
        void getdata(int height, int width)
        {
            this->height = height;
            this->width = width;
        }

        int calculateArea()
        {
            return height * width;
        }
    };

    Rectangle red;
    red.getdata(4, 5);
    cout << "Area: " << red.calculateArea() << endl;
}

void ques_4()
{
    class Complex
    {
        float real, imaginary;

    public:
        Complex(float r, float i)
        {
            real = r;
            imaginary = i;
        }

        void setComplex(float real, float imaginary)
        {
            this->real = real;
            this->imaginary = imaginary;
        }

        void displayComplex()
        {
            string sign = (imaginary >= 0) ? "+" : "-";
            cout << real << sign << "i" << imaginary << endl;
        }

        Complex operator+(const Complex &other)
        {
            return Complex(real + other.real, imaginary + other.imaginary);
        }

        Complex operator-(const Complex &other)
        {
            return Complex(real - other.real, imaginary - other.imaginary);
        }
    };

    Complex first(3, 4);
    Complex second(4, 7);

    Complex result = second - first;

    first.displayComplex();
    second.displayComplex();
    result.displayComplex();
}

void ques_5()
{
    int x = 10;

    cout << Test::val << endl;

    cout << "Local: " << x << endl;
    cout << "Global:" << ::x << endl;

    Test test;
    test.show();

    std::cout << "Hello there" << std::endl;
}

void ques_6()
{
    First::display();
    Second::display();

    cout << First::value << endl;
    cout << Second::value << endl;
}

void ques_7()
{
    enum class Suit
    {
        HEARTS,
        CLUBS,
        SPADES,
        DIAMONDS,
        INVALID
    };

    class Card
    {
    private:
        int rank;
        Suit symbol;

        int generateRank()
        {
            return (rand() % 13) + 1;
        }

        Suit generateSuit()
        {
            switch ((rand() % 4) + 1)
            {
            case 1:
                return Suit::CLUBS;
            case 2:
                return Suit::DIAMONDS;
            case 3:
                return Suit::HEARTS;
            case 4:
                return Suit::SPADES;
            }
            return Suit::INVALID;
        }

        string rankToString(int rank) const
        {
            switch (rank)
            {
            case 1:
                return "ACE";
            case 11:
                return "JACK";
            case 12:
                return "QUEEN";
            case 13:
                return "KING";
            default:
                return to_string(rank);
            }
        }

        string suitToString(Suit suit)
        {
            switch (suit)
            {
            case Suit::CLUBS:
                return "CLUBS";
            case Suit::HEARTS:
                return "HEARTS";
            case Suit::SPADES:
                return "SPADES";
            case Suit::DIAMONDS:
                return "DIAMONDS";
            default:
                return "INVALID";
            }
        }

        string suitToColor(Suit suit)
        {
            return (suit == Suit::CLUBS || suit == Suit::SPADES) ? "BLACK" : "RED";
        }

    public:
        Card(int rank, Suit suit)
        {
            this->rank = rank;
            this->symbol = suit;
        }

        Card()
        {
            this->rank = generateRank();
            this->symbol = generateSuit();
        }

        void display()
        {
            cout << "Rank: " << rankToString(this->rank) << endl;
            cout << "Suit: " << suitToString(this->symbol) << endl;
            cout << "Color: " << suitToColor(this->symbol) << endl;
        }
    };

    srand(time(0));

    Card randomCard;
    randomCard.display();
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

    return 0;
}