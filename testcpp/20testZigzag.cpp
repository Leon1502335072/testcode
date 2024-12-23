#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

typedef unsigned char byte;

const int BYTE_BITS = 8;
const int INT_BIT_SIZE = sizeof(int *) BYTE_BITS;

const char* bytes_to_binary_str(byte* v, int byte_count, char* out, int out_size)
{
    int idx = 0;
    for (int i = 0; i < byte_count; ++i)
    {
        if(i>0)
            out[idx++] = '_';
        
    }
}

int main()
{

    return 0;
}