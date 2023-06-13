#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
	    if (argc != 2) {
		            printf("사용법: %s <디렉토리명>\n", argv[0]);
			            return 1;
				        }

	        const char* dirname = argv[1];

		    // 디렉토리 생성
		        int result = mkdir(dirname, 0755);
		            if (result == 0) {
		                    printf("디렉토리 생성 성공: %s\n", dirname);
		                        } else {
		                                perror("디렉토리 생성 오류");
		                                        return 1;
		                                            }
		   
		                                                return 0;
		                                                }
		                                                
