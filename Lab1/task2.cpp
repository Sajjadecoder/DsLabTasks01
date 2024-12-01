#include<iostream>
using namespace std;
class Exam{
    string studentName,examDate;
    double score;
    public:
    Exam(){}
    Exam(string name,string date,double sc){
        studentName = name;
        score = sc;
        examDate = date;
    }
    void setDate(string date){examDate = date;}
    void setName(string name){studentName =name;}
    void setScore(double sc){score= sc;}
    void display(){
        cout<<"Student Name: "<<studentName<<endl;
        cout<<"Exam Date: "<<examDate<<endl;
        cout<<"Score: "<<score<<endl<<endl;;
    }

};
int main(){
    Exam exam1("Sajjad", "27th Aug 2024", 90.5);
    Exam exam2 = exam1;
    cout << "Exam1 details(before modification)\n";
    exam1.display();
    cout << "Exam2 details(before modification)\n";
    exam2.display();
    exam1.setName("Ahmed");
    exam1.setDate("10th February 2024");
    exam1.setScore(80.5);
    cout << "Exam1 details(after modification)\n";
    exam1.display();
    cout << "Exam2 details(after modification)\n";
    exam2.display();
}