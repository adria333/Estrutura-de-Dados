#include<stdio.h>
#include<string.h>

int main(){

    char materias[7][24]; //declarando matriz para armazenar o nome de 7 materias com no maximo 24 caracteres//
    float notas[7][3]; //declarando matriz para armazenar 3 notas por materia (atividade, lista, prova)//
    float media;

    printf("\n\n=== MATERIAS DO SEMESTRE ===\n");

    for(int i = 0; i<7; i++){ //lendo o nome das materias = linhas//
        printf("\nMateria [%d]: ", i+1); 
        scanf(" %[^\n]", materias[i]); //lendo nome da materia ate o \n//
    }

    printf("\n=== ADICIONE AS NOTAS ===\n");
    for(int i = 0; i < 7; i++){
        printf("%s: \n", materias[i]); //descrevendo o nome das materias para a adicao das notas//

        for(int j = 0; j<3; j++){ //lendo as notas//
            if(j == 0){
                printf("\nNota da Atividade: ");
                scanf("%f", &notas[i][j]);
            }else if(j == 1){
                printf("Nota da Lista: ");
                scanf("%f", &notas[i][j]);
            }else{
                printf("Nota da Prova: ");
                scanf("%f", &notas[i][j]);
            }

        }

        printf("\n");

    }

    printf("\n=== MEDIA DAS NOTAS ===\n");
    for(int i = 0; i<7; i++){ //percorrendo materias//
        media = 0;
        
        for(int j=0; j<3; j++){ //somando notas//
            media = media + notas[i][j];
        }

        media = media/3;

        printf("\n%s: %.2f\n", materias[i], media);

        if(media >= 6.00){ //aluno aprovado ou reprovado//
            printf("-> Aprovada!\n");
        }else{
            printf("-> Reprovada!\n");
        }
    }
   

}