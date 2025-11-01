#include <iostream>

int** makeMatrix(int rows, int cols);
void destroyMatrix(int** matrix);
void outputMatrix(const int* const* matrix):

int main()
{
  int rows = 0, cols = 0;
  std::cin >> rows >> cols;

  if (!std::cin)
  {
    return 1;
  }

  int** matrix = nullptr;

  matrix = makeMatrix(rows, cols);

  outputMatrix(matrix);

  destroyMatrix(matrix);
}
