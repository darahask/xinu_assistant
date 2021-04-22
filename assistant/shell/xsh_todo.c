/* xsh_todo.c - xsh_todo */

#include <xinu.h>

/*------------------------------------------------------------------------
 * xsh_todo - shell command to manage todo commands(create, delete, print, etc.)
 *------------------------------------------------------------------------
 */
shellcmd xsh_todo(int nargs, char * args[]) {

    if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
        printf("todo show - lists all the todos\n");
        printf("todo add <text> \n");
        printf("todo complete <todo_id> \n");
        printf("todo edit <todo_id> <new_text>\n");
        return 0;
    }
    if (nargs == 2 && strncmp(args[1], "show", 4) == 0) {
        int32 i = 0;
        for(i = 0; i < 100;i++){
            printf("ID:%d Message:%s\n",i,tctable[i].message);
        }
    }

    if (nargs == 3 && strncmp(args[1], "add", 3) == 0) {
        strcpy(tctable[tcindex].message,args[2]);
        tctable[tcindex].startTime = clktime;
        tcindex++;
        printf("Added %s\n",args[2] );
    }

    if (nargs == 3 && strncmp("complete", args[1], 8) == 0) {
        
        printf("\nTodo %s marked as completed...\n",args[2]);
    }
    
    if(nargs == 4 && strncmp(args[1] , "edit", 3) == 0){
        char* todo_id = args[2];
        char*  new_todo = args[3];
        //Change the file .
        //Find the todo with the given id and update it.
        printf("Successfully edited the todo\n");
    }

    if(nargs >= 3 && strncmp(args[1],"del",3) == 0) {
      printf("\nDelete %s has been deleted...\n",args[nargs-1]);
    }

    return 0;
}


