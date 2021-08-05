/**
 * Program to implement Selection sort using recursion.
 * Compilation : gcc Recursive_selection_sort.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 04/8/2021
 * Ques 1. Assignment_5 - Recursion.
 *
 */


#include<stdio.h>

/* Function to find index of minimum element in array from current index to last index
 using recursion */
int findminindex(int *arr , int n , int current)
{
    // base case -> if current index has reached ahead of last index then return -1.
    if(current == n)
    {
        return -1;
    }
    
    // initialize original minindex with current index.
    int minindex = current;
    
    // find the minimum index for next array elements using recursion and store in tempmin.
    int tempmin = findminindex(arr , n , current + 1);
    
    // if tempmin is -1 then return minindex.
    if(tempmin == -1)
    {
        return minindex;
    }
    
    // else compare element at original minindex with element at tempmin.
    else
    {
        // if element at tempmin is smaller than element at minindex , return tempmin.
        if(arr[minindex] > arr[tempmin])
        {
            return tempmin;
        }
        
        // else if element at minindex is smaller than element at tempmin , return minindex. 
        else
        {
            return minindex;
        }
    }
    
}

// Function to sort array using Recursive Selection sort.
void rec_selection_sort(int *arr , int n , int current)
{
    // base case -> if current index has reached last index then return.
    if(current == n-1)
    {
        return;
    }
    
    /* finding the index of minimum element from current index to last index 
       using recursion.
       Calling findminindex function to do it. */
    int minindex =  findminindex(arr , n , current);
    
    /* if minindex is not equal to current index then swapping the elements at
       minindex and current index. */
    if(minindex != current)
    {
        int temp = arr[minindex];
        arr[minindex] = arr[current];
        arr[current] = temp;
    }
    
    // Calling recursion for next array elements to make them sorted .
    rec_selection_sort(arr , n , current + 1);
}



int main()
{
    printf("Enter number of elements in array \n");
    int n;
    scanf("%d" ,&n);
    
    int array[n];
    printf("Enter array elements: \n");
    
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d" ,&array[i]);
    }
    
    // current index
    int index = 0;  
    
    // calling Recursive selection sort function ->
    rec_selection_sort(array , n , index);
    
    // printing sorted array elements .
    printf("Array elements after sorting : \n");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d " ,array[i]);
    }
    
    printf("\n");

    return 1;

}
