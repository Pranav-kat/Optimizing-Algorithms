#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;
int main()
{
    fstream my_file;
    int xx = 0;
    string word;
    string w;
    cout << "Enter the word to be searched" << endl;
    cin >> w;
    auto start = chrono::system_clock::now();
    my_file.open("File.txt", ios::in);
    if (!my_file)
    {
        cout << "No such file";
    }
    else
    {
        while (1)
        {
            my_file >> word;
            if (my_file.eof())
                break;
            if (word == w)
            {
                xx = xx + 1;
                cout << word << endl;
            }
            else
                continue;
        }
    }
    my_file.close();
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "elapsed time: " << elapsed_seconds.count() * 1000 << endl;
    cout << "total number of times the word has occured is: " << xx;
    return 0;
}

