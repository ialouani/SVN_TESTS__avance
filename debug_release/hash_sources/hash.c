#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

#ifndef HASH_SIZE
#define HASH_SIZE 13 // prime number
#endif

struct Cell {
  void *data;
  struct Cell *next,*prev;
};

struct HashTable{
  int (*cmp)(void *,void *);
  int (*hash)(void *);
  struct Cell **entry;
  int size;
};

// allocate a new double linked list cell storing data
struct Cell *hashNewCell(void *data){
  
struct Cell *c=malloc(sizeof(*c));
  c->data=data;
  c->next=c->prev=NULL;
  return c;
}

// allocate a new hash table for specified comparison and hash functions
struct HashTable *hashInit(int (*cmp)(void *,void *), int (*hash)(void *)){
  struct HashTable *hasht;
  int i;
  assert(cmp!=NULL);
  assert(hash!=NULL); 
  hasht = malloc(sizeof(*hasht));
  if (hasht==NULL) return NULL;
  hasht->cmp=cmp;
  hasht->hash=hash;
  hasht->entry=malloc(sizeof(*(hasht->entry))*HASH_SIZE);
  if (hasht->entry==NULL){
    free(hasht);
    return NULL;
  }
  hasht->size=HASH_SIZE;
  for(i=0;i<hasht->size;++i) hasht->entry[i]=NULL;
  return hasht;
}

// add a data into hash table
int hashAdd(struct HashTable *hash,void *data){
  int value;
  int c;
  struct Cell *cell=hashNewCell(data);
  assert(hash!=NULL);
  value=hash->hash(data);  
  fprintf(stderr,"DEBUG: hash value is %d \n",value);
  if (hash->entry[value%hash->size]==NULL){
    hash->entry[value%hash->size]=cell;
  } else {
    struct Cell *q=NULL,*p=hash->entry[value%hash->size];
    while((p!=NULL) && ((c=hash->cmp(data,p->data))>0)){
      q=p;
      p=p->next;    
    }
    if (c==0)
	return 1; // element is already in the table
    if (q==NULL){
      p->prev=cell; cell->next=p;
      hash->entry[value%hash->size]=cell;
    }else{
      q->next = cell; cell->prev=q;
    } 
  }
  return 0;
}
// search for a data into an hash table  
int hashSearch(struct HashTable *hash,void *data){
  int r=1,value;
  assert(hash!=NULL);
  value=hash->hash(data);  
  struct Cell *p=hash->entry[value%hash->size];
  while((p!=NULL) && (r=hash->cmp(data,p->data)<0))
    p=p->next;
  if (r==0) return 0;
  if (p==NULL) return 1;
  return 1;
}
// free all elements of the hash table using given release function
void hashFree(struct HashTable *hash, void (*release)(void *)){
  int i;
  assert(hash!=NULL);
  for(i=0;i<hash->size;++i){
    struct Cell *p=hash->entry[i];
    if (p==NULL) continue;
    while(p->next!=NULL){
      p=p->next;
      if (release!=NULL)
	release(p->prev->data);
      free(p->prev);
    }
  }
  free(hash->entry);
  free(hash);    
}



