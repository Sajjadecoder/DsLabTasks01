#include<iostream>
#include<random>
#include<time.h>
using namespace std;
void guessNumber(int num,int player){
    int guessNum;
    cout<<"Player "<<player<< "'s turn, Enter Number: ";
    cin>>guessNum;
    if (num==guessNum)
    {
        cout<<"Number was "<<num<<" and is correctly guessed by player "<<player<<endl;
        return;
    }
    if (guessNum<num)
    {
        cout<<"Number Guessed is low\n";
        guessNumber(num,player+1);

    }else{
        cout<<"Number Guessed is high\n";
        guessNumber(num,player+1);
    }   
}
int main(){
    srand(time(0));//to get different values (for the number to be guessed) each time the program runs
    int num= rand()%100;
    guessNumber(num,1);
    return 0;
}