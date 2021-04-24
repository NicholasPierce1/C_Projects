#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "repl.h"
#include "strvec.h"

/*
Nick Pierce
Implements the various method signatures/prototypes enclosed within
repl.h that are required to parse instructions and display them in stdout (file handle for keyboard ouput)
*/

// prompts user for input
void prompt(void){
	// sets the color of the input print to green
	printf("\033[0;34m");

	printf("$> ");

	// sets the color back to default
	printf("\033[0m");
}

// reads, and parses, input typed from the user on the command line
// input tokens (strings) are stored within the given strvec
// NOTE: buffer limits only 255 characters
void read_cmd(strvec* cmd){
	//char * buffer = calloc(256, sizeof(char*));
	//size_t buffsize = 256;
	//int read = getline(&buffer, &buffsize, stdin);
	// make sure the string vector of commands is empty

        int terminate = 1;
        int size = 0;
        int capacity = 2;
        char* string = (char*)calloc(capacity, sizeof(char));
        do{
                char* scan_ptr = (char*)calloc(1, sizeof(char));
                scanf("%c", scan_ptr);
                terminate = *scan_ptr == '\n' ? 0 : 1;
                if(terminate){
                        if(size + 1 == capacity)
                                string = (char*)realloc(string, sizeof(char) * ++capacity);
                        string[size++] = *scan_ptr;
                }
                else
                        string[size + 1] = '\0'; // or capacity - 1
                free(scan_ptr);
                scan_ptr = NULL;
        }while(terminate);

	strvec_free(cmd);
	// note, my strvec_free and strvec_push functions left the string vector
	// in a state that it could be used.  You may need to change yours.

	char * ptr = strtok(string, " \n");
	while (ptr)
	{
		strvec_push(cmd, ptr);
		ptr = strtok(NULL, " \n");
	}

	if(strvec_size(*cmd) == 0)
		strvec_push(cmd, " "); // hacky
	free(string);
	return;
}

// reads each command, with its corresponding arguments, and executes it
// currenlty: just print command with its corresponding arguments on a new line of stdout
void exec_cmd(const strvec* cmd){

	// holds the size of the strvec
	int size = strvec_size(*cmd);

	// asserts the size of the incoming strvec is greater than 0
	if(size == 0)
		return;

	// commences fork operation
	// Parent: waits for child process to execute the instructions passed within the str vector & reopens inputs
	// Child: executes the command + corresponding arugments to the terminal
	int cpid = fork();

	// determines if the spawned process is the child
	if(cpid == 0){

		// executes instruction encompassed within strvec
		if(execvp(cmd->stringPointer[0], cmd->stringPointer) == -1){
			perror(cmd->stringPointer[0]);
			exit(errno);
		}
	}
	else if(cpid < 0){
		// converts errno to a string ([5]) and inputs into perror
		char errString[5];
		sprintf(errString, "%d", errno);
		perror(errString);
	}
	else {  // in parent process
		// wait for child to finish

		// holds the status of child process whenever it changes from run/active
		int status;

		// holds the pid value of the child process that changed
		// this will only be the child that we spawned here (equal to cpid) but
		// in other use cases, where 1:m processes are transpiring, this value is integral
		// for denoting which process this method returned from
		pid_t childIdThatChangedState;

		// instigates a perrenial do-while where we wait for the child process -- denoted by pid value
		// (that's greater than 0) as it changes states until it is either stopped or recieved
		// a signal that the child process did not handle
		do{
			childIdThatChangedState = waitpid(cpid, &status, WUNTRACED); // wuntraced -- return on errors
		}while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
