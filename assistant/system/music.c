/* music.c  -  music */

#include <xinu.h>

void	music (sid32 audio_system)
{
  int i;
  wait(audio_system);
  // for ( i = 500; i < 1000; i++)
  // {
  //   kprintf("music check -- %d\n",i);
  //   audio_buffer = i;
  // }
  while (1)
  {
    sleepms(1000);
    kprintf("Seeti maaar ");
  }
  signal(audio_system);
}
