#include <bits/stdc++.h>
using namespace std;

int Array_size = 50000;
int main() {
    ofstream f("numbers.txt");
    int arr[Array_size];
    
    for (int i = 0; i < Array_size; i++) {
        arr[i] = i;
    }
    
    for (int i = 0; i < Array_size; i++) {
        swap(arr[i], arr[rand() % Array_size]);
    }
    
    for (int i = 0; i < Array_size; i++) {
        f << arr[i] << "\n";
    }
}