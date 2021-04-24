#include <stdio.h>
#include <stdlib.h>

#define MAX 50



typedef struct{
  int chave;
  // outros campos...
} REGISTRO;

typedef struct {
  REGISTRO vet[MAX+1];
  int numElem;
} LISTA;

/* Inicialização da lista sequencial (a lista já está criada e é apontada 
pelo endereço em l) */
void inicializarLista(LISTA* l){
  l->numElem = 0;
} 


/* Exibição da lista sequencial */
void exibirLista(LISTA* l){
  int i;
  printf("Lista: \" ");
  for (i=0; i < l->numElem; i++)
    printf("%i ", l->vet[i].chave); 
  printf("\"\n");
} 

/* Retornar o tamanho da lista (numero de elementos "validos") */
int tamanho(LISTA* l) {
  return l->numElem;
  
}


/* Retornar a chave do primeiro elemento da lista sequencial (caso haja) e -1
   caso a lista esteja vazia */

int primeiroElem(LISTA* l){
  if(l->numElem > 0) return l->vet[0].chave;
  else return -1; // lista vazia
} 


/* Reinicializar a estrutura */
void reinicializarLista(LISTA* l) {
  l->numElem = 0;
} 

/*Inserção dos elementos na lista */

int inserirElemLista(LISTA* l, REGISTRO reg, int i){
  int j;
  if ((l->numElem >= MAX) || (i < 0) || (i > l->numElem)) 
     return(0);
  for (j = l->numElem; j > i; j--) l->vet[j] = l->vet[j-1];
  l->vet[i] = reg;
  l->numElem++;
  return 1;
} 



/* Busca sequencial em lista */
int buscaSequencial(LISTA* l, int ch) {
  int i = 0;
  while (i < l->numElem){
    if(ch == l->vet[i].chave) return i; // achou
    else i++;
  }
  return -1; // não achou
} 

/* Exclusão do elemento cuja chave seja igual a ch */
int excluirElemLista(LISTA* l, int ch) { 
  int chave, j;
  chave = buscaSequencial(l,ch);
  if(chave == -1) return 0; // não existe
  for(j = chave; j < l->numElem-1; j++) l->vet[j] = l->vet[j+1];
  l->numElem--;
  return 1;
} /* excluirElemLista */


int main(){
// Blocos de testes das funções desenvolvidas

  LISTA lista;
 
  inicializarLista(&lista);
  REGISTRO reg;

  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));

 
  reg.chave = 9;
  inserirElemLista(&lista,reg,0);
  exibirLista(&lista);
  reg.chave = 3;
  inserirElemLista(&lista,reg,1);
  exibirLista(&lista);


  printf("\n\n\n Buscando o elemento 3 \n\n\n");
  int resp = buscaSequencial(&lista,3);
  printf (" o resultado da busca = %i \n",resp );

  reinicializarLista(&lista);
  exibirLista(&lista);
  /*
  //exibirLista(&lista);
  reg.chave=3;
  inserirElemLista(&lista,reg,1);
  reg.chave=4;
  inserirElemLista(&lista,reg,2);
  reg.chave=1;
  inserirElemLista(&lista,reg,3);
  reg.chave=12;
  inserirElemLista(&lista,reg,2);
  exibirLista(&lista);
  excluirElemLista(&lista,12);
  exibirLista(&lista);

  printf("\n\n\n Buscando o elemento 3 \n\n\n");
  int resp = buscaSequencial(&lista,3);
  printf (" o resultado da busca = %i",resp );
  
  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
  printf("Chave 4 encontrada na chaveicao: %i do vetor A.\n",buscaSequencial(&lista,4));
  printf("Chave 4 encontrada na chaveicao: %i do vetor A.\n",buscaSentinela(&lista,4));
  if (excluirElemLista(&lista,4)) printf("Exclusao bem sucedida: 4.\n");
  if (excluirElemLista(&lista,8)) printf("Exclusao bem sucedida: 8.\n");
  if (excluirElemLista(&lista,9)) printf("Exclusao bem sucedida: 9.\n");
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
  reinicializarLista(&lista);
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
*/

  return 0;
}