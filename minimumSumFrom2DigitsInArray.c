#include <stdio.h>      //given an array form two numbers from that array such that their sum is 0

int partition(int arr[], int left, int right){
    int i=left, j=right;
    while(i<j){
        do{
            ++i;
        }while(arr[i]<=arr[left]);
        do{
            --j;
        }while(arr[j]>arr[left]);
        if(i<j){
          /*  arr[i] = arr[i]^arr[j];
            arr[j] = arr[i]^arr[j];
            arr[i] = arr[i]^arr[j];  */
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
  /*  arr[left] = arr[left]^arr[j];
    arr[j] = arr[left]^arr[j];
    arr[left] = arr[left]^arr[j]; */

    int temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;
    return j;
}

void sort(int arr[], int left, int right){
    if(left<right){
        int part = partition(arr, left, right);
        sort(arr, left, part);
        sort(arr, part+1, right);
    }
}

void printArr(int arr[], int n){
    int i;
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
long computeMinSum(int arr[], int n){       //o(nlogn)
    sort(arr, 0, n);                        //sort it in ascending order and form two nums by grping alternative nums and add them
    printArr(arr, n);
    int  i, j;
    long num1=0, num2=0;
    for(i=0; i<n; i+=2){                
        num1 = num1*10 + (int)arr[i];
      
    }
    for(j=1; j<n; j+=2){
        num2 = num2*10 + (int)arr[j];
        printf("%ld\n", num2);
    }
    printf("%ld %ld\n", num1, num2);
    return (num1+num2);
}
void printStringNum(char num[], int index){
    int i;
    for(i=0; i<index; i++)
        printf("%c", num[i]);
    printf("\n");
}
#include <stdio.h>

void addStrings(char num1[], char num2[], int index1, int index2){
    int i, j;
    int n1=0, n2=0, carry=0, sumind=0;
    int sumString[1000000];
    for(i=index1-1, j=index2-1; i>=0 || j>=0; i--, j--){
        if(i>=0 && j>=0){
            char c1 = num1[i];
            char c2 = num2[j];
            n1 = (int)(c1-'0');
            n2 = (int)(c2-'0');
            int sum = n1+n2+carry;
            carry=0;
            if(sum>=10){
                int s = sum;
                sum %= 10;
                carry = s/10; 
            }
            sumString[sumind++] = sum;
        
        }
        else if(i>=0){
            char c1 = num1[i];
            n1 = (int)(c1-'0')+carry;
            carry=0;
            sumString[sumind++] = n1;
        }
        else if(j>=0){
            char c2 = num2[j];
            n2 = (int)(c2-'0')+carry;
            carry=0;
            sumString[sumind++] = n2;
        }
    }
    if(carry!=0){
        sumString[sumind++] = carry;
    }
    int end = sumind-1;
    while(sumString[end]==0)
        --end;
    for(i=end; i>=0; i--){
        printf("%d", sumString[i]);
    }
    printf("\n");
}
long computeMinSumHash(int arr[], int n){           //0(n)
    int hash[10], i;                                //hashing
    for(i=0; i<10; i++)
        hash[i]=0;
    for(i=0; i<n; i++){
        hash[arr[i]]++;
    }
    for(i=1; i<10; i++){
        
        hash[i] = hash[i]+hash[i-1];
    }
    char num1[1000000], num2[1000000];
    char numString[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int j, start=0, end, index1=0, index2=0;
    i=0;
    for(i=0; i<10; i++){
        if(hash[i]!=0){
            int end = hash[i]-1;
            for(j=start; j<=end; j++){
                if(j%2==0){
                    num1[index1++] = numString[i];
                }
                else{
                    num2[index2++] = numString[i];
                }
            }
            start=hash[i];
            }
    }
    addStrings(num1, num2, index1, index2);
    return 1;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t>0){
	    --t;
	    int n;
	    scanf("%d", &n);
	    int i, arr[n];
	    for(i=0; i<n; i++)
	        scanf("%d", &arr[i]);
	    long num = computeMinSum(arr, n);
	//    printf("%ld\n", num);
	}
	return 0;
}

/*
1
12
7 4 0 9 4 8 8 2 4 5 5 1

1
28
1 1 5 2 7 6 1 4 2 3 2 2 1 6 8 5 7 6 1 8 9 2 7 9 5 4 3 1

1
3
3 3 4
*/