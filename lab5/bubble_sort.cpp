#include <bits/stdc++.h>
#include <time.h>
using namespace std;


int Array_size = 20000;
int main() {
    ifstream in("numbers.txt");
    int arr[Array_size];
    
    for (int i = 0; i < Array_size; i++) {
        in >> arr[i];
    }
    in.close();
    
    clock_t start = clock();
    
    for (int i = 0; i < Array_size; i++) {
        for (int j = 0; j < Array_size -1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    
    clock_t end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC;
    cout << time << " seconds\n";
    
    ofstream out("sorted.txt");
    for (int i = 0; i < Array_size; i++) {
        out << arr[i] << "\n";
    }
    out.close();
}
