#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

List *init_history()
{
  List *list = malloc(sizeof(List*));
  (*list).root = NULL;
  return list;
}

int str_length(char *c)
{
  short length = 0;
  while(*(c+1)!='\0'){
    length++;
  }
  return length;
}

void add_history(List *list, char *c)
{
  puts("Entering history add");
  int id = 1;
  Item *add = malloc(sizeof(Item));
  (*add).str = copy_str(c,str_length(c));
  puts("enterd history add before if statement");
  if(list == NULL){
    (*add).id = id;
    (*list).root = add;
    puts("added to root");
  }else{ 
    Item *pointer = (*list).root;
    while((*pointer).next){
      pointer = (*pointer).next;
      id++;
    }
    (*add).id = id;
    (*pointer).next = add;
    puts("added to next");
  }
}

char *get_history(List *list, int id)
{
  Item *pointer = (*list).root;
  if(pointer == NULL){
    puts("History is empty");
    return "";
  }
  while(pointer){
    if((*pointer).id == id){
      return (*pointer).str;
    }
    pointer = (*pointer).next;
  }
  puts("Id was not found");
  return "";
}

void print_history(List *list)
{
  Item *pointer = (*list).root;
  if(pointer == NULL){
    puts("History is empty\n");
  }else{
    while(pointer){
      printf("id: %d,%s",(*pointer).id, (*pointer).str);
      pointer = (*pointer).next;
    }
    printf("\n");
  }
}

void free_history(List *list)
{
  Item *pointer;
  Item *first = (*list).root;
  while(first){
    pointer = first;
    first = (*first).next;
    free(pointer);
  }
  free(list);
}
