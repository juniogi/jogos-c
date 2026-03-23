#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("\n\n");
    printf(
            "           /\\                     /\\             \n"
            "          /**\\                   /**\\            \n"
            "         /****\\    /\\     /\\    /****\\         \n"
            "        /______\\  /__\\   /__\\  /______\\        \n"
            "        |  []  | | []|   |[] | |  []  |        Bem-vindo    \n"
            "        |     _| |   |   |   | |      |            ao\n"
            "      __|____|_|_|___|___|___|_|______|__      nosso jogo!\n"
            "     /___________________________________\\        \n"
            "     |  _  _  _  _  _  _  _  _  _  _  _  |         \n"
            "     | | || || || || || || || || || || | |         \n"
            "     | | || || || || || || || || || || | |         \n"
            "     |_|_||_||_||_||_||_||_||_||_||_||_|_|         \n"
        );

    int segundos = time(0);
    srand(segundos);
    int numerosecreto = rand();
    numerosecreto = numerosecreto % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;
    int numerotentativas;
    int acertou = 0;
    int nivel;

    printf("\n#########################################\n");
    printf("#  Tente adivinhar o numero de 1 a 100  #\n");
    printf("#########################################\n");
    printf("\nQual dificuldade voce quer jogar?\n");
    printf("(1)Facil  (2)Medio  (3)Dificil\n\n");

    while(1){
        printf("Escolha: ");
        scanf("%d", &nivel);

        int negativo = (nivel <=0 || nivel>3);
        if(negativo){
            printf("\nSelecione um numero valido!!\n");
            continue;
        }

        switch(nivel){
            case 1:
                numerotentativas = 15;
                break;
            case 2:

                numerotentativas = 10;
                break;
            default:
                numerotentativas = 5;
                break;
        }
        printf("Voce tera %d tentativas.", numerotentativas);
        break;
    }

    for(int i=1;i<=numerotentativas;i++){

        printf("\n\nTentativa %d!\n", tentativas);
        printf("Qual eh o seu chute?\n ");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        int negativo = chute<0;

        if(negativo){
            printf("Voce nao pode chutar numeros negativos!\n");

            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);

        if(acertou){
            break;
        }

        else if(maior){
            printf("Seu chute eh maior que o numero secreto\n");
        }
        else{
            printf("Seu chute eh menor que o numero secreto\n");
        }
        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / 2.0;

        pontos = pontos - pontosperdidos;
    }
    printf("Fim de Jogo\n");

    if(acertou){
        printf("Voce ganhou, parabens!!\n");
        printf("Fim de Jogo\n");
        printf("Voce acertou em %d tentativas\n", tentativas);
        printf("Total de pontos : %.1f\n", pontos);
    }
    else{
    printf("Voce errou, tente novamente!!");
    }
    return 0;
}