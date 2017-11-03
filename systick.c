#include <stdio.h>
		
typedef struct sCallChain{
	struct sCallChain *next;
	void (*func)(void);
}tCallChain;

static tCallChain* vSystickCall = NULL;

#define SYSTICKCALL(name) \
void systick_call_##name(void); \
tCallChain name = {NULL, systick_call_##name};\
void systick_call_##name(void)

SYSTICKCALL(hello)
{
	printf("Hello!\n");
	printf("%s\n", __FUNCTION__);
}

SYSTICKCALL(world)
{
	printf("world!\n");
	printf("%s\n", __FUNCTION__);
}

SYSTICKCALL(goodbye)
{
	printf("goodbye\n");
	printf("%s\n", __FUNCTION__);
}

void halSystickCallSet(tCallChain *call)
{
	tCallChain *c ;
	for(c = vSystickCall; c != NULL; c = c->next)
	{
		if(c == call)
		{
			printf("The node is already in the list!\n");
			return;
		}
	}

	call->next = vSystickCall;
	vSystickCall = call;
}

void halSystickCallClr(tCallChain *call)
{
	tCallChain *c;

	if(vSystickCall == call)
	{
		vSystickCall = vSystickCall->next;
	}
	else
	{
		for(c == vSystickCall; c !=NULL; c = c->next)
		{
			if(c->next == call)
			{
				c->next = call->next;
				break;
			}
			
		}
	}	

	call->next = NULL;
}

void systick_handler(void)
{
	tCallChain *c;
	for(c = vSystickCall; c != NULL; c = c->next)
	{
		c->func();
	}
}

void main()
{
	halSystickCallSet(&hello);	
	halSystickCallSet(&world);
	halSystickCallSet(&goodbye);
	halSystickCallSet(&hello);	
	systick_handler();
	printf("***********\n");
	

	halSystickCallClr(&hello);
	halSystickCallClr(&world);
	halSystickCallClr(&goodbye);

	systick_handler();
}



