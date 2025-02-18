#include <iostream>
#include <vector>

using namespace std;

/*
    Selection Sort : A Sorting Algorithm where we Select a value
    which is minimum and swap it with the first element

    eg: Element Set as
     13  46  24  52  20  9         1.) find Min(first,last) = 9
     ^                   ^         2.) 13>9 --> swap(first,minIdx)
    first               last

     9  46  24  52  20  13         1.) find Min(first,last) = 13
         ^               ^         2.) 46>13 --> swap(first,minIdx)
        first           last

     9  13  24  52  20  46         1.) find Min(first,last) = 20
            ^            ^         2.) 24>20 --> swap(first,minIdx)
           first        last

     9  13  20  52  24  46         1.) find Min(first,last) = 24
                ^        ^         2.) 52>24 --> swap(first,minIdx)
               first    last

     9  13  20  24  52   46         1.) find Min(first,last) = 46
                    ^     ^         2.) 52>46 --> swap(first,minIdx)
                   first  last

     9  13  20  24  46   52         1.) find Min(first,last) = 52
                        ^ ^         2.) 52>52 --> swap(first,minIdx)
                      first = last


*/
void print_1D_v(vector<int>& V)
{
    for(auto d:V)
    {
        cout << d << " ";
    }
    cout << endl;
}

int find_Min(vector<int>& Arr,int first,int last,int& min_idx)
{
    int min_val = 1e9;
    min_idx = -1;
    for(int i=first;i<last;i++)
    {
        if(Arr[i]<min_val)
        {
            min_val = Arr[i];
            min_idx = i;
        }
    }
    return min_val;
}

// TC --> O(N^2)
// Algo runs for n + (n-1) + (n-2) + (n-3) .... 2 = n.(n+1)/2 = n^2/2 + n/2 ==> n^2
void SelectionSort(vector<int>& Arr)
{
    int last = Arr.size();

    for(int first=0;first<last;first++)
    {
        int min_idx=-1;
        int min_val = find_Min(Arr,first,last,min_idx);
        if(Arr[first]>min_val)
            swap(Arr[first],Arr[min_idx]);
    }
}

int main()
{
    vector<int> Arr = { 13 , 46 , 24 , 52 , 20 , 9 };
    SelectionSort(Arr);
    cout << "After SelectionSort" << endl;
    print_1D_v(Arr);
    return 0;
}
