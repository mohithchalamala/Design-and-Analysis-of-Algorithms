#include<stdio.h> 
#include<stdbool.h>
bool isSubsetSum(int arr[], int n, int sum) 
{ 
 bool subset[n+1][sum+1];
    for (int i = 0; i <= n; i++) 
 subset[i][0] = true;  
    for (int i = 1; i <= sum; i++)  
       subset[0][i] = false; 
     for (int i = 1; i <= n; i++) 
    { 
        for (int j = 1; j <= sum; j++) 
        { 
          if(j<arr[i-1]) 
             subset[i][j] = subset[i-1][j]; 
               if (j >= arr[i-1]) 
                  subset[i][j] = subset[i-1][j] || 
                                           subset[i - 1][j-arr[i-1]]; 
        } 
    }
     printf("%d",subset[n][n+1]);
     return subset[n][sum]; 
} 



int main() 
{ 
int set,size,i;
printf("Enter the size of the array \n");
scanf("%d",&size);
int arr[size];
printf("Enter integers: ");
for(int i = 0; i <size; ++i) 
{
  scanf("%d", &arr[i]);
}
int sum;
printf("Enter the value of sum to be found in array\n");
scanf("%d",&sum);
int n = size 
if (isSubsetSum(arr, n, sum) == true) 
   printf("Found a subset with given sum"); 
else
  printf("No subset with given sum");
return 0;
}
