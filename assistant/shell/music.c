/* music.c  -  music */

#include <xinu.h>
#include <stdio.h>

/************************************************************************/
/* music  -  
/************************************************************************/

process	music (sid32 audio_system)
{
  int i;
  // wait(audio_system);
  // Critical section for us
  for(i=1;i<=200;i+=2){
    printf("Music playing: %d\n",i);
  }
  // signal(audio_system);
}
