#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{

  char in[100];
  List *history = init_history();
  while (1) {
    puts("Enter some words:");
    printf(">>");
    fgets(in,sizeof(in),stdin);
    printf("input: %sWord count: %d\n",in, count_words(in));

    char** tokens;
    tokens = tokenize(in);
    print_tokens(tokens);
    free_tokens(tokens);
    //add_history(history, in);
    print_history(history);

    free_tokens(tokens);
    //free_history(history);
  }
}
