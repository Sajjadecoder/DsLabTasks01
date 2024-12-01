#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>
using namespace std;
class Course
{
    double weightage;
    string grade;
    double mid1Wtg, mid2Wtg, finalsWtg, assignmentsWtg, quizzesWtg;

public:
Course(){}
    Course( double _mid1Wtg, double _mid2Wtg, double _finalsWtg, double _assignmentsWtg, double _quizzesWtg)
    {
        mid1Wtg = _mid1Wtg;
        mid2Wtg = _mid2Wtg;
        finalsWtg = _finalsWtg;
        assignmentsWtg = _assignmentsWtg;
        quizzesWtg = _quizzesWtg;
        weightage = 0;
        calculateWeightage();
    }
    void calculateWeightage(){
        weightage = mid1Wtg+mid2Wtg+finalsWtg+assignmentsWtg+quizzesWtg;
        calculateGrade();
    }
    void calculateGrade()
    {
        if (weightage >= 90 && weightage <= 100)
        {
            grade = "A+";
            return;
        }
        if (weightage >= 86 && weightage < 90)
        {
            grade = "A";
            return;
        }
        if (weightage >= 82 && weightage < 86)
        {
            grade = "A-";
            return;
        }
        if (weightage >= 78 && weightage < 82)
        {
            grade = "B+";
            return;
        }
        if (weightage >= 74 && weightage < 78)
        {
            grade = "B";
            return;
        }
        if (weightage >= 70 && weightage < 74)
        {
            grade = "B-";
            return;
        }
        if (weightage >= 66 && weightage < 70)
        {
            grade = "C+";
            return;
        }
        if (weightage >= 62 && weightage < 66)
        {
            grade = "C";
            return;
        }
        if (weightage >= 58 && weightage < 62)
        {
            grade = "C-";
            return;
        }
        if (weightage >= 54 && weightage < 58)
        {
            grade = "D+";
            return;
        }
        if (weightage >= 50 && weightage < 54)
        {
            grade = "D";
            return;
        }
        grade = "F";
        return;
    }
    string getGrade(){return grade;}
    
};
int generateRandomNumber( int upper) {
    return  (rand() % (upper + 1));//took a little help from internet for this function
}
int main()
{
    srand(time(0));//using this just to get unique values each time the code runs
    Course *CoursesList[4];
    int courses[4] = {3,4,2,1};
    string departments[4] = {"SE","AI","CS","DS"};
    for (int i = 0; i < 4; i++)
    {
        CoursesList[i] = new Course[courses[i]];
        for (int j = 0; j < courses[i]; j++)
        {
            int mid1 = generateRandomNumber(15);//using this function to get random marks instead of taking inputs 
            int mid2 = generateRandomNumber(15);
            int assignment = generateRandomNumber(10);
            int quiz = generateRandomNumber(10);
            int finals = generateRandomNumber(50);

            CoursesList[i][j] = Course(mid1,mid2,finals,assignment,quiz);
        }
        
    }
    for (int i = 0; i < 4; i++)
    {
        cout<<"Department Name: "<<departments[i]<<endl;
        for (int j = 0; j < courses[i]; j++)
        {
            cout<<"Course "<<j+1<<" Grade: "<<CoursesList[i][j].getGrade()<<endl;
        }
        cout<<endl;
    }
    
    return 0;
}