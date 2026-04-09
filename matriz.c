//matriz ->> notas do semestre//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

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

    char materias[7][24]; //declarando matriz para armazenar o nome de 7 materias com no maximo 24 caracteres//
    double notas[7][3]; //declarando matriz para armazenar 3 notas por materia (atividade, lista, prova)//
    double nota;
    double media;

    setlocale(LC_NUMERIC, "pt_BR.UTF-8"); //numeros com virgula//

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
                nota = ler_num_virgula();

                while(nota == -1){
                    printf("\nErro! Digite Novamente!");

                    printf("\nNota da Atividade: ");
                    nota = ler_num_virgula();
                }

                notas[i][j] = nota; 

            }else if(j == 1){
                printf("Nota da Lista: ");
                nota = ler_num_virgula();

                while(nota == -1){
                    printf("\nErro! Digite Novamente!");

                    printf("\nNota da Lista: ");
                    nota = ler_num_virgula();
                }

                notas[i][j] = nota; 
                
            }else{
                printf("Nota da Prova: ");
                nota = ler_num_virgula();

                while(nota == -1){
                    printf("\nErro! Digite Novamente!");

                    printf("\nNota da Prova: ");
                    nota = ler_num_virgula();
                }

                notas[i][j] = nota; 
                
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