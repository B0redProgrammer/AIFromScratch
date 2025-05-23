#include <stdio.h>
#include <stdlib.h>

int vecMult(float * vec, int numVals, float * vec2, int numVals2, float * ret) {
  if(numVals != numVals2) {
    return 0;
  }

  for(int i = 0; i<numVals; i++) {
    ret[i] = 0.0;
    for(int j = 0: j<numVals2; j++) {
      ret[i] += vec[i]*vec2[j]; 
    }
  }

  return 1;
}


