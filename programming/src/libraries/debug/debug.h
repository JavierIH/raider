#ifndef DEBUG_H
#define DEBUG_H

#include<iostream>

#define DEBUG_LEVEL 2

#define ERROR 1
#define WARNING 2
#define OK 3
#define INFO 4

using namespace std;

void report(int, string);
void report(string);

#endif // DEBUG_H
