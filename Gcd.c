/**
 * Program to find Gcd of two numbers using recursion.
 * Compilation : gcc Gcd.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 04/8/2021
 * Ques 2. Assignment_5 - Recursion.
 *
 */


#include<stdio.h>

// Function to find gcd of two numbers using recursion.
int gcd_(int a , int b)
{
    // base case -> if b is 0 then gcd of a and 0 is a.
    if(b == 0)
    {
        return a;
    }
    
    /* calling gcd function recursively -> (Euclid's algorithm)
    if b is greater than a then this call will pass a as b and b as a to function ,
    else if b is less than or equals to a then this call will pass a as b and b as a%b 
    ,which is basically long division method in maths to find gcd. */

    return gcd_(b , a % b);
}


int main() 
{
    int a = 0;
    int b = 0;
    printf("Enter two numbers a and b \n");
    scanf("%d %d" , &a , &b);
    
    // calling gcd function.
    int answer = gcd_(a , b);
    
    // printing required answer.
    printf("Gcd of %d and %d is : %d \n" , a , b , answer);
    
    return 1;
}

