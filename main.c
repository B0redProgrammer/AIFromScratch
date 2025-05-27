#include "math.c"

int main() {
  float ** mat2;
  if((mat2 = malloc(sizeof(float)*3)) == NULL) { return EXIT_FAILURE; }
  for(int i = 0; i<3; i++) {
    if((mat2[i] = malloc(sizeof(float)*3)) == NULL) { return EXIT_FAILURE; }
  }
  
  mat2[0][0] = 1; mat2[0][1] = 0; mat2[0][2] = -1;
  mat2[1][0] = 1; mat2[1][1] = 0; mat2[1][2] = -1;
  mat2[2][0] = 1; mat2[2][1] = 0; mat2[2][2] = -1;

  float ** matr;
  if((matr = malloc(sizeof(float *)*3)) == NULL) { return EXIT_FAILURE; }
  for(int i = 0; i<3; i++) {
    if((matr[i] = malloc(sizeof(float)*3)) == NULL) { return EXIT_FAILURE; }
  }

  matr[0][0] = 3; matr[0][1] = 0; matr[0][2] = 1;
  matr[1][0] = 1; matr[1][1] = 5; matr[1][2] = 8;
  matr[2][0] = 2; matr[2][1] = 7; matr[2][2] = 2;
  
  float * ret;
  if((ret = malloc(sizeof(float)*3)) == NULL) { return EXIT_FAILURE; }

  printf("%f", ssconv(matr, mat2, 3, 3));
 
  /*for(int i = 0; i<3; i++) {
    printf("%f, %f, %f \n", ret[i][0], ret[i][1], ret[i][2]);
  }*/

  free(ret);

  for(int i = 0; i<3; i++) {
    free(matr[i]);
  }
  free(matr);
  for(int i = 0; i<3; i++) {
    free(mat2[i]);
  }
  free(mat2);

  return 0;
}
