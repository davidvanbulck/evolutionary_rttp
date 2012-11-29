#include "utils.h"

double randval()
{
	return (double)rand()/(double)RAND_MAX;
}

double randval_between(double smallNumber, double bigNumber)
{
    double diff = bigNumber - smallNumber;
    return (((double) rand() / RAND_MAX) * diff) + smallNumber;
}

int fscanint(FILE * f, int *v)
{
    int val;
    int c, sign = 1;

    while (isspace(c = getc(f)));
    if (c == '-' || c == '+') {
        if (c == '-')
            sign = -1;
        if ((c = getc(f)) == EOF) {
            ungetc(c, f);
            return 0;
        }
    }
    if (!isdigit(c)) {
        ungetc(c, f);
        return 0;
    }
    val = c - '0';
    while (isdigit(c = getc(f)))
        val = 10 * val + (c - '0');
    *v = sign * val;
    return 1;
}

double** create_matrix(int size_x, int size_y)
{
    double** matrix;
	int i;
    matrix = calloc(size_x+1, sizeof(double*));
    for(i = 0;i<size_x;i++) {
        matrix[i] = calloc(size_y, sizeof(double));
    }
    matrix[size_x] = NULL;

    return matrix;
}

int** create_matrix_int(int size_x, int size_y)
{
    int** matrix;
	int i;
    matrix = calloc(size_x+1, sizeof(int*));
    for(i = 0;i<size_x;i++) {
        matrix[i] = calloc(size_y, sizeof(int));
    }
    matrix[size_x] = NULL;

    return matrix;
}

void copy_matrix(int** from,int** to,int size_x,int size_y)
{
	int i,j;
	for(i=0;i<size_x;i++)
		for(j=0;j<size_y;j++)
			to[i][j]=from[i][j];
}


