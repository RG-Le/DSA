#include <bits/stdc++.h>
using namespace std;

/// USING EXTRA SPACE
void mergeArrays(int x[], int y[], int a[], int s, int e) {
	int mid = (s+e)/2;
	int i = s;
	int j = mid + 1;
	int k = s;
	
	while (i <= mid && j <= e) {
		if (x[i] < y[j]) {
			a[k] = x[i];
			i++; k++;
		} else {
			a[k] = y[j];
			j++; k++;
		}
	}
	
	while (i <= mid) {
		a[k] = x[i];
		k++; i++;
	}
	
	while (j <= e) {
		a[k] = y[i];
		k++; j++;
	}	
}

void mergeSort(int a[], int s, int e) {
	if (s >= e) return;
	
	int mid = (s + e)/2;
	int x[100];
	int y[100];
	for (int i = s; i <= mid; i++) {
		x[i] = a[i];
	}
	for (int i = mid + 1; i <= e; i++) {
		y[i] = a[i];
	}
	
	mergeSort(x,s,mid);
	mergeSort(y,mid+1,e);
	mergeArrays(x,y,a,s,e);
}

// USING A SINGLE ARRAY ***BETTER APPROACH
void merge(int *a, int s, int e) {
	int mid = (s+e)/2;
	
	int i = s;
	int j = mid + 1;
	int k = s;
	
	int temp[100];
	
	while (i <= mid && j <= e) {
		if (a[i] < a[j]) {
			temp[k] = a[i];
			k++; i++;
		} else {
			temp[k] = a[j];
			k++; j++;
		}
	}
		while (i <= mid) {
			temp[k] = a[i];
			k++; i++;
		}
		
		while (j <= e) {
			temp[k] = a[j];
			k++; j++;
		}
		
		for (int i = s; i <= e; i++) {
			a[i] = temp[i];
		}
}

void mergeSort2(int a[],int s,int e){
    //Base case - 1 or 0 elements
    if(s>=e){
        return;
    }
    
    //Follow 3 steps
    //1. Divide
    int mid = (s+e)/2;
    
    //Recursively the arrays - s,mid and mid+1,e
    mergeSort2(a,s,mid);
    mergeSort2(a,mid+1,e);
    
    //Merge the two parts
    merge(a,s,e);

}


int main() {
	int a[] = {7,3,1,5,6,2};
	
	for (int i = 0; i < 6; i++) {
		cout << a[i] << " ";
	}
	
	mergeSort2(a,0,5);
	cout << endl;
	
	for (int i = 0; i < 6; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
