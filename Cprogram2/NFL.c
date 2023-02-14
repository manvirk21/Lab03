/* Importing the standard input/output library. */
#include <stdio.h>

// Structure to hold the number and points of each type of scoring
typedef struct {
  // Declaring a variable called num of type int.
  int num;
  // Declaring a variable called pts of type int.
  int pts;
} 
// Declaring a new type called scoring.
scoring;

// Function to print the final output of the program
void print_output(scoring td2p, scoring tdfg, scoring td, scoring fg, scoring safety) {
  // prints the number of each type of points scored
  printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2p.num, tdfg.num, td.num, fg.num, safety.num);
}

int main() {
  // Initialize the number and points of each type of scoring
  scoring td2p = {0, 8};
  scoring tdfg = {0, 7};
  scoring td = {0, 6};
  scoring fg = {0, 3};
  scoring safety = {0, 2};

  // Initialize the total number of points scored
  int total_pts = 0;

  // Keep the program running until the user inputs 0 or 1
  while (1) {
    // Prompt the user to enter the total number of points scored
    printf("Enter the total points scored (0 or 1 to stop): ");
    scanf("%d", &total_pts);

    // If the user inputs 0 or 1, break the loop
    if (total_pts == 0 || total_pts == 1) {
      break;
    }

    // Loop through all possible combinations of each type of scoring to find the combination that adds up to the total number of points
    for (td2p.num = 0; td2p.num <= total_pts / td2p.pts; td2p.num++) {
      /* This is a for loop that is looping through all possible combinations of touchdowns and field goals scored. */
      for (tdfg.num = 0; tdfg.num <= total_pts / tdfg.pts; tdfg.num++) {
        // This is a for loop that is looping through all possible combinations of touchdowns scored. 
        for (td.num = 0; td.num <= total_pts / td.pts; td.num++) {
          // This is a for loop that is looping through all possible combinations of field goals scored.
          for (fg.num = 0; fg.num <= total_pts / fg.pts; fg.num++) {
            // This is a for loop that is looping through all possible combinations of safeties scored.
            for (safety.num = 0; safety.num <= total_pts / safety.pts; safety.num++) {
              // Check if the current combination of scores adds up to the total number of points
              if ((td2p.pts * td2p.num + tdfg.pts * tdfg.num + td.pts * td.num + fg.pts * fg.num + safety.pts * safety.num) == total_pts) {
                /* If the combination is found, print the final output by calling the function print_output 
                and passing in the variables td2p, tdfg, td, fg, and safety. */
                print_output(td2p, tdfg, td, fg, safety);
              }
            }
          }
        }
      }
    }
  }
  /* The return statement is used to return from a function i.e. break out of the function. */
  return 0;
}
