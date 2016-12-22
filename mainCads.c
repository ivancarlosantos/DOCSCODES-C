/* ivan
 * File:   main.c
 * Author: icarlos
 *
 * Created on October 5, 2010, 1:35 PM
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _cadastro {
    char nome[50];
    char rg[10];
    int cpf;
    int ID;
} Cadastro;

FILE *arquivo;
Cadastro vet[500];

void cadastroPessoa() {

    Cadastro cads;
    char z;

    printf("\t\t\t\tcadastro de pessoa\n\n");
    if ((arquivo = fopen("/home/icarlos/arquivos_netbeans/cadastro_pessoa.txt", "a+")) == NULL) {
        printf("O arquivo não foi aberto e/ou criado.\n");
    } else {

        do {
            printf("ID:");
            scanf("%d", &(cads.ID));
            printf("nome:");
            scanf("%s", cads.nome);
            printf("RG:");
            scanf("%s", cads.rg);
            printf("CPF:");
            scanf("%d", &(cads.cpf));
            printf("\n DADOS DO CLIENTE");
            printf("\n ID: %d", cads.ID);
            printf("\n Nome: %s", cads.nome);
            printf("\n RG: %s", cads.rg);
            printf("\n CPF: %d", cads.cpf);
            printf("\ndeseja cadastrar outra pessoa?:");

            fprintf(arquivo, "%d - %s - %s - %d\n", cads.ID, cads.nome, cads.rg, cads.cpf);
            getchar();
            z = getchar();
        } while (z == 's');
    }

    fclose(arquivo);
   
}

void le_Imprime(FILE *r_arquivo) {




    fclose(arquivo);
}

int main() {

    int x;
    printf("Opção:");
    scanf("%i", &x);
    if (x == 1)
        cadastroPessoa();
    else if (x == 2)
        le_Imprime(arquivo);
    else return (EXIT_SUCCESS);

}



