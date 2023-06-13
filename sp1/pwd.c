#include <stdio.h>
#include <unistd.h>

int main() {
	    char path[1024];

	        if (getcwd(path, sizeof(path)) != NULL) {
			        printf("현재 작업 디렉토리: %s\n", path);
				    } else {
					            perror("현재 작업 디렉토리 확인 오류");
						            return 1;
							        }

		    return 0;
}

