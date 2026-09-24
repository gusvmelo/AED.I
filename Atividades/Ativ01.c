#include <stdio.h>
#include <string.h>

int main(){
    unsigned char frase[120];
    int posicao, tamanho, j,posicao_esp;

    scanf("%[^\n]", frase);
    tamanho= strlen(frase);

    int c;
    while((c=getchar())!= '\n' && (c) != EOF); //Função para limpar o buffer

    int ctgem_sem_acento[26]= {0}; //Contagem dos caracteres (={0} serve para limpar os 25 espaços de memória que podem possuir resquicios de lixo)
    int ctspace= 0; //Contagem dos espaços em branco
    int ctgem_com_acento[18] = {0}; //Contagem dos caracteres especiais(com acento)

    int min_esp[18] ={135,131,133,130,136,138,140,141,147,149,150,151,160,161,162,163,228,198};
    int mai_esp[18] ={128,182,183,144,210,212,215,222,226,227,234,235,181,214,224,233,229,199};

    for(posicao=0;posicao<tamanho;posicao++) {
        if((frase[posicao]>='A') && (frase[posicao]<='Z')) {
                j= frase[posicao]-'A';
                ctgem_sem_acento[j]++;
        }
        else if((frase[posicao]>='a') && (frase[posicao]<='z')) {
            j= frase[posicao]-'a';
            ctgem_sem_acento[j]++;
        }
        else if(frase[posicao] == ' '){
            ctspace++;
        }
        else{
            for(posicao_esp=0;posicao_esp<18;posicao_esp++) {
                if((frase[posicao]== min_esp[posicao_esp]) || (frase[posicao] == mai_esp[posicao_esp])) {
                    ctgem_com_acento[posicao_esp]++;
                    break;
            }
        }
        }
    }
    printf("\n");

    for(posicao=0;posicao<26; posicao++) {
            if(ctgem_sem_acento[posicao]>0)
                printf("%c - %d\n",('A'+posicao),ctgem_sem_acento[posicao]);
    }

    for(posicao_esp=0;posicao_esp<18;posicao_esp++) {
        if(ctgem_com_acento[posicao_esp]>0)
            printf("%c - %d\n",mai_esp[posicao_esp],ctgem_com_acento[posicao_esp]);
    }

    printf("\n%d espaços em branco",ctspace);

    return 0;
}