/* 
 * File:   main.c
 * Author: icarlos
 *
 * Created on October 8, 2010, 1:59 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _contato {
    int codigo;
    char nome[30];
    char email[100];
} contato;

int main() {

    FILE *agenda;
    contato ivan;
    char temp[4096];

    ivan.codigo = 1;
    printf("digite o seu nome:");
    gets(ivan.nome);
    printf("digite o seu email:");
    gets(ivan.email);

    agenda = fopen("/home/icarlos/arquivos_netbeans/menorzaum.txt", "a+");

    if (!agenda) {
        printf("Não foi possivel abrir e/ou criar o arquivo\n");
        EXIT_SUCCESS;
    }
    sprintf(temp, "%d - %s - %s\r\n", ivan.codigo, ivan.nome, ivan.email);
    fputs(temp, agenda);

    while (!feof(agenda)) {

        fgets(temp, sizeof (temp), agenda);

        if (temp != NULL)

            printf(" %d - %s - %s \n", ivan.codigo, ivan.nome, ivan.email);
    }

    fclose(agenda);

    return 0;
}
