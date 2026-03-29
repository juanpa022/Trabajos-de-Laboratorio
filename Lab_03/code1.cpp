#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int main() {
    const int N = 10000;
    vector<vector<int>> matriz(N, vector<int>(N, 1));

    auto inicio = chrono::high_resolution_clock::now();

    // Acceso por filas (cache-friendly)
    long long suma = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            suma += matriz[i][j];

    auto fin = chrono::high_resolution_clock::now();
    cout << "Tiempo filas: "
        << chrono::duration<double>(fin - inicio).count()
        << endl;

    inicio = chrono::high_resolution_clock::now();

    // Acceso por columnas (cache-miss)
    suma = 0;
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            suma += matriz[i][j];

    fin = chrono::high_resolution_clock::now();
    cout << "Tiempo columnas: "
        << chrono::duration<double>(fin - inicio).count()
        << endl;

    return 0;
}