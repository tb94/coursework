#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main ()
{

	pid_t pid;

	cerr << "This is the original process. PID = " << getpid() << endl;
	cerr << "The parent's PID = " << getppid() << endl;
	cerr << "Using fork()" << endl;

	pid = fork();

	if (pid < 0)
	{
		// fork failed
		cerr << "The first fork failed" << endl;
		exit(-1);
	}

	else if (pid == 0)
	{
		// child process
        cerr << "This is the child process. PID = " << getpid() << endl;
        cerr << "The parent's PID = " << getppid() << endl;
        cerr << "Using fork() again" << endl;

        pid = fork();

        if (pid < 0)
        {
            // fork failed
            cerr << "The second fork failed" << endl;
            exit(-1);
        }

        else if (pid == 0)
        {
            // grandchild process
            cerr << "This is the grandchild process. PID = " << getpid() << endl;
            cerr << "The parent's PID = " << getppid() << endl;
            cerr << "About to exit the grandchild process" << endl;
            exit(0);
        }

        else
        {
            // child process
            cerr << "This is the child process again. PID = " << getpid() << endl;
            cerr << "The parent's PID = " << getppid() << endl;
            wait(0);
            cerr << "About to exit the child process" << endl;
            exit(0);
        }
	}

	else
	{
		// parent process
        cerr << "This is the parent process. PID = " << getpid() << endl;
        cerr << "The parent's PID = " << getppid() << endl;
        sleep(2);
        cerr << "About to call ps" << endl;
        system("ps");
        wait(0);
        cerr << "About to terminate." << endl;
        exit(0);
	}

	return 0;
}
