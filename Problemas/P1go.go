package main

import (
	"fmt"
	"time"
)

func main() {
	const MAX = 10000
	A := make([][]float64, MAX)
	for i := range A { A[i] = make([]float64, MAX) }
	x, y := make([]float64, MAX), make([]float64, MAX)
	start := time.Now()
	for i := 0; i < MAX; i++ {
		for j := 0; j < MAX; j++ {
			y[i] += A[i][j] * x[j]
		}
	}
	fmt.Println("Rapido:", time.Since(start))
	start = time.Now()
	for j := 0; j < MAX; j++ {
		for i := 0; i < MAX; i++ {
			y[i] += A[i][j] * x[j]
		}
	}
	fmt.Println("Lento: ", time.Since(start))
}