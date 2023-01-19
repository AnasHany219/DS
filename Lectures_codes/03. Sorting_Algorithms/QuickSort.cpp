#include <iostream>
using namespace std;

int partition( int a[], int l, int r)
{
    int t;
    int pivot = a[l];
    int i = l;
    int j = r + 1;
    while(true) {
        do{
            ++i;
        }while(a[i] <= pivot && i <= r);
        do{
            --j;
        } while(a[j] > pivot);
        if(i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    t = a[l];
    a[l] = a[j];
    a[j] = t;
    return j;
}

void QuickSort(int a[], int l, int r)
{
   int j;
   if(l < r) {  // divide and conquer
       j = partition(a, l, r);

       QuickSort(a, l, j-1);

       QuickSort(a, j+1, r);
   }
}

// Main Function
int main(){
    int arr[] = {7, 12, 1, -2, 0, 15, 4, 11, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "before: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    QuickSort(arr, 0, n-1);

    cout << "\nafter: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
//end main()

/*
------------Output-----------
before: 7 12 1 -2 0 15 4 11 9
after: -2 0 1 4 7 9 11 12 15
*/
