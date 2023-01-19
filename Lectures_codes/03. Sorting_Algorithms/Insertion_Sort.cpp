#include <iostream>
using namespace std;

void InsertionSort(int list[], int size)
{
    int i, j, item;
    for (i = 1; i < size; i++)
    {
        item = list[i] ;
        /*  Move elements of list[0..i-1],
            that are greater than item,
            to one position ahead of their current position
        */
        for (j = i-1; (j >= 0) && (list[j] > item); j--)
            list[j + 1] = list[j];
        list[j + 1] = item ;
    }
}

// Main Function
int main(){
    int arr[] = {-45, 89, -65, 87, 0, 3, -23, 19, 56, 21, 76, -50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "before: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    InsertionSort(arr, n);

    cout << "\nafter: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
//end main()

/*
--------------------Output-------------------
before: -45 89 -65 87 0 3 -23 19 56 21 76 -50
after: -65 -50 -45 -23 0 3 19 21 56 76 87 89
*/
