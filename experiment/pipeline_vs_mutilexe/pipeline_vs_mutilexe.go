/*
@Time : 2021/8/30 2:14 下午
@Author : davin
*/
package main

import (
	"fmt"
	"github.com/gomodule/redigo/redis"
	"net/http"
	"sync"
	"time"
)

func init() {
}

func test() {
	wg := sync.WaitGroup{}
	for i:=0; i < 50; i++ {
		wg.Add(1)
		go func() {
			conn, err := redis.Dial("tcp", "11.186.5.121:6379", redis.DialReadTimeout(time.Second), redis.DialPassword("Qidian@123"))
			if err != nil {
				// handle error
				fmt.Println("dial failed")
				return
			}
			defer conn.Close()
			key := fmt.Sprintf("%s_%d", "davinliu_key_%d", i);
			_, err = conn.Do("set", key, "value")
			if err != nil {
				fmt.Println("Do Set", err)
			}
			wg.Done()
		}()
	}
	wg.Wait()
}

func testPipeLine() {
	conn, err := redis.Dial("tcp", "11.186.5.121:6379", redis.DialReadTimeout(time.Second), redis.DialPassword("Qidian@123"))
	if err != nil {
		// handle error
		fmt.Println("dial failed")
		return
	}
	for i := 0; i < 50; i++ {
		key := fmt.Sprintf("%s_%d", "davinliu_key_%d", i);
		if err := conn.Send("SET", key, "value"); err != nil {
			fmt.Println("Pipe Set", err)
		}
	}
	if err := conn.Flush(); err != nil {
		fmt.Println("Pipe Set", err)
	}
	for i := 0; i < 50; i++ {
		_, err := conn.Receive()
		if err != nil {
			fmt.Println("Pipe Set", err)
		}
	}
}

func testshun() {
	conn, err := redis.Dial("tcp", "11.186.5.121:6379", redis.DialReadTimeout(time.Second), redis.DialPassword("Qidian@123"))
	if err != nil {
		// handle error
		fmt.Println("dial failed")
		return
	}
	for i := 0; i < 50; i++ {
		key := fmt.Sprintf("%s_%d", "davinliu_key_%d", i);
		_, err = conn.Do("set", key, "value")
		if err != nil {
			fmt.Println("Do Set", err)
		}
	}
}

func SayHello(w http.ResponseWriter, req *http.Request) {
	w.Write([]byte("Hello"))
}

func SayHello1(w http.ResponseWriter, req *http.Request) {
	buf := [4096]byte{1, 2, 3, 4}
	w.Write(buf[0:])
}

func main() {
	/*a := time.Now()
	for i := 0; i < 10000; i++ {
		test()
	}
	b := time.Now()
	fmt.Println( b.Sub(a) )

	a = time.Now()
	for i := 0; i < 10000; i++ {
		testPipeLine()
	}
	b = time.Now()
	fmt.Println( b.Sub(a) )
	*/
	a := time.Now()
	for i := 0; i < 10000; i++ {
		testshun()
	}
	b := time.Now()
	fmt.Println( b.Sub(a) )
	//http.HandleFunc("/hello", SayHello)
	//http.HandleFunc("/hello1", SayHello1)
	//http.ListenAndServe(":8001", nil)
}

