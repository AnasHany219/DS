#include <iostream>
using namespace std;

// Yield location of smallest element in x[k .. size-1];

int FindMinLoc (int x[ ], int k, int size)
{
    int pos;      // x[pos] is the smallest element found so far
	pos = k;
	for (int j = k + 1; j < size; j++)
		if (x[j] < x[pos])
			pos = j;
	return pos;
}
// The main sorting function
// Sort x[0..size-1] in non-decreasing order

int SelectionSort (int x[], int size)
{  
    int k, m;
	for (k = 0; k < size - 1; k++)
    {
        m = FindMinLoc(x, k, size);
		int temp = x[k];
		x[k] = x[m];
		x[m] = temp;
	}
}

// Main Function
int main(){
    int arr[] = {3, 12, -5, 6, 142, 21, -17, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "before: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    SelectionSort(arr, n);

    cout << "\nafter: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
//end main()

/*
-------------Output------------
before: 3 12 -5 6 142 21 -17 45
after: -17 -5 3 6 12 21 45 142
*/
