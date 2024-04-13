#include<iostream>
#include<string.h>
using namespace std;

class Employee
{
    private:
    int EmployeeId;
    int Salary;
    int DeptId;

    public:
    Employee(int EmployeeId,int Salary,int DeptId)
    {
      cout<<"Employee";
      this->EmployeeId=EmployeeId;
      this->Salary=Salary;
      this->DeptId=DeptId;
    }
    
    void DisplayDetails()
    {
      cout<<"EmployeeId"<<EmployeeId<<endl;
      cout<<"Salary"<<Salary<<endl;
      cout<<"DeptId"<<DeptId<<endl;
    }
};

class Manager: virtual public Employee
{
  private:
  int Incentive;
  int no_of_tasks;

  public:
  Manager(int EmployeeId,int Salary,int DeptId,int Incentive,int no_of_tasks):Employee(EmployeeId,Salary,DeptId)
  {
    cout<<"Manager"<<endl;
    this->Incentive=Incentive;
    this->no_of_tasks=no_of_tasks;
  }
  
   void show()
   {
     cout<<"Incentive"<<Incentive<<endl;
     cout<<"no_of_tasks"<<no_of_tasks<<endl;

   }
};

class SalesPerson:virtual public Employee
{
  private:
  int PA,FA,TA;

  public:
  SalesPerson(int EmployeeId,int Salary,int DeptId,int PA,int FA,int TA):Employee(EmployeeId,Salary,DeptId)
  {
    cout<<"SalesPerson"<<endl;
    this->PA=PA;
    this->FA=FA;
    this->TA=TA;
  }
   void Display()
   {
     cout<<"PA"<<PA<<endl<<"FA"<<FA<<endl<<"TA"<<TA<<endl;

   }
};
class SalesManager:public Manager,SalesPerson
{
    private:
    int SalesinRs;

    public:
    SalesManager(int EmployeeId,int Salary,int DeptId,int Incentive,int no_of_tasks,int PA,int FA,int TA,int SalesinRs)
    :Manager(EmployeeId,Salary,DeptId,Incentive,no_of_tasks),SalesPerson(EmployeeId,Salary,DeptId,PA,FA,TA)
    ,Employee(EmployeeId,Salary,DeptId)
    
    {
      this-> SalesinRs=SalesinRs;
    }
     
    void displaySalesM()
     {
       Employee::DisplayDetails();
       Manager::show();
       SalesPerson::Display();

     }


};




int main()
{
 SalesManager sobj( 1,20000,20,500,10,500,400,300,1000);
 sobj.displaySalesM();

    return 0;
}
