#include <random>
#include <chrono>
#include <iostream>
#include <vector>
#include <fstream>

#include "QuadraticSort.h"

using namespace std;

int main()
{
    // Using fstream to save the array to the file
    ofstream File("OutArray.txt");

    // Using random to randomly generate N vector
    random_device Devc;
    mt19937 Rng(Devc());

    // A program to calculate time needed to be sorted
    int N, Min, Max;
    cout << "Enter length of array: ";
    cin >> N;

    cout << "Enter the min and max element: ";
    cin >> Min >> Max;

    // Generating Array with random elements
    vector<int> Arr;
    uniform_int_distribution<mt19937::result_type> Rand(Min, Max);

    File << "======================== Unsorted Array ======================== \n";
    for (int I = 0; I < N; ++I)
    {
        Arr.push_back(Rand(Rng));

        // Save array to file
        File << Arr[I] << " ";
    }
    File << "\n";

    // Calculate time needed
    auto Start = chrono::high_resolution_clock::now();

    // Choose which algorithm want to use
    const string Algorithm[] = { "Bubble Sort", "Selection Sort", "Insertion Sort" };
    uint16_t Option;
    cout << "Choose which sorting algorithm you want to use: \n"
         << "1.Bubble Sort\n2.Selection Sort\n3.InsertionSort\n"
         << "Your option: ";
    cin >> Option;
    cout << ">> We're trying to sort the array...Please wait...\n";

    switch (Option)
    {
    case 1:
        BubbleSort(Arr);
        break;

    case 2:
        SelectionSort(Arr);
        break;

    case 3:
        InsertionSort(Arr);
        break;
    }

    auto End = chrono::high_resolution_clock::now();
    auto Duration = chrono::duration_cast<chrono::milliseconds>(End - Start);

    // Save sorted array to file
    File << "\n======================== Sorted Array ======================== \n";
    for (int I = 0; I < N; ++I)
    {
        // Save array to file
        File << Arr[I] << " ";
    }
    File << "\n\nTime needed is " << Duration.count() << "ms with " << Algorithm[Option - 1] << "\n";

    cout << ">> We've finished the sorting. Check the result on OutArray.txt\n";

    File.close();
}
