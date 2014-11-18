#include <stdio.h>
#include <stdlib.h>

void regras(void){
    int op=0;
    system("cls");
    printf(" Regras\n\n Zuma Game:\n");
    printf("\n Atire bolas que saem de sua nave encaixando as bolas em suas respectivas cores na forma que achar melhor");
    printf("\n Para vencer, nao deixe um conjunto de bolas chegarem ate o final.\n");
    printf("\n Bom Jogo !\n");
    printf("\n(1) Voltar para o menu;\n(2) Enfrentar que nem cabra!!\n\n");

    while(op<1 || op>2){
      scanf("%d",&op);

      if(op==1){
        printf("1-ok\n");
        //menu();
      }
      else if(op==2){
                printf("2-ok\n");
        //jogo();
      }
      else{
        printf("Escolha invalida, tente de novo.\n");
      }
    }
}

int main(int argc, char *argv[])// essa parte do código são as regras
{
    regras();
  system("PAUSE");	
  return 0;
}


