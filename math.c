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

float ssconv(float ** mat, float ** mat2, int n, int m) {
  float ret = 0.0;
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<m; j++) {
      ret += mat[i][j] * mat2[i][j];
    }
  }
  return ret;
}

int convolution(float ** mat, int n, int m, float ** mat2, int n2, int m2, float ** ret, int stride) {
  for(int i = 0; i < (int)(n/stride - (n2-1)); i++) {
    for(int j = 0; j < (int)(m/stride - (m2-1)); j++) {
      float * temp[n2];

      for(int k = 0; k<n2; k++) {
        temp[k] = mat[i*stride + k] + j*stride;
      }


      ret[i][j] = ssconv(temp, mat2, n2, m2);
    }
  }
  return 1;
} 

float calcEX(int acc, float exponent) {
  float sum = 1.0;
  int factorial = 1;
  float carry = exponent;
  for(int i = 1; i<acc; i++) {
    sum += (carry / factorial);
    factorial *= (i+1);
    carry *= exponent;
  }
  return sum;
}
