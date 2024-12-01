#include<iostream>
using namespace std;
struct date
{
    int day,month,year;
};
void selectionSort(date *dates)
{
    for (int i = 0; i < 4; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < 5; j++)
        {
            if (dates[j].year<dates[minIndex].year)
            {
                minIndex = j;
            }
            
        }
        swap(dates[i],dates[minIndex]);
        
    }
    
}
void print(date *dates)
{
    cout<<"Format: DD/MM/YYYY\n";
    for (int i = 0; i <5; i++)
    {
        cout<<dates[i].day<<"/"<<dates[i].month<<"/"<<dates[i].year<<endl;
    }
    cout<<endl;
}
int main(){
    date dates[5];
    for (int i = 0; i < 5; i++)
    {
        cout<<"Enter day of entry "<<i+1<<": ";
        cin>>dates[i].day;
        cout<<"Enter month of entry "<<i+1<<": ";
        cin>>dates[i].month;
        cout<<"Enter year of entry "<<i+1<<": ";
        cin>>dates[i].year;
    }
    cout<<"Dates before sorting\n";
    print(dates);   
    cout<<"Dates after sorting\n";
    selectionSort(dates);
    print(dates);   
    return 0;
}