#include "client.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "extlib.h"

void bot_clear() {
    return;
}

void bot_prompt(__unused__ char *str) {
    return;
}

int bot_query(int __unused__ a, int __unused__ b, int opt, __unused__ char *str) {
    return opt;
}

void std_clear() {
    cls();
}

void std_prompt(char *str) {
    printf("%s", str);
}

int std_query(int a, int b, int __unused__ opt, char *str) {
    int res;
    printf("%s", str);
    while (!scanf("%d", &res));
    while (res < a || res > b) {
        fprintf(stderr, "[ERR] invalid input\n");
        fprintf(stderr, "[INF] input shall be of %d - %d\n", a, b);
        printf("%s", str);
        while (!scanf("%d", &res));
    }
    return res;
}

const client_t bot_client_base = {
    bot_clear,
    bot_prompt,
    bot_query
};

const client_t std_client_base = {
    std_clear,
    std_prompt,
    std_query
};

client_t *new_client(client_t base) {
    client_t *client = malloc(sizeof(client_t));
    *client = base;
    return client;
}

void delete_client(client_t *client) {
    free(client);
}
