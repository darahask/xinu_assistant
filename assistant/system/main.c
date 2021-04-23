/*  main.c  - main */

#include <xinu.h>

int32 audio_buffer=0;

process	music (sid32 audio_system, int32 val)
{
  int i;
  wait(audio_system);
  // Critical section for us
  // for(i=1;i<=200;i+=2){
  //   printf("Music playing: %d\n",i);
  // }
  audio_buffer = val;
  signal(audio_system);
}

process	alarm (sid32 audio_system, int32 val)
{
  int i;
  wait(audio_system);
  // Critical section for us
  // for(i=1;i<=100;i+=5){
  //   printf("Alarm playing: %d\n",i);
  // }
  audio_buffer = val;
  signal(audio_system);
}

process audio_player()
{
  printf("\nAudio Buffer: %d\n",audio_buffer);
}

process	main(void)
{
	/* Run the Xinu shell */

	recvclr();


  sid32 audio_system = semcreate(1);
  kprintf("\nTesting the work!!\n");
  int i;
  for(i=1;i<=200;i++){
    
  }
  kprintf("\nIt worked maybe!!\n");

	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));

	/* Wait for shell to exit and recreate it */

	while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	}
	return OK;
    
}


