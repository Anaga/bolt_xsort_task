#include <stdio.h>
#include <stdlib.h>

int values[] = { 88, 56, 100, 2, 25 };
int array[] = { 864, 868, 473, 248, 923, 179, 554, 987, 921, 654, 756, 458, 93, 265, 456, 514, 484, 654 };


void swap(int *a, int *b){
    const int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *input, int count) {
	printf("\nNow array is: \n");
    for(int i=0; i<count; i++) printf("%d ", input[i]);
    printf("\n");
}


void xsort (int *input, int count) {
    printArray(input,count);
    // Marcin Ciura, A102549 - sequence of increments for shell sort algorithm.
    // 1, 4, 10, 23, 57, 132, 301, 701, 1750
    //int const distArr[] = {1750, 701, 301, 132, 57, 23, 10, 4, 1};
    int const distArr[] = {10, 4, 1};
    int distSize = sizeof(distArr)/sizeof(distArr[0]);

    for (int n = 0; n < distSize; n++)
    {
        int d = distArr[n];
        printf("New distance is %d \n", d);
        for (int i = 0; i < count; i++)
        {
            for (int j = i+d; j < count; j+=d)
            {
                if (input[i] > input[j]) 
                {
                    swap(&input[i], &input[j]);
                    printf("d= %d, \t swap A[%d](%d) to A[%d](%d)\n", d, i, input[i], j, input[j]);
                }
            }
        }
    }

    printf("\nAfter sorting the list is: \n");
    printArray(input,count);
    printf("\n");
}

int main () {
    int arraySize = sizeof(array)/sizeof(array[0]);

    printf("\nBefore sorting the list is: \n");
    printArray(array,arraySize);

    xsort(array, arraySize);

    printArray(array,arraySize);

    printArray(values,5);
    xsort(values, 5);
    printArray(values,5);
    return(0);
}