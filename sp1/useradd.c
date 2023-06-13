#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	    const char *username = "newuser";  // 추가할 사용자 이름
					       
  	    // 사용자 계정 추가 명령 실행
					            if (system("useradd -m -s /bin/bash -G sudo,users newuser") == -1) {
					                    perror("Error adding user");
					                          return 1;
					                           }
					                             // 사용자 비밀번호 설정 명령 실행
					                            if (system("passwd newuser") == -1) {
					                         perror("Error setting user password");
					                                   return 1;
					                                                             }
					                      printf("User '%s' added successfully\n", username);
					       					                                                                       return 0;
					                                                                       }
					                                                                        
