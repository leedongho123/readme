#include <stdio.h>
#include <stdlib.h>

int main() {
	    extern char **environ;

	        // 모든 환경 변수 출력
	     char **env = environ;
	         while (*env != NULL) {
	                 printf("%s\n", *env);
	                         env++;
	                             }
	
	                                return 0;
	                                }
	                                
