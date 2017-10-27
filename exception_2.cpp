#include <stdio.h>
#include <setjmp.h>

#define	   RET 	  1
jmp_buf buf;


double Divide(double a, double b)
{
	if(b == 0.0)
	{
		longjmp(buf, RET);
	}
	else
	{
		return a / b;
	}
}

int main ()
{
	int ret;
	ret = setjmp(buf);	
	if(ret == 0)
	{
		printf("Dividing ...\n");
		printf("a/b = %f\n", Divide(5.0, 0.0));
	}
	else if(ret == RET)
	{
		printf("Division by zero\n ");
	}
   	return 0;
}



