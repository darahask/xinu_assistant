/* xsh_todo.c - xsh_todo */

#include <xinu.h>

/*------------------------------------------------------------------------
 * xsh_todo - shell command to manage todo commands(create, delete, print, etc.)
 *------------------------------------------------------------------------
 */
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
                 printf("ID:%d Message:%s\n",i,tctable[i].message);
            }
        }
    }

    if ((nargs == 3 && strncmp(args[1], "add", 3) == 0) || (nargs == 4 && strncmp(args[1], "add", 3) == 0)) {
        int32 i = 0;
        for(i = 0; i < 100;i++){
            if(tctable[i].deleted == DEL){
                strcpy(tctable[i].message,args[2]);
                tctable[i].startTime = clktime;
                tctable[i].endTime = clktime;
                if(nargs == 4){
                    tctable[i].endTime = clktime + args[3];
                }
                tctable[i].deleted = NDEL;
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
            tctable[id].endTime = clktime + atoi(args[4]);
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