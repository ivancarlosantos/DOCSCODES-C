/*
   Ivan Santos Menor
*/


#include<stdio.h>
#include<stdlib.h>

#define zero 0;

int adicao(int x,int y){

	return (x+y);
}

int multiplicacao(int x,int y){

	return (x*y);
}

int subtracao(int x,int y){

	return (x-y);
}

int divisao(int x,int y){

	return (x/y);
}

void menu(){
  printf("\tEscolha uma opcao para o Calculo\n");
  printf("1 - Adicao:\n");
  printf("2 - subtracao:\n");
  printf("3 - multiplicacao:\n");
  printf("4 - divisao:\n");  
}

int main(){

  int a = 0;
  int b = 0;
  int analiza; 
  int opc;
  	
  printf("\t\tCalculo Aritmetico\n\n");

  menu();
  
  printf("Digite um valor para A:");
  scanf("%i",&a);

  printf("Digite um valor para B:"); 	  
  scanf("%i",&b);

  printf("Escolha a opcao aritmetica:"); 
  scanf("%i",&opc);
	
 while(analiza){

  switch(opc){
   case 1:
   
	adicao(a,b);
	printf("A soma de %d + %d = %d",a,b,adicao(a,b)); 
   break;

   case 2:

	subtracao(a,b);
	printf("A diferenca de %d - %d = %d",a,b,subtracao(a,b));
   break; 	
    
   case 3:

	multiplicacao(a,b);
	printf("A multiplicacao de %d * %d = %d",a,b,multiplicacao(a,b));
   break;

   case 4:

	divisao(a,b);
	printf("A divisao de %d/%d = %d",a,b,divisao(a,b));
   break;	

   default:
   
   if(opc!=5){
    printf("Nenhuma opcao selecionada\n");
    continue;
   } 
  }

  if (opcao == 5) {
    printf("finalizando o sistema...\n\n");
            
  	return zero;
    }
  }
}