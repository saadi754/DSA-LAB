#include<iostream>
using namespace std;

struct student{
    int roll;
    char name[20];
    float marks;
    float percentage;
    string grade;
    char caste[20];
};

int main(){
    student s1;
    student *ptr=&s1;

    cout<<"enter the roll number = ";
    cin>>ptr->roll;
    cout<<"enter the name = ";
    cin>>ptr->name;
    cout<<"enter the marks = ";
    cin>>ptr->marks;
    cout<<"enter the percentage = ";
    cin>>ptr->percentage;
    cout<<"enter the grade = ";
    cin>>ptr->grade;
    cout<<"enter the caste = ";
    cin>>ptr->caste;

    cout<<"the details of student are "<<endl;
    cout<<"roll number = "<<ptr->roll<<endl;
    cout<<"name = "<<ptr->name<<endl;
    cout<<"marks = "<<ptr->marks<<endl;
    cout<<"percentage = "<<ptr->percentage<<endl;
    cout<<"grade = "<<ptr->grade<<endl;
    cout<<"caste = "<<ptr->caste<<endl;

    return 0; 
}