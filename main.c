#include "math.c"

int main() {
  float * vec;
  if((vec = malloc(sizeof(float)*3)) == NULL) { return EXIT_FAILURE; }

  vec[0] = 3.0;
  vec[1] = -1.0;
  vec[2] = 4.0;

  float ** matr;
  if((matr = malloc(sizeof(float *)*3)) == NULL) { return EXIT_FAILURE; }
  for(int i = 0; i<3; i++) {
    if((matr[i] = malloc(sizeof(float)*3)) == NULL) { return EXIT_FAILURE; }
  }

  matr[0][0] = 1; matr[0][1] = 0; matr[0][2] = -2;
  matr[1][0] = 0; matr[1][1] = 3; matr[1][2] = -1;
  matr[2][0] = 1; matr[2][1] = 2; matr[2][2] = 1;
  
  float * ret;
  if((ret = malloc(sizeof(float)*3)) == NULL) { return EXIT_FAILURE; }

  matrVecMult(matr, 3, 3, vec, 3, ret);
 
  for(int i = 0; i<3; i++) {
    printf("%f \n", ret[i]);
  }

  free(vec);
  free(ret);

  for(int i = 0; i<3; i++) {
    free(matr[i]);
  }
  free(matr);

  return 0;
}
