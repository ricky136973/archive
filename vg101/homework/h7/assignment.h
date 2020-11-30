//
// Created by patri on 2016/6/18.
// Edited by Yurnero Fu on 2017/10/27
//

//This is the so-called header guard, which prevent compiler load header files repeatedly.
#ifndef CTEMPLATE_ASSIGNMENT_H
#define CTEMPLATE_ASSIGNMENT_H

int getExerciseNumber(int argc, char* argv[]);
/* This function gets the exercise number to run from
 * 1. program argument (for graders)
 * 2. student's input prompt (for students), invalid input will be prompt for re-input.
 *
 * Written by VG101_SU16TA/patrick
 * Edited by VG101_FA17TA/Yurnero Fu
 */

void ex1();
void ex2();
void ex3();
void ex4();

// declare your other sub-functions here

#endif //CTEMPLATE_ASSIGNMENT_H
