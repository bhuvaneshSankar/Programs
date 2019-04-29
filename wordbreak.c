#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define ALPHA_SIZE 26


struct TrieNode{
    struct TrieNode* children[ALPHA_SIZE];
    bool endOfWord;
};
struct TrieNode * root = NULL;
struct TrieNode* createNode(){
    struct TrieNode* newnode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    newnode->endOfWord = false;
    int i;
    for(i=0; i<ALPHA_SIZE; i++)
        newnode->children[i] = NULL;
    return newnode;
}

int convertToInt(char c){
    int index = (int)c - (int)'a';
    return index;
}

struct TrieNode* insert(struct TrieNode* root, char str[], int length){
    int i;
    struct TrieNode* temp = root;
    for(i=0; i<length; i++){
        int index = convertToInt(str[i]);
        if(temp->children[index]==NULL)
            temp->children[index] = createNode();
        temp = temp->children[index];
    }
    temp->endOfWord = true;
    return root;
}

bool isLeafNode(struct TrieNode* root) 
{ 
  //  return root->endOfString != false; 
    if(root->endOfWord==true)
        return true;
    return false;
} 
void printTrie(struct TrieNode* head, char str[], int level){
    if(isLeafNode(head)){
        str[level]='\0';
        printf("%s\n",str);
        
    }
    int i;
    for(i=0; i<ALPHA_SIZE; i++){
        if(head->children[i]!=NULL){
            str[level] = i+'a';
            printTrie(head->children[i], str, level+1);
        }
    }
}
bool presentInTrie(struct TrieNode* root, char str[], int length){
    int i;
    struct TrieNode* temp = root;
    for(i=0; i<length; i++){
        int index = convertToInt(str[i]);
        if(temp->children[index]==NULL)
            return false;
        temp = temp->children[index];
    }
    if(temp->endOfWord == true)
        return true;
    else
        return false;
}


bool isPresent(char str[], int start, int end){
    int length = end-start+1;
    char word[length];
    
    int i;
    for(i=0; i<length; i++)
        word[i]=str[start+i];
    word[i] = '\0';
    printf("%s\n", word);
    if(presentInTrie(root, word, length))
        return true;
    return false;

}
bool wordPresent(char str[]){
    printf("word %s\n", str);
    int i;
    int length = strlen(str);
    printf("length = %d\n", length);
    if(length==0)
        return true;
    for(i=0; i<length; i++){
        
        if(isPresent(str, 0, i)){
            int newLength = length-(i+1);
            char newStr[newLength];
            int j;
            for(j=0; j<newLength; j++){
                newStr[j] = str[i+j+1];
            }
            newStr[j] = '\0';
            if(wordPresent(newStr))
                return true;
        }
    }  
    return false;
}
/*char* substr(char str[],int start, int len){
    int index=0, i;
    char* sub = malloc(len);
    for(i=start; i<start+len; i++){
        sub[index++] = str[i];
    }
    sub[index++] = '\0';
    printf("%s ", sub);
    return sub;
}*/
int main(){
    char dictionary[][1000] = {"mobile","samsung","sam","sung", 
                            "man","mango","icecream","and", 
                             "go","i","like","ice","cream"}; 
  //  char dictionary[][1000] = {"hello", "world"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);

    printf("\n");
    int i;
    root = createNode();
    for(i=0; i<size; i++){
        root = insert(root, dictionary[i], strlen(dictionary[i]));
       // printf("%d ", i);
    } 
    char str[] = "ilikesamsungs";
    int length = strlen(str);
    if(length==0){
        printf("false");
        return;
    }
    if(wordPresent(str))
        printf("true");
    else
        printf("false");
 /*   int level=0;
    char word[100];
    printTrie(root, word, level); */
}