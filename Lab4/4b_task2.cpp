#include<iostream>
using namespace std;

bool isSorted(int *accBalances,int size){
    for (int i = 0; i < size-1; i++)
    {
        if (accBalances[i]>accBalances[i+1])
        {
            cout<<"Error! Not Sorted\n";
            return 0;
        }
        
    }
    return 1;
    
}
void bubbleSort(int *accBalances,int size){
    for (int i = 0; i < size; i++)
    {
        bool swaps = false;
        for (int j = 0; j < size-1; j++)
        {
            if (accBalances[j]>accBalances[j+1])
            {
                swap(accBalances[j],accBalances[j+1]);
                swaps = true;
            }
            
        }
        if (!swaps)
        {
            return;
        }
        
        
    }
    
}
int interpolationSearch(int *accBalances,int size,int target){
    int left = 0;
    int right = size-1;
    while (left<=right)
    {
        int position = left + ((target - accBalances[left])*(right-left))/(accBalances[right] - accBalances[left]);
        if (target == accBalances[position])
        {
            return position;
        }
        
        if (target > accBalances[position])
        {
            left = position+1;
        }
        else{
            right = position-1;
        }
    }
    return -1;
    
}
int main(){
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    int accBalances[size];
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter Balance of account "<<i+1<<": ";
        cin>>accBalances[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout<<accBalances[i]<<" ";

    }cout<<endl;
    if (!isSorted(accBalances,size))    
    {
        bubbleSort(accBalances,size);
        cout<<"Sorted Array: ";
        for (int i = 0; i < size; i++)
        {
            cout<<accBalances[i]<<" ";

        }cout<<endl;
        
    }
    
    cout<<"Enter Target Value: ";
    int target;
    cin>>target;
    int returnIndex=interpolationSearch(accBalances,size,target);
    if (returnIndex ==-1)
    {
        cout<<target<<" not found\n";
    }else{
        cout<<target <<" found on index: "<<returnIndex;
    }
    
    


    return 0;
}