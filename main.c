/* 
 * File:   main.c
 * Author: icarlos
 *
 * Created on September 8, 2010, 11:55 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gtk/gtk.h>
#include <string.h>
#include <ctype.h>

typedef struct _carro {
    char placa[8];
    char modelo[10];
} carro;

carro estacionamento[50];

FILE *output_file;

void save(carro *qestacionamento) {

    carro save;
    int i;
    char guarda[4096];

    if ((output_file = fopen("/home/icarlos/arquivos_netbeans/estacionamento.txt", "w")) == NULL)
        printf("Não pode abrir o arquivo: %s\n", "estacionamento.txt");
    else {
        for (i = 0; i < 50; i++) {
            save = qestacionamento[i];
            sprintf(guarda, " %d - %s - %s\n", i, save.modelo, save.placa);
            fputs(guarda, output_file);
        }
        fclose(output_file);
    }
}

void read(carro *zestacionamento) {

    char caminho[256];
    int desc,i;

    printf("nome do arquivo:");
    scanf("%s", caminho);

    if ((output_file = fopen(caminho, "r")) == NULL)
        printf("Não pode abrir o arquivo: %s\n", "estacionamento.txt");
    else {
    
        for (i = 0; i < 50; i++) {
            fread(&estacionamento[i], sizeof (carro), 1, output_file);
            fscanf(output_file, " %d - %s - %s\n", &desc, zestacionamento[i].modelo, zestacionamento[i].placa);
        }
        fclose(output_file);
    }

}

void menux() {

    printf("\t\t\tGerenciador de Estacionamento\n\n");
    printf("1- entrada de veículo\n");
    printf("2- saída de veículo\n");
    printf("3- localizar veículo\n");
    printf("4- listar veículos\n");
    printf("5- salvar arquivo\n");
    printf("6- ler arquivo\n");
    printf("7- sair do sistema\n");
    printf("selecione a opção:");
}

void entrada_de_veiculo(carro *festacionamento) {


    carro ent;
    int i = 0;

    while ((strcmp(festacionamento[i].placa, "vazio") != 0) && (i < 50)) {
        i++;
    }
    if (i < 50) {
        printf("digite o modelo:");
        scanf("%s", ent.modelo);
        printf("digite a placa:");
        scanf("%s", ent.placa);
        printf("aguarde um momento...\n");
        sleep(2);
        festacionamento[i] = ent;
        printf("carro modelo:%s \tplaca:%s\n", ent.modelo, ent.placa);
        printf("carro cadastrado com sucesso!\n\n");
        sleep(2);
        system("clear");
    } else {
        printf("estacionamento lotado\n");
    }
}

void saida_de_veiculo(carro *sestacionamento) {

    carro saida;
    int i = 0;
    printf("digite o modelo:");
    scanf("%s", saida.modelo);
    printf("digite a placa:");
    scanf("%s", saida.placa);
    while (((strcmp(sestacionamento[i].modelo, saida.modelo) != 0) || (strcmp(sestacionamento[i].placa, saida.placa) != 0)) && (i < 50)) {
        i++;
    }
    if (i < 50) {
        strcpy(sestacionamento[i].modelo, "vazio");
        strcpy(sestacionamento[i].placa, "vazio");
        printf("aguarde um momento...\n");
        sleep(2);
        printf("saída liberada - Obrigado pela preferência!\n");
        sleep(2);
        system("clear");
    } else {
        printf("carro não localizado\n");
    }

}

void localizar_veiculo(carro *westacionamento) {

    int z = 0;
    carro loc;
    printf("digite o modelo:");
    scanf("%s", loc.modelo);
    printf("digite a placa:");
    scanf("%s", loc.placa);
    for (z = 0; z < 50; z++) {
        if ((strcmp(loc.modelo, westacionamento[z].modelo) == 0) && (strcmp(loc.placa, westacionamento[z].placa) == 0)) {
            printf("aguarde um momento...\n");
            carro car = westacionamento[z];
            sleep(2);
            printf("%d - modelo: %s - placa: %s\n", z, car.modelo, car.placa);
            break;
        }
    }
    if (z >= 50) {
        printf("veículo não localizado\n");
    }

}

void listar(carro *restacionamento) {
    printf("\t\timprimindo estacionamento\n\n");
    int z = 0;
    for (z = 0; z < 50; z++) {
        carro car = restacionamento[z];
        printf("%d - modelo: %s -\tplaca: %s\n", z, car.modelo, car.placa);
    }
}

int main(int argc, char *argv[]) {

    carro estacionamento[50];
    int analiza, z;
    char nome[6];
    char senha[6];
    int opcao;



    for (z = 0; z < 50; z++) {
        strcpy(estacionamento[z].modelo, "vazio");
        strcpy(estacionamento[z].placa, "vazio");
    }

    printf("\t\t\t\tGerenciador de Estacionamento\n\n");

    printf("digite login:");
    scanf("%s", nome);
    if (strcmp(nome, "admin") == 0) {

    } else {

        printf("login invalido\n");
        return 0;
    }
    printf("digite senha:");
    scanf("%s", senha);
    printf("aguarde um momento...\n");
    sleep(2);

    if (strcmp(senha, "user") == 0) {
        printf("Olá %s,Seja Bem Vindo!\n", "Ivan");
        sleep(3);
        system("clear");
    } else {
        printf("senha invalida,tente novamente...\n");
        return 0;
    }

    while (analiza) {
        menux();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:

                entrada_de_veiculo(estacionamento);

                break;

            case 2:

                saida_de_veiculo(estacionamento);

                break;

            case 3:

                localizar_veiculo(estacionamento);

                break;

            case 4:

                listar(estacionamento);

                break;

            case 5:

                save(estacionamento);

                break;

            case 6:

                read(estacionamento);

                break;

            default:

                if (opcao != 7) {
                    printf("nenhuma opção selecionada\n");
                    continue;
                }
        }
        if (opcao == 7) {
            printf("finalizando o sistema...\n\n");
            sleep(3);
            system("clear");
            return 0;
        }

    }
}

