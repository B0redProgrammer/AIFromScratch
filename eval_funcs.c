#include "math.c"

int evalFullyConnected(void * layer, float * vals, int numVals) {
  struct fullyConnected * layer = (struct fullyConnected *) layer;
   
  if(matrVecMul(layer->weights, layer->layer->numVals, layer->inputSize, vals, numVals, layer->layer->vals)) {
    return 1;
  } 
  return 0;
}
