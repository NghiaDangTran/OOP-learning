#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * question2
 *
 * COMP 2160 SECTION A02
 * ASSIGNMENT    Assignment 2, question 2
 * AUTHOR        Nghia Dang, 7863117
 * DATE          30/10/2021
 *
 * PURPOSE: a progam that ask user for matrix and add them together
 */

/*
 * struct matrix
 * 
 *  PARAMETERS:
 *     num of row
 *    num of column
 *   pointer to array of matrix
 *    
 */

typedef struct matrix
{
    int row;
    int col;
    double **data;
} matrix;
//////////////////////////////////////////// end of struct matrix /////////////////////////////////////////////////////////////////

/**
 * validate function
 * PURPOSE: check if the function is good or not 
 * INPUT PARAMETERS:
 * the matrix to check
 * 
 * OUTPUT PARAMETERS:
 *  boolean value if the matrix is ok or not
 */

int validate(matrix *m)
{
    // first we check if the matrix is good or not
    assert(m != NULL);
    assert(m->data != NULL);
    assert(m->row > 0);
    assert(m->col > 0);
    assert(m->row < 100);
    assert(m->col < 100);

    // by using assert to check  0<row<100 0<col<100 and matrix null or matrix data is null
    if (m->row <= 0 || m->col <= 0 || m->row > 100 || m->col > 100 || m == NULL || m->data == NULL)
    {

        // byt again we check if the matrix is good or not
        // by using the if incase the user turn off assert
        printf("Invalid matrix\n");
        //let the user know if it happend
        return 0;
        // and rteturn false
    }

    return 1;
}

//////////////////////////////////////////// end of validate function /////////////////////////////////////////////////////////////////
/**
 * newMatrix function
 * PURPOSE: create a new matrix
 * INPUT PARAMETERS:
 *the number of row and column
 * 
 * OUTPUT PARAMETERS:
 *  the matrix
 */

matrix *newMatrix(int row, int col)
{
    // first set the new matrix to null
    matrix *m = NULL;

    m = (matrix *)malloc(sizeof(matrix));
    // allocation the size of the matrix

    assert(NULL != m);

    if (m == NULL)
    {
        // if the matrix is null
        // then we return null
        printf("Memory allocation failed\n");
        return NULL;
    }
    else
    {

        // else we set the matrix size
        m->row = row;
        assert(m->row > 0);
        assert(m->row < 100);
        // again check if the matrix is good or not
        m->col = col;
        assert(m->col > 0);
        assert(m->col < 100);

        // then still need to check by using if incase the user turn off assert
        if (m->col < 0 || m->col > 100 || m->row < 0 || m->row > 100)
        {
            printf("Invalid matrix\n");
            return NULL;
        }
    }

    int i, j;
    m->data = (double **)malloc(sizeof(double *) * m->row);
    // allocation the size
    assert(NULL != m->data);
    if (m->data == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    else
    {
        for (i = 0; i < m->row; i++)
        {
            m->data[i] = (double *)malloc(sizeof(double) * m->col);
            assert(NULL != m->data[i]);

            if (m->data[i] == NULL)
            {
                printf("Memory allocation failed\n");
                return NULL;
            }
            else
            {
                for (j = 0; j < m->col; j++)
                {
                    m->data[i][j] = 0;
                    // fill the data with 0
                }
            }
        }
    }

    // again at the end we still need toi validate the matreix
    if (validate(m))
    {
        return m;
    }
    else
        return NULL;
    free(m);
}
//////////////////////////////////////////// end of newMatrix function /////////////////////////////////////////////////////////////////

/**
 *printMatrix function
 * PURPOSE: print out the matrix
 * INPUT PARAMETERS:
 *  the matrix
 * 
 * OUTPUT PARAMETERS:
 *  print out the matrix
 */

void printMatrix(matrix *m)
{
    // alwasy check if the matrix is good or not
    if (validate(m))

    {
        // and then print it out
        int i, j;
        for (i = 0; i < m->row; i++)
        {
            for (j = 0; j < m->col; j++)
            {

                printf("%7.1f ", m->data[i][j]);
            }
            printf("\n");
        }
    }
}
//////////////////////////////////////////// end of printMatrix function /////////////////////////////////////////////////////////////////
/**
 *print_at_index function
 * PURPOSE: print out the matrix at the index
 * INPUT PARAMETERS:
 *  the matrix and the location to print out
 * 
 * OUTPUT PARAMETERS:
 *  print out value at that index
 */

void print_at_index(matrix *m, int i, int j)
{
    assert(m != NULL);
    assert(i > 0);
    assert(j > 0);
    assert(i < 100);
    assert(j < 100);
    // check matrix again
    // and check location again
    if (i < 0 || j < 0 || i > 100 || j > 100)
    {
        printf("Invalid index\n");
        return;
    }
    if (validate(m))
    {

        if (i < m->row && j < m->col)
        {
            printf("%7.1f\n", m->data[i][j]);
        }
        else
        {
            printf("Invalid index\n");
        }
    }
}

//////////////////////////////////////////// end of print_at_index function /////////////////////////////////////////////////////////////////
/**
 *  set_at_index function
 * 
 * PURPOSE: set the value at the index
 * INPUT PARAMETERS:
 *  the matrix and the location to print out
 * 
 * OUTPUT PARAMETERS:
 *  set the value at that index
 */

void set_at_index(matrix *m, int i, int j, double value)
{
    assert(m != NULL);
    assert(i > 0);
    assert(j > 0);
    assert(i < 100);
    assert(j < 100);
    assert(i < m->row);
    assert(j < m->col);
    // check matrix again
    if (i < 0 || j < 0 || i > 100 || j > 100 || i > m->row || j > m->col)
    {
        printf("Invalid index at 138\n");

        return;
    }

    if (validate(m))
    {
        if (i < m->row && j < m->col)
        {
            // make sure i and j is good
            m->data[i][j] = value;
        }
        else
        {
            printf("Invalid index at 144\n");
        }
    }
}
//////////////////////////////////////////// end of set_at_index function /////////////////////////////////////////////////////////////////

/**
 *  addMatrix function
 * PURPOSE: add 2 matrix together
 * INPUT PARAMETERS:
 *  2 matrix
 * 
 * OUTPUT PARAMETERS:
 *  out put the new matrix of 2 matrix added together
 */
matrix *addMatrix(matrix *m1, matrix *m2)
{

    // create new matrix to store the result
    matrix *m = NULL;
    assert(m1 != NULL);
    assert(m2 != NULL);

    //check if the matrix is good or not
    if (validate(m1) && validate(m2))
    {
        if (m1->row == m2->row && m1->col == m2->col)
        {
            // if the row and col is the same
            // then we add the matrix together

            m = newMatrix(m1->row, m1->col);

            int i, j;
            for (i = 0; i < m1->row; i++)
            {
                for (j = 0; j < m1->col; j++)
                {
                    m->data[i][j] = m1->data[i][j] + m2->data[i][j];
                }
            }
        }
        else
        {
            // if the row and col is not the same
            // then make col and row to be the biggest
            // in heere i want to try something new to get the max value
            // or we can compare the row and col and get the max value
            int max_row = m1->row > m2->row ? m1->row : m2->row;
            int max_col = m1->col > m2->col ? m1->col : m2->col;

            // create the new matrix  with the max value
            m = newMatrix(max_row, max_col);
            // in the same time we create 2 new temp matrix to store the value
            matrix *m1_temp = newMatrix(max_row, max_col);
            matrix *m2_temp = newMatrix(max_row, max_col);
            // the first one is the first matrix but with the new col and row
            for (int i = 0; i < m1->row; i++)
            {
                for (int j = 0; j < m1->col; j++)
                {
                    m1_temp->data[i][j] = m1->data[i][j];
                }
            }
            // the second one is the second matrix but with the new col and row
            for (int i = 0; i < m2->row; i++)
            {
                for (int j = 0; j < m2->col; j++)
                {
                    m2_temp->data[i][j] = m2->data[i][j];
                }
            }
            // now we add the 2 matrix together
            for (int i = 0; i < max_row; i++)
            {
                for (int j = 0; j < max_col; j++)
                {

                    m->data[i][j] = m1_temp->data[i][j] + m2_temp->data[i][j];
                }
            }
        }
    }
    // and at the end stilll neeed to validate the matrix
    if (validate(m))
    {
        // if it is good then return the new matrix
        return m;
    }
    else
    {
        return NULL;
    }
}
//////////////////////////////////////////// end of addMatrix function /////////////////////////////////////////////////////////////////

/**
 * getMatrix function
 * PURPOSE: get matrix from the user 
 * 
 * INPUT PARAMETERS:
 *  none
 * 
 * OUTPUT PARAMETERS:
 *  the matrix */
matrix *getMatrix()
{
    matrix *m = NULL;
    // get the value from the user
    char *line = NULL;
    size_t len = 0;
    int row, col;

    // and the reason i want to use scanf is that i can easly get the value from the user
    // depite wether the user enter in weird value
    if (scanf("%d %d", &row, &col) != 2)
    {
        printf("Invalid input\n");
    }
    else
    {
        //make the new amatrix
        m = newMatrix(row, col);
        if (validate(m))
        {
            // validate the matreix
            int i, j;

            for (i = 0; i < m->row; i++)
            {
                for (j = 0; j < m->col; j++)
                {
                    // get the value by the user input and store it in the matrix

                    if (scanf("%lf", &m->data[i][j]) != 1)
                    {
                        printf("Invalid input\n");

                        return NULL;
                    }
                }
            }
        }
    }

    if (validate(m))
    {
        return m;
    }
    else
        return NULL;
}
//////////////////////////////////////////// end of getMatrix function /////////////////////////////////////////////////////////////////

/**
 *Transpose function
 * PURPOSE: transpose the matrix
 * INPUT PARAMETERS:
 *  the matrix and the location to print out
 * 
 * OUTPUT PARAMETERS:
 *  the matrix transposed 
 */
matrix *Transpose(matrix *m)
{
    // create the new matrix
    matrix *m1 = NULL;

    assert(m != NULL);

    if (validate(m))
    {
        // and just flip the matrix
        // row by col
        m1 = newMatrix(m->col, m->row);

        for (int i = 0; i < m1->row; i++)
        {

            for (int j = 0; j < m1->col; j++)
            {
                m1->data[i][j] = m->data[j][i];
            }
        }
    }

    // at the end validate the matrix
    if (validate(m1))
    {
        return m1;
    }
    else
        return NULL;
}

//////////////////////////////////////////// end of Transpose function /////////////////////////////////////////////////////////////////
int main(void)
{

    // ask the user to enter the matrix
    matrix *m1 = getMatrix();

    printf("m1 test\n");
    printMatrix(m1);
    matrix *m2 = getMatrix();
    printf("m2 test\n");
    printMatrix(m2);
    printf("\n");
    matrix *m3 = addMatrix(m1, m2);
    printf("m3 (m1+m2) test\n");
    printMatrix(m3);
    printf("\n");

    matrix *m4 = Transpose(m2);
    printf("m4 T(m2) test\n");
    printMatrix(m4);
    printf("\n");

    matrix *m5 = addMatrix(m1, m4);
    printf("\n");
    printf("m5 m1+t(m2) test\n");

    printMatrix(m5);

    return 0;
}

//////////////////////////////////////////// end of main function /////////////////////////////////////////////////////////////////