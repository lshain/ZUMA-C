#include<stdio.h>
#include<stdlib.h>

typedef struct cobra{
        int valor; //ver se a matriz tá como int ou char
        struct cobra *prox, *ant;} tCobra;

void criar_campo(void){
    int i, j;
    char campo[5][15];
    for(i=0; i<5; i++){
             for(j=0; j<15; j++){campo[i][j] = '_';}
             }
    for(i=0; i<5; i++){ //esse laço talvez já seja pra imprimir
             for(j=0; j<15; j++){printf("%c", campo[i][j]);}
             printf("\n");
             }         
}

void criar_lista(void){
     tCobra *cabeca, *novo;
     int cont;
     
     for(cont=0; cont<6; cont++){
                 if(cont==0){
                 cabeca = (tCobra*)malloc(sizeof(tCobra));
                 if(cabeca==NULL){
                                  printf("Erro ao inicializar, o jogo sera fechado.\n");
                                  system("pause");
                                  //exit EXIT_FAILURE;
                                  }
                                  }
                 else {
                       novo = (tCobra*)malloc(sizeof(tCobra));
                       if(novo==NULL){
                                  printf("Erro ao inicializar, o jogo sera fechado.\n");
                                  system("pause");
                                  //exit EXIT_FAILURE;
                                  }
                                  }
                 printf("%d Alocation Scucced\n", cont);
                                  }
}                 
     
int main(void){ //inicializar
    criar_campo();
    criar_lista();
             
    system("pause");
    return 0;
}
