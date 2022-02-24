/*
Q. Can we make copy constructor private? 
Ans : 
Yes, a copy constructor can be made private. When we make a copy constructor private in a class, objects of 
that class become non-copyable. This is particularly useful when our class has pointers or dynamically allocated resources.
 In such situations, we can either write our own copy constructor like above String example or make a private copy constructor 
 so that users get compiler errors rather than surprises at runtime. 


Q. Why argument to a copy constructor must be passed as a reference? 
Ans :
A copy constructor is called when an object is passed by value. Copy constructor itself is a function. So if we pass 
an argument by value in a copy constructor, a call to copy constructor would be made to call copy constructor 
which becomes a non-terminating chain of calls. Therefore compiler doesn’t allow parameters to be passed by value.


Why argument to a copy constructor should be const? 

Ans : 
Reason 1 - 
One reason for passing const reference is, we should use const in C++ wherever possible so that objects are not accidentally modified.
Reason 2 - 
the compiler creates a temporary object which is copied to t2 using copy constructor in 
the original program (The temporary object is passed as an argument to copy constructor). 
The reason for compiler error is, compiler created temporary objects cannot be bound to non-const references and 
the original program tries to do that. It doesn’t make sense to modify compiler created temporary objects as they can die any moment.




*/



#include <iostream>
#include <cstring>

using namespace std;


class Employee
{
    private:
    char* name;

    public:
    Employee(char* name)
    {
        cout<<"Parameterized Constructor called"<<endl;
        int size = sizeof(name)/sizeof(char);
        this->name = new char[size];
        strcpy(this->name, name);
    }

    Employee(const Employee& emp)
    {
        cout<<"Copy constructor called"<<endl;
        int size = sizeof(emp.name)/sizeof(char);
        name = new char[size];
        strcpy(name, emp.name);
    }

    Employee operator= (Employee& emp)
    {
        cout<<"Assignment operator called"<<endl;
        setName(emp.name);

        return *this;
    }

    ~Employee()
    {
        delete name;
    }

    void display()
    {
        cout << "Emp Name : " << name << endl;

    }

    void setName(char* name)
    {
        int size = sizeof(name)/sizeof(char);
        delete this->name;
        this->name = new char[size];
        strcpy(this->name, name);
    }

};

int main()
{
    Employee emp1((char*)"sumit kumar");//parametrized constructor calls
    emp1.display();

    Employee emp2(emp1);//copy constructor calls
    emp2.display();

    Employee emp3 = emp2;//copy constructor calls
    emp3.display();

    emp3.setName((char*)"Raju");
    emp1 = emp3;//assignment operator calls
   // emp1.display();

    return 0;
}