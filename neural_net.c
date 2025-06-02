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

typedef struct Identity {
  struct layer layer;
};

void addToNet(void * layer, char * identifier, void * args) {
  if(layer == NULL) {
    if((layer = (void *) malloc(sizeof(struct Identity))) == NULL) {
      exit(1);
    }
  }

  struct layer * Layer = (struct layer *) layer;
  while(Layer->next != NULL) { Layer = (struct layer *) Layer->next; }
  
  if(!strcmp(identifier, "fullyConnected")) {
     if((Layer->next = (void *) malloc(sizeof(struct fullyConnected))) == NULL)
    {
      printf("Malloc failed\n");
      exit(1);
    }
    struct fullyConnected * temp = (struct fullyConnected *) Layer->next;
    int * data = (int *) args;

    temp->Layer.numVals = data[0];
    if((temp->Layer.vals = malloc(sizeof(float)*data[0])) == NULL) {
      printf("Malloc failed\n");
      exit(1);
    }

    temp->inputSize = Layer->numVals;
    if((temp->weights = malloc(sizeof(float *)*)))

  }
}
