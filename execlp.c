#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	 
	 pid_t pid;
	 pid = vfork();
	 
	 if (pid < 0) {
		fprintf(stderr, "error -- failed to fork()");
		exit(EXIT_FAILURE);	
	}
	
	if (pid > 0) {
		
		int child_ret;
		
		waitpid(pid, &child_ret, 0);
		printf("Child exited with return code %i\n", WEXITSTATUS(child_ret));
		exit(EXIT_SUCCESS);
	} 
	
	else{
		getpid();
		execlp("ls", "ls", "-lh", (char *)NULL);
		exit(EXIT_SUCCESS);
	}
}

