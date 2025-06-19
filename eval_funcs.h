#ifndef EVAL_FUNCS
#define EVAL_FUNCS

void evalFullyConnected(void * layer, float * vals, int numVals);
void evalReLU(void * layer, float * vals, int numVals);
void evalSigmoid(void * layer, float * vals, int numVals);
void evalIdentity(void * layer, float * vals, int numVals);

#endif
