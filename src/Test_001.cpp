/**
 * @file Test_001.cpp
 * @brief The fork example. 
 *
 * This example demonstrate how to use fork,how to figure out which is parent 
 * and which is child process. It also demonstrate one interesting phenomenon: 
 * execute "./Test_001" and "./Test_001 > temp.out" will get different result 
 * due to the standard I/O library has buffer. It will be line-buffer for 
 * terminal, otherwize, it will be full-buffer.
 *
 * @author Peng Xia
 * @version 0.1
 * @date 2011-08-20
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		global = 6;
char	buf[] = "a write to stdout\n";

int main()
{
	int		local = 88;

	if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
		fputs("write error", stderr);

	printf("before fork\n");

	pid_t	pid;
	if ((pid = fork()) < 0) {
		fputs("fork error", stderr);
	} else if (pid == 0) {
		global++;
		local++;
	} else {
		sleep(2);
	}

	printf("pid = %d, global = %d, local = %d\n", getpid(), global, local);
	exit(0);
}


