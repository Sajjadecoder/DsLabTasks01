#include<iostream>
using namespace std;
int getLastTwoDigits(int num){
    return num%100; 
}
int binarySearch(int *nums,int size,int target,int &left){
    int right = size-1;
    while (left<=right)
    {
        int mid  = left +((right-left)/2);
        if (nums[mid]==target)
        {
            return mid;
        }
        
        if (target<nums[mid])
        {
            right = mid-1;
        }
        else{
            left  = mid+1;
        }
        
        

    }
    return -1;
    
}
int main(){
    int size = 6;
    int *nums = new int[size]{12,34,56,67,89,90};
    int left = 0;
    cout<<"Enter roll number digits(XXXX): ";
    int rollNumDigits;
    cin>>rollNumDigits;
    rollNumDigits = getLastTwoDigits(rollNumDigits);
    int retIndex = binarySearch(nums,size,rollNumDigits,left);
    if (retIndex!=-1)
    {
        cout<<"Found on index: "<<retIndex<<endl;
    }else{

    int *tempArr = new int[size+1];
    for (int i = 0; i < left; i++)
    {
            tempArr[i] = nums[i];

    }
    tempArr[left] = rollNumDigits;
    for (int i = left; i < size; i++)
    {
        tempArr[i+1] = nums[i];
    }
    delete [] nums;
    nums = tempArr;
    delete [] tempArr;
    cout<<"Updated Array(after insertion)\n";
    for (int i = 0; i < size+1; i++)
    {
        cout<<nums[i]<<" ";
    }
    }
    delete [] nums;
    return 0;
}