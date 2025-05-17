#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
  float * vals;
  int numVals;
};

typedef struct Matrix {
  float ** vals;
  int n;
  int m;
};

int matVecMult(struct Matrix * m, struct Vector * vec, struct Vector * ret) {
  if(m->n != vec->numVals) {
    return 0;
  }

  ret->numVals = m->m;
  if((ret->vals = malloc(sizeof(float)*ret->numVals)) == NULL) {
    return 0;
  }

  for(int i = 0; i<m->m; i++) {
    float sum = 0.0;
    for(int j = 0; j<m->n; j++) {
       sum += vec->vals[j] * m->vals[i][j];
    }
    ret->vals[i] = sum;
  }
  return 1;
}

void printVec(struct Vector * vec) {
  printf("Printing Vector: \n");
  for(int i = 0; i<vec->numVals; i++) {
    printf("%f,\n", vec->vals[i]);
  }
}
