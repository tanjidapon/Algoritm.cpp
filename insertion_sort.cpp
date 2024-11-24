
#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    const int MAX_SIZE = 10000;
    int number[MAX_SIZE];
    int count = 0;

    ifstream inputFile("numbers.txt");
    if (!inputFile)
    {
        cerr << "The file is not found";
        return 1;
    }

    while (inputFile >> number[count] && count < MAX_SIZE)
    {
        count++;
    }
    inputFile.close();

    clock_t start = clock();


    insertion_sort(number, count);

    clock_t end = clock();

    double time_taken = double (end - start) / CLOCKS_PER_SEC;

    ofstream outputFile("sorted.txt");
    if (!outputFile)
    {
        cerr << "Failed to open sorted.txt for writing.";
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        outputFile << number[i] << " ";
    }
    outputFile.close();

    cout << "Sorted numbers have been written to sorted.txt." << endl;
    cout << "Time taken for sorting: " << time_taken << " seconds" << endl;

    return 0;
}
