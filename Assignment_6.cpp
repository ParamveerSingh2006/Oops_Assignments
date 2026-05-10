#include "headers.h"
#define size 10

void ques_1()
{
    class Book
    {
    public:
        string title;
        string author;
        long ISBN;
    };

    class Library
    {
        Book collection[size];

    public:
        void init()
        {
            for (int i = 0; i < size; i++)
            {
                collection[i].author = "";
                collection[i].title = "";
                collection[i].ISBN = 0;
            }
        }

        bool addNewBook(string &title, string &author, long &ISBN)
        {
            for (int i = 0; i < size; i++)
            {
                if (collection[i].ISBN == 0)
                {
                    collection[i].title = title;
                    collection[i].author = author;
                    collection[i].ISBN = ISBN;
                    return true;
                }
            }
            return false;
        }

        bool removeBook(long &ISBN)
        {
            for (int i = 0; i < size; i++)
            {
                if (collection[i].ISBN == ISBN)
                {
                    collection[i].author = "";
                    collection[i].title = "";
                    collection[i].ISBN = 0;
                    return true;
                }
            }
            return false;
        }

        void displayDetails()
        {
            for (int i = 0; i < size; i++)
            {
                if (collection[i].ISBN != 0)
                {
                    cout << collection[i].title << " " << collection[i].author << " " << collection[i].ISBN << endl;
                }
            }
        }
    };

    Library lib;
    lib.init();

    string title, author;
    long ISBN;

    title = "title_1";
    author = "author_1";
    ISBN = 473658;
    lib.addNewBook(title, author, ISBN);

    title = "title_2";
    author = "author_2";
    ISBN = 472020;
    lib.addNewBook(title, author, ISBN);

    title = "title_3";
    author = "author_3";
    ISBN = 47239398;
    lib.addNewBook(title, author, ISBN);

    title = "title_4";
    author = "author_4";
    ISBN = 4723484;
    lib.addNewBook(title, author, ISBN);

    title = "title_5";
    author = "author_5";
    ISBN = 4734859;
    lib.addNewBook(title, author, ISBN);

    lib.displayDetails();

    ISBN = 472020;
    lib.removeBook(ISBN);

    cout << endl
         << "After removal:" << endl;
    lib.displayDetails();
}

void ques_2()
{
    class Book
    {
    public:
        string title;
        string author;
        long ISBN;

        Book() : title(""), author(""), ISBN(0) {}
    };

    class Library
    {
        Book *collection;
        int size;

    public:
        Library(int s) : size{s}
        {
            collection = new Book[size];
        }

        ~Library()
        {
            delete[] collection;
        }

        bool addNewBook(string &title, string &author, long &ISBN)
        {
            for (int i = 0; i < size; i++)
            {
                if (collection[i].ISBN == 0)
                {
                    collection[i].title = title;
                    collection[i].author = author;
                    collection[i].ISBN = ISBN;
                    return true;
                }
            }
            return false;
        }

        bool removeBook(long &ISBN)
        {
            for (int i = 0; i < size; i++)
            {
                if (collection[i].ISBN == ISBN)
                {
                    collection[i].title = "";
                    collection[i].author = "";
                    collection[i].ISBN = 0;
                    return true;
                }
            }
            return false;
        }

        void displayDetails()
        {
            for (int i = 0; i < size; i++)
            {
                if (collection[i].ISBN != 0)
                {
                    cout << collection[i].title << " "
                         << collection[i].author << " "
                         << collection[i].ISBN << endl;
                }
            }
        }
    };

    int n;

    cout << "Enter library size: ";
    cin >> n;

    Library lib(n);

    string title, author;
    long ISBN;

    title = "title_1";
    author = "author_1";
    ISBN = 111;
    lib.addNewBook(title, author, ISBN);

    title = "title_2";
    author = "author_2";
    ISBN = 222;
    lib.addNewBook(title, author, ISBN);

    lib.displayDetails();

    ISBN = 111;
    lib.removeBook(ISBN);

    cout << endl
         << "After removal" << endl;
    lib.displayDetails();
}

void ques_3()
{
    class Account
    {
        long acc_no;
        long trx_id;
        string trx_type;
        double balance;

    public:
        Account(long a_no, long id, string type, double bal)
            : acc_no(a_no), trx_id(id), trx_type(type), balance(bal) {}

        static long debitAmount(Account &to, Account &from, double amount)
        {
            if (from.balance >= amount)
            {
                from.balance -= amount;
                to.balance += amount;
                return from.trx_id;
            }
            return -1;
        }

        static long creditAmount(Account &to, Account &from, double amount)
        {
            if (from.balance >= amount)
            {
                from.balance -= amount;
                to.balance += amount;
                return to.trx_id;
            }
            return -1;
        }

        void displayDetails() const
        {
            cout << endl
                 << "Account Number: " << acc_no;
            cout << endl
                 << "Transaction ID: " << trx_id;
            cout << endl
                 << "Transaction Type: " << trx_type;
            cout << endl
                 << "Balance: " << balance << endl;
        }
    };

    Account person_1(50237, 123, "Savings", 10000.0);
    Account person_2(50232, 124, "Savings", 5000.0);

    Account::creditAmount(person_1, person_2, 500);

    person_1.displayDetails();
    person_2.displayDetails();
}

void ques_4()
{
    class B;

    class A
    {
        int x;

    public:
        A(int a)
        {
            x = a;
        }

        friend int add(A, B);
    };

    class B
    {
        int y;

    public:
        B(int b)
        {
            y = b;
        }

        friend int add(A, B);
    };

    class demo
    {
    public:
        static int add(A obj1, B obj2)
        {
            return obj1.x + obj2.y;
        }
    };

    A objA(10);
    B objB(20);

    int result = demo::add(objA, objB);

    cout << "Sum = " << result << endl;
}

void ques_5()
{
    class Complex
    {
        int real;
        int imaginary;

    public:
        Complex(int r, int i)
        {
            real = r;
            imaginary = i;
        }

        Complex(const Complex &c)
        {
            real = c.real;
            imaginary = c.imaginary;
        }

        void display()
        {
            cout << real << " + " << imaginary << "i" << endl;
        }

        friend void sum(Complex, Complex);
    };

    class demo
    {
    public:
        static void sum(Complex c1, Complex c2)
        {
            int r = c1.real + c2.real;
            int i = c1.imaginary + c2.imaginary;

            cout << "Sum = " << r << " + " << i << "i" << endl;
        }
    };

    Complex c1(3, 4);
    Complex c2(5, 6);

    Complex c3 = c1;

    cout << "Complex Number 1: ";
    c1.display();

    cout << "Complex Number 2: ";
    c2.display();

    cout << "Copied Complex Number: ";
    c3.display();

    demo::sum(c1, c2);
}

int main()
{
    ques_1();
    ques_2();
    ques_3();
    ques_4();
    ques_5();

    return 0;
}