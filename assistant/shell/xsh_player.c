/* xsh_player.c - xsh_player */
#include <xinu.h>

/*------------------------------------------------------------------------
 * xsh_player - shell command to manage todo commands(create, delete, print, etc.)
 *------------------------------------------------------------------------
 */

shellcmd xsh_player(int nargs, char * args[]) {

    if (nargs == 2 && strncmp(args[1], "stop", 4) == 0) {
		if(musicprocid){
			printf("about to stop\n");
			kill(musicprocid);
			musicprocid = NULL;
			printf("Player Stopped.\n",args[1]);
		}
		else
			printf("No music is playing at the moment \n");
			
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
		if(musicprocid)
		{
			pri16 suspended_id = suspend(musicprocid);
			printf("return val - %d\n", suspended_id);
		}else
			printf("No music is playing at the moment \n");
		
	}

	if (nargs >= 2 && strncmp(args[1], "play", 4) == 0) {
		if(nargs == 2)
		{
			if(musicprocid)
			{
				printf("inside resume\n");
				resume(musicprocid);
			}
			else
				printf("No music is running\n");
			
		}
		else
		{
			printf("starting new song %d\n", nargs);
			char * song = args[2];
			musicprocid = create(music, 8192, 25, "music", 2, audio_system, song);
			resume(musicprocid);
		}
		
	}

	return 0;
}