#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
int main() 
{ 
        //A null terminated array of character  
        //pointers 
        //char *args[]={"ls",NULL};
	char** args = (char**)calloc(4, sizeof(char*));
	args[0] = "touch";
	args[1] = "blah.c";
	args[2] = "blah1.c";
	// 1st arg of double pointer (or *char []) MUST be the command itself!!
	printf("is 2nd arg null: %s\n", args[1] == NULL ? "true" : "false");
        //execvp(args[0],args); 
      	execvp(args[0], args);
        /*All statements are ignored after execvp() call as this whole  
        process(execDemo.c) is replaced by another process (EXEC.c) 
        */
        printf("Ending-----"); 
      
    return 0; 
}
