#include<iostream>
#include<string>
using namespace std;
int main(){
    int *jaggedArray[5];
    for (int i = 0; i < 5; i++)
    {
        jaggedArray[i] = new int[10];
    }
    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            jaggedArray[i][j] = cnt++;
        }
    }
    //print
    cout<<"Jagged Array after initializing values\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout<<jaggedArray[i][j]<<" "; 
        }cout<<endl;
    }
    for (int i = 0; i < 5; i++) {
        delete  [] jaggedArray[i];
    }

    return 0;
}