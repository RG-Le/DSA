#include <iostream>
using namespace std;

void swap(int a[] , int pos1, int pos2){
	int temp;
	temp = a[pos1];
	a[pos1] = a[pos2];
	a[pos2] = temp;
}

int partition(int a[], int low, int high, int pivot){
	int i = low;
	int j = low;
	while( i <= high){
		if(a[i] > pivot){
			i++;
		}
		else{
			swap(a,i,j);
			i++;
			j++;
		}
	}
	return j-1;
}

void quickSort(int a[], int low, int high){
	if(low < high){
		int pivot = a[high];
		int pos = partition(a, low, high, pivot);
	
		quickSort(a, low, pos-1);
		quickSort(a, pos+1, high);
	}
}

int main() {
	int n ;
	cin>>n;
	int a[n];
	
	for( int i = 0 ; i < n; i++){
		cin>> a[i];
	}
	
	quickSort(a, 0 , n-1);
	
	for( int i = 0 ; i < n; i++){
		cout<< a[i] << " ";
	}
	return 0;
}
