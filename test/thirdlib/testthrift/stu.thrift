struct StudentRequest{
	   1: i32 sno,
	   2: string sname,
	   3: bool ssex,
	   4: i16 sage,
}

struct StudentResult{
	1: i32 ret,
	2: string smsg,
}



service Serv{
	StudentResult put(1: StudentRequest s),
}
