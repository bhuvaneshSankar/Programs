// compute the maximum sum from an array such that no two elements are adjacent
#include<stdio.h>

int computeMax(int arr[], int n, int pos, int val, int flag[]){
    if(pos>=n){             // if current position is greater than the length of the array then return 0;
        return 0;
    }
    if(flag[pos]==-1){      // if the subtree isnt visited then compute else no need
        int v1, v2;
        int local = arr[pos];
        v1 = computeMax(arr, n, pos+2, val+local, flag);        // recursive call for pos+2 index
        v2 = computeMax(arr, n, pos+3, val+local, flag);        // recursive call for pos+3 index
        v1 += local;
        v2 += local; 
        if(v1>v2){                          // set the maximum value from both pos+2 and pos+3 possibilites to current position in flag
            flag[pos] = v1;
            return v1;
        }
        else{
            flag[pos] = v2;
            return v2;
        }   
    }
    else{
        return flag[pos];
    }
}
int getMaxFromFlag(int a[], int n){             // returns maximum element from an array(flag array)
    int max=-1, i;
    for(i=0; i<n; i++){
    if(a[i]>max)
        max=a[i];
    }
    return max;
}
void main(){
    //    int arr[] = {5,3,11,20};
    //    int arr[] = {10, 20, 15, 1, 9, 12, 5};
    int i;
    //    int n = sizeof(arr)/sizeof(int);
    int n;
    scanf("%d", &n);
    int arr[n];
    int flag[n];
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        flag[i]=-1;                             //initialize flag array to -1
    }
    for(i=0; i<n; i++){
        computeMax(arr, n, i, 0, flag);          // call the function from the specified index;
    }
    printf("%d", getMaxFromFlag(flag, n));
}
 //77 96 27 92 48 87 97 56 5 54 47 32 98 71 43 23 61 86 44 27 33 93 54 99 80 95 83 59 82 28 70 12 84 93 61 69 42 74 44 17 80 43 6 1 43 25 45 84 72 71 8 63 19 34 67 66 31 74 32 33 80 44 1 50 58 79 83 28 80 27 2 59 94 48 24 58 92 12 17 27 63 61 92 4 2 72 27 7 8 64 57 19 89 74 92 99 59 61 51 51 5 60 44 47 47 10 71 19 20 30 23 26 
  

 