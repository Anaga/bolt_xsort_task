#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int values[] = {88, 56, 100, 2, 25 };
int hexArray[] = {0x4D53, 0x65B7, 0x354A, 0x87FF, 0x648F, 0x9F73, 0x21F5, 0x4E30, 0x6C54, 0x020A, 0x41D8, 0x746E, 0x48CC, 0x460A};
int array[] = {864, 23, 868, 473, 645, 12, 65, 248, 923, 154, 543, 179, 554, 987, 921, 654, 756, 458, 93, 265, 456, 514, 484, 654, 88, 56, 100, 2, 25};

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

void printArrayInHex(int *input, int count) {
    if (input != NULL)
    {
        for(int i=0; i<count; i++) printf("%04X ", input[i]);        
    }	
    printf("\n");
}

// American flag sorting

int getNibbleByPos(int number, unsigned short int pos){
    // mask of 4 bits in position - (0xF << (pos*4)
    // get only one nibble - number & mask
    // shift nibble to LSB - (number & mask) >> (pos*4)
    return (number & (0xF << (pos*4))) >> (pos*4); ;
}
typedef struct NibbleBuckets{
    int count;
    int startPos;
    int endPos;
} NibbleBucket;

#define BUCKETS_COUNT 16
// Global 16 buckets for nibles from 0 till F
 NibbleBucket bucketsArr[BUCKETS_COUNT];

void initAllBucket(){
    for (int i = 0; i < BUCKETS_COUNT; i++)
    {
        bucketsArr[i].count = 0;
        bucketsArr[i].startPos = 0;
        bucketsArr[i].endPos = 0;
    } 
}

void printAllBucket(){
    for (int i = 0; i < BUCKETS_COUNT; i++)
    {
        printf("'%X' bucket, from %d till %d, count %d\n", i, 
                    bucketsArr[i].startPos,
                    bucketsArr[i].endPos,
                    bucketsArr[i].count );
    }
}

void nibblesCounting(int *input, int start, int end, int nibblePos){
    for(int i=start; i<end; i++)
    {
        int bucketNumber = getNibbleByPos(input[i], nibblePos);
        bucketsArr[bucketNumber].count++;
    }

    bucketsArr[0].endPos = bucketsArr[0].count;
    for (int i = 1; i < BUCKETS_COUNT; i++)
    {
        bucketsArr[i].startPos = bucketsArr[i-1].endPos;
        bucketsArr[i].endPos = bucketsArr[i].startPos + bucketsArr[i].count;
    }        
}

void flagSort(int *input, int count){
    printf("American flag sort\n");
    printArrayInHex(input, count);

    int nibblePos = 3;
    while (nibblePos>0)
    {   

    initAllBucket();

    nibblesCounting(input, 0, count, nibblePos);
    printAllBucket();
    NibbleBucket curBucket;

    for (int j = 0; j < 2; j++)
    {    
        for (int i = 0; i < count; i++)
        {        
            int nib = getNibbleByPos(input[i], nibblePos);
            curBucket = bucketsArr[nib];
            
            if ((i>=curBucket.startPos) && (i<=curBucket.endPos))
            {
                // element [i] already in please;
                continue;
            }
            int indexToPost = curBucket.startPos;
            while (getNibbleByPos(input[i], nibblePos)==getNibbleByPos(input[indexToPost], nibblePos))
            {
                indexToPost++;
            }
            // ready to swap!
            // Element from [i] to [indexToPost]
            printf("Bucket %X, \t swap A[%d](%04X) to A[%d](%04X)\n", nib, i, input[i], indexToPost, input[indexToPost]);
            swap(&input[i], &input[indexToPost]);
        }  
        printf("\n");
        printArrayInHex(input, count);
    }
    nibblePos--;
    }    
}


void selectionSort(int *input, int count){
    printf("\n");
    int sorted = 0;
    while (sorted<count)
    {
        int min = input[0];
        int index = 0;
        int i = 1;
        for (; i < count-sorted; i++)
        {
            if (input[i]<min)
            {
                index = i;
                min = input[i];
            }     
        }
        printf("%d ",min);
        swap(&input[i-1], &input[index]);
        sorted++;
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

    printf("values:");
    printArray(values,5);
    printArrayInHex(values, 5);

    printf("Hex view of hexArray:");
    ssize_t hexArraySize = sizeof(hexArray)/sizeof(hexArray[0]);
    for (size_t i = 0; i < hexArraySize; i++)
    {
        for (int j = 3; j >= 0; j--) printf("%X", getNibbleByPos(hexArray[i], j));
        printf(" ");        
    }
    printf("\n");

    flagSort(hexArray,hexArraySize);

    int *pOrigArray;
    int *pArrayToTest;

    int array2[arraySize];
    int array3[arraySize];    

    pOrigArray = (int*)malloc(arraySize * sizeof(int));
    pArrayToTest = (int*)malloc(arraySize * sizeof(int));

    printf("pOrigArray");
    memcpy(array2, array, arraySize * sizeof(int));
    printArray(array2,arraySize);

    printf("pArrayToTest");
    memmove(pArrayToTest, array, arraySize * sizeof(int));
    printArray(pArrayToTest,arraySize);
    
    printf("Input numbers are: \n");
    printArrayInHex(array,arraySize);
    printf("Print out numbers in ascending order:\n");      
    flagSort(array, arraySize);

    /*
    printf("Input numbers are: \n");
    printArray(values,5);
    printf("Print out numbers in ascending order:\n");
    xsort(values, 5);

    printf("Check for zerro pointer: \n");
    int *pZerro = NULL;
    printArray(pZerro,5);
    xsort(pZerro, 5);

    selectionSort(pArrayToTest, arraySize);
    printArray(pArrayToTest,arraySize);

    selectionSort(array2, arraySize);
    printArray(array2,arraySize);


    free(pOrigArray);
    free(pArrayToTest);
    */
    return(0);
}