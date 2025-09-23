#include <stdio.h>
int main()
{
 int array[] = {2, 1, 3, 4};
 int constraint = 5;
 int length = sizeof(array) / sizeof(array[0]);
 int left = 0, currentSum = 0, maxSum = 0;
 int start = 0, end = -1;
 for (int i = 0; i < length; i++)
 {
 currentSum += array[i];
 while (currentSum > constraint)
 {
 currentSum -= array[left];
 left++;
 }
 if (currentSum > maxSum)
 {
 maxSum = currentSum;
 start = left;
 end = i;
 }
 }
 for (int i = start; i <= end; i++)
 {
 printf("%d\t ", array[i]);
 }
 if (maxSum == 0)
 printf("\nNo Feasible Subarray.\n");
 else
 printf("\nBest subarray sum under constraint: %d\n", maxSum);
 return 0;
}