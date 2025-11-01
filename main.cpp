#include <iostream>

int** makeMatrix(int rows, const size_t* rowSizes);
void destroyMatrix(int** matrix, int rows);
void outputMatrix(const int* const* matrix, int rows, const size_t* rowSizes);

int** convert(const int* arr, size_t n, const size_t* sizes, size_t rows);

int main()
{
  const int arr[] = {5, 5, 5, 6, 6, 7};
  const size_t rowSizes[] = {3, 2, 1};
  size_t rows = 3;

  int** matrix = convert((const int*)&arr, 6, (const size_t*)&rowSizes, 3);

  outputMatrix(matrix, rows, (const size_t*)&rowSizes);

  destroyMatrix(matrix, rows);
}

int** convert(const int* arr, size_t n, const size_t* rowSizes, size_t rows)
{
  int** matrix = nullptr;

  matrix = makeMatrix(rows, rowSizes);

  size_t index = 0;
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < rowSizes[i]; j++)
    {
      matrix[i][j] = arr[index];
      index++;
    }
  }

  return matrix;
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
      std::cout << (j == rowSizes[i] - 1 ? '\n' : ' ');
    }
  }
}
