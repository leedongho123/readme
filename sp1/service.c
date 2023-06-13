#include <stdio.h>
#include <stdlib.h>

int main() {
	    char service[256] = "apache2";  // 서비스 이름
					    
					        // 서비스 시작
					             char startCommand[512];
					                 sprintf(startCommand, "systemctl start %s", service);
					    
					                     int startResult = system(startCommand);
					                         if (startResult == -1) {
					                                 printf("Error starting the service.\n");
					                                         return 1;
					                                             } else if (WIFEXITED(startResult) && WEXITSTATUS(startResult) == 0) {
					                                                     printf("Service started successfully.\n");
					                                                         } else {
					                                                                 printf("Failed to start the service.\n");
					                                                                     }
					    
					                                                                      
					                                                                         sleep(3);
					 
					                                                                                 // 서비스 중지
					                                                                                     char stopCommand[512];
					                                                                                         sprintf(stopCommand, "systemctl stop %s", service);
					    
					                                                                                             int stopResult = system(stopCommand);
					                                                                                                 if (stopResult == -1) {
					                                                                                                         printf("Error stopping the service.\n");
					                                                                                                                 return 1;
					                                                                                                                     } else if (WIFEXITED(stopResult) && WEXITSTATUS(stopResult) == 0) {
					                                                                                                                             printf("Service stopped successfully.\n");
					                                                                                                                                 } else {
					                                                                                                                                         printf("Failed to stop the service.\n");
					                                                                                                                                             }
					    
					                                                                                                                                                 return 0;
					                                                                                                                                                 }
					    
