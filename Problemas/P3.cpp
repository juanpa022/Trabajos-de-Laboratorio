#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

void multiplicarBloques(int n, int b) {
    vector<vector<double>> A(n, vector<double>(n, 1.1));
    vector<vector<double>> B(n, vector<double>(n, 1.1));
    vector<vector<double>> C(n, vector<double>(n, 0.0));

    auto inicio = chrono::high_resolution_clock::now();

    // 6 Bucles Anidados
    for (int bi = 0; bi < n; bi += b) { // Bloque Fila
        for (int bj = 0; bj < n; bj += b) { // Bloque Columna
            for (int bk = 0; bk < n; bk += b) { // Bloque K
                
                // Multiplicación estándar dentro del bloque
                for (int i = bi; i < min(bi + b, n); i++) {
                    for (int j = bj; j < min(bj + b, n); j++) {
                        for (int k = bk; k < min(bk + b, n); k++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }

    auto fin = chrono::high_resolution_clock::now();
    cout << "Bloques (n=" << n << ", b=" << b << "): " 
         << chrono::duration<double>(fin - inicio).count() << "s" << endl;
}

int main() {
    int N = 1000;
    multiplicarBloques(N, 64); 
    return 0;
}