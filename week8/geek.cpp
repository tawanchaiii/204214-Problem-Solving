#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[250000];
int temp[250000];
int ans=0;

int merge(int left, int mid, int right) {
   	int c = 0;
   	int i = left; 
   	int j = mid; 
   	int k = left;
   	while ((i <= mid - 1) && (j <= right)) {
      	if (arr[i] <= arr[j]){ 
      		temp[k] = arr[i];
      		k++;
      		i++;
      	} 	
		else {
         	temp[k] = arr[j];
         	c += (mid - i);
         	k++;
         	j++;
      	}
   	}
   	while (i <= mid - 1) {
      	temp[k] = arr[i];
      	k++;
      	i++;
    }
   	while (j <= right) {
      	temp[k] = arr[j];
      	k++;
      	j++;
    }
   	for (i=left; i <= right; i++)
      	arr[i] = temp[i]; 
   	return c;
}
int mergeSort(int left, int right){
   	int mid, count = 0;
   	if (right > left) {
      	mid = (right + left)/2;
      	count = mergeSort(left, mid); 
      	count += mergeSort(mid+1, right); 
      	count += merge(left, mid+1, right); 
   }
   return count;
}

main() {
   	int n;
   	cin >> n;
   	for(int i=0;i<n;i++){
		cin >> arr[i];
   	}
   	cout << mergeSort(0,n-1);
}

