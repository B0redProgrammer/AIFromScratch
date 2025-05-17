#include "math.c"

int main() {
  struct Matrix m;
  
  m.n = 2;
  m.m = 3;
  m.vals = malloc(sizeof(float*)*m.m);
  for(int i = 0; i<m.m; i++) {
    m.vals[i] = malloc(sizeof(float)*m.n);
  }

  m.vals[0][0] = 4; m.vals[0][1] = 2;
  m.vals[1][0] = 1; m.vals[1][1] = 7;
  m.vals[2][0] = 5; m.vals[2][1] = 3;

  struct Vector v;
  v.numVals = 2;
  v.vals = malloc(sizeof(float)*v.numVals);
  v.vals[0] = 6;
  v.vals[1] = 3;

  struct Vector res; 
  if(matVecMult(&m, &v, &res)) {
    printVec(&res);
  }

  return 0;
}
