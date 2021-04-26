/* xsh_todo.c - xsh_todo */

#include <xinu.h>

/*------------------------------------------------------------------------
 * xsh_todo - shell command to manage todo commands(create, delete, print, etc.)
 *------------------------------------------------------------------------
 */

int32 cal[31][100];
int32 day;

shellcmd xsh_todo(int nargs, char * args[]) {

    if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
        printf("todo show - lists all the todos\n");
        printf("todo add <text> <end time in seconds optional> \n");
        printf("todo complete <todo_id> \n");
        printf("todo edit <todo_id> <new_text> <end time in seconds optional>\n");
        return 0;
    }
    if (nargs == 2 && strncmp(args[1], "show", 4) == 0) {
        int32 i = 0;
        for(i = 0; i < 100;i++){
            if(tctable[i].deleted == NDEL){
                printf("ID:%d\tMessage:%s\tStartTime:%d\tEndTime:%d\n",i,tctable[i].message,tctable[i].startTime,tctable[i].endTime);
            }
        }
    }

    if (nargs == 2 && strncmp(args[1], "send", 4) == 0) {
        int32 i = 0;
        kprintf("Alarm Id in todo part: %d\n",alarmid);
        for(i = 0; i < 100;i++){
            if(tctable[i].endTime <= clktime && tctable[i].endTime!=0){
                kprintf("%d\n",i);
                send(alarmid,i+1);
            }
        }
    }

    if (nargs == 3 && strncmp(args[1], "show", 4) == 0 && strncmp(args[2], "cal", 3) == 0) {
        int32 i = 0,j;
        for(i=1;i<31;i++){
            if(cal[i][0]==0)
                continue;
            
            printf("\nDay %d: \n",i);
            for(j=0;j<100;j++){
                if(cal[i][j]==0)
                    break;
                if(tctable[cal[i][j]].deleted==NDEL)
                    printf("ID:%d\tMessage:%s\n",cal[i][j],tctable[cal[i][j]].message);
            }
        }
    }


    if ((nargs == 3 && strncmp(args[1], "add", 3) == 0) || (nargs == 4 && strncmp(args[1], "add", 3) == 0)) {
        int32 i = 0,j;
      
        for(i = 1; i < 101;i++){
            if(tctable[i].deleted == DEL){
                strcpy(tctable[i].message,args[2]);
                tctable[i].startTime = clktime;
                tctable[i].endTime = clktime;
                if(nargs == 4){
                    tctable[i].endTime = clktime + atoi(args[3]);
                }
                tctable[i].deleted = NDEL;
                day = (tctable[i].endTime + 19)/20;
                for(j=0;j<100;j++){
                    if(cal[day][j]==0){
                        cal[day][j]=i;
                        break;
                    }
                }
                break;
            }


        }
        printf("Added %s\n",args[2] );
    }

    if (nargs == 3 && strncmp("complete", args[1], 8) == 0) {
        int id = atoi(args[2]);
        tctable[id].status = DONE;
        printf("\nTodo %s marked as completed...\n",args[2]);
    }
    
    if((nargs == 4 && strncmp(args[1] , "edit", 3) == 0) || (nargs == 5 && strncmp(args[1] , "edit", 3) == 0)){
        int id = atoi(args[2]);
        strcpy(tctable[id].message,args[3]);
        if(nargs == 5){
            int32 j;
            day = (tctable[id].endTime + 19)/20;
            for(j=0;j<100;j++){
                if(cal[day][j]==id){
                    cal[day][j]=0;
                    break;
                }
            }
            tctable[id].endTime = clktime + atoi(args[4]);
            

            day = (tctable[id].endTime + 19)/20;
            
            for(j=0;j<100;j++){
                if(cal[day][j]==0){
                    cal[day][j]=id;
                    break;
                }
            }
        }
        printf("Successfully edited the todo\n");
    }

    if(nargs = 3 && strncmp(args[1],"del",3) == 0) {
      printf("\nDelete %s has been deleted...\n",args[nargs-1]);
      int id = atoi(args[2]);
      tctable[id].deleted = DEL;
    }

    return 0;
}