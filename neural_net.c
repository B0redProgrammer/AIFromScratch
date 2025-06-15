#include "eval_funcs.c"

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
  struct layer Layer;
};

typedef struct Identity {
  struct layer Layer;
};

void * errorCheckedMalloc(int size) {
  void * ret;
  if((ret = (void *) malloc(size)) == NULL) {
    printf("Malloc failed\n");
    exit(1);
  }
  return ret;
}

void * addToNet(void * layer, char * identifier, void * args) {
  if(layer == NULL) {
    layer = errorCheckedMalloc(sizeof(struct Identity));
    layer->Layer.eval = &evalIdentity();
  }

  struct layer * Layer = (struct layer *) layer;
  while(Layer->next != NULL) { Layer = (struct layer *) Layer->next; }
  
  if(!strcmp(identifier, "fullyConnected")) {
    Layer->next = errorCheckedMalloc(sizeof(struct fullyConnected));
    struct fullyConnected * temp = (struct fullyConnected *) Layer->next;
    int * data = (int *) args;

    temp->Layer.numVals = data[0];
    temp->Layer.vals = (float *) errorCheckedMalloc(sizeof(float) * data[0]);
    temp->Layer.eval = &evalFullyConnected();

    temp->inputSize = Layer->numVals;
    temp->weights = (float **) errorCheckedMalloc(sizeof(float *)*temp->inputSize);

    for(int i = 0; i<temp->inputSize; i++) {
      temp->weights[i] = (float *) errorCheckedMalloc(sizeof(float) * data[0]);
    }
  }
  else if(!strcmp(identifier, "ReLU")) {
    Layer->next = errorCheckedMalloc(sizeof(struct ActivationLayer));
    struct layer * temp = (struct layer *) Layer->next;

  }
  return layer;
}

void evalNet(void * layer, float * input, int inputSize) {
  if(layer == NULL) { return; }

  struct layer * Layer = (struct layer *) layer;
  Layer->eval(layer);

  while(layer->next != NULL) {
    struct layer * nLayer = (struct layer *) layer->next;
    nLayer->eval(layer->next, layer->vals, layer->numVals);
    Layer = nLayer;
    layer = layer->next;
  }
}
