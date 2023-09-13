package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

const (
	numWorkers   = 3
	numTasks     = 10
	taskLoadTime = 200 // 每个任务的工作时间（毫秒）
)

type Task struct {
	ID  int
	Job string
}

func worker(id int, tasks <-chan Task, results chan<- Task, wg *sync.WaitGroup) {
	defer wg.Done()
	for task := range tasks {
		fmt.Printf("Worker %d is processing task %d: %s\n", id, task.ID, task.Job)
		time.Sleep(time.Millisecond * time.Duration(taskLoadTime))
		fmt.Printf("Worker %d completed task %d\n", id, task.ID)
		results <- task
	}
}

func main() {
	tasks := make(chan Task, numTasks)
	results := make(chan Task, numTasks)
	var wg sync.WaitGroup

	// 启动Worker
	for i := 1; i <= numWorkers; i++ {
		wg.Add(1)
		go worker(i, tasks, results, &wg)
	}

	// 创建并分配任务给Worker
	for i := 1; i <= numTasks; i++ {
		task := Task{ID: i, Job: fmt.Sprintf("Task %d", i)}
		tasks <- task
	}

	close(tasks) // 关闭任务通道以通知Worker没有更多任务分配

	wg.Wait() // 等待所有Worker完成任务

	close(results) // 关闭结果通道

	// 输出结果
	for result := range results {
		fmt.Printf("Master received result from Worker: %d - %s\n", result.ID, result.Job)
	}
}





下面是一个Go代码示例，实现了Master-Worker模型，满足以下要求：

Master有1000个任务。
最多3个Worker执行任务。
每个Worker如果5秒内没有任务可执行，就会退出。
Master在关闭时，需要等待所有Worker都关闭后才能关闭。
package main

import (
	"fmt"
	"sync"
	"time"
)

const (
	numTasks       = 1000
	numWorkers     = 3
	idleTimeout    = 5 * time.Second // Worker闲置超时时间
	taskProcessTime = 1 * time.Second // 每个任务处理时间
)

type Task struct {
	ID int
}

func worker(id int, tasks <-chan Task, wg *sync.WaitGroup) {
	defer wg.Done()
	for {
		select {
		case task, ok := <-tasks:
			if !ok {
				fmt.Printf("Worker %d exiting\n", id)
				return
			}
			fmt.Printf("Worker %d processing task %d\n", id, task.ID)
			time.Sleep(taskProcessTime)
			fmt.Printf("Worker %d completed task %d\n", id, task.ID)
		case <-time.After(idleTimeout):
			fmt.Printf("Worker %d idle for too long, exiting\n", id)
			return
		}
	}
}

func main() {
	tasks := make(chan Task, numTasks)
	var wg sync.WaitGroup

	// 启动Workers
	for i := 1; i <= numWorkers; i++ {
		wg.Add(1)
		go worker(i, tasks, &wg)
	}

	// 创建并分配任务给Workers
	for i := 1; i <= numTasks; i++ {
		task := Task{ID: i}
		tasks <- task
	}

	// 关闭任务通道以通知Workers没有更多任务分配
	close(tasks)

	// 等待所有Workers完成任务
	wg.Wait()

	fmt.Println("All workers have completed their tasks. Master is now exiting.")
}
