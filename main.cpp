#include <iostream>

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << A[i] << ", ";
    }
    std::cout << std::endl;
}

void merge(int left[], int right[], int leftSize, int rightSize, int output[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    std::cout<< "arrays: "<<std::endl;
    printArray(left, leftSize);
    printArray(right, rightSize);
    
    while (i < leftSize  && j < rightSize)
    {
        if (left[i] < right[j])
        {
            output[k] = left[i];
            i++;
            k++;
        }
        else
        {
            output[k] = right[j];
            j++;
            k++;
        }
    }
    
    
    while (i < leftSize)
    {
        output[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        output[k] = right[j];
        j++;
        k++;
    }

    std::cout << "merged: \t" ;
    printArray(output, k);
	std::cout << std::endl;
}

void split(int split_arr[], int src[], int split_size)
{
    for (int i = 0; i < split_size; i++)
    {
        split_arr[i] = src[i];
    }
}

void mergeSort(int unsorted[], int size)
{
    
    
    if (size > 1)
    {
        
        // create arrays on heap for left and right halves
        int mid = size / 2;
        int *left_half = new int[mid];
        int *right_half = new int[size - mid];

        // split input array into 2
        split(left_half, unsorted, mid);
        split(right_half, &unsorted[mid], (size - mid) );

        // recursively split until single element
        mergeSort(left_half, mid);
        mergeSort(right_half, size - mid);

        // merge while sorting
        merge(left_half, right_half, mid, size-mid, unsorted);
        
        delete[] left_half;
        delete[] right_half;
        

    }
    

}

int main()
{
    int arr1[3] = {1, 5, 7};
    int arr2[5] = {2, 6, 7, 8, 9};
    int outarr[8];

    int inp_arr[7] = {1, 5, 4, 11, 2, 3, 7};
    int sorted_arr[7];

   // merge(arr1, arr2, 3, 4, outarr);

    printArray(inp_arr, 7);

    mergeSort(inp_arr, 7);
    printArray(inp_arr, 7);

    // memory testing valgring
    int * a = new int;

    delete a;
    



}