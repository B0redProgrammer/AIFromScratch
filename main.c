#include "neural_net.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  void * layer = NULL;
  int n = 2;
  char fullyConnected[] = "fullyConnected";
  char ReLU[] = "ReLU";

  layer = addToNet(layer, NULL, &n);
  layer = addToNet(layer, &fullyConnected[0], &n);
  layer = addToNet(layer, &ReLU[0], NULL);
  layer = addToNet(layer, &fullyConnected[0], &n);

  float * input = malloc(sizeof(float)*n);

  input[0] = 1;
  input[1] = 1;

  evalNet(layer, input, n);

  struct layer * Layer = (struct layer *) layer;
  while(Layer->next != NULL) {
    Layer = (struct layer *)Layer->next;
  }

  for(int i = 0; i<Layer->numVals; i++) {
    printf("%f, ", Layer->vals[i]);
  }
  printf("\n");

  return 1;
}
