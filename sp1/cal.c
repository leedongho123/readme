#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	    int year = 2023;  // 연도
			          int month = 6;    // 월
			     
			             struct tm timeinfo = {
			                     .tm_year = year - 1900,
			                             .tm_mon = month - 1,
			                                     .tm_mday = 1
			                                         };
			                                             time_t rawtime = mktime(&timeinfo);
			     
			                                                 if (rawtime == -1) {
			                                                         printf("Error creating time structure.\n");
			                                                                 return 1;
			                                                                      }
			     
			                                                                                                                struct tm *caltime = localtime(&rawtime);
			                                                                                                             if (caltime == NULL) {
			                                                                                                                  printf("Error getting local time.\n");
			                                                                                               return 1;
			                                                                                                   }
			      		                                                                                                                printf("     %s %d\n", caltime->tm_mon + 1 == month ? " " : "", month);
			                                                                                                                  printf("Su Mo Tu We Th Fr Sa\n");
			     
			                                                                                                              int dayOfWeek = caltime->tm_wday;
			                                                                                                                  int totalDays = caltime->tm_mday;
			                                                                                                                     int lastDayOfMonth = caltime->tm_mon == 1 ? 28 + (caltime->tm_year % 4 == 0 && (caltime->tm_year % 100 != 0 || caltime->tm_year % 400 == 0)) :
                           30 + (caltime->tm_mon < 7 ? caltime->tm_mon % 2 : (caltime->tm_mon + 1) % 2);
                                           for (int i = 0; i < dayOfWeek; i++) {
                                                                                                                                       printf("   ");
                                                                                                                                     }
                                                                                                                                        for (int i = 1; i <= lastDayOfMonth; i++) {
                                                                                                                                                    printf("%2d%s ", i, totalDays == i ? ">" : " ");
                                                                                                                                                           if ((dayOfWeek + i) % 7 == 0) {
                                                                                                                                                                     printf("\n");
                                                                                                                                                                             }
                                                                                                                                                                                    }
                                                                                                                                                                                   printf("\n");
                                                                                                                                                                                            return 0;
                                                                                                                                                                                             }
                                                                                                                                                                                             
