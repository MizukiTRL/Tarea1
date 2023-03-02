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

int isJumper(int n,int nums[]){
    int ans=0;
    int set[n-1];
    
    if(n==1){
        ans=1;
    }else{
        for(int i=1; i<n; i++){
            set[i-1]=i;
        }
        int jolly=0;
        for(int i=0; i<n-1; i++){
            int a=nums[i];
            int b=nums[i+1];
            int dif=abs(a-b);
            
            for (int j=0; j<n-1; j++){
                if(dif==set[j]){
                    jolly++;
                }
            }
            
        }
        if(jolly==n-1){
            ans=1;
        }
    }

    return ans;
}

int main(){
    int MAX=30001;
    int nums[MAX];
    int n=0;
    int nu=1;
    int ans[MAX];
    int count=0;

    while(nu!=0){
        scanf("%d",&n);
        for(int i=0; i<n ;i++){
            scanf("%d",&nums[i]);
        }
        int jolly= isJumper(n, nums);

        ans[count]=jolly;
        if(jolly==0){
            nu=0;
        }
        count++;
    }

    for(int i=0; i<count ;i++){
        switch (ans[i])
        {
        case 1:
            printf("Jolly\n");
            break;
        
        default:
            printf("Not jolly\n");
            break;
        }
    }

    return 0;
}