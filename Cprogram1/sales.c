// Including the standard input/output library.
#include <stdio.h>
// Including the math library.
#include <math.h>

// Defining the constant NUM_MONTHS to be 12.
#define NUM_MONTHS 12

// This is an array of strings.
const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Declaring an array of doubles called sales.
double sales[NUM_MONTHS];
// Declaring an array of doubles called sixMonthAverages.
double sixMonthAverages[7];

// This program sorts the sales data from highest to lowest and prints the sorted data.
int main(void) {
    FILE *file = fopen("sales.txt", "r");
    // Checking if the file is empty.
    if (file == NULL) {
        // Printing the string to the console.
        printf("Unable to open sales file\n");
        // Returning the value 1 (FALSE) to the operating system.
        return 1;
    }

    // Read sales data from file
    // Declaring a variable called i and initializing it to 0.
    int i;
    // This is a for loop that is used to iterate through the array of sales.
    for (i = 0; i < NUM_MONTHS; i++) {
        // This is reading the sales data from the file and storing it in the array of sales.
        fscanf(file, "%lf", &sales[i]);
    }
    // Closing the file.
    fclose(file);

    // Generate sales report
    printf("Monthly Sales Report\n");
    printf("-----------------------------------\n");
    printf("Month\t\tSales\n");
    printf("-----------------------------------\n");
    // This is a for loop that is used to iterate through the array of sales.
    for (i = 0; i < NUM_MONTHS; i++) {
        // Printing the months and sales data to the console.
        printf("%s\t\t$%.2lf\n", months[i], sales[i]);
    }
    printf("-----------------------------------\n\n\n");

    // Calculate sales summary
    // Declaring a variable called total and initializing it to 0.
    double total = 0;
    // Declaring a variable called min and initializing it to the first element in the array of sales.
    double min = sales[0];
    // Declaring a variable called max and initializing it to the first element in the array of sales. 
    double max = sales[0];
    // Declaring a variable called minIndex and initializing it to 0.
    int minIndex = 0;
    // Initializing the variable maxIndex to 0.
    int maxIndex = 0;
    // This is a for loop that is used to iterate through the array of sales.
    for (i = 0; i < NUM_MONTHS; i++) {
        // This is adding the sales data to the variable total.
        total += sales[i];
        // This is checking if the sales data is less than the minimum.
        if (sales[i] < min) {
            // Setting the variable min to the value of sales[i].
            min = sales[i];
            // Setting the variable minIndex to the value of i.
            minIndex = i;
        }
        // This is checking if the sales data is greater than the maximum.
        if (sales[i] > max) {
            // Setting the variable max to the value of sales[i].
            max = sales[i];
            // Setting the variable maxIndex to the value of i.
            maxIndex = i;
        }
    }
    // This is calculating the average of the sales data.
    double average = total / NUM_MONTHS;
    // This is printing the string to the console.
    printf("Sales Summary\n");
    printf("-----------------------------------\n");
    printf("Month with lowest sales: %s ($%.2lf)\n", months[minIndex], min);
    printf("Month with highest sales: %s ($%.2lf)\n", months[maxIndex], max);
    printf("Average sales: $%.2lf\n", average);
    printf("-----------------------------------\n\n\n");

    // Calculating each of the six-month averages
    sixMonthAverages[0] = (sales[0] + sales[1] + sales[2] + sales[3] + sales[4] + sales[5]) / 6;
    sixMonthAverages[1] = (sales[1] + sales[2] + sales[3] + sales[4] + sales[5] + sales[6]) / 6;
    sixMonthAverages[2] = (sales[2] + sales[3] + sales[4] + sales[5] + sales[6] + sales[7]) / 6;
    sixMonthAverages[3] = (sales[3] + sales[4] + sales[5] + sales[6] + sales[7] + sales[8]) / 6;
    sixMonthAverages[4] = (sales[4] + sales[5] + sales[6] + sales[7] + sales[8] + sales[9]) / 6;
    sixMonthAverages[5] = (sales[5] + sales[6] + sales[7] + sales[8] + sales[9] + sales[10]) / 6;
    sixMonthAverages[6] = (sales[6] + sales[7] + sales[8] + sales[9] + sales[10] + sales[11]) / 6;
    // This is printing the strings to the console.
    printf("Six-Month Averages\n");
    printf("-----------------------------------\n");
    printf("January - June\t\t$%.2lf\n", sixMonthAverages[0]);
    printf("February - July\t\t$%.2lf\n", sixMonthAverages[1]);
    printf("March - August\t\t$%.2lf\n", sixMonthAverages[2]);
    printf("April - September\t$%.2lf\n", sixMonthAverages[3]);
    printf("May - October\t\t$%.2lf\n", sixMonthAverages[4]);
    printf("June - November\t\t$%.2lf\n", sixMonthAverages[5]);
    printf("July - December\t\t$%.2lf\n", sixMonthAverages[6]);
    printf("-----------------------------------\n\n\n");

    // Print the months and sales from the highest to lowest
  printf("Months and Sales from the Highest to Lowest:\n");
  printf("-----------------------------------\n");
  printf("Month\t\tSales\n");
  printf("-----------------------------------\n");
    // Sorting the sales data from highest to lowest
  // Declaring two variables called k and j and initializing them to 0.
  int k, j;
  // This is a for loop that is used to iterate through the array of sales.
  for (k = 0; k < NUM_MONTHS - 1; k++) {
    for (j = k + 1; j < NUM_MONTHS; j++) {
      // This is checking if the sales data is less than the sales data in the next index.
      if (sales[k] < sales[j]) {
        // Storing the value of sales[k] in a temporary variable called temp.
        double temp = sales[k];
        // Swapping the values of sales[k] and sales[j].
        sales[k] = sales[j];
        sales[j] = temp;

        // Storing the value of months[k] in a temporary variable called tempMonth.
        char *tempMonth = months[k];
        // Swapping the values of months[k] and months[j].
        months[k] = months[j];
        months[j] = tempMonth;
      }
    }
  }

  // Printing the sorted data
  // This is a for loop that is used to iterate through the array of sales.
  for (i = 0; i < NUM_MONTHS; i++) {
    // This is printing the months and sales data to the console.
    printf("%s\t\t$%.2lf\n", months[i], sales[i]);
  }

  // This is returning the value 0 (TRUE) to the operating system.
  return 0;
}