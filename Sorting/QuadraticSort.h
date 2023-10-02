// Quadratic Sort is any commons sorting algorithm that has time complexity O(N^2)

#include <vector>

using namespace std;

void Swap(int& A, int& B)
{
    int Temp = A;
    A        = B;
    B        = Temp;
}

void BubbleSort(vector<int>& Arr)
{
    size_t N = Arr.size();

    for (size_t I = 0; I < N; ++I)
        for (size_t J = I; J < N; ++J)
            if (Arr[I] > Arr[J])
                Swap(Arr[I], Arr[J]);
}

void SelectionSort(vector<int>& Arr)
{
    size_t N = Arr.size();

    for (size_t I = 0; I < N; ++I)
    {
        size_t MinIdx = I;

        for (size_t J = I + 1; J < N; ++J)
            if (Arr[J] < Arr[MinIdx])
                MinIdx = J;

        // Swap the minimum
        if (MinIdx != I)
            Swap(Arr[MinIdx], Arr[I]);
    }
}

void InsertionSort(vector<int>& Arr)
{
    size_t N = Arr.size();

    for (size_t I = 0; I < N; ++I)
    {
        int Key  = Arr[I];
        size_t J = I - 1;

        while (J >= 0 && Key < Arr[J])
        {
            Arr[J + 1] = Arr[J];

            --J;
        }

        Arr[J + 1] = Key;
    }
}
