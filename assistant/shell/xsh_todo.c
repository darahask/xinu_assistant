/* xsh_todo.c - xsh_todo */

#include <xinu.h>

#include <stdio.h>

#include <string.h>
 // #include <time.h>

/*------------------------------------------------------------------------
 * xsh_todo - shell command to manage todo commands(create, delete, print, etc.)
 *------------------------------------------------------------------------
 */
shellcmd xsh_todo(int nargs, char * args[]) {
    int32 i; /* index into proctabl		*/
    int32 nextch; /* character read from file	*/
    did32 descr; /* descriptor for a file	*/
    char * argptr; /* pointer to next arg string	*/
    // FILE    *todoptr;       /* Todo file db pointer */
    int id = 0;

    /*
    Every song can be of type of their transcripts.
    eg.
    0-3 "..."
    3-4 "..."
    4-6 "..."
    .
    .
    etc.
    */


    /* For argument '--help', emit help about the 'cat' command	*/

    if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
        printf("todo show - lists all the todos\n");
        printf("todo add <text> \n");
        printf("todo complete <todo_id> \n");
        printf("todo edit <todo_id> <new_text>\n");
        return 0;
    }
    if (nargs == 2 && strncmp(args[1], "show", 4) == 0) {
        // char* line;
        // todoptr = fopen("../database/todo.txt","r");
        // fscanf(todoptr,"%s", line);
        // printf("%s", line);
        // fclose(todoptr);
        printf("<i,dbmsassignment>\n");
    }

    if (nargs == 3 && strncmp(args[1], "add", 3) == 0) {
        // char* line;
        // time_t seconds;
        // argptr = args[2];
        // seconds = time(NULL);
        // todoptr = fopen("../database/todo.txt","w");
        // itoa(seconds,line);
        // strcat(line,", ");
        // strcat(line,argptr);
        // fprintf(todoptr,"%s", line);
        printf("Added %s\n",args[2] );
        // fclose(todoptr);
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




    
/* krithik */
// #include <xinu.h>
// #include <stdio.h>
// #include <string.h>

    // shellcmd xsh_todo(int nargs, char*args[]){
    // lfsopen( & devtab[17], "todo.txt", "w");
    // lflputc( & devtab[17], 'k');
    // lflwrite( & devtab[17], "kirtik", 6);
    // lflclose( & devtab[17]);
    // }

    return 0;
}


