#include<iostream>
using namespace std;

struct afnan{
    int a;
    int b;
};

void add(struct afnan *n){
    cout<<"a = ";
    cin>>n->a;
    cout<<"b = ";
    cin>>n->b;
    cout<<"the sum is "<<n->a+n->b<<endl;
}


int main(){
    struct afnan n1;
    add(&n1);
    return 0;
}