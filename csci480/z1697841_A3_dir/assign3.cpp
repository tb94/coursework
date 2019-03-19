
    //*************************************************//
    //                     CSCI 480                    //
    //       Assignment 3 - Microshell Simulation      //
    //                                                 //
    // This program creates a microshell to take       //
    // a custom pipe symbol                            //
    //                                                 //
    // Programmer - Tim Bretz                          //
    // Date - 9/25/17                                  //
    //*************************************************//

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    char buf[1024];
    pid_t pid1,
          pid2;
    int status;
    char *cmd1[10],
         *cmd2[10]; // array of commands and arguments 
    int i = 0;
    int pipeA[2];

    printf("480 shell> ");

    while (cin.getline(buf, 1024))
        {
            bool p = false;
            i = 0; 
            while (i < 10)
            {
                cmd1[i] = NULL;
                cmd2[i] = NULL;
                i++;
            }

            if (strcmp(buf, "q") == 0 || strcmp(buf, "quit") == 0)
            {
                exit(0);
            }
            
            for (int j = 0; i < strlen(buf); i++)
            {
                if (buf[j] == '|' && buf[j + 1] == '|');
                {
                    // pipe
                    p = true;
                }
            }

            if (p == true)
            {
                char *command[2];
                int num = 0;
                char *ptr;

                command[0] = strtok(buf, "||");
                
                while ((ptr = strtok(NULL, "||")) != NULL)
                {
                    num++;
                    command[num] = ptr;
                }
                
                num = 0;
                cmd1[0] = strtok(command[0], " ");
                
                while((ptr = strtok(NULL, " ")) != NULL)
                {
                    num++;
                    cmd1[num] = ptr;
                }

                num = 0;
                cmd2[0] = strtok(command[1], " ");

                while ((ptr = strtok(NULL, " ")) != NULL)
                {
                    num++;
                    cmd2[num] = ptr;
                }


                if (pipe(pipeA) == -1)
                {
                    perror("pipe A eroor");
                    exit(-5);
                }
                

                if ((pid1 = fork()) < 0)
                        {printf("fork error");}

                else if (pid1 == 0)
                {
                    // child
               
                    // close standard out
                    close(1);
                    close(pipeA[0]);
                    // dup standard out to pipe(write end)
                    dup(pipeA[1]);
                    
                    // close the pipe
                    close(pipeA[1]);
                    
                    // execute command
                    execvp(cmd1[0], cmd1);
                    
                    // print error, exit(error)
                    cerr << "Exec err" << cmd1 << endl;
                    exit(-1);
                    
               }
               if ((pid2 = fork()) < 0)
               {
                     printf("fork error");
               }


               else if (pid2 == 0)
               {
                   // second child
                        
                    close(0);
                    close(pipeA[1]);

                    dup(pipeA[0]);


                    close(pipeA[0]);

                    execvp(cmd2[0], cmd2);

                    cerr << "Exec err" << cmd2 << endl;
                    exit(-1);
               }
                    

            }

            else if (p == false)
            {
                int num = 0;
                char *ptr;
                
                
                cmd1[0] = strtok(buf, " ");

                while ((ptr = strtok(NULL, " ")) != NULL)
                {
                    num++;
                    cmd1[num] = ptr;
                }

                if ((pid1 = fork()) < 0)
                {
                    printf("fork error");
                }

                else if (pid1 == 0)
                {
                    //child 
                                    
                    execvp(cmd1[0], cmd1);
                    cerr << "Exec err";
                    exit(-1);
                }

            }

            // close pipe
            close(pipeA[1]);
            close(pipeA[0]);

            if (p)
            {
                if ((pid2 = waitpid(pid2, &status, 0)) < 0)
                    printf("waitpid error, pid2");
            }
            
            if ((pid1 = waitpid(pid1, &status, 0)) < 0)
                printf("waitpid error");
            printf("480 shell> ");

        }
    return 0;
}
