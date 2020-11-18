#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "game.h"

const char *help = 
    "  -h|--help                print this help message\n"
    "  --log filename           write the logs in filename (default: onecard.log)\n"
    "  -n n|--player-number=n   n players, n must be larger than 2 (default: 4)\n"
    "  -c c|--initial-cards=c   deal c cards per player, c must be at least 2 (default: 5)\n"
    "  -d d|--decks=d           use d decks 52 cards each, d must be at least 2 (default: 2)\n"
    "  -r r|--rounds=r          play r rounds, r must be at least 1 (default: 1)\n"
    "  -a|--auto                run in demo mode\n";

typedef struct _args {
    int h;
    int n;
    int c;
    int d;
    int r;
    int a;
    char* fnamelog;
    int err;
} args_t;

int tag(char *arg) {
    return arg[0] == '-' ? arg[1] == '-' ? 2 : 1 : 0;
}

args_t parse_args(int argc, char *argv[]) {
    args_t args = {0, 4, 5, 2, 1, 0, malloc(256), -1};
    sprintf(args.fnamelog, "onecard.log");

    for (int i = 0; i < argc; ++i) {
        if (tag(argv[i]) == 1) {
            switch (argv[i][1]) {
                case 'h':
                    args.h = 1;
                    break;
                case 'a':
                    args.a = 1;
                    break;
                case 'n':
                    sscanf(argv[i + 1], "%d", &args.n);
                    if (args.n < 2) {
                        fprintf(stderr, "[ERR] n must be at least 2\n");
                        free(args.fnamelog);
                        exit(-1);
                    }
                    break;
                case 'c':
                    sscanf(argv[i + 1], "%d", &args.c);
                    if (args.c < 2) {
                        fprintf(stderr, "[ERR] c must be at least 2\n");
                        free(args.fnamelog);
                        exit(-1);
                    }
                    break;
                case 'd':
                    sscanf(argv[i + 1], "%d", &args.d);
                    if (args.d < 2) {
                        fprintf(stderr, "[ERR] d must be at least 2\n");
                        free(args.fnamelog);
                        exit(-1);
                    }
                    break;
                case 'r':
                    sscanf(argv[i + 1], "%d", &args.r);
                    if (args.r < 1) {
                        fprintf(stderr, "[ERR] r must be at least 1\n");
                        free(args.fnamelog);
                        exit(-1);
                    }
                    break;
                default:
                    args.err = i;
                    return args;
            }
        }

        if (tag(argv[i]) == 2) {
            int flag = 1;
            char argn[256];
            memset(argn, 0, 256);
            size_t spn = strcspn(argv[i], "=");
            memcpy(argn, &argv[i][2], spn - 2);
            // fprintf(stderr, "[INF] received long arg '%s'\n", argn);

            if (strcmp(argn, "help") == 0) {
                args.h = 1;
                flag = 0;
            }

            if (strcmp(argn, "auto") == 0) {
                args.a = 1;
                flag = 0;
            }

            if (strcmp(argn, "player-number") == 0) {
                argv[i][spn] = ' ';
                sscanf(argv[i], "%s %d", argn, &args.n);
                flag = 0;
                if (args.n < 2) {
                    fprintf(stderr, "[ERR] n must be at least 2\n");
                    free(args.fnamelog);
                    exit(-1);
                }
            }

            if (strcmp(argn, "initial-cards") == 0) {
                argv[i][spn] = ' ';
                sscanf(argv[i], "%s %d", argn, &args.c);
                flag = 0;
                if (args.c < 2) {
                    fprintf(stderr, "[ERR] c must be at least 2\n");
                    free(args.fnamelog);
                    exit(-1);
                }
            }

            if (strcmp(argn, "decks") == 0) {
                argv[i][spn] = ' ';
                sscanf(argv[i], "%s %d", argn, &args.d);
                flag = 0;
                if (args.d < 2) {
                    fprintf(stderr, "[ERR] d must be at least 2\n");
                    free(args.fnamelog);
                    exit(-1);
                }
            }

            if (strcmp(argn, "rounds") == 0) {
                argv[i][spn] = ' ';
                sscanf(argv[i], "%s %d", argn, &args.r);
                flag = 0;
                if (args.r < 1) {
                    fprintf(stderr, "[ERR] r must be at least 1\n");
                    free(args.fnamelog);
                    exit(-1);
                }
            }

            if (strcmp(argn, "log") == 0) {
                sscanf(argv[i + 1], "%s", args.fnamelog);
                flag = 0;
            }

            if (flag) {
                args.err = i;
                return args;
            }
        }
    }

    return args;
}

int main(int argc, char *argv[]) {
    args_t args = parse_args(argc, argv);
    if (args.err >= 0) {
        fprintf(stderr, "[ERR] unrecognized command line option '%s'\n", argv[args.err]);
        free(args.fnamelog);
        return -1;
    }

    if (args.h) {
        printf("%s", help);
        free(args.fnamelog);
        return 0;
    }

    srand((unsigned)time(NULL));

    game_t *game = new_game(
        args.n,
        args.c,
        args.d,
        args.r,
        args.a,
        args.fnamelog
    );
    start(game);
    delete_game(game);
    free(args.fnamelog);

    return 0;
}
