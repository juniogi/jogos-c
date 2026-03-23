#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <time.h>
#include <stdlib.h>

char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

void abertura(){
    printf("*************************\n");
    printf("*     Jogo de Forca     *\n");
    printf("*************************\n\n");
}

void chuta(){
    char chute;
    printf("\n\nQual a letra?  ");
    scanf(" %c", &chute);
    chutes[chutesdados] = chute;
    chutesdados++;
}

void desenhaforca(){

    printf("\nVoce ja deu %d chutes\n\n", chutesdados);

    for(int i=0; i<strlen(palavrasecreta); i++){

        int achou = jachutou(palavrasecreta[i]);

        if(achou){
            printf("%c ", palavrasecreta[i]);
        }
        else{
            printf("_ ");
        }

    }
    printf("\n");
}

void adicionapalavra() {
    char quer;
    printf("Voce gostaria de adicionar uma palavra? (S/N)\n");
    scanf(" %c", &quer);

    if (quer == 'S') {
        char novapalavra[20];
        printf("Qual a nova palavra?");
        scanf("%s", &novapalavra);

        FILE* f;
        f = fopen("palavras.txt", "r+");
        if (f==0){
            printf("Desculpe, banco de dados não disponivel");
            exit(1);
        }
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0 , SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
}
void escolhapalavra(){
    FILE* f;
    f = fopen("palavras.txt", "r");

    if (f==0) {
        printf("Desculpe, banco de dados não disponivel");
        exit(1);
    }

    int qtdpalavras;
    fscanf(f, "%d", &qtdpalavras);
    srand(time(0));
    int randomcio=rand() % qtdpalavras;

    for (int i = 0; i <= randomcio; i++) {
        fscanf(f, "%s", &palavrasecreta);
    }

    fclose(f);
}

int acertou() {
    for (int i = 0; i <strlen(palavrasecreta); i++) {
        if (!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }
    return 1;
}

int enforcou(){

    int erros = 0;

    for(int i=0; i<chutesdados; i++){
        int existe = 0;

        for(int j=0; j<strlen(palavrasecreta); j++){
            if(chutes[i] == palavrasecreta[j]){

                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
    }

    return erros >= 5;
}

int jachutou(char letra){
    int achou = 0;

    for(int j=0; j<chutesdados; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
    return achou;
}

int main(){

    escolhapalavra();
    abertura();

    do{
        desenhaforca();
        chuta();

    }while(!acertou() && !enforcou());

    adicionapalavra();
}