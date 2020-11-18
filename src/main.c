#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

extern void work_with_array(long long* array , int* number_of_elements);

struct params_exist
{
    int from;
    int to;
};

int check_params(int argc, char* argv[], long long* restrict to, long long* restrict from, struct params_exist *ExistOfParams){

    if(argc <= 1) return -1;
    if(argc > 3) return -2;

    if(argc > 2 && ( ((strncmp(argv[1] , "--from=" , 7) ==0 )  && (strncmp(argv[2] , "--from=" , 7) ==0))
        || ((strncmp(argv[1] , "--to=" , 5) ==0 )  && (strncmp(argv[2] , "--to=" , 5) ==0) ) ) )
    {
        return -3;
    }

    for (int i = 1; i < argc; ++i)
    {
        if( (*(from) == 0) && (strncmp(argv[i]  , "--from=" , 7) == 0))    
        {
            *(from) = strtoll(argv[i] +7 , NULL, 10 );  

            ExistOfParams -> from = 1;
        }

        else if( (*(to) == 0)  && (strncmp( argv[i]  , "--to=" , 5) == 0))    
        {
            *(to) = strtoll(argv[i] +5 , NULL, 10 );          

            ExistOfParams -> to = 1;
        }
    }
    if (ExistOfParams -> from == 0 && ExistOfParams -> to == 0)
    {      
        return -4;
    }

    return 0;
}

int enter_array(long long* restrict from, long long* restrict to,long long* restrict array,
                long long* restrict array2, int size, struct params_exist *ExistOfParams)
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
        if(number <= *from && ExistOfParams ->from != 0 )
        {
            fprintf(stdout, "%lli " , number);
        }
        if(number >= *to && ExistOfParams->to != 0)
        {
            fprintf(stderr , "%lli " , number);
        }
        if(((number > *from) || (ExistOfParams -> from == 0 ))
        && ((number < *to) || ExistOfParams -> to == 0))                                     
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


    long long int numbers[100];
    long long int copy_numb[100];

    long long int from = 0, to = 0;
    struct params_exist ExistOfParams = {0,0};

    
    

    int result_of_check = check_params(argc, argv, &to, &from, &ExistOfParams);
    if (result_of_check != 0){
        return result_of_check;
    }

    int elements_in_array = enter_array(&from, &to, numbers, copy_numb, 100, &ExistOfParams);
    if (elements_in_array < 0){
        return -5;
    }

  
     
    int output;


    work_with_array(numbers,&elements_in_array);


    for(int i = 0 ; i < elements_in_array ; ++i)
    {
        if(numbers[i] != copy_numb[i])
        {
            output+=1;
        }
    }

    return output;  
}
