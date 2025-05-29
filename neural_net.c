typedef struct layer {
  char * identifier;
  void * next;
  void (* eval)(void *, float *, int);

  float * vals;
  int numVals;
};

typedef struct fullyConnected {
  struct layer Layer;

  int inputSize;

  float ** weights;
};

typedef struct ActivationLayer {
  struct layer layer;
};

void addToNet(void * layer, char * identifier, void * args) {
  if(!strcmp(identifier, "fullyConnected")) {
    if(layer == NULL) {

    }
  }
}
