#include <iostream>

int main(){
	int *dynamicArray = new int[5]; //Allocates memory for 5 integers
for(int i = 0; i < 5; i++){
	dynamicArray[i] = i + 1; //Assign values to the array
	std::cout<<dynamicArray[i]<<"\n";
}//end for

delete[] dynamicArray; //Frees the allocated memory

}//end main
