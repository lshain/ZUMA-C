#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define cor1 223
#define cor2 228

typedef struct cobra{
        int valor; //ver se a matriz tá como int ou char
        struct cobra *prox, *ant;} tCobra;

void criar_campo(void){
    int i, j;
    char campo[5][15], *jogador;
    for(i=0; i<5; i++){
             for(j=0; j<15; j++){campo[i][j] = '_';}
             }
    jogador = &campo[4][7];
    *jogador = '@';
    for(i=0; i<5; i++){ //esse laço talvez já seja pra imprimir
             for(j=0; j<15; j++){printf("%c ", campo[i][j]);}
             printf("\n\n");
             }         
}

/*void imprime_lista_teste(tCobra *inicio){
    tCobra *aux;
    system("cls");

    for(aux=inicio;aux!=NULL;aux=aux->prox){
                                            printf("\t%c\n",aux->valor);
                                            printf("\n");
                                            }
}*/

void criar_lista(void){
     tCobra *cabeca, *aux, *pre;
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
                 //imprime_lista_teste(cabeca);
}

void jogada(char controle, char campo[5][15]){
     char *ld = &campo[4][14], *le = &campo[4][0];
	 if(controle == 'a'|| controle == 'd' || controle == 'w'){
		if(controle == 'd' && p!=ld){
			p++;
		}
		else if(controle == 'a' && p!=le){
			p--;
		}
		else if(controle == 'w'){
			//tiro();
		}
	}
}

void entrada_player(char campo[5][15], char *p){
     int i, j;
     char controle;
     while(controle != '27'){
		while(!kbhit()){
			system("cls");
			for(i=0; i<5; i++){ //esse laço talvez já seja pra imprimir
             for(j=0; j<15; j++){printf("%c ", campo[i][j]);}
             printf("\n\n");
             }
			jogada(controle, p, campo);
			delay(20);
		}
		controle = getch();
	}
     }
     
int main(void){ //inicializar
    criar_campo();
    criar_lista();
    entrada_player();//passar parametros
             
    system("pause");
    return 0;
}
