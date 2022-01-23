#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	 pid_t pid;
	 pid = fork();
	 
	 if (pid < 0) {
		fprintf(stderr, "error -- failed to fork()");
		exit(EXIT_FAILURE);	
	}
	
	if (pid > 0) {
		
		int child_ret;
		
		wait(&child_ret);
		printf("Child exited with return code %i\n", WEXITSTATUS(child_ret));
		exit(EXIT_SUCCESS);
	} 
	
	else{
		getpid();

		char  *args[] = {"ls", "-lh", (char *)NULL};
		execvp("ls", args);
		exit(EXIT_SUCCESS);
	}
}

