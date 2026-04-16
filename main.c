#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float trian[][2]={
     {0.0},
     {1,3},
     {2,6},
     {3,9},
     {4,12},
};
#define train_count ( sizeof(trian)/sizeof(trian[0]))

float cost(float w){
     float sum =0.0;
     for(size_t i =0 ; i< train_count ; ++i ){
          float x = trian[i][0];
          float y = w*x;
          float d = trian[i][1]-y;
          sum += d*d;
     }
     return sum / train_count ;
}

float rand_float(){
     return (float)rand()/(float)RAND_MAX;
}


int main(){
     srand(time(0));
     float w = rand_float()*10.0f;
     float esp = 1e-3;
     float rate = 1e-3;
     for (size_t i =0;i< 500 ; ++i)
     {
          float de = (cost(w+esp)-cost(w))/esp;
          w -= rate*de ;
          
     }
     printf("c=%f,w=%f\n", cost(w), w );
     
     return 0;
}