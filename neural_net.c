typedef struct layer {
  char * identifier;
  void * next;
  void * (* eval)(void*);

  struct Vector vals;
};

typedef struct fullyConnected {
  struct layer Layer;

  int numOutVals;

  struct Matrix weights;
};

public void addLayer(void * prevLayer, void * newLayer) {
  struct layer * prevLayerComps = ((struct layer *) prevLayer);

  prevLayerComps.next = newLayer;
}
