#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
# define sort_array _sort_array

extern void array_sort(int*, int*, int );

void all_output(char** params, int params_count, int* numbers, int numbers_size, int* Stdout, int Stdout_size, int* Stderr, int Stderr_size, int exit_code, int* Reduced, int Redused_size, int* Sorted){
    printf("\nParams: ");
    for (int i = 0; i < params_count; i++){
        printf("%s ",params[i]);
    }

    printf("\nInput: ");
    for (int i = 0; i < numbers_size; i++){
        printf("%d ",numbers[i]);
    }

    printf("\nStdout: ");
    for (int i = 0; i < Stdout_size; i++){
        printf("%d ",Stdout[i]);
    }

    printf("\nStderr: ");
    for (int i = 0; i < Stderr_size; i++){
        printf("%d ",Stderr[i]);
    }

    printf("\nExit Code: %d ",exit_code);

    printf("\n(Reduced: ");
    for (int i = 0; i < Redused_size; i++){
        printf("%d ",Reduced[i]);
    }
    printf(", Sorted: ");
    for (int i = 0; i < Redused_size; i++){
        printf("%d ",Sorted[i]);
    }
    printf(")\n");


}

void print_array(int* array, int size){
    
    for (int i = 0; i < size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void copy_array(int* array, int* copied_array, int size){
    for (int i = 0; i < size; i++){
        copied_array[i] = array[i];
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

int reducedArraySize(int* arr, int from, int to, int size)
{
    int newSize = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] > from && arr[i] < to)
        {
            newSize++;
        }
    }
    return newSize;
}

void reduceArray(int* arr, int* newArr, int from, int to, int size)
{
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > from && arr[i] < to)
        {
            newArr[j] = arr[i];
            j++;
        }
    }
    
}

void output_arrays( int* numbers, int numbers_size, int from, int to, int* Stdout, int *stdout_size, int* Stderr, int *stderr_size)
{
    int count_Stdout = 0;
    int count_Stderr = 0;

    for (int i = 0; i < numbers_size; i++) {
        if (numbers[i] <= from ) {
            Stdout[count_Stdout] = numbers[i];
            count_Stdout++;
        }
        if (numbers[i] >= to ) {
            Stderr[count_Stderr] = numbers[i];
            count_Stderr++;
        }
    }
    *stdout_size = count_Stdout;
    *stderr_size = count_Stderr;
}

int main(int argc, char **argv)
{   
    if(argc <= 1) return -1;
    if(argc > 3) return -2;
    if(argc > 2 && strchr(argv[1], '=') == NULL && strchr(argv[2], '=') == NULL) return -4;

    int *numbers = malloc(sizeof(long long)*100);
    int Stdout[100],Stderr[100];
    char divisor = ' '; 
    int ArraySize = 0;

    char fromCount = 0;
    char toCount = 0;
    int from = INT_MIN;
    int to = INT_MAX;
    int reducedSize;
    int count_Stdout = 0;
    int count_Stderr = 0;

    while(divisor == ' '){

        scanf("%d%c", &numbers[ArraySize], &divisor);
        ArraySize++;
    }

    for (int i = 1; i < argc; i++)
    {
        if (strncmp(argv[i], "--from=", 7) == 0)
        {
            if (fromCount == 1)
            {
                
                return -3;
            }
            if (strlen(argv[i]) > 7)
            {
                from = atoi(argv[i] + 7);
            }
            else
            {
                from = INT_MIN;
            }

            fromCount = 1;
        }
        else if (strncmp(argv[i], "--to=", 5) == 0)
        {
            if (toCount == 1)
            {
                
                return -3;
            }
            if (strlen(argv[i]) > 5)
            {
                to = atoi(argv[i] + 5);
            }

            else
            {
                to = INT_MAX;
            }
            
            toCount = 1;
        }

    }
    if (fromCount == 0 && toCount == 0)
    {      
        return -4;
    }

    output_arrays(numbers,ArraySize,from,to,Stdout,&count_Stdout,Stderr,&count_Stderr);
    reducedSize = reducedArraySize(numbers, from, to, ArraySize);
     
    int output;
    int ReducedArray[reducedSize];
    int SortedArray[reducedSize];

    copy_array(ReducedArray, SortedArray, reducedSize);
    reduceArray(numbers, ReducedArray, from, to, ArraySize);
    array_sort(ReducedArray, SortedArray, reducedSize);



    output = array_compare(ReducedArray, SortedArray, reducedSize);
    all_output(argv,argc,numbers,ArraySize,Stdout,count_Stdout,Stderr,count_Stderr,output,ReducedArray,reducedSize,SortedArray);

    return output;  
}
