#include <stdio.h>

int main(int argc, char* argv[]) {
	    if (argc != 3) {
		            printf("사용법: %s <소스> <대상>\n", argv[0]);
			            return 1;
				        }

	        const char* source = argv[1];
		    const char* target = argv[2];

		        if (rename(source, target) == -1) {
				        perror("파일 이동/이름 변경 오류");
					        return 1;
						    }

			    printf("파일 이동/이름 변경 완료: %s -> %s\n", source, target);

			        return 0;
}

