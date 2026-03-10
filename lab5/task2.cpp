#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int Array_size = 50000;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }
    
    int i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1) {
        arr[k++] = L[i++];
    }
    
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    ifstream in("numbers.txt");
    int arr[Array_size];
    
    for (int i = 0; i < Array_size; i++) {
        in >> arr[i];
    }
    in.close();
    
    cout << "1. Selection Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Merge Sort\n";
    cout << "4. Quick Sort\n";
    cout << "Choose: ";
    
    int choice;
    cin >> choice;
    
    clock_t start = clock();
    
    if (choice == 1) {
        selectionSort(arr, Array_size);
    } else if (choice == 2) {
        insertionSort(arr, Array_size);
    } else if (choice == 3) {
        mergeSort(arr, 0, Array_size - 1);
    } else if (choice == 4) {
        quickSort(arr, 0, Array_size - 1);
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
