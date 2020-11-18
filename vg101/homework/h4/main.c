#include "assignment.h"

int main(int argc, char* argv[]) {
    int ex = getExerciseNumber(argc, argv);
    switch (ex) {
        case 1 :
            ex1();
            return 0;
        case 2:
            ex2();
            return 0;
        case 3:
            ex3();
            return 0;
        case 4:
            ex4();
            return 0;
        case 5:
            ex5();
            return 0;
        default:
            fprintf(stderr, "Exercise %d does not exist! Please check it and try again.\n", ex);
            return -1;
    }
}

int getExerciseNumber(int argc, char* argv[]) {
    if (argc <= 0 || argc > 2) {
        fprintf(stderr, "Illegal Usage");
        exit(-2);
    }
    if (argc == 2) {
        // Grader provided argument
        char *str = argv[1];
        int crit = 1;
        crit = crit && (str[0] == '-');
        crit = crit && (str[1] == 'e');
        crit = crit && (str[2] == 'x');
        if (crit)
            if (str[3] > '0' && str[3] <= '9')
                return str[3] - '0';
        fprintf(stderr, "Illegal argument");
        exit(-3);
    }
    if (argc == 1) {
        // Student running without argument
        int exerciseNum = 0;
        while (1) {
            printf("Please input your exercise number: ");
            while (!scanf("%d", &exerciseNum));
            if (exerciseNum > 0 && exerciseNum < 10)
                return exerciseNum;
            fprintf(stderr, "Illegal input, try again\n");
        }
    }
	return 0;
}