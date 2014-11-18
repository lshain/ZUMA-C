#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define cor1 3
#define cor2 7
#define linhas 3
#define colunas 15

typedef struct jogador{
int posicao;
char simbolo;
char tiro;
char ptiro;
} tjogador;

typedef struct cobra{
        char valor;
        int x, y;
        struct cobra *prox, *ant;} tCobra;

void criar_campo(char campo[linhas][colunas]){
    int i, j;
    for(i=0; i<linhas; i++){
             for(j=0; j<colunas; j++){campo[i][j] = '_';}
             }
             
    for(i=0; i<linhas; i++){ //esse laço talvez já seja pra imprimir
             for(j=0; j<colunas; j++){printf("%c ", campo[i][j]);}
             printf("\n");
             }         
}

void imprime_lista_teste(tCobra *inicio){
    tCobra *aux;
    system("cls");

    for(aux=inicio;aux!=NULL;aux=aux->prox){
                                            printf("\t%c\t%p\n",aux->valor, *aux);
                                            printf("\n");
                                            }
}

tCobra* criar_lista(tCobra *cabeca){
     tCobra *aux, *pre;
     int cont;
     
     for(cont=0; cont<6; cont++){
                 aux = (tCobra*)malloc(sizeof(tCobra));
                 if(aux==NULL){
                               printf("Erro ao inicializar, o jogo sera fechado.\n");
                               system("pause");
                               exit(EXIT_FAILURE);
                               }
                 if(cont==0){
                             cabeca = aux;
                             cabeca->ant = NULL;}
                 else if(cont==1){
                                  cabeca->prox=aux;
                                  aux->ant=cabeca;
                                  pre = aux;}
                 else {
                      pre->prox = aux;
                      aux->ant = pre;
                      pre = aux;}
                 aux->valor=rand()%(cor2-cor1)+cor1;}
                 aux->prox=NULL;
                                                                   
                 //printf("%d Alocation Scucced\n", cont+1);
                 imprime_lista_teste(cabeca);
                 return cabeca;
}                


     
int main(void){ //inicializar
    tCobra *cabeca;
    char campo[linhas][colunas];
     
    criar_lista(cabeca);
    criar_campo(campo);
    printf("%p", cabeca);
    //while()         
    system("pause");
    return 0;
}
