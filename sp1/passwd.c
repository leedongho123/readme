#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	    const char *username = "ldh1265";  // 비밀번호를 변경할 사용자 이름
					   
					        // 사용자 비밀번호 변경 명령 실행
					          if (system("sudo passwd ldh1265") == -1) {
					                   perror("Error changing user password");
					                            return 1;
					                                }
					   
					               printf("Password for user '%s' changed successfully\n", username);
					                                    return 0;
					                                        }
					                                      
