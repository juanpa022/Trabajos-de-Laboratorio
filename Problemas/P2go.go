package main

import (
	"fmt"
	"time"
)

func multiplicar(n int) {
	A := make([][]float64, n)
	B := make([][]float64, n)
	C := make([][]float64, n)
	for i := range A {
		A[i], B[i], C[i] = make([]float64, n), make([]float64, n), make([]float64, n)
	}

	inicio := time.Now()

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				C[i][j] += A[i][k] * B[k][j]
			}
		}
	}

	fmt.Printf("Tamaño %dx%d: %v\n", n, n, time.Since(inicio))
}

func main() {
	multiplicar(200)
	multiplicar(500)
	multiplicar(1000)
}