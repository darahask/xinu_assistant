/* music.c  -  music */

#include <xinu.h>

void	music (sid32 audio_system, char* song)
{
  int i;
  wait(audio_system);
  for(i = 1; i < 100; i++)
  {
    sleepms(100);
    audio_buffer = i;
    kprintf("%s-%d ", song,audio_buffer);
  }
  signal(audio_system);
  musicprocid = NULL;
}
