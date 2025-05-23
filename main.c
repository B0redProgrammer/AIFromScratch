#include "math.c"

int main() {
  float * vec1 = malloc(sizeof(float)*3);

  vec1[0] = 1.0;
  vec1[1] = 2.0;
  vec1[2] = 3.0;

  float * vec2 = malloc(sizeof(float)*3);

  vec2[0] = 2.0;
  vec2[1] = 1.0;
  vec2[2] = 3.0;

  float res = vecMult(vec1, 3, vec2, 3);

  printf("%f", res);
 
  free(vec1);
  free(vec2);

  return 0;
}
