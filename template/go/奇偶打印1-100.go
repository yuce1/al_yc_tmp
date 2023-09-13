package main

import (
	"fmt"
	"sync"
)

func printOdd(oddCh, evenCh chan int, wg *sync.WaitGroup) {
	defer wg.Done()
	for i := 1; i <= 100; i += 2 {
		fmt.Printf("Odd: %d\n", i)
		evenCh <- i
		<-oddCh
	}
}

func printEven(oddCh, evenCh chan int, wg *sync.WaitGroup) {
	defer wg.Done()
	for i := 2; i <= 100; i += 2 {
		fmt.Printf("Even: %d\n", i)
		oddCh <- i
		<-evenCh
	}
}

func main() {
	oddCh := make(chan int)
	evenCh := make(chan int)
	var wg sync.WaitGroup

	wg.Add(2)

	go printOdd(oddCh, evenCh, &wg)
	go printEven(oddCh, evenCh, &wg)

	wg.Wait()
}
