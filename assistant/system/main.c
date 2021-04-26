/*  main.c  - main */
#include <xinu.h>

process	main(void)
{
	/* Run the Xinu shell */
	recvclr();
  //creation of semaphore
  audio_system = semcreate(2);
  audio_buffer = 0;
  //starting stuff
  kprintf("\nTesting the work!!\n");
  //shell creation
  resume(create(shell, 8192, 50, "shell", 1, CONSOLE));
  //related to alarm
  alarmid = create(alarmproc,8192,30,"alarm",0);
  resume(alarmid);
	// while (TRUE) {
	// 	receive();
	// 	sleepms(200);
	// 	kprintf("\n\nMain process recreating shell\n\n");
	// 	resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	// }
	return OK;
    
}