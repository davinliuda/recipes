namespace cpp weibo

struct Request{
    1: string data
}

struct Response{
    1: string data 
}


service Service{

    Response control(1: Request param)
}
