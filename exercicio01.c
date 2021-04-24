#include <stdio.h>
#include <stdlib.h>

#define MAX 15


typedef struct{
  int chave;
  int altura;
} REGISTRO;

typedef struct {
  REGISTRO vet[MAX+1];
  int numElem;
} LISTA;

void startList(LISTA* list){
    list->numElem =0;
}

void listagem(LISTA* list){
    int i;

    printf("Chave: \"");
    for (i=0; i < list->numElem; i++)
    {
        printf("%i ", list->vet[i].chave);
    }
    printf("\" \n\n");



    printf("Altura: \"");
    for (i=0; i < list->numElem; i++)
    {
        printf("%i ", list->vet[i].altura);
    }
    printf("\" \n\n");
}

int main()
{
    /* code */
    LISTA regs;
    startList(&regs); 

    regs.vet[0].chave=1;
    regs.vet[0].altura =180;

     regs.vet[1].chave=3;
    regs.vet[1].altura =179;
    
    regs.numElem = 2;

    listagem(&regs);
    return 0;
}
