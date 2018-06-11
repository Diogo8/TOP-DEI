#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 4098

void print_matrix(int **matrix, int height);
int longer_path(int **paths, int height);
void clean(int **matrix, int height);
int **get_test(int height);

int main(){
  int i, height, num_tests;
  int **tests = NULL;

  scanf("%d", &num_tests);

  for(i = 0; i < num_tests; i++){
    scanf("%d", &height);
    tests = get_test(height);
    printf("%d\n", longer_path(tests, height));
    clean(tests, height);
    free(tests);
  }

  return 0;
}

int longer_path(int **paths, int height){
  int i, j, max_value;

  for(i = 1; i < height; i++){
    max_value= 0;
    for(j = 0; j <= i; j++){
      if(j == 0)
        paths[i][j] += paths[i-1][j];

      else if(j == i)
        paths[i][j] += paths[i-1][j-1];

      else
        if(paths[i][j] + paths[i-1][j-1] > paths[i][j] + paths[i-1][j])
          paths[i][j] += paths[i-1][j-1];
        else
          paths[i][j] += paths[i-1][j];

      if (i == height-1 && paths[i][j] > max_value)
        max_value = paths[i][j];
    }
  }
  return max_value;
}

void print_matrix(int **matrix, int height){
  int i,j;

  for(i = 0; i < height; i++){
    for(j = 0; j < i + 1; j++){
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int **get_test(int height){
  int i, j, input_width;
  int input_height = height * sizeof(int*);
  int **input = (int**)malloc(input_height);
  char number[MAX_LEN];

  for(i = 0; i < height; i++){
    input_width = (i + 1) * sizeof(int);
    input[i] = (int*)malloc(input_width);
    for(j = 0; j <= i; j++){
      scanf("%s", number);
      input[i][j] = atoi(number);
    }
  }

  return input;
}

void clean(int **matrix, int height){
  int i;

  for(i = 0; i < height; i++){
    free(matrix[i]);
  }
}
