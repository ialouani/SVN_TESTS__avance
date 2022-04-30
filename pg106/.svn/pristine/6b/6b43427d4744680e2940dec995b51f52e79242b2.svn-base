#include<stdio.h>
#include<assert.h>
#include<hash.h>
#include<stdint.h> //for the type cast: intptr_ si on met dans un reservoir int
//pour cela plus que sa place .///

int cmp_int(void* a, void* b){
  if(a<b) return -1;
  if(a==b) return 0;
  return 1;
}

int hash_int(void* a){
  return (intptr_t )a;
}

void test_add(){
  struct hash_Table=NULL;
  t=hash_init(cmp_int,hash_int);
  assert(hash_add(t,(void*) 1)==0);
  assert(hash_add(t,(void*)1)==1);
}


int main(){
  //assert(false && "mon premier test");
  //test_init();
  //test_init2();
  test_add();
  return 0;
}
