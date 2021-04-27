/* music.c  -  music */

#include <xinu.h>

void	music (sid32 audio_system, char* song)
{
  int i;
  wait(audio_system);
  // for ( i = 500; i < 1000; i++)
  // {
  //   kprintf("music check -- %d\n",i);
  //   audio_buffer = i;
  // }
  // while (1)
  for(i = 1; i < 100; i++)
  {
    sleepms(100);
    kprintf("%s-%d ", song,i);
  }
  signal(audio_system);
  musicprocid = NULL;
}
