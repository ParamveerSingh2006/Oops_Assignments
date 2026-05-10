#include "headers.h"

void ques_1()
{
    fstream file;
    file.open("NUM.txt", ios::out);
    if(file.is_open()){
        for(int i{1}; i<=200; i++){
            file<<i<<endl;
        }
        file.close();
    }
}

void ques_2()
{
    fstream file;
    file.open("NOTES.txt", ios::in);
    if(file.is_open()){
        char c;
        int count{1};
        while(file.get(c)){
            if(isalpha(c)){
                count++;
            }
        }
        cout<<count<<" alphabets are present."<<endl;
        file.close();
    }


}

void ques_3()
{
    fstream file_1;
    fstream file_2;
    file_1.open("NOTES.txt", ios::in);
    file_2.open("NUM.txt", ios::out);
    if(file_1.is_open() && file_2.is_open()){
        string line;
        while(getline(file_1, line)){
            file_2<<line<<endl;
        }
        file_1.close();
        file_2.close();
    }
}

void ques_4()
{
    string to_insert{};
    cout << "Enter the string." << endl;
    getline(cin, to_insert);

    fstream file("ques_4.txt", ios::out);
    file << to_insert;
    file.close();

    string retrived{};
    fstream file_1("ques_4.txt", ios::in);
    cout << "Extracted Text:" << endl;
    while (getline(file_1, retrived)){
        cout << retrived;
    }
    file_1.close();
}

void ques_5()
{
    fstream file;

    file.open("AZ.txt", ios::out);
    if(file.is_open()){
        for(char ch = 'A'; ch <= 'Z'; ch++){
            file << ch;
        }
        file.close();
    }

    file.open("AZ.txt", ios::in);
    if(file.is_open()){
        file.seekg(9);
        char ch;
        file.get(ch);
        cout << "10th character: " << ch << endl;
        file.close();
    }

    file.open("AZ.txt", ios::in | ios::out);
    if(file.is_open()){
        file.seekp(4);
        file << 'X';
        file.close();
    }

    file.open("AZ.txt", ios::in);
    if(file.is_open()){
        file.seekg(0, ios::end);
        cout << "File size: " << file.tellg() << " bytes" << endl;
        file.close();
    }

    file.open("AZ.txt", ios::in);
    if(file.is_open()){
        file.seekg(-1, ios::end);
        char ch;
        file.get(ch);
        cout << "Last character: " << ch << endl;
        file.close();
    }

    file.open("data.txt", ios::out);
    if(file.is_open()){
        file << "This is line one.\n";
        file << "This is line two.\n";
        file << "This is line three.\n";
        file.close();
    }

    file.open("data.txt", ios::in);
    if(file.is_open()){
        file.seekg(9);
        cout << "Current position: " << file.tellg() << endl;

        char ch;
        cout << "Remaining content:\n";
        while(file.get(ch)){
            cout << ch;
        }
        file.close();
    }
}

void ques_6()
{
    fstream file;

    file.open("hello.txt", ios::out);
    if(file.is_open()){
        string text = "Hello World";
        for(char ch : text){
            file.put(ch);
            cout << "Position after writing '" << ch << "': " << file.tellp() << endl;
        }
        file.close();
    }

    file.open("hello.txt", ios::in | ios::out);
    if(file.is_open()){
        file.seekp(6);
        file << "C++  ";
        file.close();
    }

    file.open("hello.txt", ios::in);
    if(file.is_open()){
        string line;
        cout << "Updated content:\n";
        while(getline(file, line)){
            cout << line;
        }
        file.close();
    }
}

int main(){
    ques_1();
    ques_2();
    ques_3();
    ques_4();
    ques_5();
    ques_6();
    return 0;
}