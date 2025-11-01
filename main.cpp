#include <iostream>

int** makeMatrix(int rows, int cols);
void destroyMatrix(int** matrix, int rows);
void inputMatrix(int** matrix, int rows, int cols);
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

  try
  {
    matrix = makeMatrix(rows, cols);
  }
  catch(const std::bad_alloc& e)
  {
    return 2;
  }

  inputMatrix(matrix, rows, cols);
  if (!std::cin)
  {
    destroyMatrix(matrix, rows);
    return 1;
  }

  outputMatrix(matrix);

  destroyMatrix(matrix, rows);
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

void inputMatrix(int** matrix, int rows, int cols)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      std::cin >> matrix[i][j];
    }
  }
}
