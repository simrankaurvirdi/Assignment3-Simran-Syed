/*Multithreaded program that calculates various statistical values for a list of numbers. 
This program will be passed a series of numbers onthe command line and will then create three separate worker threads.
One thread will determine the average of the numbers, the second will determine the maximum value, 
and the third will determine the minimum value.*/

//  stats.c
//  Created by Simran Kaur and Syed Turab on 2018-11-02.

//#include "Question1.h"



#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> // for threads
#include <limits.h> // limits header

/*https://www.geeksforgeeks.org/int_max-int_min-cc-applications
https://www.tutorialspoint.com/c_standard_library/limits_h.html*/




//number of elements
int numberofelements;


// we need 3 functions -> max value, min value, avg value in 3 seperate threads



//function to find Max value in a separate thread

void* findMaximum(void *vargp)
{
    int *array = (int *)vargp; // pointer of array of elements is equal to the thread
    
    int max = INT_MIN; // the max number will be the minimum value for integer max (limits.h)
    for(int i = 0; i< numberofelements; i++) // iterate through arrary
    {
        if(array[i]>=max){
            max = array[i];
        }
    }
    
    int* result = malloc(sizeof(result)); // allocating result to memory
    *result= max; // pointer of result is equal to the max number
    return result; // return the result
    
}


 //function to find Min value in a separate thread

void* findMinimum(void *vargp)
{
    int *array = (int *)vargp; // pointer of array of elements is equal to the thread
    
    int min = INT_MAX; // the min number will be the maximum value for integer min (limits.h)
    for(int i = 0; i< numberofelements; i++) //iterate through array
    {
        if(array[i]<=min){
            min = array[i];
        }
    }
    
    int* result = malloc(sizeof(result)); // allocating result to memory
    *result= min; // pointer of result is equal to the min number
    return result; // return the result
}


//function to find average value in a separate thread
void* findAverage(void *vargp)
{
    int *array = (int* )vargp; // pointer of array of elements is equal to the thread
    
    int sum = 0; // integer sum declared
    for(int i = 0; i< numberofelements; i++) // iterate through array
    {
        sum += array[i];
    }
    double avg = (double)sum/numberofelements; // average calculation
    
    double* result = malloc(sizeof(avg)); // allocating result to memory
    *result = avg; // pointer of result is equal to the average number
    return result; // return the result
}

int main(int argc, char* argv[]){
    
    //Put this because the first arugment of the program is the name of the program (./Question1.c)
    numberofelements = argc-1;
    
    if(numberofelements<2){
        perror ("Please enter some numbers ( 2 or more) to perform tasks.");  //errorchecking
        exit(1);
        //printf("Please enter some numbers to perform the tasks \n"); 
        //return 0;
    }
    
  

    
    //creating an  array to store numbers
    int* array = malloc(numberofelements*sizeof(int));
    
    // starting from index 1
    for(int i = 1; i<= numberofelements; i++){
        
        array[i-1] = atoi(argv[i]);
    }
    
    
    
     // create threads to perform operation
    
    pthread_t tid1,tid2,tid3;
    pthread_create(&tid1,NULL,findMaximum,array);  // Thread ID ,Null, function name, arugment to pass
    pthread_create(&tid2,NULL,findMinimum,array); // Thread ID ,Null, function name, arugment to pass
    pthread_create(&tid3,NULL,findAverage,array); // Thread ID ,Null, function name, arugment to pass
    
    
   
    
   
   //   pthread_join  is used so the main function waits for all the arugments to be finished (max,min,avg)
 
    
    void* max = malloc(sizeof(max)); // dynamically allocating memory for maximum number
    void* min = malloc(sizeof(min)); // dynamically allocatiing memory for minimum number
    void* avg = malloc(sizeof(avg)); // dynamically allocation memory for average
    pthread_join(tid1,&max); // thread id for max , return value from  thread
    pthread_join(tid2,&min); // thread id for min , return value from thread
    pthread_join(tid3,&avg); // thread id for avg, reutrn value from thread
    
    
    printf("Maximum is:%d\n",*((int*)max)); // print the maximum value
    printf("Minimum is:%d\n",*((int*)min)); // print the minimum value
    printf("Average is:%f\n",*((double*)avg)); // print the average value
    
    free(max); // free the max from memory so another process can run
    free(min); // free the min from memory so another process can run
    free(avg); // free the average from memory so another process can run
    free(array); // free the array
    printf("\n"); // new line
    
} // end main

