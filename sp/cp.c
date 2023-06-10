#include <stdio.h>

int main(int argc, char* argv[]) {
	    if (argc != 3) {
		            printf("사용법: %s <소스파일> <대상파일>\n", argv[0]);
			            return 1;
				        }

	        const char* sourceFile = argv[1];
		    const char* targetFile = argv[2];

		        FILE* source = fopen(sourceFile, "rb");
			    if (source == NULL) {
				            perror("소스파일 열기 오류");
					            return 1;
						        }

			        FILE* target = fopen(targetFile, "wb");
				    if (target == NULL) {
					            perror("대상파일 열기 오류");
						            fclose(source);
							            return 1;
								        }

				        int c;
					    while ((c = fgetc(source)) != EOF) {
						            if (fputc(c, target) == EOF) {
								                perror("파일 쓰기 오류");
										            fclose(source);
											                fclose(target);
													            return 1;
														            }
							        }

					        printf("파일 복사 완료: %s -> %s\n", sourceFile, targetFile);

						    fclose(source);
						        fclose(target);
							    return 0;
}

