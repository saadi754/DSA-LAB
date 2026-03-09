#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream f("numbers.txt");
    int arr[20000];
    
    for (int i = 0; i < 20000; i++) {
        arr[i] = i;
    }
    
    for (int i = 0; i < 20000; i++) {
        swap(arr[i], arr[rand() % 20000]);
    }
    
    for (int i = 0; i < 20000; i++) {
        f << arr[i] << "\n";
    }
}