package main

import (
	"fmt"
	"time"
)

func multiplicarBloques(n, b int) {
	A := make([][]float64, n); B := make([][]float64, n); C := make([][]float64, n)
	for i := range A {
		A[i], B[i], C[i] = make([]float64, n), make([]float64, n), make([]float64, n)
	}

	start := time.Now()

	// 6 Bucles
	for bi := 0; bi < n; bi += b {
		for bj := 0; bj < n; bj += b {
			for bk := 0; bk < n; bk += b {
				// Multiplicación interna
				for i := bi; i < bi+b && i < n; i++ {
					for j := bj; j < bj+b && j < n; j++ {
						for k := bk; k < bk+b && k < n; k++ {
							C[i][j] += A[i][k] * B[k][j]
						}
					}
				}
			}
		}
	}

	fmt.Printf("Bloques (n=%d, b=%d): %v\n", n, b, time.Since(start))
}

func main() {
	multiplicarBloques(1000, 64)
}