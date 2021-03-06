#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE   1u
#define FALSE  0u

typedef unsigned char       boolean; 
typedef unsigned short int  uInt8;

int values[] = {88, 56, 100, 2, 25 };
int hexArray[] = {0x4D53, 0x65B7, 0x354A, 0x87FF, 0x648F, 0x9F73, 0x21F5, 0x4E30, 0x6C54, 0x020A, 0x41D8, 0x746E, 0x48CC, 0x460A};
int array[] = {864, 23, 868, 473, 645, 12, 65, 248, 923, 154, 543, 179, 554, 987, 921, 654, 756, 458, 93, 265, 456, 514, 484, 654, 88, 56, 100, 2, 25};
int smallArray[] = {15, 4, 9, 5, 7, 14, 3, 8, 2, 0, 1, 12};
int bigArray[] = {
 0x096a, 0x117e, 0x06e9, 0x0a94, 0x14f8, 0x0f8a, 0x0605, 0x1dbe, 0x0b47, 0x008d, 0x0022, 0x0130, 0x1269, 0x06cb, 0x113d, 0x06da, 0x1134, 0x0da3, 0x0afc, 0x11c5,
 0x1349, 0x122f, 0x1168, 0x12a4, 0x0aef, 0x1150, 0x0bbe, 0x019e, 0x0322, 0x0f74, 0x0dab, 0x106d, 0x1309, 0x011a, 0x0816, 0x05f4, 0x0782, 0x0bd5, 0x1170, 0x02ec,
 0x19aa, 0x06d6, 0x08a0, 0x0c98, 0x023c, 0x0922, 0x030c, 0x0103, 0x0020, 0x1326, 0x0b40, 0x1abc, 0x0f1f, 0x0797, 0x13b9, 0x0860, 0x0f86, 0x08ae, 0x11c7, 0x0244,
 0x0f31, 0x08df, 0x06f5, 0x0320, 0x0610, 0x0257, 0x0556, 0x04f4, 0x0c09, 0x09dc, 0x0b2d, 0x0097, 0x11db, 0x0f2a, 0x16ad, 0x0b6e, 0x1275, 0x033f, 0x00ca, 0x08f6,
 0x0d20, 0x0959, 0x010c, 0x0114, 0x034c, 0x0223, 0x0561, 0x12a0, 0x0e16, 0x048d, 0x00cb, 0x0383, 0x0ace, 0x079a, 0x080c, 0x1ace, 0x0d06, 0x0369, 0x0bcf, 0x1282,
 0x0b20, 0x1576, 0x0665, 0x1099, 0x0697, 0x044d, 0x11e6, 0x0172, 0x0ac7, 0x09d6, 0x0943, 0x07f4, 0x09bc, 0x136b, 0x04cd, 0x041d, 0x1347, 0x0574, 0x10c6, 0x111a,
 0x0529, 0x03b5, 0x1114, 0x0f58, 0x0560, 0x0ae6, 0x05c5, 0x0ac0, 0x115c, 0x0719, 0x082a, 0x0bef, 0x02e7, 0x0887, 0x0e5d, 0x0323, 0x0e97, 0x0b62, 0x0bb4, 0x06cd,
 0x108b, 0x0dfc, 0x03c2, 0x113e, 0x0432, 0x0075, 0x0cf0, 0x0e8d, 0x0bb3, 0x04ba, 0x0d23, 0x0b45, 0x09c9, 0x0235, 0x077c, 0x02f1, 0x00bd, 0x059b, 0x0e77, 0x083d,
 0x01a1, 0x12f5, 0x0d9c, 0x0c10, 0x061b, 0x0f2e, 0x048a, 0x1242, 0x094b, 0x08c2, 0x0e4a, 0x10e4, 0x0e46, 0x0cb2, 0x0f62, 0x11cf, 0x0f9a, 0x06a5, 0x0e0e, 0x019f,
 0x0cdd, 0x0b18, 0x05b0, 0x10aa, 0x08d6, 0x13d2, 0x08eb, 0x0147, 0x0e14, 0x09b7, 0x055b, 0x0755, 0x0b75, 0x1121, 0x07df, 0x0c3d, 0x0e54, 0x0dbe, 0x07a0, 0x0eeb,
 0x0dc4, 0x046c, 0x0614, 0x0834, 0x1715, 0x12c9, 0x0bd3, 0x0841, 0x0c2b, 0x0624, 0x0650, 0x0968, 0x0fb2, 0x0c61, 0x1140, 0x0ee4, 0x0049, 0x1146, 0x1335, 0x103b,
 0x136a, 0x0457, 0x0431, 0x03bb, 0x0712, 0x0abe, 0x0d91, 0x0082, 0x18eb, 0x11ff, 0x030b, 0x0921, 0x024b, 0x04a8, 0x073b, 0x037f, 0x07cc, 0x0c0d, 0x0caf, 0x089e,
 0x10d9, 0x12c4, 0x09e0, 0x1203, 0x104d, 0x0b73, 0x0568, 0x117f, 0x0b3d, 0x03cb, 0x06bd, 0x178f, 0x019c, 0x020e, 0x0f22, 0x0f92, 0x125a, 0x000a, 0x014e, 0x0a29,
 0x055a, 0x0add, 0x09d4, 0x008c, 0x015b, 0x115e, 0x0cd5, 0x0cdb, 0x09fa, 0x053a, 0x11f4, 0x03c9, 0x1330, 0x042c, 0x01ce, 0x12b5, 0x0f99, 0x0514, 0x08d7, 0x0296,
 0x1191, 0x0d5e, 0x12a5, 0x038f, 0x04e2, 0x0649, 0x0bab, 0x030d, 0x0715, 0x0db6, 0x0b68, 0x0f49, 0x1277, 0x009a, 0x08c5, 0x0b84, 0x0183, 0x05b2, 0x09bf, 0x0e02,
 0x0558, 0x0cc2, 0x0551, 0x0a56, 0x0572, 0x086b, 0x0342, 0x09ec, 0x06ce, 0x0e2d, 0x0b2b, 0x0e1b, 0x0f4d, 0x0309, 0x1256, 0x048c, 0x0181, 0x060b, 0x0861, 0x12b4,
 0x01b2, 0x0df3, 0x034a, 0x03e2, 0x0135, 0x0421, 0x0c74, 0x075e, 0x03ee, 0x129c, 0x0096, 0x0c16, 0x0083, 0x00f6, 0x0028, 0x0cd3, 0x0f89, 0x0d9d, 0x016d, 0x0866,
 0x0d62, 0x00a6, 0x0274, 0x09c5, 0x0a11, 0x12ef, 0x1303, 0x0726, 0x04b7, 0x0b2c, 0x0a7b, 0x0623, 0x0f26, 0x03ae, 0x1219, 0x078f, 0x1004, 0x0300, 0x0060, 0x08c4,
 0x0e2c, 0x06c3, 0x0df8, 0x045d, 0x0b46, 0x10c9, 0x02d4, 0x019a, 0x0e4c, 0x0754, 0x0f05, 0x0ceb, 0x0893, 0x0c5e, 0x018f, 0x05d3, 0x05a6, 0x11e8, 0x1249, 0x00c7,
 0x0b61, 0x1193, 0x0055, 0x01ac, 0x1345, 0x0594, 0x014f, 0x1c72, 0x0b99, 0x07f6, 0x11cd, 0x0670, 0x029b, 0x06fe, 0x0d11, 0x077e, 0x01e0, 0x0e59, 0x065f, 0x073a,
 0x0178, 0x0b16, 0x045e, 0x1288, 0x1bb0, 0x0e87, 0x0373, 0x015c, 0x0057, 0x0cc8, 0x1893, 0x0af0, 0x12d7, 0x0b6c, 0x0a9d, 0x02b1, 0x15a6, 0x17f2, 0x0245, 0x0eec,
 0x066e, 0x0684, 0x00d6, 0x00b5, 0x0837, 0x0348, 0x04e0, 0x02d7, 0x00f4, 0x1102, 0x0f52, 0x1628, 0x007e, 0x0fa0, 0x119d, 0x0c0c, 0x09cf, 0x0eb5, 0x120f, 0x030f,
 0x01b5, 0x0cbe, 0x03d3, 0x0552, 0x0dfe, 0x0d7d, 0x0d50, 0x0bc7, 0x034b, 0x1841, 0x0935, 0x04f8, 0x0237, 0x0e76, 0x07e0, 0x10a3, 0x11be, 0x0f63, 0x127c, 0x005a,
 0x1155, 0x1175, 0x0516, 0x0bed, 0x0657, 0x0739, 0x0768, 0x10f2, 0x0729, 0x0586, 0x0c33, 0x0a96, 0x121d, 0x0cd1, 0x08d5, 0x189e, 0x0d31, 0x0af7, 0x062b, 0x0a65,
 0x0153, 0x11b8, 0x0fee, 0x01ee, 0x0db4, 0x029d, 0x0a76, 0x0622, 0x12c6, 0x0d88, 0x0166, 0x1187, 0x0e57, 0x11f8, 0x10dd, 0x06c5, 0x0f48, 0x1233, 0x0c8d, 0x1054,
 0x1000, 0x0ea4, 0x0485, 0x0ee2, 0x1070, 0x0460, 0x0a90, 0x12d8, 0x0ff9, 0x0b83, 0x1320, 0x1254, 0x0fa3, 0x10d0, 0x124e, 0x186a, 0x1300, 0x076d, 0x0c92, 0x0bfd,
 0x0341, 0x0937, 0x0e2a, 0x1498, 0x0496, 0x09c3, 0x02a8, 0x1377, 0x1172, 0x0a26, 0x0366, 0x0d04, 0x0e24, 0x1174, 0x0e6b, 0x1006, 0x11f1, 0x03ad, 0x0b26, 0x0c1e,
 0x0f36, 0x0a88, 0x100f, 0x0eac, 0x0be1, 0x0b92, 0x0a98, 0x098d, 0x0a5f, 0x073e, 0x0dd3, 0x131e, 0x1298, 0x0d9b, 0x0429, 0x0efe, 0x0ab1, 0x10d3, 0x133b, 0x0d2a,
 0x125c, 0x04ad, 0x0a0f, 0x0c46, 0x0312, 0x14b0, 0x1032, 0x0e0d, 0x1122, 0x09b4, 0x0c11, 0x0576, 0x112c, 0x1127, 0x0b7c, 0x0d95, 0x039a, 0x03a0, 0x1113, 0x12d9,
 0x06cf, 0x05ec, 0x1367, 0x062e, 0x0c0a, 0x0380, 0x03cf, 0x0bf4, 0x0c89, 0x111b, 0x0616, 0x11d8, 0x079e, 0x0132, 0x1276, 0x0fe4, 0x0abc, 0x11eb, 0x0c41, 0x0459,
 0x02dd, 0x1284, 0x0c68, 0x1a8c, 0x0a58, 0x0880, 0x11c4, 0x1050, 0x066a, 0x0596, 0x0d85, 0x15f4, 0x05e6, 0x0dd1, 0x05c2, 0x0e66, 0x0641, 0x0a69, 0x0780, 0x027b,
 0x0f06, 0x12e9, 0x0fab, 0x114f, 0x03d5, 0x011d, 0x0f3f, 0x0660, 0x0875, 0x0c26, 0x08e8, 0x12d4, 0x018d, 0x0e4d, 0x0e1a, 0x0424, 0x0b0e, 0x0629, 0x0c18, 0x0897,
 0x0967, 0x106a, 0x0762, 0x09f1, 0x0339, 0x0eff, 0x06f2, 0x0738, 0x1041, 0x067c, 0x03ed, 0x1199, 0x0b64, 0x0706, 0x02f9, 0x14e0, 0x0646, 0x01be, 0x1331, 0x0200,
 0x0c8a, 0x10c2, 0x028a, 0x1136, 0x0ee0, 0x00cc, 0x0965, 0x1222, 0x055c, 0x071a, 0x0e44, 0x0259, 0x0e94, 0x07ea, 0x004b, 0x0c51, 0x0a71, 0x0957, 0x103e, 0x01c7,
 0x03fa, 0x1b64, 0x009c, 0x104f, 0x08b7, 0x0cf9, 0x0559, 0x0bb5, 0x129d, 0x0180, 0x0d9a, 0x0cd4, 0x0fca, 0x134f, 0x156e, 0x0399, 0x0261, 0x0bbc, 0x0609, 0x07ca,
 0x1273, 0x1033, 0x0776, 0x0b30, 0x07eb, 0x1195, 0x0346, 0x0a4d, 0x0a46, 0x072e, 0x059f, 0x08b3, 0x0e78, 0x0d55, 0x0ce7, 0x00f8, 0x03e0, 0x0f02, 0x08db, 0x0e7e,
 0x0ae3, 0x0352, 0x0f59, 0x0be9, 0x03b1, 0x0325, 0x111c, 0x052f, 0x07a7, 0x0493, 0x086a, 0x04a3, 0x01cc, 0x0546, 0x096b, 0x10ca, 0x090b, 0x1057, 0x0106, 0x100b,
 0x0d02, 0x01c9, 0x08bb, 0x088b, 0x0011, 0x06fb, 0x10b2, 0x039d, 0x03b9, 0x0a93, 0x0d4a, 0x04bb, 0x1eb5, 0x049c, 0x0ecb, 0x07f5, 0x0ca1, 0x0390, 0x104c, 0x0f80,
 0x1302, 0x0e36, 0x0cba, 0x0afb, 0x006b, 0x07e7, 0x0265, 0x0d3c, 0x0230, 0x136f, 0x0ebd, 0x02b0, 0x0df0, 0x0bd7, 0x112e, 0x08f4, 0x0316, 0x0dd8, 0x00d3, 0x1260,
 0x0c66, 0x0652, 0x0ec5, 0x0400, 0x074c, 0x0906, 0x0c71, 0x1135, 0x00e5, 0x004a, 0x0d84, 0x07cb, 0x0bd6, 0x04c1, 0x1024, 0x0280, 0x0e3a, 0x0456, 0x0084, 0x0418,
 0x00d5, 0x1200, 0x048f, 0x0c45, 0x10b8, 0x0f2b, 0x1280, 0x1072, 0x0e61, 0x11fa, 0x0b93, 0x0628, 0x0abf, 0x0321, 0x0bf7, 0x027c, 0x0ff1, 0x0b9c, 0x03a2, 0x0f3d,
 0x0f7b, 0x110d, 0x0686, 0x097b, 0x00f0, 0x03b7, 0x1015, 0x010e, 0x0cef, 0x112f, 0x0778, 0x0db2, 0x0c08, 0x0878, 0x123a, 0x090c, 0x0d43, 0x0e9a, 0x0a42, 0x05df,
 0x11d6, 0x0a37, 0x0808, 0x0d0f, 0x0ff4, 0x0868, 0x119f, 0x02ef, 0x1011, 0x07d8, 0x077d, 0x09aa, 0x0127, 0x015e, 0x0b34, 0x09a6, 0x08ba, 0x0ccb, 0x0e4e, 0x12f6,
 0x0cab, 0x12fc, 0x1634, 0x0dac, 0x1290, 0x1228, 0x0ce0, 0x0595, 0x0e1c, 0x0f11, 0x0cc6, 0x033e, 0x0be5, 0x0c5d, 0x0d4c, 0x0534, 0x0e7c, 0x0ab6, 0x0a4f, 0x0aad,
 0x064a, 0x0740, 0x033c, 0x05bf, 0x03d8, 0x0853, 0x0e53, 0x0148, 0x05dd, 0x0871, 0x0985, 0x0258, 0x093e, 0x03d6, 0x1366, 0x056e, 0x0365, 0x0ee9, 0x0004, 0x0287,
 0x0fcd, 0x1154, 0x0518, 0x051b, 0x028e, 0x09fd, 0x0499, 0x0cfb, 0x0188, 0x027e, 0x0b5b, 0x058c, 0x0515, 0x0035, 0x0143, 0x17a0, 0x0b0c, 0x0226, 0x049f, 0x0adc,
 0x028f, 0x11b3, 0x0fc3, 0x12f7, 0x1235, 0x00f7, 0x09ef, 0x0375, 0x08b0, 0x12e1, 0x0186, 0x135b, 0x0994, 0x190c, 0x0f00, 0x017c, 0x04cc, 0x060d, 0x18b4, 0x1230,
 0x0d12, 0x0d1a, 0x0edf, 0x1816, 0x0187, 0x0747, 0x1287, 0x0d4d, 0x0977, 0x095f, 0x0ac5, 0x0f4b, 0x1295, 0x05ed, 0x0d2e, 0x1192, 0x0a9a, 0x0685, 0x1234, 0x10d4,
 0x10fd, 0x0d05, 0x14af, 0x12d2, 0x094c, 0x0751, 0x10ad, 0x133c, 0x0f3b, 0x122e, 0x1058, 0x0926, 0x0baa, 0x0d7a, 0x037d, 0x0976, 0x125b, 0x063c, 0x0bad, 0x0eba,
 0x0044, 0x0634, 0x0958, 0x021f, 0x0174, 0x05f5, 0x040f, 0x0332, 0x0396, 0x0a8c, 0x05fa, 0x0e27, 0x1107, 0x074f, 0x10b5, 0x060c, 0x0801, 0x0afd, 0x057d, 0x0426 };

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

int getNibbleByPos(int number, uInt8 pos){
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

void initOneRowBucket(int startPos, uInt8 rowPos){
    for (uInt8 i = 0; i < DIGIT_COUNT; i++)
    {
        bucketsArr[i][rowPos].count = 0;
        bucketsArr[i][rowPos].startPos = startPos;
    }
}

void printAllBucket(){
    for (uInt8 r = 0; r < ROWS_COUNT; r++)
    {
        for (uInt8 i = 0; i < DIGIT_COUNT; i++)
        {
            printf("[%d][%X] bucket, count %d, start pos %d\n", r, i, bucketsArr[i][r].count, bucketsArr[i][r].startPos);
        }
    }
}

void nibblesCounting(int *input, int start, int count, uInt8 nibblePos){
    for(int i=start; i<count+start; i++)
    {
        int bucketNumber = getNibbleByPos(input[i], nibblePos);
        bucketsArr[bucketNumber][nibblePos].count++;
    }

    for (uInt8 i = 1; i < DIGIT_COUNT; i++)
    {
        bucketsArr[i][nibblePos].startPos = bucketsArr[i-1][nibblePos].startPos + bucketsArr[i-1][nibblePos].count;
    }
}

void oneDigitSort(int *input, int count, int startPos, uInt8 nibblePos){
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
            uInt8 nib = getNibbleByPos(input[i], nibblePos);
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

//Recurent helper function for flagSort
void subArraySort(int *input, int count, int startPos, uInt8 nibblePos) {
    
    oneDigitSort(input, count, startPos, nibblePos);

    if (0 == nibblePos) return;

    nibblePos--;
    for (uInt8 i = 0; i < DIGIT_COUNT; i++)
    {
        NibbleBucket curBucket = bucketsArr[i][nibblePos+1];
        if (curBucket.count <= 1) continue;
        subArraySort(input, curBucket.count, curBucket.startPos, nibblePos);
    }
}

int getMax(int *input, int count){
    int max = input[0];
    for (int i = 0; i < count; i++)
    {
        if (max < input[i]) max = input[i];        
    }
    return max;    
}

uInt8 getMaxNibblePosition(int max){
    uInt8 ret = 0;
    while (max >>= 4) ret++;
    return ret;
}


void flagSort(int *input, int count){
    //printf("American flag sort, input:\n");
    //printArrayInHex(input, 0, count);
    for (uInt8 i = 0; i < ROWS_COUNT; i++)
    {
        initOneRowBucket(0, i);
    }

    int maxElement = getMax(input, count);
    uInt8 maxNibble = getMaxNibblePosition(maxElement);
    //printf("Maximim element in array is 0x%04X, we shall start to sort from %d nibble \n", maxElement, maxNibble);

    subArraySort(input, count, 0, maxNibble);
    //printf("American flag sort, output:\n");
    //printArrayInHex(input, 0, count);
    //printArray(input, count);

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

void shellSort(int *input, int count) {
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
}


void xsort (int *input, int count) {
    if (NULL == input)
    {
        printf("input pointer shall be valid\n");
        return;
    }
    flagSort(input, count);
    printArray(input,count);
    printf("\n");
}

int main () {

    int arraySize = sizeof(array)/sizeof(array[0]);
    int *pOrigArray = (int*)malloc(arraySize * sizeof(int));
    memcpy(pOrigArray, array, arraySize * sizeof(int));

    int hexArraySize = sizeof(hexArray)/sizeof(hexArray[0]);
    int *pOrigHexArray = (int*)malloc(hexArraySize * sizeof(int));
    memcpy(pOrigHexArray, hexArray, hexArraySize * sizeof(int));

    int smallArraySize = sizeof(smallArray)/sizeof(smallArray[0]);
    int *pSmallArray = (int*)malloc(smallArraySize * sizeof(int));
    memcpy(pSmallArray, smallArray, smallArraySize * sizeof(int));

    int *pArrayToTest;

    pArrayToTest = (int*)malloc(arraySize * sizeof(int));
    memcpy(pArrayToTest, pOrigArray, arraySize * sizeof(int));
    xsort(pArrayToTest, arraySize);

    pArrayToTest = realloc(pArrayToTest, hexArraySize * sizeof(int));
    memcpy(pArrayToTest, hexArray, hexArraySize * sizeof(int));
    xsort(pArrayToTest, hexArraySize);

    pArrayToTest = realloc(pArrayToTest, smallArraySize * sizeof(int));
    memcpy(pArrayToTest, smallArray, smallArraySize * sizeof(int));
    xsort(pArrayToTest, smallArraySize);




    printf("Check for zerro pointer: \n");
    int *pZerro = NULL;
    printArray(pZerro,5);
    xsort(pZerro, 5);

    int bigArraySize = sizeof(bigArray)/sizeof(smallArray[0]);
    xsort(bigArray, bigArraySize);
    printArrayInHex(bigArray, 0, bigArraySize);

    free(pOrigArray);
    free(pArrayToTest);

    return(0);
}