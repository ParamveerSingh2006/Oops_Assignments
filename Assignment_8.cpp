#include "headers.h"

void ques_1()
{
    fstream file;
    file.open("NUM.TXT", ios::out);
    if (file.is_open())
    {
        for (int i{1}; i <= 200; i++)
        {
            file << i << endl;
        }
        file.close();
    }
}

void ques_2()
{
    fstream file;
    file.open("NOTES.TXT", ios::in);
    if (file.is_open())
    {
        char c;
        int count{0};
        while (file.get(c))
        {
            if (isalpha(c))
            {
                count++;
            }
        }
        cout << count << " alphabets are present." << endl;
        file.close();
    }
}

void ques_3()
{
    class Student
    {
        char name[30];
        int roll;
        float marks;

    public:
        void get()
        {
            cin >> name >> roll >> marks;
        }
        void show()
        {
            cout << name << " " << roll << " " << marks << endl;
        }
    };

    Student s1, s2;

    cout << "Enter name, roll, marks: ";
    s1.get();

    fstream file;
    file.open("student.bin", ios::binary | ios::out);
    if (file.is_open())
    {
        file.write((char *)&s1, sizeof(s1));
        file.close();
    }

    file.open("student.bin", ios::binary | ios::in);
    if (file.is_open())
    {
        file.read((char *)&s2, sizeof(s2));
        s2.show();
        file.close();
    }
}

void ques_4()
{
    fstream src, dest;
    src.open("source.txt", ios::in);
    dest.open("copy.txt", ios::out);
    if (src.is_open() && dest.is_open())
    {
        char ch;
        while (src.get(ch))
        {
            dest.put(ch);
        }
        src.close();
        dest.close();
    }
}

void ques_5()
{
    fstream file;
    char input[100];
    cout << "Enter a string: ";
    cin.getline(input, 100);

    file.open("charfile.txt", ios::out);
    if (file.is_open())
    {
        file << input;
        file.close();
    }

    int len = 0;
    while (input[len] != '\0')
        len++;
    cout << "Length: " << len << endl;

    char stored[100];
    file.open("charfile.txt", ios::in);
    if (file.is_open())
    {
        int i = 0;
        char ch;
        while (file.get(ch))
        {
            stored[i++] = ch;
        }
        stored[i] = '\0';
        cout << "Stored characters: " << stored << endl;
        file.close();
    }
}

void ques_6()
{
    fstream file;
    file.open("point.txt", ios::out);
    if (file.is_open())
    {
        file << "12345";
        file.close();
    }

    file.open("point.txt", ios::in);
    if (file.is_open())
    {
        file.seekg(2);
        char ch;
        file.get(ch);
        cout << "3rd character: " << ch << endl;
        file.close();
    }

    file.open("point.txt", ios::in | ios::out);
    if (file.is_open())
    {
        file.seekp(2);
        file.put('X');
        file.close();
    }

    file.open("point.txt", ios::in);
    if (file.is_open())
    {
        file.seekg(0, ios::end);
        cout << "File size: " << file.tellg() << " bytes" << endl;
        file.close();
    }

    file.open("point.txt", ios::out);
    if (file.is_open())
    {
        file.put('A');
        cout << "tellp after put A: " << file.tellp() << endl;
        file.put('B');
        cout << "tellp after put B: " << file.tellp() << endl;
        file.close();
    }

    file.open("point.txt", ios::in);
    if (file.is_open())
    {
        file.seekg(0, ios::end);
        streampos fsize = file.tellg();
        file.seekg(-1, ios::end);
        char last;
        file.get(last);
        cout << "Last character: " << last << endl;
        file.close();
    }
}

int main()
{
    ques_1();
    ques_2();
    ques_3();
    ques_4();
    ques_5();
    ques_6();
    return 0;
}