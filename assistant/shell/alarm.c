/* alarm.c  -  alarm */

#include <xinu.h>
#include <stdio.h>

/************************************************************************/
/* alarm  -  
/************************************************************************/

process	alarm (sid32 audio_system)
{
  int i;
  // wait(audio_system);
  // Critical section for us
  for(i=1;i<=100;i+=5){
    printf("Alarm playing: %d\n",i);
  }
  // signal(audio_system);
}


/*

music is playing and it has resource as sound system

suddenly alarm starts ringing
so it needs access to sound system
so it needs a high priority as well
and music has to release its lock over sound system

Once alrm stops ringing, music system resumes back its process

*/