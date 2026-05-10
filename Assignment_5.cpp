#include "headers.h"

void ques_1()
{
    class Parent
    {
    protected:
        string familySecret = "We are very rich";
    };

    class Child : public Parent
    {
    public:
        void spillFamilySecret()
        {
            cout << familySecret << endl;
        }
    };

    Child child;
    child.spillFamilySecret();
}

void ques_2()
{
    class Parent
    {
    private:
        string personalSecret = "I lost my wallet with my ID.";

    protected:
        string familySecret = "We are very rich.";

    public:
        string noSecret = "They have a weird family.";
    };

    class CloseChild : public Parent
    {
    public:
        void spillFamilySecrets()
        {
            cout << "CloseChild: " << familySecret << endl;
        }
    };

    class MiddleChild : protected Parent
    {
    public:
        void spillFamilySecrets()
        {
            cout << "MiddleChild: " << familySecret << endl;
        }
    };

    class NeighboursChild : private Parent
    {
    public:
        void spillFamilySecrets()
        {
            cout << "NeighboursChild: " << noSecret << endl;
        }
    };

    CloseChild closeChild;
    MiddleChild middleChild;
    NeighboursChild neighbor;

    closeChild.spillFamilySecrets();
    middleChild.spillFamilySecrets();
    neighbor.spillFamilySecrets();

    cout << "Access from main: " << closeChild.noSecret << endl;
}

void ques_3()
{
    class Base
    {
    public:
        Base()
        {
            cout << "Base Constructor Called" << endl;
        }

        ~Base()
        {
            cout << "Base Destructor Called" << endl;
        }
    };

    class Derived : public Base
    {
    public:
        Derived()
        {
            cout << "Derived Constructor Called" << endl;
        }

        ~Derived()
        {
            cout << "Derived Destructor Called" << endl;
        }
    };

    Derived obj;
}

void ques_4()
{
    cout << "Single Inheritance:" << endl;

    class Parent1
    {
    public:
        int money = 203948;
    };

    class Child1 : public Parent1
    {
    };

    Child1 child1;
    cout << child1.money << endl;

    cout << endl
         << "Multiple Inheritance:" << endl;

    class Mother
    {
    protected:
        int money = 203948;
    };

    class Father
    {
    protected:
        int money = 123948;
    };

    class Child2 : public Mother, public Father
    {
    public:
        int money = Mother::money + Father::money;
    };

    Child2 child2;
    cout << child2.money << endl;

    cout << endl
         << "Multilevel Inheritance:" << endl;

    class GrandFather
    {
    protected:
        int money;

    public:
        GrandFather()
        {
            money = 20;
        }
    };

    class Father2 : protected GrandFather
    {
    protected:
        int money;

    public:
        Father2()
        {
            money = 20 + GrandFather::money;
        }
    };

    class Child3 : protected Father2
    {
    public:
        int money;

        Child3()
        {
            money = 15 + Father2::money;
        }

        void checkBalance()
        {
            cout << "I have $" << money << endl;
        }
    };

    Child3 child3;
    child3.checkBalance();

    cout << endl
         << "Hierarchal Inheritance:" << endl;

    class LibraryUser
    {
    protected:
        string name;
        int id;
        string contact;

    public:
        LibraryUser(string name, int id, string contact)
        {
            this->name = name;
            this->id = id;
            this->contact = contact;
        }

        void displayUserInfo()
        {
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Contact: " << contact << endl;
        }
    };

    class Student1 : public LibraryUser
    {
    private:
        string gradeLevel;

    public:
        Student1(string name, int id, string contact, string gradelevel) : LibraryUser(name, id, contact)
        {
            gradeLevel = gradelevel;
        }

        void displayStudentInfo()
        {
            displayUserInfo();
            cout << "Grade Level: " << gradeLevel << endl;
        }
    };

    class Teacher : public LibraryUser
    {
    private:
        string department;

    public:
        Teacher(string name, int id, string contact, string dept) : LibraryUser(name, id, contact)
        {
            department = dept;
        }

        void displayTeacherInfo()
        {
            displayUserInfo();
            cout << "Department: " << department << endl;
        }
    };

    cout << "Student Details:" << endl;
    Student1 s1("Rahul Sharma", 101, "9876543210", "3rd Year");
    s1.displayStudentInfo();

    cout << endl
         << "Teacher Details:" << endl;
    Teacher t1("Dr. Mehta", 201, "9123456780", "Computer Science");
    t1.displayTeacherInfo();

    cout << endl
         << "Hybrid Inheritance:" << endl;

    class Device
    {
    public:
        void printDeviceDetails()
        {
            cout << "--------------" << endl;
            cout << "Power: 25W" << endl;
            cout << "Voltage: 5V" << endl;
            cout << "Amperage: 0.5A" << endl;
            cout << "--------------" << endl;
        }
    };

    class Phone : virtual public Device
    {
    public:
        void printPhoneDetails()
        {
            cout << "--------------" << endl;
            cout << "Gen: 5G" << endl;
            cout << "Plan: Unlimited" << endl;
            cout << "Technology: Volte" << endl;
            cout << "--------------" << endl;
        }
    };

    class Camera : virtual public Device
    {
    public:
        void printCameraDetails()
        {
            cout << "--------------" << endl;
            cout << "Aperture: 2.5" << endl;
            cout << "ISO: 500" << endl;
            cout << "Shutter: 1/20" << endl;
            cout << "--------------" << endl;
        }
    };

    class SmartPhone : public Camera, public Phone
    {
    };

    SmartPhone apple;
    apple.printDeviceDetails();
    apple.printPhoneDetails();
    apple.printCameraDetails();
}

void ques_5()
{
    class Book
    {
    protected:
        string title;
        string author;
        double price;

    public:
        Book(string t, string a, double p)
        {
            title = t;
            author = a;
            price = p;
        }

        void displayBookInfo()
        {
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Price: $" << price << endl;
        }
    };

    class Textbook : public Book
    {
    private:
        string subject;

    public:
        Textbook(string t, string a, double p, string s) : Book(t, a, p)
        {
            subject = s;
        }

        void displayTextbookInfo()
        {
            displayBookInfo();
            cout << "Subject: " << subject << endl;
        }
    };

    cout << "General Book:" << endl;
    Book b1("The Alchemist", "Paulo Coelho", 499);
    b1.displayBookInfo();

    cout << endl
         << "Textbook:" << endl;
    Textbook t1("Engineering Mathematics", "B.S. Grewal", 799, "Mathematics");
    t1.displayTextbookInfo();
}

void ques_6()
{
    class Speedometer
    {
    public:
        void speedDetails()
        {
            cout << "------------" << endl;
            cout << "Speed: 70 Km/Hr" << endl;
            cout << "------------" << endl;
        }
    };

    class FuelGuage
    {
    public:
        void fuelDetails()
        {
            cout << "------------" << endl;
            cout << "Range: 86 Km" << endl;
            cout << "------------" << endl;
        }
    };

    class Thermometer
    {
    public:
        void thermalDetails()
        {
            cout << "------------" << endl;
            cout << "Temprature: Optimal" << endl;
            cout << "------------" << endl;
        }
    };

    class DashBoard : public Speedometer, public FuelGuage, public Thermometer
    {
    public:
        void viewDash()
        {
            speedDetails();
            fuelDetails();
            thermalDetails();
        }
    };

    DashBoard dash;
    dash.viewDash();
}

void ques_7()
{
    class Vehicle
    {
    protected:
        string make;
        string model;
        int year;

    public:
        Vehicle(string mk, string md, int yr) : make(mk), model(md), year(yr) {}

        void displayVehicleInfo() const
        {
            cout << "Make: " << make << endl;
            cout << "Model: " << model << endl;
            cout << "Year: " << year << endl;
        }

        virtual ~Vehicle() {}
    };

    class Truck : public Vehicle
    {
    protected:
        double load_capacity;

    public:
        Truck(string mk, string md, int yr, double lc) : Vehicle(mk, md, yr), load_capacity(lc) {}

        void displayTruckInfo() const
        {
            displayVehicleInfo();
            cout << "Load Capacity: " << load_capacity << " tons" << endl;
        }
    };

    class RefrigeratedTruck : public Truck
    {
    private:
        double temperature_control;

    public:
        RefrigeratedTruck(string mk, string md, int yr, double lc, double temp)
            : Truck(mk, md, yr, lc), temperature_control(temp) {}

        void displayRefrigeratedTruckInfo() const
        {
            displayTruckInfo();
            cout << "Temperature Control: " << temperature_control << " C" << endl;
        }
    };

    cout << "Truck Details:" << endl;
    Truck t1("Tata", "LPT 1613", 2022, 10);
    t1.displayTruckInfo();

    cout << endl
         << "Refrigerated Truck Details:" << endl;
    RefrigeratedTruck rt1("Volvo", "F12", 2023, 15, -5);
    rt1.displayRefrigeratedTruckInfo();
}

void ques_8()
{
    class Person
    {
    protected:
        string name;
        string address;

    public:
        Person(string n, string a) : name(n), address(a) {}

        void displayPerson() const
        {
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;
        }
    };

    class Staff : virtual public Person
    {
    protected:
        int employee_id;
        string department;

    public:
        Staff(string n, string a, int eid, string dept) : Person(n, a), employee_id(eid), department(dept) {}

        void displayStaff() const
        {
            cout << "Employee ID: " << employee_id << endl;
            cout << "Department: " << department << endl;
        }
    };

    class Student : virtual public Person
    {
    protected:
        int student_id;
        string grade;

    public:
        Student(string n, string a, int sid, string g) : Person(n, a), student_id(sid), grade(g) {}

        void displayStudent() const
        {
            cout << "Student ID: " << student_id << endl;
            cout << "Grade: " << grade << endl;
        }
    };

    class TeachingAssistant : public Staff, public Student
    {
    public:
        TeachingAssistant(string n, string a, int eid, string dept, int sid, string g)
            : Person(n, a), Staff(n, a, eid, dept), Student(n, a, sid, g) {}

        void displayTA() const
        {
            displayPerson();
            displayStaff();
            displayStudent();
        }
    };

    TeachingAssistant ta("Rahul Sharma", "Delhi", 5001, "Computer Science", 22001, "A");

    ta.displayTA();
}

void ques_9()
{
    class Parent
    {
    public:
        void say()
        {
            cout << "Parent has been called." << endl;
        }

        void work()
        {
            cout << "Only the parent will work" << endl;
        }
    };

    class Child : public Parent
    {
    public:
        void say()
        {
            cout << "Child has been called." << endl;
        }

        void work()
        {
            cout << "Only the parent will work" << endl;
        }
    };

    Parent superclass;
    Child derivedclass;

    superclass.say();
    derivedclass.say();

    superclass.work();
    derivedclass.work();
}

void ques_10()
{
    class Animal
    {
    public:
        void whatIsIt()
        {
            cout << "It is an animal." << endl;
        }

        void speak()
        {
            cout << "The Animal Made a Noise." << endl;
        }
    };

    class Duck : public Animal
    {
    public:
        void speak()
        {
            cout << "Quack!!" << endl;
        }
    };

    class Cat : public Animal
    {
    public:
        void speak()
        {
            cout << "Meow!!" << endl;
        }
    };

    class Dog : public Animal
    {
    public:
        void speak()
        {
            cout << "Woof!!" << endl;
        }
    };

    Dog snoopy;
    Cat ginger;
    Duck donald;

    snoopy.whatIsIt();
    ginger.whatIsIt();
    donald.whatIsIt();

    snoopy.speak();
    ginger.speak();
    donald.speak();
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
    ques_9();
    ques_10();

    return 0;
}