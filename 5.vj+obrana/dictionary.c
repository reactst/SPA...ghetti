#include "dictionary.h"
#include <malloc.h>
#include <string.h>
Dictionary create(){
    Dictionary dict = (Word *)malloc(sizeof(Word));
    dict->count = 0;
    dict->next = NULL;
    return dict;
}
void add(Dictionary dict, char *str){
    Dictionary novi = (Dictionary *)malloc(sizeof(Word));
    Dictionary temp = dict;
    novi->word = strdup(str);
    novi->count = 1;
    novi->next = NULL;
    while (dict){
        if (temp->next == NULL)
        {
            temp->next = novi;
            return;
        }
        else if (strcmp(temp->next->word, str)==0)
        {
            temp->next->count++;
            return;
        }
        else if (strcmp(temp->next->word, str)>0)
        {
            novi->next = temp->next;
            temp->next = novi;
            return;
        }
        else
            temp = temp->next;
    }
}
void print(Dictionary dict){
    dict = dict->next;
    while (dict) {
        printf("%s\t|\t%d\n", dict->word, dict->count);
        dict = dict->next;
    }
}
void destroy(Dictionary dict){
    Dictionary sljedeci;
    while (dict){
        sljedeci = dict->next;
        free(dict);
        dict = sljedeci;
    }
}
Dictionary filterDictionary(Dictionary indict, int (*filter)(Word *w)){
    Dictionary temp = indict;
    Dictionary novi = (Word *)malloc(sizeof(Word));
    while (temp->next != NULL){
        if (filter(temp->next) == 0){
            novi = temp->next;
            temp->next = novi->next;
            free(novi);
        }
        else{
            temp = temp->next;
        }
    }
    indict = temp;
    return indict;
}
int filter(Word *w){
    int duljina = strlen(w->word);
    if (duljina > 3 && (w->count > 4 && w->count < 11)){
        return 1;
    }
    else{
        return 0;
    }
}
void add_word(Dictionary dict, char *str){
  Dictionary n = dict->next;
  Dictionary nova = (Dictionary)malloc(sizeof(Word));
  nova->word = (char*)malloc(sizeof(char) * strlen(str) + 1); 
  strcpy(nova->word, str);
  nova->count = 1;
  nova->next = dict->next;
  dict->next = nova;
}
char* longest_word(Dictionary dict){
    dict=dict->next;
    char* temp=dict->word;
    while(dict!=NULL){
        if(strlen(dict->word)>strlen(temp)){
            temp=dict->word;
        }
    dict=dict->next;
    }
  return temp;
}
int word_sum(Dictionary dict){
    int wordsum=0;
    while(dict!=NULL){
        wordsum+=dict->count;
        dict=dict->next;
    }
    return wordsum;
}
void delete_before_element(Dictionary dict, char* str){
    Dictionary novi=(Dictionary)malloc(sizeof(Word));
    novi->word=(char*)malloc(sizeof(char)*strlen(str)+1);
    novi->count=1;
    char test[]="youngest";
    strcpy(novi->word,str);
    Dictionary n=dict->next;
    Dictionary p=dict;
    while(n!=NULL){
        if(strcmp(n->word,test)==0){
            novi->next=n;
            dict->next=novi;
        }
    n=n->next;
    dict=dict->next;
    }
}
void delete_before_index(Dictionary dict,char* str,int index){
    Dictionary novi=(Dictionary)malloc(sizeof(Word));
    novi->word=(char*)malloc(sizeof(char)*strlen(str)+1);
    novi->count=1;
    strcpy(novi->word,str);
    Dictionary n=dict->next;
    int brojac=0;
    while(n!=NULL){
        if(brojac==index){
            novi->next=n;
            dict->next=novi;
        }
    brojac++;
    n=n->next;
    dict=dict->next;
    }
}
void delete_first(Dictionary dict){
    Dictionary temp=dict->next;
    Dictionary n=dict->next->next;
    dict->next=n;
    free(temp->word);
    free(temp);
}
void delete_last(Dictionary dict){
    Dictionary n=dict->next;
do{
    n=dict;
    dict=dict->next;
    if(dict->next==NULL){
        n->next=NULL;
        free(dict->next);
        }
    }
    while(n->next!=NULL);
};
void delete_word (Dictionary dict, char* str){
    Dictionary temp=dict->next;
    while (temp!=NULL){
        dict=dict->next;
        if (temp->word==str){

        }
    }
}