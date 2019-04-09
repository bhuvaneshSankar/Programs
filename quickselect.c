#include<stdio.h>       //algorithm to find kth max/min elem in an array in o(n) time.
                        //best and avg => o(n), worst case => o(n)

int  partition(int arr[], int left, int right){
    int i = left, j = right;
    while(i<j){
        do{
            ++i;
        }while(arr[i]<=arr[left]);          //pivot element = arr[left];
        do{
            --j;
        }while(arr[j]>arr[left]);
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;
    return j;
}
int selectKthElem(int arr[], int left, int right, int k){
    if(left<right){
        int part = partition(arr, left, right);
        if(part==k-1){
            return arr[part];
        }
        else if(part>k-1){        // k is lesser than part so search in left part
            selectKthElem(arr, left, part, k);
        }
        else if(part<k-1){        // k is higher than part so search in right part
            selectKthElem(arr, part+1, right, k);
        }
        
    }
}
int main(){
  /*  int arr[] = {9,8,7,6,5,4,13,2,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int kthSmallestElem = selectKthElem(arr, 0, len, k);
    printf("%d\n", kthSmallestElem);
  */
    int t=1;
//	scanf("%d", &t);
	while(t>0){
	    --t;
	    int n;
	    scanf("%d", &n);
	    int arr[n], i, k;
	    for(i=0; i<n; i++)
	        scanf("%d", &arr[i]);
	    scanf("%d", &k);
     //   k=2;
	    int kthSmallestElement = selectKthElem(arr, 0, n, k);
	    printf("%d\n", kthSmallestElement);
	}
}
