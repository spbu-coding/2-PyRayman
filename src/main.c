#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
# define sort_array _sort_array

extern void array_sort(int* , int* , int );
/*
void all_output(long long* restrict Stdout, int Stdout_size, long long* restrict Stderr, int Stderr_size){

 
    for (int i = 0; i < Stdout_size; i++){
        fprintf(stdout ,"%lli ",Stdout[i]);
    }

 
    for (int i = 0; i < Stderr_size; i++){
        fprintf(stderr,"%lli ",Stderr[i]);
    }


}

void copy_array(int *source, int *target, int count_of_elements){
    for(int i = 0; i < count_of_elements; i++){
        target[i] = source[i];
    }
}

int array_compare(int* reducedArray,  int* sortedArray, int size){
    int counter = 0;
    for(int i = 0; i < size; i++){
        if (reducedArray[i] != sortedArray[i]){
            counter++;
        }
    }
    return counter;
}

int reducedArraySize(long long* restrict arr, long long* restrict from, long long* restrict to, int size)
{
    int newSize = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] > *from && arr[i] < *to)
        {
            newSize++;
        }
    }
    return newSize;
}

void reduceArray(long long* restrict arr, int* newArr, long long* restrict from, long long* restrict to, int size)
{
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > *from && arr[i] < *to)
        {
            newArr[j] = arr[i];
            j++;
        }
    }
    
}

void output_arrays( long long* restrict numbers, int numbers_size, long long* restrict from, long long* restrict to, long long* restrict Stdout, int *stdout_size, long long* restrict Stderr, int *stderr_size)
{
    int count_Stdout = 0;
    int count_Stderr = 0;

    for (int i = 0; i < numbers_size; i++) {
        if (numbers[i] <= *from ) {
            Stdout[count_Stdout] = numbers[i];
            count_Stdout++;
        }
        if (numbers[i] >= *to ) {
            Stderr[count_Stderr] = numbers[i];
            count_Stderr++;
        }
    }
    *stdout_size = count_Stdout;
    *stderr_size = count_Stderr;
}
*/
int check_params(int argc, char* argv[], long long* restrict to, long long* restrict from, int* toCount, int* fromCount){

    if(argc <= 1) return -1;
    if(argc > 3) return -2;

    if(argc > 2 && ( ((strncmp(argv[1] , "--from=" , 7) ==0 )  && (strncmp(argv[2] , "--from=" , 7) ==0))
        || ((strncmp(argv[1] , "--to=" , 5) ==0 )  && (strncmp(argv[2] , "--to=" , 5) ==0) ) ) )
    {
        return -3;
    }

    for (int i = 1; i < argc; ++i)
    {
        if (strncmp(argv[i], "--from=", 7) == 0)
        {
            if (*fromCount == 1)
            {
                
                return -3;
            }
            
            *from = strtoll(argv[i] + 7, NULL, 10);
            *fromCount = 1;
        }

        else if (strncmp(argv[i], "--to=", 5) == 0)
        {
            if (*toCount == 1)
            {
                
                return -3;
            }
            
            
            *to = strtoll(argv[i] + 5, NULL, 10);     
            
            *toCount = 1;
        }

    }
    if (*fromCount == 0 && *toCount == 0)
    {      
        return -4;
    }

    return 0;
}

int enter_array(long long* restrict from, long long* restrict to,long long* restrict array,
                long long* restrict array2, int size, int from_count, int to_count)
{
    int elements_in_array = 0;                                                          
    long long number;                                                                   
    char check_for_the_last_element;                                                    

    do {

        if(scanf("%lli%c" , &number , &check_for_the_last_element ) !=2 )               
        {
            fprintf(stderr , "can't read [%d] element" , elements_in_array);
            return -1;
        }
        if(number <= *from && from_count != 0 )
        {
            fprintf(stdout, "%lli " , number);
        }
        if(number >= *to && to_count != 0)
        {
            fprintf(stderr , "%lli " , number);
        }
        if(((number > *from) || (from_count == 0 ))
        && ((number < *to) || to_count == 0))                                     
        {
            array[elements_in_array] = number;
            array2[elements_in_array] = number;
            elements_in_array+=1;
        }

    } while (check_for_the_last_element != '\n' && elements_in_array < size);  

    return elements_in_array;   
}

int main(int argc, char **argv)
{   
//    if(argc <= 1) return -1;
//    if(argc > 3) return -2;
//    if(argc > 2 && strchr(argv[1], '=') == NULL && strchr(argv[2], '=') == NULL) return -4;


    long long int numbers[100];
    long long int copy_numb[100];
//    long long int Stdout[100],Stderr[100];
//    char divisor = ' '; 
//    int ArraySize = 0;
    int to_count = 0, from_count = 0;


    long long int from = 0, to = 0;
    
 //   int reducedSize;
   // int count_Stdout = 0;
   // int count_Stderr = 0;
/*
    while(divisor == ' '){

        scanf("%lli%c", &numbers[ArraySize], &divisor);
        ArraySize++;
    }
*/  
    int result_of_check = check_params(argc, argv, &to, &from, &from_count, &to_count);
    if (result_of_check != 0){
        return result_of_check;
    }

    int elements_in_array = enter_array(&from, &to, numbers, copy_numb, 100, from_count, to_count);
    if (elements_in_array < 0){
        return -5;
    }

    //output_arrays(numbers,ArraySize, &from, &to,Stdout,&count_Stdout,Stderr,&count_Stderr);
 //   reducedSize = reducedArraySize(numbers, &from, &to, ArraySize);
     
    int output;
/*
    int ReducedArray[reducedSize];
    int SortedArray[reducedSize];

    copy_array(SortedArray,ReducedArray, reducedSize );
    reduceArray(numbers, ReducedArray, &from,  &to, ArraySize);
    array_sort(ReducedArray, SortedArray, reducedSize);
*/


    //output = array_compare(ReducedArray, SortedArray, reducedSize);
    //all_output(Stdout,count_Stdout,Stderr,count_Stderr);

    for(int i = 0 ; i < elements_in_array ; ++i)
    {
        if(numbers[i] != copy_numb[i])
        {
            output+=1;
        }
    }

    return output;  
}
