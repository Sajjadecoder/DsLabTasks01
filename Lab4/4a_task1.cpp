#include<iostream>
using namespace std;
void bubbleSort(int *array,int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-1; j++)
        {
            if (array[j]<array[j+1])
            {
                swap(array[j],array[j+1]);
            }
            
        }
        
    }
    
}
void print(int *array,int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int size;
    cout<<"Enter size of Array: ";
    cin>>size;
    while (size<=0)
    {
        cout<<"Size must be greater than 0\nRe Enter: ";
        cin>>size;
    }
    int array[size];
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter element "<<i+1<<": ";
        cin>>array[i];
    }
    
    cout<<"Array before sorting: ";
    print(array,size);
    bubbleSort(array,size);
    cout<<"Array after sorting: ";
    print(array,size);
    return 0;
}