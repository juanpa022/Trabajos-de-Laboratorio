#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void multiplicar(int n) {
    vector<vector<double>> A(n, vector<double>(n, 1.0));
    vector<vector<double>> B(n, vector<double>(n, 1.0));
    vector<vector<double>> C(n, vector<double>(n, 0.0));
    auto inicio = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> tiempo = fin - inicio;
    cout << "Tamaño " << n << "x" << n << ": " << tiempo.count() << " segundos" << endl;
}

int main() {
    multiplicar(200);
    multiplicar(500);
    multiplicar(1000); 
    return 0;
}