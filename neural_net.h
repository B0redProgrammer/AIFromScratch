#ifndef NEURAL_NET
#define NEURAL_NET

struct layer {
  char * identifier;
  void * next;
  void (* eval)(void *, float *, int);

  float * vals;
  int numVals;
};

struct fullyConnected {
  struct layer Layer;

  int inputSize;

  float ** weights;
};

struct ActivationLayer {
  struct layer Layer;
};

struct Identity {
  struct layer Layer;
};

void * addToNet(void * layer, char * identifier, void * args);
void evalNet(void * layer, float * input, int inputSize);
#endif
