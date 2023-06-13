#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 100

void printBanner(const char *text) {
	    int i, j;
	        int length = strlen(text);

		    // 대문자로 변환하여 출력
		         for (i = 0; i < length; i++) {
		                 putchar(toupper(text[i]));
		                         putchar(' ');
		                            }
		                                 putchar('\n');
		    		                                     // 밑줄 출력
		                                         for (j = 0; j < length * 2; j++) {
		                                                putchar('=');
		                                                     }
		                                                       putchar('\n');
		                                                    }
		                                             int main() {
		                                            const char *input = "Hello, World!";  // 출력할 텍스트
		                                                                 printBanner(input);
		                                                      return 0;
		                                                }
		                                                                     
