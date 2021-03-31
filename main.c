#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE   1u
#define FALSE  0u

typedef unsigned char       boolean;        /* for use with TRUE/FALSE        */


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

void printArrayInHex(int *input, int startPos, int count) {
    if (input != NULL)
    {
        for(int i=0; i<count; i++) printf("%04X ", input[i+startPos]);
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
} NibbleBucket;

#define DIGIT_COUNT 16
#define ROWS_COUNT 4
// Global 16*4 buckets for niblles from 0 till F,  16 for one digit, 4 for all 4 digits,
NibbleBucket bucketsArr[DIGIT_COUNT][ROWS_COUNT];

void initOneRowBucket(int startPos, int rowPos){
    for (int i = 0; i < DIGIT_COUNT; i++)
    {
        bucketsArr[i][rowPos].count = 0;
        bucketsArr[i][rowPos].startPos = startPos;
    }
}

void printAllBucket(){
    for (int r = 0; r < ROWS_COUNT; r++)
    {
        for (int i = 0; i < DIGIT_COUNT; i++)
        {
            printf("[%d][%X] bucket, count %d, start pos %d\n", r, i, bucketsArr[i][r].count, bucketsArr[i][r].startPos);
        }
    }
}

void nibblesCounting(int *input, int start, int count, int nibblePos){
    for(int i=start; i<count+start; i++)
    {
        int bucketNumber = getNibbleByPos(input[i], nibblePos);
        bucketsArr[bucketNumber][nibblePos].count++;
    }

    for (int i = 1; i < DIGIT_COUNT; i++)
    {
        bucketsArr[i][nibblePos].startPos = bucketsArr[i-1][nibblePos].startPos + bucketsArr[i-1][nibblePos].count;
    }
}

void oneDigitSort(int *input, int count, int startPos, int nibblePos){
    //printf("oneDigitSort, startPos %d, count %d, nibblePos %d \n",startPos, count, nibblePos);
    initOneRowBucket(startPos, nibblePos);
    nibblesCounting(input, startPos, count, nibblePos);
    //printAllBucket();
    NibbleBucket curBucket;
    for (int i = startPos; i < count+startPos; i++)
    {
        boolean elementInPlase = FALSE;
        //printf("oneDigitSort, i=%d \n", i);
        while (FALSE == elementInPlase )
        {
            int nib = getNibbleByPos(input[i], nibblePos);
            curBucket = bucketsArr[nib][nibblePos];

            if ((i>=curBucket.startPos) && (i<= (curBucket.startPos+curBucket.count) ))
            {
                // element [i] already in please;
                elementInPlase = TRUE;
                break;
            }

            int indexToPost = curBucket.startPos;
            while (getNibbleByPos(input[i], nibblePos)==getNibbleByPos(input[indexToPost], nibblePos))
            {
                indexToPost++;
            }

            // ready to swap!
            // Element from [i] to [indexToPost]
            //printf("Bucket %X, \t swap A[%d](%04X) to A[%d](%04X)\n", nib, i, input[i], indexToPost, input[indexToPost]);
            swap(&input[i], &input[indexToPost]);
        }
    }
    //printf("\n");
    //printArrayInHex(input, startPos, count);
}


void flagSort(int *input, int count){
    printf("American flag sort, input:\n");
    printArrayInHex(input, 0, count);
    for (int i = 0; i < ROWS_COUNT; i++)
    {
        initOneRowBucket(0, i);
    }

    int nibblePos = 3;
    //while (nibblePos>0)
    {
        oneDigitSort(input, count, 0, nibblePos);

        // sort next nible:
        nibblePos = 2;
        for (int i = 0; i < DIGIT_COUNT; i++)
        {
            NibbleBucket curBucket = bucketsArr[i][nibblePos+1];
            if (curBucket.count <= 1)  continue;
            oneDigitSort(input, curBucket.count, curBucket.startPos, nibblePos);
            // sort next nible:
            nibblePos = 1;
            for (int j = 0; j < DIGIT_COUNT; j++)
            {
                NibbleBucket curBucket = bucketsArr[j][nibblePos+1];
                if (curBucket.count <= 1) continue;
                oneDigitSort(input, curBucket.count, curBucket.startPos, nibblePos);
                // sort next nible:
                nibblePos = 0;
                for (int k = 0; k < DIGIT_COUNT; k++)
                {
                    NibbleBucket curBucket = bucketsArr[k][nibblePos+1];
                    if (curBucket.count <= 1) continue;
                    oneDigitSort(input, curBucket.count, curBucket.startPos, nibblePos);
                }
            }
        }
    }
    printf("American flag sort, output:\n");
    printArrayInHex(input, 0, count);

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
    printArrayInHex(values, 0, 5);

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
    printArrayInHex(array, 0, arraySize);
    printf("Print out numbers in ascending order:\n");
    flagSort(array, arraySize);


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

    return(0);
}