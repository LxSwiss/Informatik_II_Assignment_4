#include <iostream>
#include <stdlib.h>

#define LENGTH 10
class Sort
{
public:
  void insertionSort (int arr[], int length);
  void quickSort (int arr[], int left, int right);
private:
  int partition (int a[], int left, int right);
  void exchange (int a[], int i, int j);
};

void
Sort::insertionSort (int arr[], int length)
{
	int temp;
	if(length==0){
		return;
	}
	for(int i=1; i<=length; i++){
		for(int j=0; j<i; j++){
			if(arr[i]< arr[j]){
				temp = arr[i];
				for(int k=i; k>j; k--){
					arr[k]= arr[k-1];
				}
				arr[j] = temp;
			}
		}
	}
}

void
Sort::quickSort (int a[], int left, int right)
{
	if(right-left<=0){
		return;
	}

	int temp;
	int j = 0;
	int randvar = (rand() % (right-left)) +left;

	temp = a[right];
	a[right]= a[randvar];
	a[randvar] = temp;

	for(int i = left ; i<=right; i++){
		if(a[i]<=a[right]){
			temp= a[left+j];
			a[left+j]= a[i];
			a[i]=temp;
			j++;
		}
	}


	quickSort(a, left, left+j-2);


	quickSort(a, left+j, right);

}

int
main (int argc, char *const argv[])
{

  std::cout << "Enter the " << LENGTH << " elements of the array" << std::
    endl;
  int arr[LENGTH];
  for (int i = 0; i < LENGTH; i++)
    {
      //std::cin >> arr[i];
	  arr[i] = rand() % 100;
    }
  Sort Object;
  // Each of the following should work
  Object.insertionSort (arr, LENGTH);
  Object.quickSort (arr, 0, LENGTH-1);

  std::cout << "Sorted list:" << std::endl;
  for (int i = 0; i < LENGTH; i++)
    {
      std::cout << arr[i] << std::endl;
    }

  return 0;
}

