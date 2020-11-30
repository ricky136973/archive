//Created by patrick, edited by Yurnero Fu

#include "assignment.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int ex;
    do {
        ex = getExerciseNumber(argc, argv);
        switch (ex){
            case 1 :
                ex1();
                break;
            case 2:
                ex2();
                break;
            case 3:
                ex3();
                break;
            case 4:
                ex4();
                break;
            case 0:
                //exit case
                return 0;
            default:
                cerr<<"The exercise does not exist!"<<endl;
                cerr<<"You specified exercise: "<<ex<<endl;
                return 0;
        }
    }
    while (argc == 1);
    return 0;
}

int getExerciseNumber(int argc, char* argv[]){
    if(argc <= 0 || argc > 2) {
        cerr<<"Illegal Usage"<<endl;
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
            if ( str[3] > '0' && str[3] <= '9')
                return (str[3] - '0');
        cerr<<"Illegal Usage"<<endl;
        exit(-3);
    }
    if (argc == 1) {
        //Student running test repeatedly
        int exerciseNum = 0;
        while (true) {
            cout<<"Please input your exercise number: ";
            std::cin>>exerciseNum;
            char c = 0;
            while ((c = (char)getchar()) != '\n' && c != EOF);
            if (exerciseNum >= 0 && exerciseNum < 10)
                return exerciseNum;
            cerr<<"Illegal input, try again"<<endl;
        }
    }
    return -1;
}
