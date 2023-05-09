#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]){
	if(argc!=2){
		fprintf(stderr, "Forneça um número como argumento.\n");
		return -1;
	}
	
	int n = atoi(argv[1]);
	if(n<1){
		fprintf(stderr, "Forneça um número maior ou igual a 1.\n");
		return -1;
	}

	pid_t pid = fork();

	if(pid<0){
		fprintf(stderr, "Falha no fork.\n");
		return -1;
	}
	else if(pid==0){
		printf("%d ", n);

		while(n!=1){
			if(n%2==0)
				n /= 2;
			else
				n = (3*n)+1;
			
			printf("%d ", n);
		}
		putchar('\n');
	}
	else{
		wait(NULL);
		printf("Processo filho terminado.\n");
	}

	return 0;
}