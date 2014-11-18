#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define cor1 3
#define cor2 7
#define linhas 3
#define colunas 15

typedef struct jogador{
char tiro;
char ptiro;
int casa;
} tJogador;

typedef struct cobra{
char valor;
int x;
struct cobra *prox, *ant;} tCobra;

void imprime_lista_teste(tCobra *inicio, char tiro, char ptiro){
    tCobra *aux;
    system("cls");

    for(aux=inicio;aux!=NULL;aux=aux->prox){
                                            printf("\t%d\t%c\t",aux->x, aux->valor);
                                            printf("\n\n");
                                            }
    printf("\n\nTiro Atual: %c\nProximo Tiro: %c\n\n\n", tiro, ptiro);
}

void imprime_first(char campo[linhas][colunas],char tiro, char ptiro){
     int i,j;
     system("cls");
     for(i=0; i<linhas; i++){
             for(j=0; j<colunas; j++){printf("%c ", campo[i][j]);}
             printf("\n");
             }
    printf("\n\nTiro Atual: %c\nProximo Tiro: %c\n\n\n", tiro, ptiro);
}

void limpar(tCobra *fTrilha){
     tCobra *iTrilha;
     for(iTrilha = fTrilha; iTrilha->valor==(iTrilha->ant)->valor; iTrilha= iTrilha->ant); //leve i trilha po inicio da sequencia que sera removida
     for(; fTrilha->valor==(iTrilha->prox)->valor; fTrilha= fTrilha->prox); //leva ftrilha pro íltimo da sequência.
     (iTrilha->ant)->prox = (fTrilha->prox)->ant; //fez o elo dos elementos sem os endereços que serão removidos
     for(iTrilha= iTrilha->prox; iTrilha!= fTrilha; iTrilha= iTrilha->prox)free(iTrilha->ant);
     free(fTrilha); 
}

int main(int argc, char *argv[]){
        
    tCobra *cabeca;
    tJogador play;
    //<Preparando o player(){
    srand(time(NULL));
    
    play.tiro = rand()%(cor2-cor1)+cor1;
    play.ptiro = rand()%(cor2-cor1)+cor1;
    //</Preparando o player>
    
    //<Inicializando a cobra>
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
                 aux->x = cont;
                 aux->valor=rand()%(cor2-cor1)+cor1;}
                 aux->prox=NULL;
                 
    //</Inicializando Cobra>
    int op=1;
    while(op==1){
                imprime_lista_teste(cabeca, play.tiro, play.ptiro);
                //random
                srand(time(NULL));
                play.casa = rand()%2*cont;
                printf("**********Alvo*********\n %d\n", play.casa);
                
                for(pre=cabeca; pre!=NULL && pre->x!= play.casa; pre=pre->prox);
                if(pre==NULL) printf("\nErrou o tiro.\n");
                else{
                     printf("\nAcertou o tiro.\n");
                     aux = (tCobra*)malloc(sizeof(tCobra));
                     if(aux==NULL){
                               printf("Erro ao inicializar, o jogo sera fechado.\n");
                               system("pause");
                               exit(EXIT_FAILURE);}
                     (pre->prox)->ant = aux;
                     aux->prox = pre->prox;
                     pre->prox = aux;
                     aux->ant = pre;
                     aux->valor = play.tiro;
                     }
                play.tiro = play.ptiro;
                play.ptiro = rand()%(cor2-cor1)+cor1;
                for(aux=cabeca->prox;aux!=NULL; aux=aux->prox){
                                                if((aux->ant)->valor == aux->valor && (aux->prox)->valor == aux->valor){
                                                                     printf("\n***Bom tiro***\n");
                                                                     ((aux->ant)->ant)->prox = (aux->prox)->prox;
                                                                     pre = aux;
                                                                     aux = (aux->ant)->ant;
                                                                     (aux->prox)->ant = aux; //até aqui foi refeito o elo da lista e isolado a trinca a saer deletada
                                                                     if(cabeca!=pre->ant)free(pre->ant);
                                                                     else {
                                                                          cabeca=(pre->prox)->prox;
                                                                          free(pre->ant);}
                                                                     if(cabeca!=pre){
                                                                                     pre= pre->prox;
                                                                                     free(pre->ant);}
                                                                     else{
                                                                          cabeca = (pre->prox)->prox;
                                                                          pre= pre->prox;
                                                                          free(pre->ant);}
                                                                     if(cabeca!=pre) free(pre);
                                                                     else{
                                                                          cabeca = pre->prox;
                                                                          free(pre);}
                                                                          }
                                                                          }
                                                                     
                                                                    
                                                                     
                /*for(cont=0, aux=cabeca;aux!=NULL; aux=aux->prox){ //laço para testar os iguais
                            if( aux->valor == (aux->prox)->valor){ 
                                cont++;
                                if(cont=2) limpar(aux->prox);
                                }
                            else cont=0;
                            }*/
                //atualizar alvos
                for(pre=cabeca, cont=0; pre!=NULL;cont++, pre=pre->prox){ pre->x=cont;}
                     
                scanf("%d",&op); //
                }
    
    system("pause");
    return 0;
}
