#include<iostream>
#include<string.h>
using namespace std;

class Employee
{
    private:
    int EmployeeID;
    int Salary;
    int Department_id;
    public:
    Employee(int EmployeeID,int Salary,int Department_id)
    {    cout<<"Employee"<<endl;
        this->EmployeeID = EmployeeID;
        this->Salary = Salary;
        this->Department_id = Department_id;
    }

    void DisplayDetails()
    {        cout<<"Employee ID : "<<EmployeeID<<endl;
        cout<<"Salary : "<<Salary<<endl;
        cout<<"Department_id : "<<Department_id<<endl;
    }

};

class Manager: virtual public Employee 
{
    private:
    int incentives;
    int no_of_tasks;
    
    public:
    Manager(int EmployeeID,int Salary,int Department_id,int incentives,int no_of_tasks):Employee(EmployeeID,Salary,Department_id)
    {
        cout<<"Manager"<<endl;
        this->incentives = incentives;
        this->no_of_tasks = no_of_tasks;
    }

    void show()
    {        cout<<"incentives : "<<incentives<<endl;
        cout<<"No of tasks : "<<no_of_tasks<<endl;
    }
    
};

class Saleperson : virtual public Employee
{
    private:   int PA;
    int FA;
    int TA;

    public:
    Saleperson(int EmployeeID,int Salary,int Department_id,int PA,int FA,int TA):Employee(EmployeeID,Salary,Department_id)
    {
        cout<<"Saleperson"<<endl;
        this->PA = PA;
        this->FA = FA;
        this->TA = TA;
    }

    void Display()
    {
        cout<<"P Allowance : "<<PA<<endl;
        cout<<"F Allowance : "<<FA<<endl;
        cout<<"T Allowance : "<<TA<<endl;
    }

};

class SalesManager:  public Manager,Saleperson
{
    private:
    int SalesinRs;
    public:
    SalesManager(int EmployeeID,int Salary,int Department_id,int incentives,int no_of_tasks,int PA,int FA,int TA,int SalesinRs):
    Manager(EmployeeID,Salary,Department_id,incentives,no_of_tasks),Saleperson(EmployeeID,Salary,Department_id,PA,FA,TA),
    Employee(EmployeeID,Salary,Department_id)
    {
        cout<<"SalesManager"<<endl;
        this->SalesinRs = SalesinRs;
    }

    void DisplaysalesM()
    { 
        Employee::DisplayDetails();
        Manager::show();
		Saleperson::Display();
    }
};

int main()
{
    SalesManager sm1(10,50000,101,1000,5,450,500,900,50000);
    sm1.DisplaysalesM();
    
    return 0;
}




// Employee eobj(2,50000,5);
    // eobj.DisplayDetails();

    // Manager mobj(3,45000,6,10000,5);
    // mobj.DisplayDetails();
    // mobj.show();

    // Saleperson sobj(4,4000,7,500,1000,2000);
    // sobj.DisplayDetails();
    // sobj.Display();

    // SalesManager smobj(3,70000,8,1000,5,2000,3000,1000,100000);

    // smobj.DisplaysalesM();