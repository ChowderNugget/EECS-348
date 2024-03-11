// https://www.w3schools.com/c/c_files_read.php
// https://stackoverflow.com/questions/293438/left-pad-printf-with-spaces
// https://www.digitalocean.com/community/tutorials/initialize-an-array-in-c
// https://www.geeksforgeeks.org/strtof-function-c/
// https://www.tutorialspoint.com/c-program-to-sort-an-array-in-an-ascending-order
#include <stdio.h>
#include <stdlib.h> // for strtof function

int main() {  
    char sales_array[12][15];
    char month_array[12][15] = {"January", "February", "March",
                                    "April", "May", "June",
                                    "July", "August", "September",
                                    "October", "November", "December"};
    FILE *fptr = fopen("input.txt", "r"); 

    // puts sales numbers into sales_array
    for (int i = 0; i < 12; i++) {
        fgets(sales_array[i], 15, fptr);
    }

    // prints sales numbers from sales_array
    printf("\n%s\n\n", "Monthly sales report for 2021:");
    printf("%-10s %s\n", "Month", "Sales");
    for (int i = 0; i < 12; i++) {
        printf("%-10s %s", month_array[i], sales_array[i]);
    }
    
    // prints sales summary
    float min_sale = 0;
    int min_month;
    float max_sale = 0;
    int  max_month;
    float total_sale = 0;
    float average_sale;

    for (int i = 0; i < 12; i++) {
	float current_sale = strtof(sales_array[i], NULL);
        total_sale += current_sale;
	if (min_sale == 0 || min_sale > current_sale) {
	    min_sale = current_sale;
	    min_month = i;
	}
	if (max_sale == 0 || max_sale < current_sale) {
            max_sale = current_sale;
            max_month = i;
        }
    }
    average_sale = total_sale / 12;

    printf("\n\n%s\n", "Sales summary:");
    printf("\n%-15s %.2f  (%s)", "Minimum sales:", min_sale, month_array[min_month]);
    printf("\n%-15s %.2f  (%s)", "Maximum sales:", max_sale, month_array[max_month]);
    printf("\n%-15s %.2f\n", "Average sales:", average_sale);
    
    // prints six-month moving average

    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i < 7; i++) {
	float total = 0;
    	for (int j = 0; j < 6; j++) {
	    total += strtof(sales_array[i+j], NULL);
	} 	
	printf("\n%-10s- %-10s  %.2f", month_array[i], month_array[i+5], total/6);
    }

    // pritns sales report highest to lowest
    
    printf("\n\nSales Report (Highest to Lowest):\n");
    printf("\n  %s\t\t%s","Month", "Sales");	

    float new_array[12];
    int month_index[12];

    for (int i = 0; i < 12; i++) {
    	new_array[i] = strtof(sales_array[i], NULL);
	month_index[i] = i;
    }

    float temp;
    int index_temp;
    for (int i = 0; i < 12; i++) {
    	for (int j = i + 1; j < 12; j++) {
	    if (new_array[i] > new_array[j]) {
	        temp = new_array[i];
		index_temp = month_index[i];
		new_array[i] = new_array[j];
		month_index[i] = month_index[j];
		new_array[j] = temp;
		month_index[j] = index_temp;
	    }
	} 
    }

    for (int i = 11; i > -1; i--) {
        printf("\n%-15s\t$%.2f", month_array[month_index[i]], new_array[i]);
    }

    printf("\n\n");
    fclose(fptr);
    return(0);
}
