#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
	    int pid;
	        int ppid;
		    char state[16];
		        char command[256];
} ProcessInfo;

int main() {
	    FILE *fp;
	        char buffer[BUFFER_SIZE];

		    fp = popen("ps -e -o pid,ppid,state,comm", "r");
		        if (fp == NULL) {
				        printf("Error executing ps command.\n");
					        return 1;
						    }

			    ProcessInfo processes[100];
			        int processCount = 0;

				    // 첫 번째 라인은 헤더이므로 무시
				         fgets(buffer, BUFFER_SIZE, fp);
				    
				             while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
				                     int pid, ppid;
				                             char state[16], command[256];
				                                     sscanf(buffer, "%d %d %s %s", &pid, &ppid, state, command);
				    
				                                             processes[processCount].pid = pid;
				                                                     processes[processCount].ppid = ppid;
				                                                             strcpy(processes[processCount].state, state);
				                                                                     strcpy(processes[processCount].command, command);
				    
				                                                                             processCount++;
				                                                                                 }
				    
				                                                                                     pclose(fp);
				    
				                                                                                         // 결과 출력
				                                                                                             printf("%-8s %-8s %-8s %s\n", "PID", "PPID", "STATE", "COMMAND");
				                                                                                                 for (int i = 0; i < processCount; i++) {
				                                                                                                         printf("%-8d %-8d %-8s %s\n", processes[i].pid, processes[i].ppid, processes[i].state, processes[i].command);
				                                                                                                             }
				    
				                                                                                                                 return 0;
				                                                                                                                 }
				    
