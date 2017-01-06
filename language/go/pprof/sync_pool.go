package main


import(
    "sync"
    "bytes"
    "time"
)

var ci sync.Pool


type CacheChatMsgInfo struct {
    sync.Mutex
    MsgId             int64
    MsgTag            int
    Time              int64
    Data              *bytes.Buffer
    ref               int32
    TimeRecvFromLogic int64
    TimeSendToClient  int64
}

func init() {
    ci.New = func() interface{} {
        return &CacheChatMsgInfo{
            Data: &bytes.Buffer{},
            ref:  0,
        }
    }
}


func main(){
    for i := 0 ;i < 10000;i++{
        go func(){
           for{
                _ = ci.Get().(*CacheChatMsgInfo);
                //ci.Put(c)
                time.Sleep(10 * time.Millisecond)
                //ci.Put(c)
            } 
        }()
    }

    select{}

}
