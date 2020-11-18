#ifndef ONECARD_CLIENT_H
#define ONECARD_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "extlib.h"

typedef void (*clear_func_t)();
typedef void (*prompt_func_t)(char*);
typedef int (*query_func_t)(int, int, int, char*);

typedef struct _client {
    clear_func_t clear;
    prompt_func_t prompt;
    query_func_t query;
} client_t;

void bot_clear();
void bot_prompt(char *str);
int bot_query(int a, int b, int opt, char *str);

void std_clear();
void std_prompt(char *str);
int std_query(int a, int b, int opt, char *str);

extern const client_t bot_client_base;
extern const client_t std_client_base;

client_t *new_client(client_t base);
void delete_client(client_t *client);

#endif //ONECARD_CLIENT_H
