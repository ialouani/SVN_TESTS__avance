#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include"../hash_sources/hash.h"
#include<string.h>

int cmp_int(void *a, void *b){
    int x=(int )a;
    int y=(int )b;
    if (x<y) return -1;
    if (x==y) return 0;
    return 1;
}

int hash_int(void *a){
    return (int) a;
}

void test_hash_init(){
//    assert(false && "premier test");
    struct HashTable *hash=NULL;
    hash=hashInit(cmp_int,hash_int);
    assert(hash!=NULL);
    hashFree(hash,NULL);
}
void test_hash_add(){
    int i;
    struct HashTable *hash=NULL;
    //assert(false && "premier test");
    hash=hashInit(cmp_int,hash_int);
    for(i=0;i<100;++i){
        assert(hashAdd(hash,(void *)i)==0);
    }
    for(i=0;i<100;++i){
        assert(hashAdd(hash,(void *)i)==1);
    }
    hashFree(hash,NULL);

}
void test_hash_search(){
    int i;
    struct HashTable *hash=NULL;
    //assert(false && "hash search");
    hash=hashInit(cmp_int,hash_int);
    assert(hashSearch(hash,(void *)0)==1);
    for(i=0;i<100;++i)
        hashAdd(hash,(void *)i);
    for(i=0;i<100;++i)
        assert(hashSearch(hash,(void *)i)==0);
    for(i=100;i<200;++i)
        assert(hashSearch(hash,(void *)i)==1);
    hashFree(hash,NULL);
}


static int release_int_cpt=0;
void release_int(void *p){
    assert((int )p==11);
    release_int_cpt+=1;
}

void test_hash_free(){
    struct HashTable *hash=NULL;
    //assert(false && "hash search");
    hash=hashInit(cmp_int,hash_int);
    hashAdd(hash,(void *)11);
    hashFree(hash,release_int);
    assert(release_int_cpt==1);
}

int main(int argc, char **argv){
    char all=0;
    if (argv[1]==NULL)
        all=1;
    if (all || (strcmp(argv[1],"init")==0))
        test_hash_init();
    if (all || (strcmp(argv[1],"add")==0))
        test_hash_add();
    if (all || (strcmp(argv[1],"search")==0))
        test_hash_search();
    if (all || (strcmp(argv[1],"free")==0))
        test_hash_free();
    return 0;
}
