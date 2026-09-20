#include <stdio.h>
int numeros[200]={0};
    int indicedosnumeros=0;
    int indicepares=0;
    int indeceimpares=0;                
    int ctddosprimos=3;
    int divisoresdosprimos=1;
    int qtd=1;
    int numerospares[200]={0};
    int qtddepares=0;
    int numerosimpares[200]={0};
    int qtddeimpares=0;
    int paresmult7[50]={0};
    int qtdparesmult7=0;
    int indicepares7=0;
    int imparesprimos[50]={0};
    int qtdimparesprimos=0;
    int indiceimprimos=0;

int main() {
    int epar(int num) {
        if (num%2==0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int mult(int num,int div) {
        if (num%div==0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int metade= (numeros[indicedosnumeros])/2;
    int primo(int num) {
        while(ctddosprimos<metade) {
            if(!mult(num,ctddosprimos)) {
                ctddosprimos=ctddosprimos+2;
            }
            else {
                divisoresdosprimos++;
            }
        }
        if(divisoresdosprimos==1) {
            return 1; //Ehprimo
        }
        else {
            return 0; //N_Ehprimo
        }

    }
    indicedosnumeros=0;
    scanf("%d",&numeros[indicedosnumeros]);
    while(numeros[indicedosnumeros]!=0 && qtd<200) { //Laço para separar os pares dos impares
        if(epar(numeros[indicedosnumeros])) {
            numerospares[indicepares]=numeros[indicedosnumeros];
            qtddepares++;
            indicepares++;
        }
        else {
            numerosimpares[indeceimpares]=numeros[indicedosnumeros];
            qtddeimpares++;
            indeceimpares++;
        }
        indicedosnumeros++;
        qtd++;
        scanf("%d",&numeros[indicedosnumeros]);
        
    }
    indicepares=0;
while(indicepares<qtddepares) {
     printf("%d", numerospares[indicepares]);
     indicepares++;
}
   int limpador;
    while((limpador=getchar())!= '\n' && (limpador) != EOF);
}   