#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int main() {
    int MAX = 10000;
    vector<vector<double>> A(MAX, vector<double>(MAX, 1.0));
    vector<double> x(MAX, 1.0), y(MAX, 0.0);

    auto t1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            y[i] += A[i][j] * x[j]; 
    auto t2 = chrono::high_resolution_clock::now();
    cout << "Rapido: " << chrono::duration<double>(t2 - t1).count() << "s" << endl;
    for (int i = 0; i < MAX; i++) y[i] = 0; 
    auto t3 = chrono::high_resolution_clock::now();
    for (int j = 0; j < MAX; j++)
        for (int i = 0; i < MAX; i++)
            y[i] += A[i][j] * x[j];
    auto t4 = chrono::high_resolution_clock::now();
    cout << "Lento: " << chrono::duration<double>(t4 - t3).count() << "s" << endl;

    return 0;
}