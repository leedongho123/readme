#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	    const char *fortunes[] = {
		            "Fortune 1",
			            "Fortune 2",
				            "Fortune 3",
					            "Fortune 4",
						            "Fortune 5"
								        };
	        int numFortunes = sizeof(fortunes) / sizeof(fortunes[0]);

		    srand(time(NULL));
		        int randomIndex = rand() % numFortunes;

			    printf("%s\n", fortunes[randomIndex]);

			        return 0;
}

