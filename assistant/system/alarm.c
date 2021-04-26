#include<xinu.h>

void alarmproc(){
  while (1)
  {
    umsg32 message = receive();
    if(message != 0){
        kprintf("Todo Alarm awakened %d\n",message-1);
        wait(audio_system);
        int i;
        for(i=0;i<=100;i++){
            kprintf("check -- %d\n",i);
            audio_buffer = i;
        }
        signal(audio_system);
    }
  }
}