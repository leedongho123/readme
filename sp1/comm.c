#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
	    FILE *file1, *file2;
	        char file1Path[256] = "file1.txt";  // 첫 번째 파일 경로
   char file2Path[256] = "file2.txt";  // 두 번째 파일 경로
       file1 = fopen(file1Path, "r");
             file2 = fopen(file2Path, "r");

                if (file1 == NULL || file2 == NULL) {
                         printf("Error opening files.\n");
                                return 1;
                                    }

                                        char line1[MAX_LINE_LENGTH];
                                           char line2[MAX_LINE_LENGTH];
                            // 두 파일을 한 줄씩 읽어 비교
                                         while (fgets(line1, MAX_LINE_LENGTH, file1) != NULL && fgets(line2, MAX_LINE_LENGTH, file2) != NULL) {
                                                       int compareResult = strcmp(line1, line2);
                                                              if (compareResult == 0) {
                                                                             // 공통된 라인
                                                                                          printf("\t%s", line1);
                                                                                                } else if (compareResult < 0) {
                                                                                            // 첫 번째 파일의 라인이 더 작음
                                                                                                                             printf("<\t%s", line1);
                                                                                                                                    } else {
                                                                                                                                                // 두 번째 파일의 라인이 더 작음
                                                                                                                                                           printf(">\t%s", line2);
                                                                                                                                                                   }
                                                                                                                                                                       }

                                                                                                                                                                             // 첫 번째 파일에 남은 라인 출력
                                                                                                                                                                                 while (fgets(line1, MAX_LINE_LENGTH, file1) != NULL) {
                                                                                                                                                                                         printf("<\t%s", line1);
                                                                                                                                                                                             }
                                                                                                                                                                                                 // 두 번째 파일에 남은 라인 출력
                                                                                                                                                                                                     while (fgets(line2, MAX_LINE_LENGTH, file2) != NULL) {
                                                                                                                                                                                                            printf(">\t%s", line2);
                                                                                                                                                                                                                }
                                                                                                                                                                                                                    fclose(file1);
                                                                                                                                                                                                                         fclose(file2);
                                                                                                                                                                                                                    return 0;
			                                                                                                                                                                                                                             }
			
