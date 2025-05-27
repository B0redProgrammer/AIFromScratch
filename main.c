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
  if((matr = malloc(sizeof(float *)*6)) == NULL) { return EXIT_FAILURE; }
  for(int i = 0; i<6; i++) {
    if((matr[i] = malloc(sizeof(float)*6)) == NULL) { return EXIT_FAILURE; }
  }

  float ** ret;
  if((ret = malloc(sizeof(float*)*4)) == NULL) { return EXIT_FAILURE; }
  for(int i = 0; i<4; i++) {
    if((ret[i] = malloc(sizeof(float)*4)) == NULL) { return EXIT_FAILURE; }
  }

  matr[0][0] = 10; matr[0][1] = 10;matr[0][2] = 10;matr[0][3] = 0;matr[0][4] = 0;matr[0][5] = 0; 
  matr[1][0] = 10; matr[1][1] = 10;matr[1][2] = 10;matr[1][3] = 0;matr[1][4] = 0;matr[1][5] = 0; 
  matr[2][0] = 10; matr[2][1] = 10;matr[2][2] = 10;matr[2][3] = 0;matr[2][4] = 0;matr[2][5] = 0; 
  matr[3][0] = 10; matr[3][1] = 10;matr[3][2] = 10;matr[3][3] = 0;matr[3][4] = 0;matr[3][5] = 0; 
  matr[4][0] = 10; matr[4][1] = 10;matr[4][2] = 10;matr[4][3] = 0;matr[4][4] = 0;matr[4][5] = 0; 
  matr[5][0] = 10; matr[5][1] = 10;matr[5][2] = 10;matr[5][3] = 0;matr[5][4] = 0;matr[5][5] = 0; 
 
  convolution(matr, 6, 6, mat2, 3, 3, ret, 1);
  for(int i = 0; i<4; i++) {
    printf("%f, %f, %f, %f\n", ret[i][0], ret[i][1], ret[i][2], ret[i][3]);
  }

  for(int i = 0; i<4; i++) {
    free(ret[i]);
  }
  free(ret);

  for(int i = 0; i<6; i++) {
    free(matr[i]);
  }
  free(matr);
  for(int i = 0; i<3; i++) {
    free(mat2[i]);
  }
  free(mat2);

  return 0;
}
