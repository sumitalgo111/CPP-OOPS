#include <iostream>

using namespace std;

class Complex
{
    private:
    int r;//real number
    int i;//imaginary number

    public:
    Complex():r(0),i(0)
    {}

    Complex(int r, int i)
    {
        this->r = r;
        this->i = i;
    }

    Complex operator+ (const Complex& obj2)
    {
        Complex obj;
        obj.r = this->r + obj2.r;
        obj.i = this->i + obj2.i;
        return obj;
    }

    void display()
    {
        cout<<"real : "<<r<<", imag : "<<i<<endl;
    }
};

int main()
{

    Complex obj1(2,1), obj2(3,2);

    Complex obj3;
    obj3 = obj1 + obj2;

    obj1.display();
    obj2.display();
    obj3.display();

    return 0;
}