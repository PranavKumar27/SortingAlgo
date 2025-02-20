#include <iostream>
#include <vector>

using namespace std;


/*
Quick Sort

Steps: Find the Pivot Element and place it in the current position
Move the Lesser element to the left and larger elements to the right

Consider first Element as the pivot element
Keep on moving if element < pivot  eg : Arr[i]<=pivot;
                                        i++

If Not stop i

Keep on Moving if the element > pivot eg: Arr[j]>pivot
                                          j--;

If(i<j)
Swap(Arr[i],Arr[j])

Do this till (i<j)

If i>j the break and swap(pivot, Arr[j])

Eg:    low                     high
        9, 7, 3, 5, 8, 1, 4, 2, 6
        0  1  2  3  4  5  6  7  8
        i                       j

        pivot = 9
    At i = 0, pivot>=9
    At i = 1, pivot>=7
    At i = 2, pivot>=3
    At i = 3, pivot>=5
    At i = 4, pivot>=8
    At i = 5, pivot>=1
    At i = 6, pivot>=4
    At i = 7, pivot>=2
    At i = 8, pivot>=6

    At j = 8, pivot<6  - False

    i<j -- False

    Swap(pivot,Arr[j])

       low                     high
        6, 7, 3, 5, 8, 1, 4, 2, 9
        0  1  2  3  4  5  6  7  8
        i                       j

    Divide into two Parts Correction position for 9 is found

    Left and right

   low                  high
    6, 7, 3, 5, 8, 1, 4, 2
    0  1  2  3  4  5  6  7
    i                    j

    pivot = 6

    At i = 0, pivot>=6
    At i = 1, pivot>=7

    At j = 7, pivot<2  - True

    i<j -- True
    swap(i,j)


   low                  high
    6, 2, 3, 5, 8, 1, 4, 7
    0  1  2  3  4  5  6  7
    i                    j

    At i = 1, pivot>=2
    At i = 2, pivot>=3
    At i = 3, pivot>=5
    At i = 4, pivot>=8

    At j = 7, pivot<7
    At j = 6, pivot<4

    i<j -- True
    swap(i,j)

   low                  high
    6, 2, 3, 5, 4, 1, 8, 7
    0  1  2  3  4  5  6  7
    i                    j

    At i = 4, pivot>=4
    At i = 5 pivot>=1
    At i = 6 pivot>=8

    At j = 6, pivot<8
    At j = 5, pivot<1

    i<j -- false

    Swap(pivot,Arr[j])

   low                  high
    1, 2, 3, 5, 4, 6, 8, 7
    0  1  2  3  4  5  6  7
    i                    j


    Ans So on...
*/


int findPivotElement_Position(vector<int>& Arr,int low,int high)
{
    int i = low,j=high;

    while(i<j)
    {

        int pivot = Arr[low];

        while(Arr[i]<=pivot && i<=high-1)
        {
            i++;
        }


        while(Arr[j]>pivot && j>=low+1)
        {
            j--;
        }



        if(i<j)
        {
            swap(Arr[i],Arr[j]);
        }
    }
    if(low>=0 && j>=0)
        swap(Arr[low],Arr[j]);
    return j;
}

// TC --> O(NLogN)
// SC --> O(1)
void QuickSort(vector<int>& Arr,int low,int high)
{
    if(low<high)
    {
        int partion = findPivotElement_Position(Arr,low,high);
        cout << "partion =" << partion << endl;
        QuickSort(Arr,low,partion-1);
        QuickSort(Arr,partion+1,high);
    }

}

void print_1D_v(vector<int>& V)
{
    for(auto d:V)
    {
        cout << d << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> Arr = {9, 7, 3, 5, 8, 1, 4, 2, 6};
    int low = 0,high=Arr.size()-1;
    QuickSort(Arr,low,high);
    cout << "Sorted Array" << endl;
    print_1D_v(Arr);
    return 0;
}
