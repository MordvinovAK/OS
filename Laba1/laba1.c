#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
pid_t pid;
int rv;
	switch(pid=fork()) 
	{
		case -1:
		printf("Error");
		exit(1);
		
		case 0:
		printf("IM CHILD!\n");
		printf("CHILD PID - %d\n", getpid());
		sleep(3);
		printf("VVEDITE KOD VOZVRATA");
		scanf(" %d",&rv);
		printf("CHILD EXIT, KOD VOZVRATA = %d\n", rv);
		exit(rv);
		
		default:
		printf("IM PARENT!\n");
		printf("PARENT PID - %d\n", getpid());
		wait(&rv);
		printf("PARENT POLUCHIL KOD VOZVRATA - %d\n",WEXITSTATUS(rv));
		printf("PRENT EXIT\n");	
	}
return 0;
}
