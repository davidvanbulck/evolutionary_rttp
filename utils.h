#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "genotype.h"

double randval();
double randval_between(double smallNumber, double bigNumber);
/*
 * The fscanint function read the next int integer from the stream f,
 * and assigns the value through the second argmument, v, which must be
 * a pointer. It returns 0 if end of file or an error occurs; otherwise 
 * it returs 1.
 *
 * It is faster than fscanf.
 */
int fscanint(FILE * f, int *v);
double** create_matrix(int size_x, int size_y);
int** create_matrix_int(int size_x, int size_y);
void copy_matrix(int** from,int** to,int size_x,int size_y);

#endif
