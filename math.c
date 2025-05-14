typedef struct Vector {
  float * vals;
  int numVals;
};

void vectorMult(struct Vector * vec1, struct Vector * vec2) {
  if(vec1->numVals != vec2->numVals) {
    return;
  }
  for(int i = 0; i<vec1->numVals; i++) {
    float sum = 0.0;
    for(int j = 0; j<vec2->numVals; j++) {
      sum += vec1[i]*vec2[j];
    }
    vec1[i] = sum;
  }
}
