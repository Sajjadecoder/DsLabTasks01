#include<iostream>
using namespace std;
class BankAccount{
    int balance;
    public:    
    //ssd
    BankAccount(){
        balance = 500;//assuming this value 

    }
    BankAccount(int bal){
        balance = bal;
    }
    BankAccount(const BankAccount &obj){
        this->balance = obj.balance;
    }
    void display(){
        cout<<"Balance: $"<<balance<<endl;
        
    }
    void setBalance(int bal){
        balance = bal;
    }
};  
int main(){
    BankAccount account1;
    BankAccount account2(1000);
    BankAccount account3(account2);
    cout<<"Details Before deducting 200 from account 3\n";
    cout<<"Account 1:\n";
    account1.display();
    cout<<endl;
    cout<<"Account 2:\n";
    account2.display();
    cout<<endl;
    cout<<"Account 3:\n";
    account3.display();
    cout<<endl;
    account3.setBalance(800);
    cout<<"Details After deducting 200 from account 3\n";
    cout<<"Account 1:\n";
    account1.display();
    cout<<endl;
    cout<<"Account 2:\n";
    account2.display();
    cout<<endl;
    cout<<"Account 3:\n";
    account3.display();
    cout<<endl;
    return 0;
}