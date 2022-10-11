#include <stdio.h>


void print_space(int num, int type){ //printa o tipo selecionado a qtd "num" de vezes
    for(int inside = 0; inside<num;inside++){
        if (type == 0)printf(" ");
        if (type == 1)printf("*");
    }
}


void losango_structure(int size, int inside){ //Corpo do losangulo sem as pontas -- size = largura do losango, inside -- variavel para o interior
    int temp_size = size, reverse = 1; // reverse -- quando chega na metade do desenho faz o processo reverso
        while(1){
            if (inside+2 >= size)reverse = 0;
            printf("\n");
            print_space((temp_size/2), 0); //Esquerda do Losango
            printf("*"); //Borda Esquerda do Losango
            print_space(inside, 1); //Interior do Losango
            printf("*"); //Borda Direita do Losango
            if (reverse == 1){ 
                temp_size -= 2;
                inside += 2;
            }
            if (reverse == 0){
                temp_size += 2;
                inside -= 2; 
            }
            if (inside<0){
                printf("\n");
                break;
            }
        }
}


void print_losango(int size){
    if (size == 1){
        printf("*");
        return;
    }
    int inside;
    if (size%2 == 1){ //Para Impar
        inside = 1; 
        print_space(size/2+1,0);
        printf("*");
        losango_structure(size, inside);
        print_space(size/2+1,0);
        printf("*");
    }
    else{ //Para Par
        inside = 0;
        losango_structure(size-1, inside);
    }
}


int tamanho(){
    int size;
    do{
        printf("Digite o Tamanho do losango (maior que zero): ");
        scanf("%d", &size);
    }
    while (size<=0);
    return size;
}


int main(){
    int size = tamanho();
    print_losango(size);
    return 0;
}