#include <xinu.h>
#include <stdio.h>
#include <string.h>

shellcmd xsh_todo(int nargs, char*args[]){

	

    if(nargs == 3 && strncmp("complete",args[1],8)==0){
		printf("\ninside todo complete...\n");
		
		lfsopen(&devtab[17],"todo.txt","w");
		lflputc(&devtab[17],'k');
		lflwrite(&devtab[17],"kirtik",6);
		lflclose(&devtab[17]);
		
	}

	return 0;
}
