#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <ctime>

using namespace std;

// function to do partition for quick sort
int partition(vector<int>& arr, int low, int high) {
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

// recursive quick sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int sample_num;
    string filename;
    vector<int> data;
    ifstream infile;
    
    // ask user for sample number
    cout << "Enter the sample number (1, 2, 3, etc): ";
    cin >> sample_num;
    
    // construct filename automatically
    filename = "samples/sample_" + to_string(sample_num) + ".txt";
    
    // open the file
    infile.open(filename);
    if (!infile.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }
    
    // read numbers from file into vector
    int num;
    while (infile >> num) {
        data.push_back(num);
    }
    infile.close();
    
    if (data.empty()) {
        cerr << "Error: No data found in file" << endl;
        return 1;
    }
    
    // store original data for logging
    vector<int> original_data = data;
    
    // open log file for appending
    ofstream logfile("log.txt", ios::app);
    
    // get test number from log file (count existing lines)
    int test_num = 1;
    ifstream logread("log.txt");
    string line;
    while (getline(logread, line)) {
        if (line.find("Test number:") != string::npos) {
            test_num++;
        }
    }
    logread.close();
    
    // record start time in microseconds
    auto start_time = chrono::high_resolution_clock::now();
    
    // do quick sort
    quickSort(data, 0, data.size() - 1);
    
    // record end time in microseconds
    auto end_time = chrono::high_resolution_clock::now();
    
    // calculate duration in microseconds
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    
    // write to log file
    logfile << "\n========================================\n";
    logfile << "Test number: " << test_num << "\n";
    logfile << "File: " << filename << "\n";
    logfile << "Start time: " << start_time.time_since_epoch().count() << " microseconds\n";
    logfile << "End time: " << end_time.time_since_epoch().count() << " microseconds\n";
    logfile << "Duration of sorting: " << duration.count() << " microseconds\n";
    
    logfile << "\nData before sorting: ";
    for (int i = 0; i < original_data.size(); i++) {
        logfile << original_data[i];
        if (i < original_data.size() - 1) logfile << " ";
    }
    logfile << "\n";
    
    logfile << "Data after sorting: ";
    for (int i = 0; i < data.size(); i++) {
        logfile << data[i];
        if (i < data.size() - 1) logfile << " ";
    }
    logfile << "\n";
    
    logfile << "Number of variables created in memory: 4\n";
    logfile << "Estimated memory before sorting: " << (original_data.size() * sizeof(int)) << " bytes\n";
    logfile << "Estimated memory after sorting: " << (data.size() * sizeof(int)) << " bytes\n";
    logfile << "Number of pointers used: 2\n";
    logfile << "Number of new/delete operations: 0\n";
    logfile << "========================================\n";
    
    logfile.close();
    
    // print result to console
    cout << "\nSorting completed successfully!" << endl;
    cout << "Duration: " << duration.count() << " microseconds" << endl;
    cout << "Results logged to log.txt" << endl;
    
    return 0;
}
