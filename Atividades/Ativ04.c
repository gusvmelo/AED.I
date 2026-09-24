#include <stdio.h>
#include <string.h>
int num[2]={0};
char numb1[9]={0};
char numb2[9]={0};
int indnum;
int indnumb1=7;
int indnumb2=7;
int resultnum1[8]={0,0,0,0,0,0,0,0};
int indresult1;
int resultnum2[8]={0,0,0,0,0,0,0,0};
int indresult2;
char resultadogeral[9]={0,0,0,0,0,0,0,0};


int main() {
    //Funções 
    char inttochar(int alg) {
        if (alg==0) {
            return '0'; 
        }
        else if(alg==1) {
            return '1';
        }
    }
    int restdivp2(int num,int div) {
        return num%div;
    }
    
    void transdecpbin(int n,int result[]) {
        int posicao=7;

        while(posicao>=0) {
            result[posicao]=restdivp2(n,2);
            n=n/2;
            posicao=posicao-1;
        }
    }

    //Fim das funçoes

    //Leitura dos meu numeros decimais
    indnum=0;
    printf("Digite os dois numeros:\n");
    while(indnum<2) {
        scanf("%d",&num[indnum]);
        indnum++;
    }
    //Chamar a função de tranformação para os dois numeros
    transdecpbin(num[0],resultnum1);
    transdecpbin(num[1],resultnum2);

    //Chamar a função de conversão para char para o numero 1 e armazenar no vetor
    int indresult1=0;
    int indnumb1=0;
    while(indresult1<8 && indnumb1<8) {
        numb1[indnumb1]=inttochar(resultnum1[indresult1]);
        indresult1++;
        indnumb1++;
    }

    //Chamar a função de conversão para char para o numero 2 e armazenar no vetor
    int indresult2=0;
    int indnumb2=0;
    while(indresult2<8 && indnumb2<8) {
        numb2[indnumb2]=inttochar(resultnum2[indresult2]);
        indresult2++;
        indnumb2++;
    }

    //Soma
    int indsoma=7;
    int vaium=0;
    while(indsoma>=0) {
        int bitA= numb1[indsoma]-'0';
        int bitB= numb2[indsoma]-'0';
        int somabi=bitA+bitB+vaium;

        if(somabi==0) {
            resultadogeral[indsoma]='0';
            vaium=0;
        }
        else if(somabi==1) {
            resultadogeral[indsoma]='1';
            vaium=0;
        }
        else if(somabi==2) {
            resultadogeral[indsoma]='0';
            vaium=1;
        }
        else if(somabi==3) {
            resultadogeral[indsoma]='1';
            vaium=1;
        }
        indsoma=indsoma-1;
    }

    printf("\n");
    printf("A soma dos seus dois numeros em binario e:\n");

    indsoma=0;
    while(indsoma<8) {
        printf("%c",resultadogeral[indsoma]);
        indsoma++;
    }
    
    printf("\n");
    




    return 0;
}