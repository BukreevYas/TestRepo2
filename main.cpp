#include <iostream>

int** makeMatrix(int rows, int cols);
void destroyMatrix(int** matrix, int rows);
void inputMatrix(int** matrix, int rows, int cols);
void outputMatrix(const int* const* matrix, int rows, int cols);

int** convert(const int* arr, size_t n, const size_t* sizes, size_t rows);

int main()
{
}

int** convert(const int* arr, size_t n, const size_t* rowSizes, size_t rows)
{
  int** matrix = nullptr;

  try
  {
    matrix = makeMatrix(rows, rowSizes);
  }
  catch(const std::bad_alloc& e)
  {
    return 2;
  }

  // convert

  outputMatrix(matrix, rows, rowSizes);

  destroyMatrix(matrix, rows);
}

int** makeMatrix(int rows, const size_t* rowSizes)
{
  int** matrix = new int*[rows];

  for (size_t i = 0; i < rows; i++)
  {
    try
    {
      matrix[i] = new int[rowSizes[i]];
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

void outputMatrix(const int* const* matrix, int rows, const size_t* rowSizes)
{
  std::cout << '\n';

  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < rowSizes[i]; j++)
    {
      std::cout << matrix[i][j];
      std::cout << (j == cols - 1 ? '\n' : ' ');
    }
  }
}
