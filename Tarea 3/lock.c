#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int grados(int clave[]){
    int suma=0;

    suma+=80;
    suma+=clave[0]+(40-clave[1]);
    suma+=40;
    suma+=(40-clave[1])+clave[2];
    suma+=clave[2]+(40-clave[3]);

    suma*=9;
    return suma;
}

int main(){
    int n=1;
    int clave[4];
    int ans[1000];
    int rep=0;
    
    while(n!=0){
        for(int i=0; i<4; i++){
            scanf("%d", &clave[i]);
        }
        int contador=0;
        for(int i=0; i<4; i++){
            if(clave[i]==0){
                contador++;
            }
        }
        if(contador<4){
            ans[rep]=grados(clave);
            rep++;
        }else{
            n=0;
        }
    }

    for(int i=0; i<rep; i++){
        printf("%d\n",ans[i]);
    }

    return 0;
}