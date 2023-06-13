#include <stdio.h>

#define PAGE_SIZE 20  // 페이지당 라인 수
		      
		      int main() {
		          const char *filename = "file.txt";  // 보여줄 파일명
		      		              FILE *file = fopen(filename, "r");
		                   if (file == NULL) {
		                           printf("Error opening the file.\n");
		                                   return 1;
		                                       }
		      
		                                        char line[256];
		                                              int lineCount = 0;
		                                                 int pageCount = 1;
		                                                       int shouldPrint = 1;
		      
		                                                           while (fgets(line, sizeof(line), file) != NULL) {
		                                                                   if (shouldPrint) {
		                                                                              printf("%s", line);
		                                                                                          lineCount++;
		                                                                                                  }
		      		                                                                                                           if (lineCount >= PAGE_SIZE) {
		                                                                                                                       lineCount = 0;
		                                                                                                                                   pageCount++;
		      
		                                                                                                                                               printf("-- Page %d --\n", pageCount);
		      
		                                                                                                                                                           // 페이지 단위로 입력을 받고 사용자 입력에 따라 동작할 수 있도록 추가 로직 필요
		      
		                                                                                                                                                                       printf("Press Enter to continue or q to quit.\n");
		                                                                                                                                                                                  char userInput = getchar();
		      		                                                                                                                                                                                              if (userInput == 'q' || userInput == 'Q') {
		                                                                                                                                                                                                               break;
		                                                                                                                                                                                                                           }
		      
		                                                                                                                                                                                                                                       shouldPrint = 0;
		                                                                                                                                                                                                                                               } else {
		                                                                                                                                                                                                                                                           shouldPrint = 1;
		                                                                                                                                                                                                                                                                   }
		                                                                                                                                                                                                                                                                       }
		      
		                                                                                                                                                                                                                                                                           fclose(file);
		      
		                                                                                                                                                                                                                                                                               return 0;
		                                                                                                                                                                                                                                                                               }
		      
