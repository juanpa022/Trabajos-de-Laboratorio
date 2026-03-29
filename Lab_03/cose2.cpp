#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>   

using namespace std;

int main() {
    const int N = 100000000; 

    vector<double> A(N, 1.0);
    vector<double> B(N, 2.0);
    vector<double> C(N, 0.0);

    // Versión Secuencial
   
    auto inicio = chrono::high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }

    auto fin = chrono::high_resolution_clock::now();
    cout << "Tiempo Secuencial: "
        << chrono::duration<double>(fin - inicio).count()
        << " segundos" << endl;

    //  Loop Unrolling
 
    inicio = chrono::high_resolution_clock::now();

    for (int i = 0; i < N; i += 4) {
        C[i] = A[i] + B[i];
        C[i + 1] = A[i + 1] + B[i + 1];
        C[i + 2] = A[i + 2] + B[i + 2];
        C[i + 3] = A[i + 3] + B[i + 3];
    }

    fin = chrono::high_resolution_clock::now();
    cout << "Tiempo Loop Unrolling: "
        << chrono::duration<double>(fin - inicio).count()
        << " segundos" << endl;

    // Paralelismo con OpenMP
    
    inicio = chrono::high_resolution_clock::now();

#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }

    fin = chrono::high_resolution_clock::now();
    cout << "Tiempo OpenMP: "
        << chrono::duration<double>(fin - inicio).count()
        << " segundos" << endl;

    return 0;
}