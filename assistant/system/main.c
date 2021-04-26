/*  main.c  - main */

#include <xinu.h>

void alarmproc(){
  while (1)
  {
    printf("Current PID: %d\n",currpid);
    umsg32 message = receive();
    if(message != 0){
      printf("Todo Alarm awakened %d\n",message-1);
    }
  }
}

process	main(void)
{
	/* Run the Xinu shell */

	recvclr();
  resume(create(shell, 8192, 50, "shell", 1, CONSOLE));
  alarmid = create(alarmproc,8192,40,"alarmproc",0);
  kprintf("Alarm Id created: %d\n",alarmid);
  resume(alarmid);

	/* Wait for shell to exit and recreate it */

	while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	}
	return OK;
    
}
