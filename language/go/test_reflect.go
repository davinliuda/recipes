package main
import(
    "reflect"
    "fmt"
)


type BBB struct{
    
}

type AAA struct{
    a int `spack:"a"`
    b int `spack:"c"`
    c BBB `spack:"bbb"`
}


func main(){

    a := AAA{}

    val := reflect.ValueOf(&a)

    
    fmt.Println(val.Kind())

    cc := reflect.ValueOf(val.Elem().Interface())
    
    for i:=0; i<cc.NumField();i++{
        f := cc.Type().Field(i)
        fmt.Println(f.Name)
        fmt.Println(f.Tag)
        fmt.Println(f.Tag.Get("spack"))
    }

}
