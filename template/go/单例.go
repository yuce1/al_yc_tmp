package main

import (
	"fmt"
	"sync"
)

type Singleton struct {
	data string
}

var instance *Singleton
var once sync.Once

func GetInstance() *Singleton {
	once.Do(func() {
		instance = &Singleton{data: "This is the Singleton instance"}
	})
	return instance
}

func main() {
	// 创建多个实例，但都会返回同一个实例
	instance1 := GetInstance()
	instance2 := GetInstance()

	fmt.Println("Instance 1 Data:", instance1.data)
	fmt.Println("Instance 2 Data:", instance2.data)

	if instance1 == instance2 {
		fmt.Println("Both instances are the same")
	} else {
		fmt.Println("Instances are different")
	}
}



单例模式是一种设计模式，用于确保一个类只有一个实例，并提供一个全局访问点以获取该实例。这在某些情况下非常有用，例如需要共享资源、配置管理、线程池等。单例模式通常涉及以下几个关键点：

私有构造函数：确保不能通过常规的方式创建多个实例。
私有静态变量：用于存储单一实例的引用。
公共静态方法：提供对唯一实例的访问。