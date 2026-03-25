//vetor controle de gastos semanal//

#include<stdio.h>

void dias_da_semana(int i);

int main(){

    float total_diario[7], gasto_faculdade[7],gasto_extra[7], gasto_trabalho[7];
    float gasto_semanal = 0.0;
    float maior_gasto = 0.0;
    int op_valida = 0;
    int i, semana;

    printf("\n===========================\n");
    printf("CONTROLE DE GASTOS SEMANAIS\n");
    printf("===========================\n");

    //apresentacao da semana//

    while(op_valida==0){

        printf("\nSelecione a Semana do Mes:\n\n1 - Primeira Semana\n2 - Segunda Semana\n3 - Terceira Semana\n4 - Quarta Semana\nDigite: ");
        scanf("%d", &semana);

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

    for(i = 0; i<7; i++){
        dias_da_semana(i);

        printf("\nGastos Faculdade: R$ ");
        scanf("%f", &gasto_faculdade[i]);

        printf("Gastos Trabalho: R$ ");
        scanf("%f", &gasto_trabalho[i]);

        printf("Gastos Extras: R$ ");
        scanf("%f", &gasto_extra[i]);

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