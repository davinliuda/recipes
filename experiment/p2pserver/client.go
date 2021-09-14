package main

import (
	"fmt"
	"net"
    "time"
)

func connect(saddr string){
    var (
        addr     *net.UDPAddr
        err      error
        mainConn *net.UDPConn
        buf      []byte = make([]byte, 1024)
        length   int
    )

    addr, err = net.ResolveUDPAddr("udp4", saddr)
    if err != nil {
        return
    }
    if mainConn, err = net.ListenUDP("udp4", nil); err != nil {
        fmt.Println(err.Error())
        return
    }
    s := "register" + mainConn.LocalAddr().String()
    length, err = mainConn.WriteTo([]byte(s), addr)
    for {
        fmt.Println("recv..........")
        length, addr, err = mainConn.ReadFromUDP(buf)
        sss := string(buf[0:length])
        fmt.Println("read from udp", addr.String(), sss, length)
        time.Sleep(1*time.Second)
        for i:=1;i<5;i++{
            addr, err = net.ResolveUDPAddr("udp4", sss)
            length, err = mainConn.WriteTo([]byte("send dataing..."), addr)
            fmt.Println("yyy", addr.String(), err, length)
            time.Sleep(time.Millisecond)
        }
    }


}


func main() {

    go connect("5.9.42.142:12110")
    //go connect("5.9.42.143:12110")
    time.Sleep(100*time.Second)

}
