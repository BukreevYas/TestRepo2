#include <iostream>

int** makeMatrix(int rows, int cols);
void destroyMatrix(int** matrix, int rows);
void outputMatrix(const int* const* matrix);

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

int** makeMatrix(int rows, int cols)
{
  int** matrix = new int*[rows];

  for (size_t i = 0; i < rows; i++)
  {
    try
    {
      matrix[i] = new int[cols];
    }
    catch (const std::bad_alloc& e)
    {
      destroyMatrix(matrix, i);
      throw;
    }
  }
  
  return matrix;
}

void destroyMatrix(int** matrix, int rows)
{
  for (size_t i = 0; i < rows; i++)
  {
    delete[] matrix[i];
  }

  delete[] matrix;
}
