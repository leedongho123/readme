#include <stdio.h>
#include <string.h>

int main() {
	    char message[256];

	        printf("Enter the message: ");
		    fgets(message, sizeof(message), stdin);
		        message[strcspn(message, "\n")] = '\0';  // 개행 문자 제거
				 printf("%s\n", message);
				   return 0;
	         }
				        
