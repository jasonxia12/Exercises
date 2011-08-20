/**
 * @file Test_002.cpp
 * @brief The vfork example
 *
 * This example demonstrate what does vfork works. vfork will not copy 
 * parent process and run on the parents memory. And vfork promissed 
 * before the child process calls exec/exit the parent process will stay
 * in sleep state. So we did not need to call sleep explicity. This 
 * example also demonstrate _exit. _exit will not flush the buffer to 
 * make sure parent process works correctly. If using exit, the output 
 * will be undefined.
 *
 * @author Peng Xia
 * @version 0.1
 * @date 2011-08-20
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int		local = 88;

	printf("before fork\n");

	pid_t	pid;
	if ((pid = vfork()) < 0) {
		fputs("fork error", stderr);
	} else if (pid == 0) {
		local++;
		_exit(0);
	}

	printf("pid = %d, local = %d\n", getpid(), local);
	exit(0);
}
