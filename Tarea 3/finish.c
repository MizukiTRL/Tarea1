#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int race(int n, int arr1[], int arr2[]){
    int ans=0;
    for(int i=0; i<n; i++){
        int gas=0;
        gas=gas+arr1[i];
        gas=gas-arr2[i];
        printf("%d\n", gas);
        if(gas<0){
            ans=1;
        }
    }

    return ans;
}

int main(){
    
    int testCases;
    scanf("%d", &testCases);
    int ans[testCases];

    for(int a=0; a<testCases; a++){
        int n;
        scanf("%d", &n);
        int stations1[n];
        int stations2[n];

        for(int i=0; i<n; i++){
            scanf("%d", &stations1[i]);
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &stations2[i]);
        }
        for(int i=0; i<n; i++){
            printf("%d ", stations2[i]);
        }
        
        ans[a]=race(n, stations1, stations2);
    }

    for(int i = 0; i < testCases; i++) {
        printf("Case %d: ", i+1);
        if(ans[i] == 1) {
            printf("Not possible\n");
        } else {
            printf("Possible from station %d\n", i+1);
        }
    }
    return 0;
}