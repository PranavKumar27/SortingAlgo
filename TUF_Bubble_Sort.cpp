#include <iostream>
#include <vector>

using namespace std;

/*  Move the heaviest to the right. Compare every two element if first is larger than second swap them


Iteration 1

    13  46  24  52  20  9
    ^    ^                          13<46   ->  True -> No swap

    13  46  24  52  20  9
        ^   ^                         46<24 -> False --> swap

    13  24  46  52  20  9
             ^   ^                     46<52 -> True --> No swap

    13  24  46  52  20  9
                 ^      ^              52<20 ->  Fail --> swap

    13  24  46  20  52  9
                     ^ ^              52<9 ->  Fail --> swap

    13  24  46  20  9  52
                     ^ ^              52<9 ->  Fail --> swap


Iteration 2

    13  24  46  20  9  52
    ^    ^                          13<24   ->  True -> No swap

    13  24  46  20  9  52
        ^   ^                         24<46 -> True --> No swap

    13  24  46  20  9  52
             ^   ^                     46<20 -> False --> swap

    13  24  20  46  9  52
                 ^      ^              46<9 ->  Fail --> swap

    13  24  20  9  46  52
                    ^   ^               46<52 ->  True --> No swap

    13  24  20  9  46  52
                       ^^              i reached N

Iteration 3

    13  24  20  9  46  52
    ^    ^                          13<24   ->  True -> No swap

    13  24  20  9  46  52
        ^   ^                         24<20 -> False --> swap

    13  20  24  9  46  52
             ^  ^                     24<9 -> False --> swap

    13  20  9  24  46  52
                ^  ^                   24<46 ->  True --> No swap

    13  20  9  24  46  52
                    ^   ^               46<52 ->  True --> No swap

    13  20  9  24  46  52
                       ^^              i reached N

Iteration 4

    13  20  9  24  46  52
    ^    ^                          13<20   ->  True -> No swap

    13  20  9  24  46  52
        ^   ^                         20<9 -> False --> swap

    13  9  20  24  46  52
            ^  ^                     20<24 -> True --> No swap

    13  9  20  24  46  52
                ^  ^                   24<46 ->  True --> No swap

    13  9  20  24  46  52
                    ^   ^               46<52 ->  True --> No swap

    13  9  20  24  46  52
                       ^^              i reached N

We can avoid the last three comparison by subtracting i from j since at any point i elements will be sorted

Iteration 4

    13  9  20  24  46  52
    ^   ^                              13<9   ->  False -> swap

    9  13  20  24  46  52
        ^   ^                         13<20 -> True --> No swap

    9  13  20  24  46  52
            ^  ^                     20<24 -> True --> No swap

    9  13  20  24  46  52
                ^  ^                   24<46 ->  True --> No swap

    9  13  20  24  46  52
                    ^   ^               46<52 ->  True --> No swap

    9  13  20  24  46  52
                       ^^              i reached N

Iteration 5

    9  13  20  24  46  52
    ^   ^                              9<13   ->  True -> No swap

    9  13  20  24  46  52
        ^   ^                         13<20 -> True --> No swap

    9  13  20  24  46  52
            ^  ^                     20<24 -> True --> No swap

    9  13  20  24  46  52
                ^  ^                   24<46 ->  True --> No swap

    9  13  20  24  46  52
                    ^   ^               46<52 ->  True --> No swap

    9  13  20  24  46  52
                       ^^              i reached N




*/

void print_1D_v(vector<int>& V)
{
    for(auto d:V)
    {
        cout << d << " ";
    }
    cout << endl;
}

// TC --> O(N^2)
// Algo runs for n + (n-1) + (n-2) + (n-3) .... 2 = n.(n+1)/2 = n^2/2 + n/2 ==> n^2

void BubbleSort(vector<int>& Arr)
{
    int n = Arr.size();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(Arr[j]>Arr[j+1])
            {
                swap(Arr[j],Arr[j+1]);
            }
        }
    }
}

// If Array is Already Sorted, then Loop will break in n times
// TC --> O(N)
void BubbleSort_Optimized(vector<int>& Arr)
{
    int n = Arr.size();

    for(int i=0;i<n;i++)
    {
        bool didSwap = false;
        for(int j=0;j<n-1-i;j++)
        {
            if(Arr[j]>Arr[j+1])
            {
                swap(Arr[j],Arr[j+1]);
                didSwap = true;
            }
        }
        if(didSwap==false) // If no Swaps done, this means Array is Sorted
            break;
        cout << "runs" << endl;
    }
}

int main()
{
    vector<int> Arr = {13,  46,  24,  52,  20,  9};
    BubbleSort(Arr);
    cout << "Sorted Array -- >" << endl;
    print_1D_v(Arr);

    vector<int> Arr2 = {1,2,3,4,5,6};
    BubbleSort_Optimized(Arr2);
    cout << "Sorted Array -- >" << endl;
    print_1D_v(Arr2);
    return 0;
}
