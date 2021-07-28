/* 	Adalberto Ramirez
*  	vyr040
*
*	program creates a child process and reads the files and prints the output in those
*	child process that are inputted from the command argument when the program is ran
*	when the child process is finished the program the displays the child process print
*	that the X number of files passed through have been read
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fptr;
    int i;
    char word;

	// for loop that creates the child process using fork()
    for(i = 1; i<=argc; i++)
    {
		// if the child process is equal to 0
        if(fork()==0)
        {

            int wordCount = 0;
			// if the counter is not equal to the end of the list
            if(i != argc)
            {
				// opens the current file
                fptr = fopen(argv[i], "r");
				// if NULL displays to the user that the file can not be opened
                if(fptr == NULL)
                {
                    printf("Cannot open file\n");
                }
                else
                {
					// reads the file untill it reaches the end of the file
                    while(word != EOF)
                    {
						//saves the character into word
                        word = fgetc(fptr);
						//if the character is a space or nextline character increments by 1
                        if (word == ' ' || word == '\n')
                        {
                            wordCount +=1;
                        }
                        //printf("%c", word);
                    }
                    printf("\nChild process for File_%s: number of words is %d\n", argv[i], wordCount);
             //       printf("\n");
                }
				// closes the file
                fclose(fptr);
            }
			// exits the child process
            exit(0);
        }
    }
	// prints the parent process output
    printf("All %d files have been counted!\n", argc-1);
    return 0;
        
}
