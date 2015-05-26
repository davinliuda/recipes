#ifndef _SUM_H
#define _SUM_H

int Sum(int* src,int n){
	if(n == 0){
		return 0;
	}
	int a = Sum(src,n-1);
	return n + a;
}

#endif