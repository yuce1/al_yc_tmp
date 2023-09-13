package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

const (
	numProducers = 3
	numConsumers = 2
	numItems     = 10
)

var (
	producerWaitGroup sync.WaitGroup
	consumerWaitGroup sync.WaitGroup
)

func producer(id int, ch chan int) {
	defer producerWaitGroup.Done()
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < numItems; i++ {
		item := rand.Intn(100)
		fmt.Printf("Producer %d: produced item %d\n", id, item)
		ch <- item
		time.Sleep(time.Millisecond * time.Duration(rand.Intn(100)))
	}
}

func consumer(id int, ch chan int) {
	defer consumerWaitGroup.Done()
	for {
		item, ok := <-ch
		if !ok {
			fmt.Printf("Consumer %d: channel closed, exiting\n", id)
			return
		}
		fmt.Printf("Consumer %d: consumed item %d\n", id, item)
		time.Sleep(time.Millisecond * time.Duration(rand.Intn(100)))
	}
}

func main() {
	ch := make(chan int, 5)

	for i := 0; i < numProducers; i++ {
		producerWaitGroup.Add(1)
		go producer(i, ch)
	}

	for i := 0; i < numConsumers; i++ {
		consumerWaitGroup.Add(1)
		go consumer(i, ch)
	}

	producerWaitGroup.Wait()

	// Close the channel to signal consumers to exit.
	close(ch)

	consumerWaitGroup.Wait()
}


