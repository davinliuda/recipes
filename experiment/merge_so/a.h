#ifndef _A_H_
#define _A_H_

class AA {
public:
    static AA* Instace() {
        static AA obj;
        return &obj;
    }
    int getA() {
	return a++;
    }
    int a = 0;
};

#endif

