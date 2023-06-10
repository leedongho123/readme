#include <stdio.h>

int main(int argc, char* argv[]) {
	    if (argc < 2) {
		            printf("사용법: %s <파일1> <파일2> ... <파일N>\n", argv[0]);
			            return 1;
				        }

	        int i;
		    for (i = 1; i < argc; i++) {
			            const char* filename = argv[i];

				            FILE* file = fopen(filename, "r");
					            if (file == NULL) {
							                perror("파일 열기 오류");
									            return 1;
										            }

						            int c;
							            while ((c = fgetc(file)) != EOF) {
									                putchar(c);
											        }

								            fclose(file);
									        }

		        return 0;
}

