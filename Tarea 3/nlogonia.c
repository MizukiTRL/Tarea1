#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int nationality(int nm[], int xy[]){

    int res=0;

    if(nm[0]<xy[0]){
        if(nm[1]<xy[1]){
            res=1;
        }else if(nm[1]>xy[1]){
            res=2;
        }
    }else if(nm[0]>xy[0]){
        if(nm[1]<xy[1]){
            res=4;
        }else if(nm[1]>xy[1]){
            res=3;
        }
    }
    if(nm[0]==xy[0]){
        res=5;
    }
    if(nm[1]==xy[1]){
        res=5;
    }

    return res;
}

int main(){
    int k=1;
    int nm[2];
    int xy[2];

    while(k!=0){
        scanf("%d", &k);

        int res[k];
        
        for(int i=0; i<2; i++){
            scanf("%d", &nm[i]);
        }

        for(int i=0; i<k; i++){
            for(int j=0; j<2; j++){
                scanf("%d", &xy[j]);
            }

            res[i]=nationality(nm, xy);
        }

        for(int i=0; i<k; i++){
            switch (res[i]){

            case 1:
                printf("NE\n");
            break;

            case 2:
                printf("SE\n");
            break;

            case 3:
                printf("SO\n");
            break;
                
            case 4:
                printf("NO\n");
            break;

            case 5:
                printf("divisa\n");
            break;
            
            default:

            break;
            }
        }
    }

    return 0;
}