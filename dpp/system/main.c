/*  main.c  - main */

#include <xinu.h>

sid32 room;
sid32 spoon[5];

void philosopher( int );
void eat(int);

process main(void)
{
	recvclr();
	int i;
	pid32 pid[5];
	
	room = semcreate(5);
	
	for(i=0;i<5;i++)
		spoon[i] = semcreate(1);
		
	for(i=0;i<5;i++){
		pid[i] = create(philosopher,4096,20,"phy",1,i);
	}
	for(i=0;i<5;i++)
		resume(pid[i]);

	return OK;
}

void philosopher(int phil)
{

	wait(room);
	kprintf("Philosopher %d has entered room\n",phil);
	wait(spoon[phil]);
	wait(spoon[(phil+1)%5]);

	eat(phil);
	sleep(2);
	kprintf("Philosopher %d has finished eating\n",phil);

	signal(spoon[(phil+1)%5]);
	signal(spoon[phil]);
	signal(room);
}

void eat(int phil)
{
	kprintf("Philosopher %d is eating\n",phil);
}
