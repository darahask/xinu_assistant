/* xsh_phil.c - xsh_phil */

#include <xinu.h>

/*------------------------------------------------------------------------
 * xsh_phil - shell command to manage phil commands(create, delete, print, etc.)
 *------------------------------------------------------------------------
 */


sid32 room;
sid32 spoon[100];

void philosopher( int, int );
void eat(int);


shellcmd xsh_phil(int nargs, char * args[]) {

    if (nargs == 2 ) {
        int no_phil = atoi(args[1]);
        int i;
        pid32 pid[no_phil];
        
        room = semcreate(no_phil);
        
        for(i=0;i<no_phil;i++)
            spoon[i] = semcreate(1);
            
        for(i=0;i<no_phil;i++){
            pid[i] = create(philosopher,4096,20,"phy",2,i,no_phil);
        }
        for(i=0;i<no_phil;i++)
            resume(pid[i]);
    }


    return 0;
}

void philosopher(int phil, int no_phil)
{

	wait(room);
	kprintf("Philosopher %d has entered room\n",phil);
	wait(spoon[phil]);
	wait(spoon[(phil+1)%no_phil]);

	eat(phil);
	sleep(2);
	kprintf("Philosopher %d has finished eating\n",phil);

	signal(spoon[(phil+1)%no_phil]);
	signal(spoon[phil]);
	signal(room);
}

void eat(int phil)
{
	kprintf("Philosopher %d is eating\n",phil);
}