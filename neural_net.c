typedef struct layer {
  char * identifier;
  void * next;
  void * (* eval)(void*);

  float * vals;
  int numVals;
};

typedef struct fullyConnected {
  struct layer Layer;

  int inputSize;

  float ** weights;
};

