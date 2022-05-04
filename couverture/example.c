#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


int str_hash(unsigned char *str)
{
  int hash = 5381;
  int c;
  
  while ((c = *str++)!='\0')
    hash = ((hash << 5) + hash) + c; 
  
  return hash;
}

/*!
 * \brief main main program
 * \param argc program argument counter
 * \param argv array of arguments
 * \return 0 if everything ok
 */
int main(int argc, char **argv){
  int indice;
  struct HashTable *hash=hashInit((void *)strcmp,(void *)str_hash);
  for(indice=0;indice<argc;++indice)
      printf("%d : %s\n",indice,argv[indice]);
  //struct HashTable *hash=hashInit((void *)strcmp);
  //printf("add toto %d \n",hashAdd(hash,"toto"));
  printf("add titi %d \n",hashAdd(hash,"titi"));
  printf("ajout titi %d \n",hashAdd(hash,"titi"));
  printf("toto => %d\n",hashSearch(hash,"toto"));
  printf("titi => %d\n",hashSearch(hash,"titi"));
  printf("tbtb => %d\n",hashSearch(hash,"tbtb"));
  hashFree(hash,NULL);
  return EXIT_SUCCESS;
}
