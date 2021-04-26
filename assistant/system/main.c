/*  main.c  - main */

#include <xinu.h>

int32 audio_buffer=0;
pid32 alaid;

void  print_audio_buffer ()
{
  while (1)
  {
    // if(audio_buffer < 100)
      printf("Audio: %d\n",audio_buffer);
  }
}

void alarm_(sid32 audio_system)
{
  int i;
  wait(audio_system);
  for(i=0;i<=100;i++){
    kprintf("check -- %d\n",i);
    audio_buffer = i;
  }
  signal(audio_system);
}

void music_(sid32 audio_system)
{
  int i;
  wait(audio_system);
  // while(1){
    
  // }
  for ( i = 500; i < 1000; i++)
  {
    kprintf("music check -- %d\n",i);
    // sleepms(200);
    audio_buffer = i;
  }
  
  signal(audio_system);
}

void csalarm(){
  while(1){
    if(clktime > 2){
      resume(alaid);
      printf("SWITCHED\n");
      break;
    }
  }
}

process	main(void)
{
	/* Run the Xinu shell */

	recvclr();

  sid32 audio_system = semcreate(2);
  kprintf("\nTesting the work!!\n");

  resume(create(music_,8192, 25, "music", 1, audio_system));
  alaid = create(alarm_,8192, 50, "audio", 1, audio_system);
  resume(create(csalarm,8192, 30, "cswitch", 0));
  // resume(create(print_audio_buffer,8192, 25, "printaudi", 0));

  // resume(create(shell, 8192, 50, "shell", 1, CONSOLE));

	/* Wait for shell to exit and recreate it */

	while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 50, "shell", 1, CONSOLE));
	}
	return OK;
    
}


/*

> todo 


*/