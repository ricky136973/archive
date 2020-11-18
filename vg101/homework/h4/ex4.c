#ifndef JOJ
#include "assignment.h"
#endif

#include <stdio.h>
#include <stddef.h>
#include <limits.h>

#ifndef __STDC_NO_COMPLEX__

#include <complex.h>

#endif //__STDC_NO_COMPLEX__

#ifdef CHECK_TYPE
#undef CHECK_TYPE
#endif
#define CHECK_TYPE(s, type) \
if ((size_t)(s) == sizeof(type)) printf("%s\n", #type);

void que4_1();
void que4_2();
void que4_3();

void que4_1() {
    int op;
    printf("[1] Check Vowel or Consonant\n");
    printf("[2] Find Data Type with Size\n");
    printf("Input your option: ");
    scanf("%d", &op);
    switch (op) {
        case 1:
            que4_2();
            break;

        case 2:
            que4_3();
            break;

        default:
            printf("Invalid Option\n");
            break;
    }
}

void que4_2() {
    char c;
    printf("Input a letter: ");
    c = getc(stdin);
    c = c <= 32 ? getc(stdin) : c;
    c += c >= 'A' && c <= 'Z' ? 32 : 0;
    if (c >= 'a' && c <= 'z') {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                printf("Vowel\n");
                break;
            
            default:
                printf("Consonant\n");
                break;
        }
    } else {
        printf("Not a Letter\n");
    }
}

void que4_3() {
    size_t s;
    char u;
    printf("Input the size and the unit (b|B): ");
    scanf("%zu%c", &s, &u);
    s /= u == 'b' ? 8 : 1;
    printf("The following type(s) have the corresponding size:\n");
    
    CHECK_TYPE(s, _Bool);

    CHECK_TYPE(s, char);
    CHECK_TYPE(s, signed char);
    CHECK_TYPE(s, unsigned char);

    CHECK_TYPE(s, short int);
    CHECK_TYPE(s, unsigned short int);
    CHECK_TYPE(s, int);
    CHECK_TYPE(s, unsigned int);
    CHECK_TYPE(s, long int);
    CHECK_TYPE(s, unsigned long int);
    CHECK_TYPE(s, long long int);
    CHECK_TYPE(s, unsigned long long int);

    CHECK_TYPE(s, float);
    CHECK_TYPE(s, double);
    CHECK_TYPE(s, long double);

    #ifndef __STDC_NO_COMPLEX__
    CHECK_TYPE(s, float _Complex);
    CHECK_TYPE(s, double _Complex);
    CHECK_TYPE(s, long double _Complex);
    #endif //__STDC_NO_COMPLEX__

    #if defined(__STDC_IEC_559_COMPLEX__) && defined(_Imaginary_I)
    CHECK_TYPE(s, float _Imaginary);
    CHECK_TYPE(s, double _Imaginary);
    CHECK_TYPE(s, long double _Imaginary);
    #endif // defined(__STDC_IEC_559_COMPLEX__) && defined(_Imaginary_I)

    CHECK_TYPE(s, void*);
}

void ex4() {
    que4_1();
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex4();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H