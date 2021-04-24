#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "repl.h"
#include "strvec.h"

/*
Nick Pierce
Driver file to accept input from file handle (stdin) that targets the keyboard and parse statements
into the command and all arguments relating to it to screen (stdout)
Uses a strvec to retain the various instructional components
*/

void main(void){

	// inits a strvec
	strvec cmd;
	strvec_init(&cmd);

	do {
		prompt();
		read_cmd(&cmd);
		if(strcmp(cmd.stringPointer[0], "exit") == 0 || strcmp(cmd.stringPointer[0], " ") == 0)
			continue;
		exec_cmd(&cmd);
	} while (strcmp(strvec_get(cmd, 0), "exit") != 0);

	strvec_free(&cmd);
}
