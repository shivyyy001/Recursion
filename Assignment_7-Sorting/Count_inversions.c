/**
 * Program to Count Inversions in an array , which is the count of how far ,
 * is the array from being sorted. 
 * 
 * Compilation : gcc Count_inversions.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 11/8/2021
 * Assignment 7 - Sorting .
 *
 */



#include <stdio.h>
#define int long long

// Function to merge two sorted arrays.
int mergeTwoSorted(int *a , int n , int start , int mid , int end)
{
    // creating a temp array of size (end - start + 1).
    int temparr[end - start  + 1];
    
    // initialize count with 0.
    int count = 0;
    
    // pos -> index to traverse the temp array.
    // i   -> start index of left array.
    // j   -> start index of right array. 
    int pos = 0;
    int i = start;
    int j = mid + 1;
    
    // filling the temp array with sorted elements from left and right array.
    while(i <= mid && j <= end)
    {
        /* if left array element if less than or equal to right array element,
        then put left array element into temp array. */
        if(a[i] <= a[j])
        {
            temparr[pos++] = a[i];
            i++;
        }
        
        /* else if right array element if less than or equal to left array 
        element, then put right array element into temp array. */
        else
        {
            temparr[pos++] = a[j];
            j++;
            
            /* inversion count = (mid - i + 1) as that right array element will 
            be less than or equal to (mid - i + 1) elements from left array */
            count += (mid - i + 1);
        }
    }
    
    // fill the temp array with remaining elements from left array ,if any.
    while(i <= mid)
    {
        temparr[pos++] = a[i];
        i++;  
    }
    
    // fill the temp array with remaining elements from right array ,if any.
    while(j <= end)
    {
        temparr[pos++] = a[j];
        j++;
    }
    
    
    pos = 0;
    // copy temp array elements , which is sorted , to original array.
    for(int i = start ; i <= end ; i++)
    {
        a[i] = temparr[pos++];
    }
    
    // return count of inversions.
    return count;
}


// Function to perform merge sort.
int mergeSort(int *a , int n , int start , int end)
{
    // base case -> if start >= end then return 0.
    if(start >= end)
    {
        return 0;
    }
    
    // calculating middle.
    int mid = (start + ((end - start) / 2) );
    
    // initial inversion count = 0.
    int count = 0;
    
    // calculating inversion count for left array using recursion and putting in count.
    count += mergeSort(a , n , start , mid);
    
    // calculating inversion count for right array using recursion and putting in count.
    count += mergeSort(a , n , mid+1 , end);
    
    // calculating inversion count while merging two sorted arrays.
    count += mergeTwoSorted(a , n , start , mid , end);
    
    // returning count;
    return count;
    
}

// Function to calculate inversions in an array.
int inversionCount(int *a , int n)
{
    // initialize start with 0 and end with n-1;
    int start = 0;
    int end = n - 1;
    
    // calling the mergeSort function to count inversions while sorting array.
    int answer = mergeSort(a , n , start , end);
    
    //returning answer.
    return answer;
    
}


int main() 
{
    printf("Enter number of elements in array \n");
    int n;
    scanf("%lld" , &n);
	
    // making an array of n size.
    int a[n];
	
    printf("Enter array elements \n");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%lld" , &a[i]);
    }
	
    // Calling inversionCount function ->
    int answer = inversionCount(a , n);
	
    // printing answer.
    printf("Inversions count = %lld\n" , answer);
	
    return 1;

}
