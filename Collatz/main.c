#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]){
	/*
		Fork faz o processo filho começar na
		próxima linha de código.

		Enquanto o pai está fazendo a checagem
		o processo filho está fazendo ela ao
		mesmo tempo.
	*/
	pid_t pid = fork();

	if(pid<0){
		fprintf(stderr, "Fork failed.\n");
		return -1;
	}
	else if(pid==0){
		// O pai é o processo principal
		printf("[FILHO]: %d		[PAI]: %d\n", getpid(), getppid());

		// execlp faz com que o processo filho seja substituido
		//execlp("/bin/ls", "ls", "-ll");
	}
	else{
		// O pai é o shell
		printf("[PROCESSO]: %d	[PAI]: %d\n", getpid(), getppid());
		wait(NULL);
		printf("Child complete.\n");
	}

	return 0;
}