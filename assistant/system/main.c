/*  main.c  - main */

#include <xinu.h>

int32 audio_buffer=0;
int prev=-1;

void  write_to_audio_buffer (sid32 audio_system, int32 val)
{
  wait(audio_system);
  audio_buffer = val;
  // prev = val;
  signal(audio_system);
}

void alarm_(sid32 audio_system)
{
  printf("in alarm");
  int32 i;
  for(i=1;i<=40;i+=5){
    // resume(create(write_to_audio_buffer, 8192, 30, "ala", 2, audio_system, i));
    wait(audio_system);
    audio_buffer = i;
    // prev = val;
    signal(audio_system);
  }
}

void music_(sid32 audio_system)
{
  int32 i;
  for(i=100;i<=200;i+=2){
    if(i==150){
      printf("##################################################################################\n");
      resume(create(alarm_, 8192, 40, "alarm", 1, audio_system));
    }else{
      // printf("##################################################################################\n");
      // resume(create(write_to_audio_buffer, 8192, 30, "mus", 2, audio_system, i));
      wait(audio_system);
      audio_buffer = i;
      // prev = val;
      signal(audio_system);
    }
  }
}

void audio_player(sid32 audio_system)
{
  // printf("before audio\n");
  // int i;
  while(1)
  {
    // wait(audio_system);
    printf("*\n");
    // int a = 5;
    if(audio_buffer)
    {
      printf("\nAudio - %d\n", audio_buffer);
    }
    // int b = a;
    // signal(audio_system);
  }
    // printf("after audio\n");

}


process	main(void)
{
	/* Run the Xinu shell */

	recvclr();


  sid32 audio_system = semcreate(1);
  kprintf("\nTesting the work!!\n");

  resume(create(audio_player, 8192, 50, "audio_player", 1, audio_system));
  resume(create(music_,8192, 25, "music", 1, audio_system));
  
  // resume(create(shell, 8192, 50, "shell", 1, CONSOLE));


  kprintf("\nIt worked maybe!!\n");

	/* Wait for shell to exit and recreate it */

	// while (TRUE) {
	// 	receive();
	// 	sleepms(200);
	// 	kprintf("\n\nMain process recreating shell\n\n");
	// 	resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	// }
	return OK;
    
}


