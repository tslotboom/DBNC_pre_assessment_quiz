#include <stdio.h>
#include <stdlib.h>

#include <globals.h>


#define NUM_COMMAND_LINE_ARGS 2


int squareMaker(int N, int M, int* outputBuffer);
int fillOneByOneSquares(int num, int bufferIndex, int* outputBuffer);


/**
 * Print the set of squares that are possible to be created within a rectangle
 * of size NxM, ensuring that all squares are as large as possible. 
 * @param N: length of rectangle
 * @param M: width of rectangle
 * @param outputBuffer: the buffer to contain the ordered pairs of squares that
 * have been generated.
 * @return The amount of ordered pairs in outputBuffer
*/
int squareMaker(int N, int M, int* outputBuffer){
    int bufferIndex, largerNum, smallerNum;
    bufferIndex = 0;
    while (N != M && N > 1 && M > 1){
        if (N > M){
            largerNum = N;
            smallerNum = M;
        }
        else{
            largerNum = M;
            smallerNum = N;
        }
        outputBuffer[bufferIndex++] = smallerNum;
        outputBuffer[bufferIndex++] = smallerNum;

        N = smallerNum;
        M = largerNum - smallerNum;
        if (!realloc(outputBuffer, (bufferIndex + 2) * sizeof(int))){
            printf("ERROR: Realloc failed for output buffer\n");
            return FAILURE;
        }
    }
    if (N == M){
        outputBuffer[bufferIndex++] = N;
        outputBuffer[bufferIndex++] = M;
    }
    else if (N == 1){
        bufferIndex = fillOneByOneSquares(M, bufferIndex, outputBuffer);
    }
    else if (M == 1){
        bufferIndex = fillOneByOneSquares(N, bufferIndex, outputBuffer);
    }
    else{
        printf("ERROR: Shouldn't ever get here\n");
        return FAILURE;
    }
    return bufferIndex;
}

/**
 * Fill the output buffer with the remaining 1x1 squares to be extracted from a 
 * rectangle.
 * @param num: the number of 1x1 squares to be added.
 * @param bufferIndex: the current index in the buffer.
 * @param outputBuffer: the buffer to contain the ordered pairs of squares that
 * have been generated.
 * @return The amount of ordered pairs in outputBuffer
*/
int fillOneByOneSquares(int remainingSquares, int bufferIndex, int* outputBuffer){
    int i;
    if (!realloc(outputBuffer, (bufferIndex + remainingSquares * 2) * sizeof(int))){
        printf("ERROR: Realloc failed for output buffer\n");
        return FAILURE;
    }
    for (i=0; i<remainingSquares; i++){
        outputBuffer[bufferIndex++] = 1;
        outputBuffer[bufferIndex++] = 1;
    }
    return bufferIndex;
}


int main(int argc, char *argv[]){
    int N, M, outputBufferSize, i;
    int* outputBuffer;

    if (argc != NUM_COMMAND_LINE_ARGS + 1){
        printf("ERROR: Correct usage is: ./q1 <N> <M>\n");
        return FAILURE;
    }

    N = atoi(argv[1]);
    M = atoi(argv[2]);

    printf("\nInput: N = %d, M = %d\n", N, M);

    if (N < 1 || M < 1){
        printf("ERROR: N and M must be positive integers\n");
        return FAILURE;
    }

    outputBuffer = (int*) malloc(sizeof(int) * 2);
    if (outputBuffer == NULL){
        printf("ERROR: Malloc for outputbuffer failed\n");
        return FAILURE;
    }

    outputBufferSize = squareMaker(N, M, outputBuffer);
    if (outputBufferSize == FAILURE){
        printf("ERROR: Error encountered when running squareMaker\n");
        free(outputBuffer);
        return FAILURE;
    }
    printf("Output: ");
    for (i=0; i<outputBufferSize - 2; i=i+2){
        printf("%dx%d, ", outputBuffer[i], outputBuffer[i+1]);
    }

    printf("%dx%d\n", outputBuffer[outputBufferSize - 2], outputBuffer[outputBufferSize - 1]);
    
    free(outputBuffer);
    return SUCCESS;
}