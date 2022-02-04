#include <stdio.h>

int RoundRobin(int lista[20], int quantProcesso, int slice){
    int i;
    int c;
    int temp;
    int maior;
    

    printf("\n");
    
    for(c=0; c < quantProcesso; c++){
        if(c == 0){
            maior = lista[0];
        }
        else{
            if(lista[c] > maior){
                maior = lista[c];
            }
        }
    }
    
    while(maior != 0){
        for(c=0; c < quantProcesso; c++){
            if(lista[c] > slice){
                printf("P%d, %d; ", c+1, slice);
                lista[c] = lista[c] - slice;
            }
            else{
                if(lista[c] <= slice & lista[c] != 0){
                    printf("P%d, %d*; ", c+1, lista[c]);
                    lista[c] = 0;
                }
            }
        }
        printf("\n");
        maior = maior - slice;
        if(maior < 0){
            maior = 0;
        }
    }
}

int main(void){
    int i;
    int c;
    int slice;
    int quantProcessoAlta;
    int quantProcessoBaixa;
    int altaPrioridade[20];
    int baixaPrioridade[20];
    
    printf("Informe a quantidade de processos da lista com prioridade: ");
    scanf("%d", &quantProcessoAlta);
    
    printf("Informe a quantidade de processos da lista sem prioridade: ");
    scanf("%d", &quantProcessoBaixa);
    
    printf("\nLista com prioridade!\n");
    for(i=1; i <= quantProcessoAlta; i++){
        printf("informe o tempo de execução do processo P%d: ", i);
        scanf("%d", &altaPrioridade[i-1]);
    }
    
    printf("\nLista sem prioridade!\n");
    for(i=1; i <= quantProcessoBaixa; i++){
        printf("informe o tempo de execução do processo P%d: ", i);
        scanf("%d", &baixaPrioridade[i-1]);
    }
    
    printf("\nInforme o time slice: ");
    scanf("%d", &slice);
    
    for(i=0; i < quantProcessoAlta; i++){
        if(altaPrioridade[i] != 0){
            printf("\nAlta prioridade!!!\n");
            RoundRobin(altaPrioridade, quantProcessoAlta, slice);
        }else{
            for(c=0; c < quantProcessoBaixa; c++){
                if(baixaPrioridade[i] != 0){
                    printf("\nBaixa prioridade!!!\n");
                    RoundRobin(baixaPrioridade, quantProcessoBaixa, slice);
                }
            }
        }
    }
}