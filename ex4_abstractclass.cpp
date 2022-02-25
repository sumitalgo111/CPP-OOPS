
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
        int size = sizeof(name)/sizeof(char);
        this->name = new char[size];
        strcpy(this->name, name);
    }

    Employee(const Employee& emp)
    {
        int size = sizeof(emp.name)/sizeof(char);
        name = new char[size];
        strcpy(name, emp.name);
    }

    Employee& operator= (Employee& emp)
    {
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

    virtual void Insurance() = 0;

};

class Manager : public Employee
{
    public:
    Manager(char* name):Employee(name){}

    void Insurance()
    {
        cout<<"Rank: Manager"<<endl;
        cout<<"Insurance Coverage: 1 Crore"<<endl;
    }
};

class Lead : public Employee
{
    public:
    Lead(char* name):Employee(name){}

    void Insurance()
    {
        cout<<"Rank: Lead"<<endl;
        cout<<"Insurance Coverage: 50 Lakhs"<<endl;
    }
};


int main()
{
    Manager emp1((char*)"Sumit kumar");//parametrized constructor calls
    Lead    emp2((char*)"Rohit Kumar");
    //Employee emp3((char*)"Uday Kumar");

    Employee* emp;

    emp = &emp1;
    emp->display();
    emp->Insurance();

    emp = &emp2;
    emp->display();
    emp->Insurance();

 /*   emp = &emp3;
    emp->display();
    emp->Insurance();*/

    return 0;
}