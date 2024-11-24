
#include<iostream>
#include<vector>
#include<set>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<algorithm>

using namespace std;

int main()
{
    int amount;
    cout << "Enter the number's amount: ";
    cin >> amount;
    srand(time(0));
    set <int> uniqueNumbers;
    while (uniqueNumbers.size() < amount)
    {
        int randomNum = rand();
        uniqueNumbers.insert(randomNum);
    }
    vector<int> randomNumbers(uniqueNumbers.begin(), uniqueNumbers.end());

    random_shuffle (randomNumbers.begin(), randomNumbers.end());
    ofstream outFile("numbers.txt");
    if (outFile.is_open())
    {
        for (int num : randomNumbers)
        {
            outFile << num << " ";
        }
        outFile.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
    return 0;
}
