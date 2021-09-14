package main

import (
	"fmt"
	"net"
	"time"
)

func main() {
	var (
		cliList  map[string]int = make(map[string]int, 10)
		addr     *net.UDPAddr
		err      error
		mainConn *net.UDPConn
		buf      []byte = make([]byte, 1024)
	)

	addr, err = net.ResolveUDPAddr("udp4", "0.0.0.0:12110")
	if err != nil {
		fmt.Println("resolve udp addr err:", err.Error())
		return
	}
	if mainConn, err = net.ListenUDP("udp4", addr); err != nil {
		return
	}
	for {
		l, cAddr, err := mainConn.ReadFromUDP(buf)
		fmt.Println(l, cAddr, err, string(buf[0:l]))
		cliList[cAddr.String()] = int(time.Now().Unix())


		for key, _ := range cliList {
            for key1, _ := range cliList{
                addr, err = net.ResolveUDPAddr("udp4", key)
                for i:=0;i<10;i++{
                        if key != key1{
                            l, err = mainConn.WriteToUDP([]byte(key1), addr)
                            fmt.Println("write to udp reciver:", addr, "talk:", key1, err)
                        }
                }
            }
        }
        //time.Sleep(1*time.Second)
	}
}
