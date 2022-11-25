#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define NUM_ELEMENTS 7

#define UNDEFINED 0
#define COMMAND 1
#define ARGUMENT 2

struct element
{
	char* str;
	int type;
};