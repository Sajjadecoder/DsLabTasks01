#include<iostream>
using namespace std;
int getSum(int **array,int sum,int i,int j,int row,int *cols){
    if (i==row-1 && j == cols[i]-1)
    {
        sum+=array[i][j];
        return sum;
    }

    sum+=array[i][j];
    if (j==cols[i]-1)
    {
        getSum(array,sum,i+1,0,row,cols);
    }
    else{
        getSum(array,sum,i,j+1,row,cols);

    }
     
    
}
int main(){
    int row;
    cout<<"Enter Rows: ";
    cin>>row;
    while (row<=0)
    {
        cout<<"Enter row greater than 0: ";
        cin>>row;
    }
    
    int *jaggedArray[row];
    int columns[row];
    for (int i = 0; i < row; i++)
    {
        cout<<"Enter Columns for row "<<i+1<<": ";
        int col;
        cin>>col;
        while (col<1)
        {
            cout<<"Enter column greater than 0: ";
            cin>>col;
        }
        
        columns[i] = col;
        jaggedArray[i] = new int[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < columns[i]; j++)
        {
            jaggedArray[i][j] = i+j+1;
        }
        
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < columns[i]; j++)
        {
            cout<<jaggedArray[i][j]<<" ";
        }
        cout<<endl;
        
    }
    int sum = 0;
    cout<<"Sum of all elements: "<<getSum(jaggedArray,sum,0,0,row,columns);

    return 0;
}