#include <iostream>
#include <vector>

using namespace std;

/*
 Take and Element and Place in the Correct Order

 Eg :
        15  6  9  14  13  12  10
        ^^

        15  6  9  14  13  12  10    Array 15  6 is not Sorted since 15>6, Hence Swap
        ^   ^

        6  15  9  14  13  12  10    Array 6  15 is Sorted after swap
        ^   ^

        6  15  9  14  13  12  10    Array 6  15  9 is not Sorted since 15>9, Hence swap
        ^      ^

        6   9  15  14  13  12  10    Array 6  9  15 is Sorted after swap
        ^      ^

        6   9  15  14  13  12  10    Array 6  9  15  14 is Not Sorted since 15>14, Hence Swap
        ^           ^

        6   9  14  15  13  12  10    Array 6  9  14  15 is Sorted after Swap
        ^           ^

        6   9  14  15  13  12  10    Array 6  9  14  15 13 is not Sorted since 15>13, Hence Swap
        ^               ^

        6   9  14  13  15  12  10    Array 6  9  14  13 15 is not Sorted since 14>13, Hence Swap
        ^               ^

        6   9  13  14  15  12  10    Array 6  9  13  14 15 is Sorted after Swap
        ^               ^

        6   9  13  14  15  12  10    Array 6  9  13  14 15 12 is not Sorted since 15>12, Hence Swap
        ^                  ^

        6   9  13  14  12  15  10    Array 6  9  13  14 12 15 is not Sorted since 14>12, Hence Swap
        ^                  ^

        6   9  13  12  14  15  10    Array 6  9  13  12 14 15 is not Sorted since 13>12, Hence Swap
        ^                  ^

        6   9  12  13  14  15  10    Array 6  9  12  13 14 15 is Sorted After Swap
        ^                  ^

        6   9  12  13  14  15  10    Array 6  9  12  13 14 15 10 is not Sorted since 15>10, Hence Swap
        ^                       ^

        6   9  12  13  14  10  15    Array 6  9  12  13 14 10 15 is not Sorted since 14>10, Hence Swap
        ^                       ^

        6   9  12  13  10  14  15    Array 6  9  12  13 14 10 15 is not Sorted since 13>10, Hence Swap
        ^                       ^

        6   9  12  10  13  14  15    Array 6  9  12  13 14 10 15 is not Sorted since 12>10, Hence Swap
        ^                       ^

        6   9  10  12  13  14  15    Array 6  9  12  13 14 10 15 is not Sorted since 12>10, Hence Swap
        ^                       ^

        6   9  10  12  13  14  15    Array 6  9  12  13 14 10 15 is Sorted After Swap
        ^                       ^
*/

void print_1D_v(vector<int>& V)
{
    for(auto d:V)
    {
        cout << d << " ";
    }
    cout << endl;
}

// Worst Case TC --> O(N^2)
// Best Case TC --> O(N)
void InsertionSort(vector<int>& Arr)
{
    int n = Arr.size();

    for(int i = 1;i<n;i++)
    {
        int j=i;
        while(j>0 && Arr[j-1]>Arr[j])
        {
            swap(Arr[j-1],Arr[j]);
            j--;
            cout << "Runs" << endl;
        }
    }

}

int main()
{
    vector<int> Arr = {15,  6,  9,  14,  13,  12,  10};
    InsertionSort(Arr);
    cout << "Sorted Array -- >" << endl;
    print_1D_v(Arr);
    InsertionSort(Arr);
    cout << "Hello world!" << endl;
    return 0;
}
