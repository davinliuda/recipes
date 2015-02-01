package main

import(
	"fmt"
	"net"
	"time"
)

var client int32
var recv int32
var send int32

func printQps(){
	for{
		fmt.Println("qps,send: recv",send," ",recv)
		send=0
		recv=0
		time.Sleep(time.Second)
	}
}
func handleConnection(conn net.Conn){
	buf := make([]byte,1024)
	for{
		length1,err := conn.Read(buf)
		if err != nil{
			client--
			fmt.Println("client error",err.Error(),client)
			conn.Close()
			return
		}
		recv++
		length2,err := conn.Write(buf[0:length1])
		if err != nil{
			fmt.Println("client error",err.Error(),client)
			client--
			conn.Close()
			return
		}
		send++
		if length2 != length1{
			fmt.Printf("write block,length1:%d length2:%d",length1,length2)
		}
	}
}

func main(){
	ln, err := net.Listen("tcp", ":999")
	if err != nil {
		fmt.Println("accept:",err.Error())
		return
	}
	go printQps()
	for {
		conn, err := ln.Accept()
		if err != nil {
			fmt.Println("error:",err.Error())
			continue
		}
		client++
		fmt.Println("client come in:",client)
		go handleConnection(conn)
	}

}
