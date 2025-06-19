#ifndef MATH
#define MATH

float vecMult(float * vec, int numVals, float*vec2, int numVals2);
int matrVecMult(float ** mat, int n, int m , float* vec, int numVals, float* ret);

int convolution(float ** mat, int n, int m, float ** mat2, int n2, int m2, float ** ret, int stride);

float calcEX(int acc, float exponent);

#endif
