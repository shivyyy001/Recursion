/**
 * Program to print n times , the every 3rd element of fibonacci series.
 * Compilation : gcc Print_fibo_third.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 04/8/2021
 * Ques 4. Assignment_5 - Recursion.
 *
 */



#include<stdio.h>

// Dp array used for memoization , initialized with 0.
int Dp[1000000] = {0};


// Function to print n times , the every 3rd element of fibonacci series
void printfibo(int n , int current)
{
    // base case -> if n is 0 then we have nothing to print , hence return.
    if(n == 0)
    {
        return;
    }
    
    // Calculate the current fibonacci number using previous 2 fibonacci numbers.
    Dp[current] = Dp[current - 1] + Dp[current - 2];
    
    // if current is a multiple of 3 then print that fibonacci number.
    if(current % 3 == 0)
    {
        printf("%d " , Dp[current]);
        
        // decreasing n by 1 as one fibonacci number is printed.
        n--;
    }
    
    // recursively calling for printfibo function.
    printfibo(n , current + 1);
    
}



/* Function to call printfibo function to print n times , every 3rd element of 
fibonacci series . */
void fib(int n)
{
    /* initializing Dp[1] with 1 and Dp[2] with 1 as these are the 
    first two elements of fibonacci series. */
    Dp[1] = 1;
    Dp[2] = 1;
   
    // initializing current with 3.
    int current = 3;
    
    // Calling printfibo with n and current as parameters->
    printfibo(n , current);
   
}



int main()
{
    int n;
    printf("Enter the value of n : \n");
    scanf("%d",&n);
    
    printf("Printing n times , the every third element of fibonacci series : \n");
    
    // Calling fib function.
    fib(n);
    
    printf("\n");
    
    return 1;
}



