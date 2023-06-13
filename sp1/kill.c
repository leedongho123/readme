#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main() {
	    pid_t pid = 1234;  // 종료할 프로세스의 PID
			       
			            if (kill(pid, SIGTERM) == -1) {
			                    printf("Error executing kill command.\n");
			                            return 1;
			                                }
			       
			                                    printf("Kill command sent to process with PID %d\n", pid);
			       
			                                        return 0;
			                                       }
			                                       
