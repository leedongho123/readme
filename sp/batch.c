#include <stdio.h>
#include <stdlib.h>

int main() {
	    char scriptPath[256] = "script.sh";  // 실행할 스크립트 파일 경로
						     char command[512];
			         sprintf(command, "bash %s", scriptPath);
			
			             int result = system(command);
			                 if (result == -1) {
			                         printf("Error executing the script.\n");
			                                 return 1;
			                                     } else if (WIFEXITED(result) && WEXITSTATUS(result) == 0) {
			                                             printf("Script executed successfully.\n");
			                                                 } else {
			                                                         printf("Failed to execute the script.\n");
			                                                             }
			
			                                                                 return 0;
			                                                                 }
			                                                               
