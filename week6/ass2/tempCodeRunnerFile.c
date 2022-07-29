#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_LINE 801
const char SEPARATOR[] = " \n";

typedef enum BOOL {
  FALSE = 0,
  TRUE = 1
} Bool;

// use of a struct is optional, but much easier than passing lots of parameters
// an uninitialized matrix has both rows and cols set to 0
typedef struct MATRIX {
  double matrix[MAX_ROWS][MAX_COLS];
  int rows;
  int cols;
} Matrix;

Matrix mat_a, mat_b, mat_result;

void matrix_validate(Matrix *m)
{
  assert(NULL != m);
  assert(m->rows >= 0 && m->rows <= MAX_ROWS);
  assert(m->cols >= 0 && m->cols <= MAX_COLS);
}

double matrix_get(Matrix *m, int r, int c)
{
  double result = 0.0;
  
  matrix_validate(m);
  assert(r >= 0 && r < m->rows);
  assert(c >= 0 && c < m->cols);

  result = m->matrix[r][c];

  matrix_validate(m);
  
  return result;
}

void matrix_set(Matrix *m, int r, int c, double value)
{
  matrix_validate(m);
  assert(r >= 0 && r < m->rows);
  assert(c >= 0 && c < m->cols);

  m->matrix[r][c] = value;

  matrix_validate(m);
}

Bool matrix_read(Matrix *m)
{
  Bool valid = FALSE, bad_input = FALSE;
  int rows = 0, cols = 0;
  char line[MAX_LINE];
  char *str_result = NULL, *token;
  double value;

  assert(NULL != m);

  // de-initialize m
  m->rows = 0;
  m->cols = 0;
  
  str_result = fgets(line, MAX_LINE, stdin);
  if (NULL != str_result) {
    // input-line-too-long is an error
    if ('\n' == line[strlen(line)-1]) {
      token = strtok(line, SEPARATOR);
      if (NULL != token) {
        rows = atoi(token);
        token = strtok(NULL, SEPARATOR);
        if (NULL != token) {
          cols = atoi(token);
        }
      }
    }
  }

  if (NULL == str_result || 0 == rows || 0 == cols) {
    fprintf(stderr, "Invalid matrix size specification: %s\n", line);
  } else {
    for (int row = 0; row < rows && !bad_input; row++) {
      str_result = fgets(line, MAX_LINE, stdin);
      if (NULL == str_result) {
        fprintf(stderr, "Not enough input rows (ran out at %d, expected %d).\n", row+1, rows);
        bad_input = TRUE;
      } else {
        token = strtok(line, SEPARATOR);
        for (int col = 0; col < cols && !bad_input; col++) {
          if (NULL == token) {
            fprintf(stderr, "Not enough input columns on row %d (ran out at %d, expected %d).\n", row+1, col+1, cols);
            bad_input = TRUE;
          } else {
            value = strtod(token, &str_result);
            if (str_result == token) {
              fprintf(stderr, "Invalid number on row %d column %d: %s.\n", row+1, col+1, token);
              bad_input = TRUE;
            } else {
              // can't use matrix_set yet because m isn't fully initialized
              m->matrix[row][col] = value;
              token = strtok(NULL, SEPARATOR);
            }
          }
        }
      }
    }
    if (!bad_input) {
      // only initialize when we're sure the input is good
      m->rows = rows;
      m->cols = cols;
      valid = TRUE;
    }
  }

  matrix_validate(m);
  
  return valid;  
}

void matrix_print(Matrix *m)
{
  char whitespace;

  matrix_validate(m);

  printf("%d %d\n", m->rows, m->cols);
  for (int row = 0; row < m->rows; row++) {
    for (int col = 0; col < m->cols; col++) {
      if (col < m->cols-1) {
        whitespace = ' ';
      } else {
        whitespace = '\n';
      }
      printf("%7.1f%c", matrix_get(m, row, col), whitespace);
    }
  }

  matrix_validate(m);
}

// sum can be the same as either a or b
void matrix_add(Matrix *a, Matrix *b, Matrix *sum)
{
  int rows, cols;
  
  matrix_validate(a);
  matrix_validate(b);
  assert(NULL != sum);

  // use the max of rows and cols
  rows = (a->rows > b->rows) ? a->rows : b->rows;
  cols = (a->cols > b->cols) ? a->cols : b->cols;
  
  sum->rows = rows;
  sum->cols = cols;

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      if (row < a->rows && col < a->cols && row < b->rows && col < b->cols) {
        matrix_set(sum, row, col, matrix_get(a, row, col) + matrix_get(b, row, col));
      } else if (row < a->rows && col < a->cols) {
        matrix_set(sum, row, col, matrix_get(a, row, col));
      } else if (row < b->rows && col < b->cols) {
        matrix_set(sum, row, col, matrix_get(b, row, col));
      } else {
        matrix_set(sum, row, col, 0.0);
      }
    }
  }
  
  matrix_validate(a);
  matrix_validate(b);
  matrix_validate(sum);
}

void matrix_transpose(Matrix *m, Matrix *t)
{
  matrix_validate(m);
  assert(NULL != t);  

  t->rows = m->cols;
  t->cols = m->rows;
  for (int row = 0; row < m->rows; row++) {
    for (int col = 0; col < m->cols; col++) {
      matrix_set(t, col, row, matrix_get(m, row, col));
    }
  }
  
  matrix_validate(m);
  matrix_validate(t);
}

int main()
{
  Bool is_ok;
  
  is_ok = matrix_read(&mat_a);
  is_ok = is_ok && matrix_read(&mat_b);
  
  if (is_ok) {
    matrix_validate(&mat_a);
    matrix_validate(&mat_b);
  
    matrix_add(&mat_a, &mat_b, &mat_result);
    matrix_validate(&mat_result);
    matrix_print(&mat_result);

    matrix_validate(&mat_a);
    matrix_validate(&mat_b);
  
    matrix_transpose(&mat_b, &mat_result);

    matrix_validate(&mat_b);
    matrix_validate(&mat_result);

    matrix_add(&mat_a, &mat_result, &mat_result);
    matrix_validate(&mat_result);
    matrix_print(&mat_result);
  }
  
  return 0;
}