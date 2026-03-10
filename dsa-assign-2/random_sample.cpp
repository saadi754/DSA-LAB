#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <filesystem>

using namespace std;

int main() {
    int n, m, k, seed;
    string target_path = "samples";  // samples folder
    
    // Get user inputs
    cout << "Enter number of elements per sample (n): ";
    cin >> n;
    
    cout << "Enter number of samples to generate (m): ";
    cin >> m;
    
    cout << "Enter maximum range value (k): ";
    cin >> k;
    
    cout << "Enter random seed: ";
    cin >> seed;
    
    // Create directory if it doesn't exist
    filesystem::create_directories(target_path);
    
    // Initialize random number generator with the given seed
    mt19937 gen(seed);
    uniform_int_distribution<> dis(0, k - 1);
    
    // Generate m samples
    for (int i = 1; i <= m; i++) {
        string filename = target_path + "/sample_" + to_string(i) + ".txt";
        ofstream file(filename);
        
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            continue;
        }
        
        // Generate n random numbers for this sample
        for (int j = 0; j < n; j++) {
            file << dis(gen);
            if (j < n - 1) file << " ";
        }
        file << endl;
        file.close();
        
        cout << "Generated " << filename << endl;
    }
    
    cout << "\nAll samples generated successfully!" << endl;
    
    return 0;
}