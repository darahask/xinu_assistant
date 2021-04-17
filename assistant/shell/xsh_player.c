/* xsh_player.c - xsh_player */

#include <xinu.h>

#include <stdio.h>

#include <string.h>

#include <stdlib.h>
 // #include <time.h>

/*------------------------------------------------------------------------
 * xsh_player - shell command to manage todo commands(create, delete, print, etc.)
 *------------------------------------------------------------------------
 */

// typedef struct Queue queue;

// struct Queue {

// 	char * songName;
// 	queue * next;
// };

// queue * node1, * node2, * start;


// start->songName = "Song ABC";
// start->next = node1;

// node1->songName = "Song PQR";
// node->next = node2;

// node1->songName = "Song XYZ";
// node1->next = NULL;

char queue[3][20] = {"Song ABC","Song PQR","Song XYZ"};
int32 qsize=3;


shellcmd xsh_player(int nargs, char * args[]) {
	int32 i; /* index into proctabl		*/
	int32 nextch; /* character read from file	*/
	did32 descr; /* descriptor for a file	*/
	char * argptr; /* pointer to next arg string	*/
	// FILE    *playerptr;       /* Todo file db pointer */


    if (nargs == 2 && strncmp(args[1], "stop", 4) == 0) {
			printf("Player Stopped.\n",args[1]);
	}

	/* For argument '--help', emit help about the 'cat' command	*/

	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		printf("player play <finename>  --> Play the given song\n");
		printf("player pause (this will pause current running file) \n");
		printf("player stop \n");
		printf("player remove <filename> -> Remove the song\n");
		printf("player queue -> Show the current queue\n");

		return 0;
	}
	if (nargs == 2 && strncmp(args[1], "pause", 5) == 0) {
		printf("Player Stopped\n");
	}
	if (nargs == 3 && strncmp(args[1], "play", 4) == 0) {
		char * song_id = args[2];
		//Creaate a process to play the song
		printf("Player Started song %s\n", song_id);
	}

	if (nargs == 2 && strncmp(args[1], "queue", 5) == 0) {
		kprintf("\nSongs in Queue:\n\n");

		// queue * tmp;
		// tmp = start;
		// if (start == NULL) {
		// 	kprintf("No songs added to queue\n\n");
		// }

		// int cnt = 0;
		// while (tmp != NULL) {
		// 	kprintf("%d. %s\n", cnt, tmp - > songName);
		// }

		for(i=0;i<qsize;i++){
			kprintf("%d. %s\n",i+1,queue[i]);
		}
	}
  
	if (nargs == 3){
		if(strncmp(args[1],"remove",6) == 0){
			char * song_id = args[2];
			//Remove the song file 
			printf("Removed song wth id %s\n", song_id);
		}

	}

	

	return 0;
}