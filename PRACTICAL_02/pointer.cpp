#include <iostream>

int main(){
	int arr[] = {10, 20, 30};
	int size = sizeof(arr)/sizeof(arr[0]);
	int *pArr = arr;
	for(int i = 0; i < size; i++){
	std::cout<<"Element "<<i<<" is: "<< *(pArr+i)<<"\n";
	}//end for
}//end main
