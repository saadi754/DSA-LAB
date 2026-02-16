#include <iostream>
using namespace std;

struct complex{
	float real;
	float img;
};

int main(){
	complex c1;
	complex *ptr=&c1;

	cout<<"enter the value of real = ";
	cin>>ptr->real;
	cout<<"enter the value of img = ";
	cin>>ptr->img;
	cout<<"the number is "<<ptr->real<<"+"<<ptr->img<<"i"<<endl;
	return 0; 

}
// g++ lab1.c -o lab1
// ./lab1