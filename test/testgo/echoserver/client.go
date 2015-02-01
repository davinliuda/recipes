package main

import(
        "fmt"
        "net"
	"bytes"
	"time"
)

var req int32
var client int32
func printQps(){
	for{
		time.Sleep(time.Second)
		fmt.Println("qps:",req)
		req=0
	}
}
func handconnection(conn net.Conn){
	buf := bytes.NewBufferString("hello,world").Bytes()
	for{
		_,err := conn.Write(buf)
		if err != nil{
                        client--
			conn.Close()
                        return
                }
		req++
		_,err = conn.Read(buf)
                if err != nil{
                        client--
			conn.Close()
                        return
                }
		time.Sleep(1*time.Millisecond)
	}

}

func main(){
	go printQps()
	for{
		if client >= 20000{
                        time.Sleep(60*time.Second)
                }	
		conn, err := net.Dial("tcp", "10.210.215.64:999")
		if err != nil {
			fmt.Println("dial error",err.Error())
			continue
		}
		client++
		fmt.Println("tcp connected nums:",client,":",req)
		go handconnection(conn)
	}
}
