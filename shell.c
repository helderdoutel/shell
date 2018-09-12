#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define DELIMITADOR " \t\n"

size_t BUFSIZE = sizeof(char)*4096;

char ** dividir_linha(char * linha){
    int posicao = 0;
    char ** argumentos = malloc(BUFSIZE);
    char * argumento;

    if(!argumentos){
        printf("Erro de alocacao\n");
        exit(EXIT_FAILURE);
    }

    argumento = strtok(linha,DELIMITADOR);

    while(argumento != NULL){
        argumentos[posicao] = argumento;
        posicao++;

        argumento = strtok(NULL,DELIMITADOR);
    }
    argumentos[posicao] = NULL;
    return argumentos;
 }

 void funcao_cd(char * caminho){

 }

 void limpar_linha(char * linha){
     for(int x=0;x<BUFSIZE;x++){
         linha[x] = '\0';
     }
 }

int funcao_pwd(){
    char pwd[BUFSIZE];
    if (getcwd(pwd, sizeof(pwd)) != NULL) {
        printf(" %s\n", pwd);
    } else {
        perror("Erro no comando pwd");
        return 1;
    }
    return 0;
}

int main(){
    char *linha = malloc(BUFSIZE);
    char **args;
    int n;
    size_t tamanho;
    while(1){
        n = 0;
        printf("->");
        tamanho = getline(&linha,&BUFSIZE,stdin);
        args = dividir_linha(linha);
        while(args[n] != NULL){
            n++;
        }
        if(n >= 1){
            if(strcmp("cd", args[0]) == 0){
                if(n >= 2)
                    funcao_cd(args[1]);
            }else if(strcmp("pwd", args[0]) == 0){
                funcao_pwd();
            }else if(strcmp("exit",args[0]) == 0){
                break;
            }
        }
        limpar_linha(linha);
    }
    return 0;
}