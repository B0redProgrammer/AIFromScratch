#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float vecMult(float * vec, int numVals, float * vec2, int numVals2) {
  if(numVals != numVals2) {
    return NAN;
  }

  float sum = 0.0;
  for(int j = 0; j<numVals2; j++) {
    sum += vec[j]*vec2[j]; 
  }
 
  return sum;
}

int matrVecMult(float ** mat, int n, int m, float * vec, int numVals, float * ret) {
  if(m != numVals) {
    return 0;
  }

  for(int i = 0; i<n; i++) {
    ret[i] = vecMult(mat[i], m, vec, numVals);
  }
  return 1;
}
