#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	    if (argc < 2) {
		            printf("사용법: %s <파일1> <파일2> ... <파일N>\n", argv[0]);
			            return 1;
				        }

	        int i;
		    for (i = 1; i < argc; i++) {
			            const char* filename = argv[i];

				            if (unlink(filename) == -1) {
						                perror("파일 삭제 오류");
								            return 1;
									            }

					            printf("파일 삭제 완료: %s\n", filename);
						        }

		        return 0;
}

