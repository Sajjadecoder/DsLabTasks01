#include<iostream>
#include<string>
using namespace std;
int main(){
    string s,t;
    cout<<"Enter text: ";
    getline(cin,s);
    cout<<"Enter pattern: ";
    getline(cin,t);
    for (int i = 0; i < s.length()-t.length(); i++)
    {   
        int k = i;
        int cnt = 0;
        bool isOverlapping = true;
        for (int j = 0; j < t.length(); j++)
        {
            if(s[k] != t[j]){
                bool isOverlapping = false;
                break;
            }
            cnt++;
            k++;
        }
        if(isOverlapping && cnt == t.length()){
            cout<<"Overlapping at index: "<<i<<endl;
        }
        
    }
    
    return 0;
}