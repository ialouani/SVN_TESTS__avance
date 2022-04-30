#include<stdio.h>
#include<assert.h>
#include<hash.h>
#include<stdint.h> //for the type cast: intptr_ si on met dans un reservoir int
//pour cela plus que sa place .///

int cmp(void* a, void* b){
  return 0;
}

int hash(void* a){
  return 0;
}

void test_init(){
  struct hash_Table *t=NULL;
  t=hash_init(NULL,NULL);
  assert(t==NULL);
}

void test_init2(){
  struct hash_Table *t=NULL;
  t=hash_init(cmp,hash);
  assert(t!=NULL);
}


int main(){
  //assert(false && "mon premier test");
  test_init();
  test_init2();
  return 0;
}
