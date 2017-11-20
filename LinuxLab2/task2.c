/*
* �������� ��������� �� ����� ������� �������, �� � ��������-������ 
* ��������� ��������� ����� wait(). ���������, ��� � ���� ������ 
* ������������� �������� ������� �� 1 ������ �������������� 
* ��������-������.
*/

#include <stdio.h> //printf
#include <stdlib.h> //exit
#include <sys/types.h> //W***
#include <sys/wait.h> //wait


int main()
{
	int child = fork();
	if ( child == -1 )
	{
		perror("couldn't fork.");
		exit(1);
	}
	if ( child == 0 )
	{
        //������������� ���
        sleep(2);
        printf( "Child: pid=%d;	group=%d;	parent=%d\n", getpid(), getpgrp(), getppid() );

	}
	else
	{
		//������������ ���
        printf( "Parent: pid=%d;	group=%d;	child=%d\n", getpid(), getpgrp(), child );
        int status;
        pid_t ret_value;
        ret_value = wait( &status );
        if ( WIFEXITED(status) )
            printf("Parent: child %d finished with %d code.\n", ret_value, WEXITSTATUS(status) );
        else if ( WIFSIGNALED(status) )
            printf( "Parent: child %d finished from signal with %d code.\n", ret_value, WTERMSIG(status));
        else if ( WIFSTOPPED(status) )
            printf("Parent: child %d finished from signal with %d code.\n", ret_value, WSTOPSIG(status));
		return 0;
	}
}
