#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bubbleSort(int array[], int size) {
    int i, j, temp;
    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - i - 1; j++) {
            if(array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}


int parking(){
    int numTiendas;
    scanf("%d", &numTiendas);
    char tiendas[1100];

    scanf(" %[^\n]", tiendas); 
    //scanf("%s", &tiendas);

    int tienda[numTiendas];

    printf("%s\n", tiendas);
    
    char * token = strtok(tiendas, " ");

    int j=0;
    while( token != NULL) {
        
        tienda[j]= atoi(token);
        //printf("%d\n", tienda[j]);
        token = strtok(NULL, " ");
        j++;
    }

    /*for(int i=0; i<numTiendas;i++){
        printf("token: %d \n", tienda[i]);
    }
    */
    
    bubbleSort(tienda, numTiendas);    
    
    int maxWalk;
    int bestParking= (tienda[numTiendas-1]-tienda[0])/2;

    if(bestParking>tienda[0]){
        maxWalk= 2*(abs(tienda[0]-bestParking))+2*(abs(tienda[numTiendas-1]-bestParking));
    }else{
        bestParking-=1;
        maxWalk=2*(abs(tienda[numTiendas-1]));
    }

    return maxWalk;
}

int main(){

    int testCase=1;
    

    while(testCase!=0){
        scanf("%d", &testCase);
        int ans[testCase];

        for(int i=0; i<testCase; i++){
            ans[i] = parking();
        }

        for(int i=0; i>testCase; i++){
            printf("%d\n", ans[i]);
        }
    }

    return 0;
}
