#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	    if (argc != 2) {
		            printf("사용법: %s <디렉토리>\n", argv[0]);
			            return 1;
				        }

	        const char *dirPath = argv[1];
		    
		    if (rmdir(dirPath) == -1) {
			            perror("디렉토리 삭제 오류");
				            return 1;
					        }

		        printf("디렉토리 삭제 완료: %s\n", dirPath);

			    return 0;
}

