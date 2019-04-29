#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define ALPHA_SIZE 26
struct trieNode{
    struct trieNode* children[ALPHA_SIZE];
    bool endOfWord;
};
struct trieNode* head;
int convertToInt(char c){
    int index = (int)c - (int)'a';
    return index;
}
struct trieNode* createNode(){
    struct trieNode* newnode = (struct trieNode*)malloc(sizeof(struct trieNode));
    int i;
    for(i=0; i<ALPHA_SIZE; i++){
        newnode->children[i] = NULL;
    }
    newnode->endOfWord = false;
    return newnode;
}
struct trieNode* insertString(struct trieNode* head, char str[], int len){
    struct trieNode* temp = head;
    int i;
    for(i=0; i<len; i++){
        int pos = convertToInt(str[i]);
        if(temp->children[pos]==NULL){
            temp->children[pos] = createNode();
        }
        temp = temp->children[pos];
    }
    temp->endOfWord = true;
    return head;
}
bool cont = true;
bool isPrint = false;
void printTrie(struct trieNode* root, char s[], int index, char query[], int start, int end){
    if(cont==true){
    if(root->endOfWord==true){
        bool print = true;
        s[index] = '\0';
        int i;
        for(i=start; i<=end; i++){
            if(query[i]!=s[i]){
                print = false;
                break;
            }
        }
        if(print==true){
            isPrint = true;
            printf("%s ", s);
        }
    }
    int i;
    for(i=0; i<ALPHA_SIZE; i++){
        if(root->children[i]!=NULL){
            s[index] = (char)(i+'a');
            printTrie(root->children[i], s, index+1, query, start, end);
        }
    }
    }
}

int main() {
	int t;
	scanf("%d", &t);
	while(t>0){
	    --t;
	    int n, i;
	    scanf("%d", &n);
	    char dictionary[50][50];
	    for(i=0; i<n; i++){
	        scanf("%s", dictionary[i]);
	    }
	    head = createNode();
	    for(i=0; i<n; i++){
	        head = insertString(head, dictionary[i], strlen(dictionary[i]));
	    }
	    char query[6];
	    scanf("%s", query);
	    char s[100];
	    for(i=0; i<strlen(query); i++){
	        printTrie(head, s, 0, query, 0, i);
	        if(isPrint==false)
	            printf("0");
	        printf("\n");
	        isPrint = false;
	        cont=true;
	    }
	        
	}
	return 0;
}