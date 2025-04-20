#include<iostream>
using namespace std;
typedef struct{
    int employee_ID;
    string name;
    float salary;
}Employee;
void IncreaseSalary(Employee &a,float percent){
    a.salary *=(1+percent/100);
}
int main(){
    Employee engineer;
    engineer.employee_ID=1234;
    engineer.name="Oscar Mutamba";
    engineer.salary=2e5;
    IncreaseSalary(engineer,12);
    cout<<engineer.salary<<endl;
    Employee *pAccountant=new Employee;
    pAccountant->employee_ID=1235;
    pAccountant->name="Malcom W";
    pAccountant->salary=3e5;
    IncreaseSalary(*pAccountant,10);
    cout<<pAccountant->salary<<endl;
    delete pAccountant;
    return 0;
}