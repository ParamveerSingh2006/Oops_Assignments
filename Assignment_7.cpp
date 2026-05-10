#include "headers.h"

void ques_1(){
    class polygon{
        protected:
            double height{}, width{};
        public:
            polygon(double a, double b):height{a}, width{b}{};

            void set_value(double a, double b){
                height=a;
                width=b;
            }

            virtual double calculate_area(){
                return 0;
            }
    };

    class rectangle: public polygon{
        public:
            rectangle(int a, int b): polygon(a, b) {};
            double calculate_area() override{
                return height*width;
            }

    };

    class triangle: public polygon{
        public:
            triangle(int a, int b): polygon(a, b) {};
            double calculate_area() override{
                return 0.5*height*width;
            }

    };

}

void ques_2(){
    class shape{
        protected:
            double height{}, width{};
        public:
            shape(double a, double b):height{a}, width{b}{};

            void set_value(double a, double b){
                height=a;
                width=b;
            }

            virtual double area(){
                return 0;
            }

            virtual string display(){
                return "generic_shape";
            }
    };

    class rectangle: public shape{
        public:
            rectangle(int a, int b): shape(a, b) {};
            double area() override{
                return height*width;
            }
            string display() override{
                return "rectangle";
            }
        };

        class triangle: public shape{
            public:
            triangle(int a, int b): shape(a, b) {};
            double area() override{
                return 0.5*height*width;
            }
            string display() override{
                return "triangle";
            }

    };
        class circle: public shape{
            public:
            circle(int a): shape(a, a) {};
            double area() override{
                return 3.14*height*width;
            }
            string display() override{
                return "circle";
            }

    };
}

void ques_3(){
    class triangle{
        protected:
            int base{};
            int height{};
        public:
            triangle(int a, int b): base{a}, height{b} {};
            double area(int side){
                return (sqrt(3) / 4) * pow(side, 2);
            }

            double area(int base, int height){
                return 0.5 * base * height;
            }

            double area(double base, double equalSide){
                double height = sqrt(pow(equalSide, 2) - (pow(base, 2) / 4));
                return 0.5 * base * height;
            }
    };
}

void ques_4(){
    class student{
        protected:
            string name {"Student"};
        public:
            student(string n): name{n}{};
            virtual void display(){
            }
    };

    class engineering: public student{
        public:
            engineering(string name): student(name){};
            void display() override{
                cout<<name<<" from Engineering."<<endl;
        }
    };

    class medical: public student{
        public:
            medical(string name): student(name){};
            void display() override{
                cout<<name<<" from Medical."<<endl;
        }

    };
}

void ques_5(){
    class Time{
    int h{}, m{}, s{};
    public:
        Time()=default;
        Time(int a, int b, int c): h{a}, m{b}, s{c} {
            adjust();
        };
        void display(){
            cout<<h<<":"<<m<<":"<<s<<endl;
        }
        void adjust(){
            h=h+(m+(s/60))/60;
            m=(m+(s/60))%60;
            s=s%60;
        }
        Time operator +(Time t1){
            Time temp;
            temp.h=h+t1.h;
            temp.m=m+t1.m;
            temp.s=s+t1.s;
            temp.adjust();
            return temp;
        }
};
}

void ques_6(){
    class STRING{
        public:
            string eg {"Default"};
            STRING()=default;
            STRING(string a): eg{a} {};
            STRING operator + (STRING demo){
                STRING temp;
                temp.eg=eg+demo.eg;
                return temp;
            }

            bool operator == (STRING demo){
                return(eg==demo.eg);
            }
    };
}

void ques_7(){
    class matrix{
        int mat[2][2] {};
        public:
            matrix()=default;
            void set(int i, int j, int a){
                if(i<2 && j<2) mat[i][j]=a;
            }
            friend matrix operator *(matrix m1, matrix m2);
            void display(){
                for(int i{}; i<2; i++){
                    for(int j{}; j<2; j++){
                        cout<<mat[i][j]<<" ";
                    }
                    cout<<endl;
                }
            }
    };

    matrix operator *(matrix m1, matrix m2){
        matrix demo;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                demo.mat[i][j] = 0;
                for(int k = 0; k < 2; k++){
                    demo.mat[i][j] += m1.mat[i][k] * m2.mat[k][j];
                }
            }
        }
        return demo;
    }
}

void ques_8(){
    class out_bounds
    {
    protected:
        int arr[3]{};

    public:
        out_bounds(int a, int b, int c)
        {
            arr[0] = a;
            arr[1] = b;
            arr[2] = c;
        }
        out_bounds() = default;

        int &operator[](int index)
        {
            if (index < 0 || index > 2)
            {
                cout << "Out of bounds!" << endl;
                exit(1);
            }
            else
                return arr[index];
        }
    };
}

void ques_9()
{
    class initialize_overload
    {
        int a, b, c;

    public:
        initialize_overload() : a{}, b{}, c{} {};
        void operator()(int d, int e, int f)
        {
            a = d;
            b = e;
            c = f;
        }
        void operator()(int d, int e)
        {
            a = d;
            b = e;
            c = 0;
        }
        void display()
        {
            cout << "a: " << a << endl;
            cout << "b: " << b << endl;
            cout << "c: " << c << endl;
        }
    };
}

void ques_10(){
    class Complex {
        float real, imag;
    public:
        friend istream& operator>>(istream &in, Complex &c){
            in>>c.real>>c.imag;
            return in;
        }
        friend ostream& operator<<(ostream &out, const Complex &c){
            out<<c.real<<" + i"<<c.imag;
            return out;
        }
    };                                          
}

void ques_11(){
    class Test {
        float value;
    public:
        Test(float f) : value(f) {}
        void display() { cout<<value<<endl; }
};
}

void ques_12(){
    class Test {
        float value;
    public:
        Test(float f) : value(f) {}
        operator float() { return value; }   // conversion operator
    };
}

void ques_13(){
    class Polar {
    public:
        double r, theta;
        Polar(double r, double t) : r(r), theta(t) {}
    };

    class Cartesian {
        double x, y;
    public:
        Cartesian() : x(0), y(0) {}
        Cartesian(const Polar &p) {
            x = p.r * cos(p.theta);
            y = p.r * sin(p.theta);
        }
        void show() {
            cout<<"x = "<<x<<", y = "<<y<<endl;
        }
    };
}

int main()
{
    return 0;
}