#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    string *rows[n];
    int seats[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter Seats For Row "<<i+1<<": ";
        cin>>seats[i];
        rows[i] = new string[seats[i]];
    }
    //initializing
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < seats[i]; j++)
        {
            rows[i][j] = "";
        }
        
    }
    bool stop = false;
    while (!stop)
    {
        cin.ignore();
        cout<<"Enter Attendee's Name: ";
        string name;
        getline(cin,name);
        cout<<"Enter Row and Seat Number: ";
        int currRow,currSeat;
        cin>>currRow>>currSeat;
        currRow--;currSeat--;
        if (rows[currRow][currSeat]=="")
        {
            rows[currRow][currSeat] = name;
            cout<<"Seat alloted successfully!\n";
        }else{
            cout<<"This seat is already booked\n";
        }
        cout<<"Enter 1 to Continue\nEnter 0 to exit\nChoice: ";
        int ch;
        cin>>ch;
        if (ch==0)
        {
            stop = true;
        }
        

    }
    //displaying the booked seats
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < seats[i]; j++)
        {   
            if (rows[i][j]!="")
            {
                cout<<"Row "<<i+1<<" Seat Number "<<j+1<<" is alloted to "<<rows[i][j]<<endl; 
            }
            
            
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        delete [] rows[i];
    }
        
        
    
    













    return 0;
}