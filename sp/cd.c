#include <stdio.h>
#include <unistd.h>

int main() {
	    const char *path = "/path/to/directory"; 
						     
						          int result = chdir(path);
						              if (result == 0) {
						                      printf("작업 디렉토리 변경 성공: %s\n", path);
						                          } else {
						                                  perror("작업 디렉토리 변경 실패");
						                                          return 1;
						                                              }
						     					                                                  return 0;
						                                                  }
						     
