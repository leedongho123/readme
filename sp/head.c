#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

void head(FILE* file, int numLines) {
	    char line[MAX_LINE_LENGTH];
	        int lineCount = 0;

		    while (fgets(line, sizeof(line), file) != NULL && lineCount < numLines) {
			            printf("%s", line);
				            lineCount++;
					        }
}

int main(int argc, char* argv[]) {
	    if (argc < 2) {
		            printf("사용법: %s <파일명> [출력 라인 수]\n", argv[0]);
			            return 1;
				        }

	        const char* filename = argv[1];
		    int numLines = 10; // 기본적으로 10 라인을 출력
				       
				            if (argc >= 3) {
				                   numLines = atoi(argv[2]);
				                       }
				       
				                            FILE* file = fopen(filename, "r");
				                               if (file == NULL) {
				                                        perror("파일 열기 오류");
				                                                return 1;
				                                                   }
				       
				                                                        head(file, numLines);
				       
				                                                            fclose(file);
				                                                                return 0;
				                                                                }
				                                                                
