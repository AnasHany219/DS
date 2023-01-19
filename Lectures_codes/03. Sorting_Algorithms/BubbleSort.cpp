#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void BubbleSort(int x[], int n)
{
    for (int i = n - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (x[j] > x[j+1])
                swap(x[j], x[j+1]);
}

// Main Function
int main(){
    int arr[] = {-45, 89, -65, 87, 0, 3, -23, 19, 56, 21, 76, -50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "before: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    BubbleSort(arr, n);

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
