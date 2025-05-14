typedef struct layer {
  char * identifier;
  void * next;
  void * (* eval)(void*);

  float * vals;
  int numInVals;
};

typedef struct fullyConnected {
  struct layer Layer;

  int numOutVals;

  float * weights;
  int numWeights;
};

public void addLayer(void * prevLayer, void * newLayer) {
  struct layer * prevLayerComps = ((struct layer *) prevLayer);

  prevLayerComps.next = newLayer;
}
