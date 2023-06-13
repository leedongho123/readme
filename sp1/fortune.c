#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	    const char *fortunes[] = {
		            "가는 말이 고와야 오는 말이 곱다.",
			            "고래싸움에 새우등 터진다.",
				            
					    
					 "사공이 많으면 배가 산으로 간다."
								        };
	        int numFortunes = sizeof(fortunes) / sizeof(fortunes[0]);

		    srand(time(NULL));
		        int randomIndex = rand() % numFortunes;

			    printf("%s\n", fortunes[randomIndex]);

			        return 0;
}

