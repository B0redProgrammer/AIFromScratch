#include "math.c"
#include "neural_net.c"
#include <stdio.h>

void evalFullyConnected(void * layer, float * vals, int numVals) {
  struct fullyConnected * Layer = (struct fullyConnected *) layer;
   
  if(matrVecMult(Layer->weights, Layer->layer->numVals, Layer->inputSize, vals, numVals, Layer->layer->vals)) {
    return;
  } 
  printf("Weight-Value multiplication failed \n");
  exit(1);
}

void evalReLU(void * layer, float * vals, int numVals) {
  struct layer * Layer = (struct layer *) layer;

  if(layer->numVals != numVals) {
    printf("ReLU function evaluating wrong amount of values\n");
    exit(1);
  }

  for(int i = 0; i<numVals; i++) {
    Layer->vals[i] = (vals[i] < 0) ? 0 : vals[i];
  }
}

void evalSigmoid(void * layer, float * vals, int numVals) {
  struct layer * Layer = (struct layer *) layer;

  if(Layer->numVals != numVals) {
    printf("Sigmoid function evaluating wrong amount of values\n");
    exit(1);
  }
  int acc = 20;

  for(int i = 0; i<numVals; i++) {
    Layer->vals[i] = 1/(1+calcEx(acc, -vals[i]));
  }
}

void evalIdentity(void * layer, float * vals, int numVals) {
  struct layer * Layer = (struct layer *) layer;

  if(Layer->numVals != numVals) {
    printf("Identity function evaluating wrong amount of values\n");
    exit(1);
  }

  for(int i = 0; i<numVals; i++) {
    Layer->vals[i] = vals[i];
  }
}
