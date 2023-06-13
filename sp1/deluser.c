#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	    const char *username = "dong";  // 삭제할 사용자 이름
					   
					        // 사용자 계정 삭제 명령 실행
					            char command[100];
					                sprintf(command, "sudo deluser %s", username);
					                    if (system(command) == -1) {
					                            perror("Error deleting user");
					                                    return 1;
					                                        }
					                      printf("User '%s' deleted successfully\n", username);
					   		                                           return 0;
					                                         }
					                                                
