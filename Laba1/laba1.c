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
		printf("Im child!\n");
		printf("CHILD PID - %d\n", getpid());
		sleep(2);
		printf("Enter return code");
		scanf(" %d",&rv);
		printf("CHILD EXIT, RETURN CODE = %d\n", rv);
		exit(rv);
		
		default:
		printf("Im parent!\n");
		printf("PARENT PID - %d\n", getpid());
		wait(&rv);
		printf("PARENT GET RETURN CODE - % d\n",WEXITSTATUS(rv));
		printf("PARENT EXIT\n");	
	}
return 0;
}
