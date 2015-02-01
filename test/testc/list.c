#include<stdio.h>
typedef struct list_s{
	struct list_s * next;
	int a;
	int b;
} list_t;
main()
{
	list_t lA, lB, lC, lD;
	list_t * phead = &lA;
	lA.next = &lB;
	lA.a = 11;
	lA.b = 12;
	lB.next = &lC;
	lB.a = 21;
	lB.b = 22;
	lC.next = &lD;
	lC.a = 31;
	lC.b = 32;
	lD.next = 0;
	lD.a = 41;
	lD.b = 42;
	printf("%d\n", ((list_t *)phead)->a);
	printf("%d\n", (**(list_t**)phead).a);
	printf("%d\n", (***(list_t***)phead).a);
	printf("%d\n", (****(list_t****)phead).a);
	printf("%d\n", ((list_t *)phead)->b);
	printf("%d\n", (**(list_t**)phead).b);
	printf("%d\n", (***(list_t***)phead).b);
	printf("%d\n", (****(list_t****)phead).b);
}
