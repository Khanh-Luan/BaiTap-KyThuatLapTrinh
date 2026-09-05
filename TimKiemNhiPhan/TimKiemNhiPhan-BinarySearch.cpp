#include <iostream>
using namespace std;

int BinarySearch(int a[], int n, int x)
{
	int left = 0; int right = n - 1; int mid;
	while(left <= right){
		mid = (left + right) / 2;
		
		if (a[mid] == x) return mid;
		
		if (a[mid] < x) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}
       
int main() {
    int a[] = {2, 4, 6, 8, 10};
    int n = sizeof(a)/sizeof(a[0]);
    int x = 8;
    int result = BinarySearch(a,n,x);
    
    if (result != -1) {
    	cout << "Tim thay " << x << " tai vi tri: " << result << endl;}
    else {
    	cout << "Khong tim thay " << x << "trong mang." << endl;}
	return 0; 
}
