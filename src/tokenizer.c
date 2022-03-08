#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define debug 0

int space_char(char c)
{
  return ((c == '\t' || c == ' ') && c);
}

int non_space_char(char c)
{
  return (!space_char(c) && c);
}

char *word_start(char *pc)
{
  char *pcInit = pc;
  if (debug) puts("in word_start()\n");
  while (space_char(*pc) && *pc)
    pc++;
  if (debug) printf("word_start(%s) returned pointer at index %d\n", pcInit, pc - pcInit);
  return pc;
}

  /* int i; */
  /* for(i=0; *(c+i) != '\0'; i++){ */
  /*   if(non_space_char(*(c+i))){ */
  /*     return c+i; */
  /*   } */
  /* } */
  /* return c+i; */


char *word_terminator(char *c)
{
  if (debug) puts("in word_terminator()\n");
  int i;
  for(i=0; *(c+i) != '\0';i++){
    if(space_char(*(c+i))){
      break;
    }
  }
  if (debug) printf("word_terminator(%s) returning pointer at index %d\n", c, i);
  return c+i;
}

int count_words(char *c)
{
  int counter = 0;
  char *pointer = c;
  while(non_space_char(*pointer)){
    if(*pointer == '\0') break;
    pointer = word_terminator(pointer);
    pointer = word_start(pointer);
    counter++;
  }
  if (debug) printf("count_words(%s) returns %d\n", c, counter);
  return counter;
}

char *copy_str(char *inC,short length)
{
  char *copy = malloc((length+1)*sizeof(char));
  int i;
  for(i=0; i<length; i++)
  {
    copy[i] = inC[i];
  }
  copy[i] = '\0';
  return copy;
}

char word_length(char *c)
{
  int length =0;
  char *start = word_start(c);
  char *end = word_terminator(start);
  length = end - start;
  return length;
}
 
char **tokenize(char *c)
{
  int countWords = count_words(c);
  char **tokens = malloc((countWords+1) * sizeof(char*)), **tokens2;
  tokens2 = tokens;
  int i, length;
  for (i=0; i < countWords; i++) {
    c = word_start(c);
    length = word_length(c);
    *tokens2 = copy_str(c,length);
    if (debug) printf("token: %s\n", tokens[i]);
    tokens2 ++;
    c = word_terminator(c);
  }
  *tokens2 = 0;
  return tokens;
}

void print_tokens(char **tokens)
{
  int i=0;
  while(*tokens){
    printf("Token[%d]: %s\n",i,*tokens);
    tokens ++;
    i++;
  }
}

void free_tokens(char **tokens)
{
  int i=0;
  while(tokens[i]){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
