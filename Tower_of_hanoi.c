/**
 * Program to implement Tower of hanoi function.
 * Compilation : gcc Tower_of_hanoi.c
 * Execution : ./a.out
 *
 * @Shivansh Kaushal ( 1910990128 )  , 04/8/2021
 * Ques 3. Assignment_5 - Recursion.
 *
 */


#include<stdio.h>

// Global variable count to count the number of movements.
int count = 0;

// Function to implement tower of hanoi using recursion.
void tower_of_hanoi(int n, char from, char to, char aux)
{
    // Base case for 0 number of towers.
    if(n == 0) 
    {
        return;
    }
    
    // calling recursion for n-1 disks to put from 'from' tower to 'aux' tower.
    tower_of_hanoi(n-1 , from , aux , to);
    
    // making a move of putting largest disk from 'from' tower to 'to' tower.
    printf("%c to %c \n" , from , to);
    
    // increase the number of movements by 1 in each iteration. 
    count++;

    // calling recursion for n-1 disks to put from 'aux' tower to 'to' tower.
    tower_of_hanoi(n-1 , aux , to , from);
    
}



int main() 
{
    int n;

    printf("Enter number of disks on 'From' tower \n");
    scanf("%d" , &n);

    //calling tower of hanoi function with A as source , C as destination and 
    // B as helper tower .
    tower_of_hanoi(n,'A','C','B');
    
    // printing required number of movements.
    printf("Total movements required = %d\n" , count);

    return 1;
}
