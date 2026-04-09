//vetor ->> controle de gastos semanal//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

void dias_da_semana(int i);

double ler_num_virgula(){ //transformando letras para numeros//

    char numeros[6]; 
    double resultado;
    
    scanf(" %[^\n]", numeros);

    for(int i=0; i<strlen(numeros); i++){
        int atual = numeros[i]+0; //atual recebe numero escrito e reescreve como a representacao da tabela ascii//

        if(atual != 46 && atual != 44){ //verificacao de virgula = 44 e ponto = 46//
            if(atual > 57 || atual < 48){ //verificando se o valor digitado esta dentro do intervalo de numeros esperado (0-9)==(48-57)//
                return -1.0;
            }
        }else if(atual == 44){
            numeros[i] = '.'; //transforma virgula em ponto//
        }
    }

    resultado = atof(numeros); //string -> double//
    return resultado;

}

int main(){

    double total_diario[7], gasto_faculdade[7],gasto_extra[7], gasto_trabalho[7];
    double gasto_semanal = 0.0, op_valida = 0.0;
    double semana;

    setlocale(LC_NUMERIC, "pt_BR.UTF-8"); 

    printf("\n===========================\n");
    printf("CONTROLE DE GASTOS SEMANAIS\n");
    printf("===========================\n");

    //apresentacao da semana//
    while(op_valida==0){

        printf("\nSelecione a Semana do Mes:\n\n1 - Primeira Semana\n2 - Segunda Semana\n3 - Terceira Semana\n4 - Quarta Semana\nDigite: ");

        semana = ler_num_virgula();

        while(semana == -1){
            printf("\nErro! Digite Novamente!");

            printf("\nSelecione a Semana do Mes:\n\n1 - Primeira Semana\n2 - Segunda Semana\n3 - Terceira Semana\n4 - Quarta Semana\nDigite: ");
                semana = ler_num_virgula();
        }

        if(semana == 1){
        printf("\nSEMANA 01:\n");
        op_valida = 1;
        }else if(semana == 2){
        printf("\nSEMANA 02:\n");
        op_valida = 1;
        }else if(semana == 3){
        printf("\nSEMANA 03:\n");
        op_valida = 1;
        }else if(semana == 4){
        printf("\nSEMANA 04:\n");
        op_valida = 1;
        }else{
        printf("\nINVALIDO!\n");
        }
    }

    //gastos diarios//
    for(int i = 0; i<7; i++){
        dias_da_semana(i);

        printf("\nGastos Faculdade: R$ ");

        gasto_faculdade[i] = ler_num_virgula();

        while(gasto_faculdade[i] == -1){
            printf("\nErro! Digite Novamente!");

            printf("\nGastos Faculdade: R$ ");
                gasto_faculdade[i] = ler_num_virgula();
        }

        printf("Gastos Trabalho: R$ ");

        gasto_trabalho[i] = ler_num_virgula();

        while(gasto_trabalho[i] == -1){
            printf("\nErro! Digite Novamente!");

            printf("\nGastos Trabalho: R$ ");
                gasto_trabalho[i] = ler_num_virgula();
        }

        printf("Gastos Extras: R$ ");

        gasto_extra[i] = ler_num_virgula();

        while(gasto_extra[i] == -1){
            printf("\nErro! Digite Novamente!");

            printf("\nGastos Extra: R$ ");
                gasto_extra[i] = ler_num_virgula();
        }

        total_diario[i] = gasto_extra[i] + gasto_trabalho[i] + gasto_faculdade[i];

        printf("\nGasto Diario Total: R$ %.2f\n", total_diario[i]);

        gasto_semanal = gasto_semanal + total_diario[i];

        }


    printf("\n-> Gasto Semanal Total: R$ %.2f\n\n", gasto_semanal);

}

//apresentacao do dia//
void dias_da_semana(int i){

    if(i==0){
        printf("\n-----Segunda-Feira-----\n");
    }else if(i==1){
        printf("\n-----Terca-Feira-----\n");
    }else if(i==2){
        printf("\n-----Quarta-Feira-----\n");
    }else if(i==3){
        printf("\n-----Quinta-Feira-----\n");
    }else if(i==4){
        printf("\n-----Sexta-Feira-----\n");
    }else if(i==5){
        printf("\n-----Sabado-----\n");
    }else{
        printf("\n-----Domingo-----\n");
    }

}

