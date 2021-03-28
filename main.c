#include <stdio.h>
#include <stdlib.h>

int values[] = { 88, 56, 100, 2, 25 };
int array[] = { 864, -23, 868, 473, -5645, 12, 65, 248, 923,-54, -543, 179, 554, 987, 921, 654, 756, 458, 93, 265, -456, 514, 484, 654, 88, 56, 100, 2, 25};


void swap(int *a, int *b){
    const int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *input, int count) {
    if (input != NULL)
    {
        for(int i=0; i<count; i++) printf("%d ", input[i]);        
    }	
    printf("\n");
}


void xsort (int *input, int count) {
    if (NULL == input)
    {
        printf("input pointer shall be valid");
        return;
    }
    // Marcin Ciura, A102549 - sequence of increments for shell sort algorithm.
    // 1, 4, 10, 23, 57, 132, 301, 701, 1750
    int const distArr[] = {1750, 701, 301, 132, 57, 23, 10, 4, 1};
    int distSize = sizeof(distArr)/sizeof(distArr[0]);

    // Detect starting distanse as distArr[].max less, than 1/2 incomming input array length
    int start = 0;
    while (distArr[start] > count/2)  start++;

    for (int n = start; n < distSize; n++)
    {
        int d = distArr[n];
        //printf("New distance is %d \n", d);
        for (int i = 0; i < count; i++)
        {
            for (int j = i+d; j < count; j+=d)
            {
                if (input[i] > input[j]) 
                {
                    swap(&input[i], &input[j]);
                    //printf("d= %d, \t swap A[%d](%d) to A[%d](%d)\n", d, i, input[i], j, input[j]);
                }
            }
        }
    }

    //printf("\nAfter sorting the list is: \n");
    printArray(input,count);
    printf("\n");
}

int main () {
    int arraySize = sizeof(array)/sizeof(array[0]);

    printf("Input numbers are: \n");
    printArray(array,arraySize);
    printf("Print out numbers in ascending order:\n");
    xsort(array, arraySize);

    printf("Input numbers are: \n");
    printArray(values,5);
    printf("Print out numbers in ascending order:\n");
    xsort(values, 5);

    printf("Check for zerro pointer: \n");
    int *pZerro = NULL;
    printArray(pZerro,5);
    xsort(pZerro, 5);

    return(0);
}