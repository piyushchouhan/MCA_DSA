//subset_sum
#include <stdio.h>
#include <stdbool.h>

// Function to check if a subset with given sum exists
bool isSubsetSum(int set[], int n, int sum,int subset[][10])
{


    // If the sum is 0, an empty subset can be found
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    // If the sum is not 0 but the set is empty, no subset can be found
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    // Fill the subset table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If the current element is greater than the sum,
            // exclude it and check the remaining subset
            if (set[i - 1] > j)
                subset[i][j] = subset[i - 1][j];
            else {
                // Check if the subset can be found by including or excluding the current element
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
            }
        }
    }

    // Return the value in the bottom-right corner of the table
    return subset[n][sum];
}

// Test the subset sum algorithm
int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
     int n = 6;
    int sum = 9;
    int subset[7][10];

    if (isSubsetSum(set, n, sum,subset))
        printf("Subset with the given sum exists.\n");
    else
        printf("Subset with the given sum does not exist.\n");

    return 0;
}
