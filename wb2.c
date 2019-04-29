#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define ALPHA_SIZE 26
struct trieNode{
    struct trieNode* children[ALPHA_SIZE];
    bool endOfWord;
};
struct trieNode* head = NULL;
struct trieNode* createNode(){
    struct trieNode* newnode = (struct trieNode*)malloc(sizeof(struct trieNode));
    newnode->endOfWord = false;
    int i;
    for(i=0; i<ALPHA_SIZE; i++){
        newnode->children[i]=NULL;
    }
    return newnode;
}

int convertToInt(char c){
    int index = (int)c - (int)'a';
    return index;
}
struct trieNode* insertString(struct trieNode* root, char str[], int len){
//    printf("\n%d ", len);
    int i;
    struct trieNode* temp = root;
    for(i=0; i<len; i++){
        int position = convertToInt(str[i]);
//        printf("%d ", position);
        if(temp->children[position]==NULL)
            temp->children[position] = createNode();
        temp = temp->children[position];
        if(i==len-1)
            temp->endOfWord = true;  
    }  
    return root;
}
void printTrie(struct trieNode* root, char s[], int index){
    if(root->endOfWord==true){
        s[index] = '\0';
        printf("%s ", s);
    }
    int i;
    for(i=0; i<ALPHA_SIZE; i++){
        if(root->children[i]!=NULL){
            s[index] = (char)(i+'a');
            printTrie(root->children[i], s, index+1);
        }
    }
}
/*void formWordBreak2(struct trieNode* root, char s[], int index, char str[], int curr, int len){
    int i;
    bool branch = false;
    if(root->endOfWord==true){
        for(i=0; i<ALPHA_SIZE; i++){
            if(root->children[i]!=NULL){
                char ch = (char)(i+'a');
                if(ch==str[curr]){
                    branch = true;
                }
            }
        }
        if(branch==true){
            int cpyIndex = index;
            s[index++]= ' ';
            for(i=0; i<ALPHA_SIZE; i++){
                if(root->children[i]!=NULL){
                    s[index] = (char)(i+'a');
                    if(curr+1<len){
                        formWordBreak2(root->children[i], s, index+1, str, curr+1, len);
                    }
                }
            }
            index = cpyIndex;
            for(i=0; i<ALPHA_SIZE; i++){
                if(root->children[i]!=NULL){
                    s[index] = (char)(i+'a');
                    if(curr+1<len){
                        formWordBreak2(root->children[i], s, index+1, str, curr+1, len);
                    }
                }
            }        
        }
        else{
            s[index]=' ';
            if(curr+1<len){
                formWordBreak2(head, s, index+1, str, curr+1, len);
            }
        }
        if(curr+1==len){
            s[index] = '\0';
            printf("%s ", s);
        }
    }
    
    for(i=0; i<ALPHA_SIZE; i++){
        if(root->children[i]!=NULL){
            s[index] = (char)(i+'a');
            if(curr+1<len){
                formWordBreak2(root->children[i], s, index+1, str, curr+1, len);
            }
        }
    }
}*/
bool endOfPath(struct trieNode* root){
    int i;
    for(i=0; i<ALPHA_SIZE; i++){
        if(root->children[i]!=NULL)
            return false;
    }
    return true;
}
void formWb(struct trieNode* root, char s[], int index, char str[], int curr, int len){
    if(curr==len)
        return;
    int i;
    if(root->endOfWord==true){
        if(curr+1<len && endOfPath(root)==true){
            s[index]=' ';
            index += 1;
            if(curr+1<len)
                formWb(root, s, index+1, str, curr, len);
        }
        else if(curr+1==len){
            s[index]='\0';
            printf("%s ", s);
        }
    }
    
    for(i=0; i<ALPHA_SIZE; i++){
        if(root->children[i]!=NULL){
            s[index] = (char)(i+'a');
            if(curr+1<len)
                formWb(root->children[i], s, index+1, str, curr+1, len);
        }
    }
}
bool presentInTrie(struct trieNode* root, char str[], int length){
    int i;
    struct trieNode* temp = root;
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
  //  printf("%s\n", word);
    if(presentInTrie(head, word, length))
        return true;
    return false;

}
bool isAlpha(char c){
    if(c>=97 && c<=122)
        return true;
    return false;
}
void printFinalStr(char str[], int start, int end){
    int i;
    printf("(");
    while(!isAlpha(str[end]))
        --end;
    for(i=start; i<=end; i++){
        printf("%c", str[i]);
    }
    printf(")\n");
}
int id=0;
void formString(char finalS[][1000], char s[], int start, int end){
    int i, index=0;
    char local[1000];
 //   printFinalStr(s, start, end);
    local[index++] = '(';
    while(!isAlpha(s[end]))
        --end;
    for(i=start; i<=end; i++){
        local[index++] = s[i];
    }
    local[index++] = ')';
    local[index] = '\0';
    strcpy(finalS[id++], local);
}
void printWhole(char s[][1000]){
    int i;
    for(i=0; i<id; i++){
        printf("%s\n", s[i]);
    }
}
void printStr(char str[], int start, int end){
    int i;
    for(i=start; i<=end; i++)
        printf("%c", str[i]);
    printf("\n");
}
bool wordPresent(char finalS[][1000], char str[], char s[], int index){
 //   printf("word %s\n", str);
    int i, j;
    int length = strlen(str);
 //   printf("length = %d\n", length);
    if(length==0)
        return true;
    for(i=0; i<length; i++){
    //    printStr(str, 0, i);
        int ind = index;
        if(isPresent(str, 0, i)){
        //    printStr(str, 0, i);
            ind = index;
            for(j=0; j<=i; j++){
                s[ind] = str[j];
                ind++;

            }
            s[ind++] = ' ';
            s[ind] = '\0';
        //    printf("%d s =  ", index);
        //    printStr(s, 0, ind);
            int newLength = length-(i+1);
            if(newLength==0){
                s[ind]='\0';
                formString(finalS, s, 0, ind);
            //    printFinalStr(s, 0, ind);
            }
            char newStr[newLength];
            
            for(j=0; j<newLength; j++){
                newStr[j] = str[i+j+1];
            }
            newStr[j] = '\0';
            if(wordPresent(finalS, newStr, s, ind)){
            //    printStr(str, 0, i);
            //    s[ind]='\0';
            //    printFinalStr(s, 0, ind);
            //    printf(" ");
            //    printf("%s ", newStr);
            //    return true;
            }
        }
    }  
    return false;
}
int main(){
    int n = 5, i, j;
//    char dictionary[][50] = { "and", "ladder", "sand", "snake", "snakes"};
    char dictionary[][50] = { "hcdar", "lrm", "lr", "m", "wk"};
    head = createNode();
    for(i=0; i<n; i++){
        head = insertString(head, dictionary[i], strlen(dictionary[i]));
    //    printf("%s ", dictionary[i]);
    }
  //  printTrie(head, s, 0);
    char str[100] = "hcdarlrm";
  //  char str[100] = "snakesandladder";
    int len = strlen(str);
 //   formWb(head, s, 0, str, 0, len);
    char s[100] = "";
    char finalS[10][1000];
    wordPresent(finalS, str, s, 0);
    printWhole(finalS);
    char sr[5] = "lr";
 //   wordPresent(sr);
}
/*
  s = "snakesandladder",
dict = ["snake", "snakes", "and", "sand", "ladder"]
*/