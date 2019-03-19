
    //*************************************************//
    //                     CSCI 480                    //
    //       Assignment 2 - Process Communication      //
    //                                                 //
    // This program creates 3 processes and 3 pipes    //
    // to communicate between them                     //
    //                                                 //
    // Programmer - Tim Bretz                          //
    // Date - 9/14/17                                  //
    //*************************************************//


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

void PWork(int*, int*);
void CWork(int*, int*);
void GWork(int*, int*);

int main()
{
    int pipeA[2],
        pipeB[2],
        pipeC[2];

    pid_t pid;
    
    if (pipe(pipeA) == -1)
    {
        perror("pipe A error");
        exit(-5);
    }
    if (pipe(pipeB) == -1)
    {
        perror("pipe B error");
        exit(-5);
    }
    if (pipe(pipeC) == -1)
    {
        perror("pipe C error");
        exit(-5);
    }

	pid = fork();
	
    if (pid > 0)
	{
		// parent process
        // reads from pipe C
        // writes to pipe A

        close(pipeC[1]);
        close(pipeA[0]);
        close(pipeB[0]);
        close(pipeB[1]);

        PWork(pipeA, pipeC);

        close(pipeC[0]);
        close(pipeA[1]);
        
        wait(0);
        exit(0);
    }

    else if (pid == 0)
    {
        // child process

        pid = fork();

        if(pid > 0)
        {
            // child process
            // reads from Pipe A
            // writes to Pipe B
        
            close(pipeA[1]);
            close(pipeB[0]);
            close(pipeC[1]);
            close(pipeC[0]);

            CWork(pipeB, pipeA);

            close(pipeA[0]);
            close(pipeB[1]);

            wait(0);
            exit(0);
        }

        else if(pid == 0)
        {
            // grandchild process
            // reads from Pipe B
            // writes to Pipe C

            close(pipeB[1]);
            close(pipeC[0]);
            close(pipeA[0]);
            close(pipeA[1]);

            GWork(pipeC, pipeB);

            close(pipeB[0]);
            close(pipeC[1]);

            wait(0);
            exit(0);
        }

        else
        {
            // fork failed
            cerr << "The first fork failed" << endl;
            exit(-5);
        }        
    }

    else
    {
	    // fork failed
	    cerr << "The first fork failed" << endl;
    	exit(-5);
    }

    return 0;
}

void PWork(int* writefd, int* readfd)
{
    char buffer[10],
         value[10] = {"1\0"};
    int m = 1;
    
    write(writefd[1], value, strlen(value)+1);
    cout << "Parent:\t\t\tValue = " << value << endl;

    while(m <= 99999999)
    {
        char temp;
        int i = 0;

        do
        {
            read(readfd[0], &temp, 1);
            value[i] = temp;
            i++;
        }
        while(temp != '\0');
       
        m = atoi(value);
        m = 4 * m + 3;
       
        sprintf(buffer, "%d", m);
        strcat(buffer, " ");

        write(writefd[1], buffer, strlen(buffer)+1);
        cout << "Parent:\t\t\tValue = " << value << endl;
    }
}

void CWork(int* writefd, int* readfd)
{
    char buffer[10],
         value[10] = {"1\0"};
    int m = 1;
    
    while(m <= 99999999)
    {
        char temp;
        int i = 0;

        do
        {
            read(readfd[0], &temp, 1);
            value[i] = temp;
            i++;
        }
        while(temp != '\0');

        m = atoi(value);
        m = 4 * m + 3;
       
        sprintf(buffer, "%d", m);
        strcat(buffer, " ");

        write(writefd[1], buffer, strlen(buffer)+1);
        cout << "Child:\t\t\tValue = " << value << endl;
    }

}

void GWork(int* writefd, int* readfd)
{
    char buffer[10],
         value[10] = {"1\0"};
    int m = 1;
    
    while(m <= 99999999)
    {
        char temp;
        int i = 0;

        do
        {
            read(readfd[0], &temp, 1);
            value[i] = temp;
            i++;
        }
        while(temp != '\0');

        m = atoi(value);
        m = 4 * m + 3;
       
        sprintf(buffer, "%d", m);
        strcat(buffer, " ");

        write(writefd[1], buffer, strlen(buffer)+1);
        cout << "Grandchild:\t\tValue = " << value << endl;
    }
}
