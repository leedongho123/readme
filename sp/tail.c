#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

void tail(FILE* file, int numLines) {
	    char line[MAX_LINE_LENGTH];
	        int lineCount = 0;
		    int totalLines = 0;
		        long long fileSize;
			    long long offset;

			        // 파일 크기 계산
				     fseek(file, 0, SEEK_END);
				         fileSize = ftell(file);
				
				             // 파일 끝에서부터 라인 수를 세면서 이동
				                 while (lineCount < numLines && totalLines < fileSize) {
				                         // 현재 위치에서 1 바이트씩 앞으로 이동
				                                 offset = ftell(file);
				                                         fseek(file, offset - 1, SEEK_SET);
				
				                                                 // 개행 문자까지 이동
				                                                         while (fgetc(file) != '\n') {
				                                                                     if (fseek(file, -2, SEEK_CUR) != 0) {
				                                                                                     fseek(file, 0, SEEK_SET);
				                                                                                                     break;
				                                                                                                                 }
				                                                                                                                         }
				
				                                                                                                                                 // 한 줄 읽기
				                                                                                                                                         if (fgets(line, sizeof(line), file) != NULL) {
				                                                                                                                                                     lineCount++;
				                                                                                                                                                             }
				
				                                                                                                                                                                     totalLines++;
				                                                                                                                                                                         }
				
				                                                                                                                                                                             // 파일 끝으로부터 출력
				                                                                                                                                                                                 fseek(file, 0, SEEK_END);
				                                                                                                                                                                                     while (lineCount > 0) {
				                                                                                                                                                                                             // 현재 위치에서 1 바이트씩 앞으로 이동
				                                                                                                                                                                                                     offset = ftell(file);
				                                                                                                                                                                                                             fseek(file, offset - 1, SEEK_SET);
				
				                                                                                                                                                                                                                     // 개행 문자까지 이동
				                                                                                                                                                                                                                             while (fgetc(file) != '\n') {
				                                                                                                                                                                                                                                         if (fseek(file, -2, SEEK_CUR) != 0) {
				                                                                                                                                                                                                                                                         fseek(file, 0, SEEK_SET);
				                                                                                                                                                                                                                                                                         break;
				                                                                                                                                                                                                                                                                                     }
				                                                                                                                                                                                                                                                                                             }
				
				                                                                                                                                                                                                                                                                                                     // 한 줄 읽기
				                                                                                                                                                                                                                                                                                                             if (fgets(line, sizeof(line), file) != NULL) {
				                                                                                                                                                                                                                                                                                                                         printf("%s", line);
				                                                                                                                                                                                                                                                                                                                                     lineCount--;
				                                                                                                                                                                                                                                                                                                                                             }
				                                                                                                                                                                                                                                                                                                                                                 }
				                                                                                                                                                                                                                                                                                                                                                 }
				
				                                                                                                                                                                                                                                                                                                                                                 int main(int argc, char* argv[]) {
				                                                                                                                                                                                                                                                                                                                                                     if (argc < 2) {
				                                                                                                                                                                                                                                                                                                                                                             printf("사용법: %s <파일명> [출력 라인 수]\n", argv[0]);
				                                                                                                                                                                                                                                                                                                                                                                     return 1;
				                                                                                                                                                                                                                                                                                                                                                                         }
				
				                                                                                                                                                                                                                                                                                                                                                                             const
				                                                                                                                                                                                                                                                                                                                                                                             
