#include<iostream>
#include<string>
using namespace std;
struct employee{
    string name,designation;
    int priority;
};
void insertionSort(employee *employees){
    for(int i = 1;i< 8;i++)
    {
        employee tempEmployee = employees[i];
        int j = i-1;
        while (j>=0 && employees[j].priority>=tempEmployee.priority)
        {
            employees[j+1] = employees[j];
            j--;

        }
        employees[j+1] = tempEmployee;
        
    }
}
void print(employee *employees)
{
    
    for (int i = 0; i <8; i++)
    {
        cout<<employees[i].name<<" - "<<employees[i].designation<<endl;
    }
    cout<<endl;
}
int main(){
    
    employee employees[8];
    //hardcode initializing
    employees[0].name = "John";
    employees[0].designation= "EMP";
    employees[0].priority = 6;
    employees[1].name = "Alex";
    employees[1].designation= "CFO";
    employees[1].priority =3;
    employees[2].name = "Brian";
    employees[2].designation= "MGR";
    employees[2].priority =5;
    employees[3].name = "Chris";
    employees[3].designation= "EMP";
    employees[3].priority =6;
    employees[4].name = "Mary";
    employees[4].designation= "VP";
    employees[4].priority =4;
    employees[5].name = "Bruce";
    employees[5].designation= "CTO";
    employees[5].priority =2;
    employees[6].name = "Felix";
    employees[6].designation= "MGR";
    employees[6].priority =5;
    employees[7].name = "Harry";
    employees[7].designation= "CEO";
    employees[7].priority =1;
    cout<<"Before Sorting\n\n";
    print(employees);
    insertionSort(employees);
    cout<<"After Sorting\n\n";
    print(employees);

    return 0;
}