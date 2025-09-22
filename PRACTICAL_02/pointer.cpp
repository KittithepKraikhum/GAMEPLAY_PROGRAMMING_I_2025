#include <iostream>

int main(){
	int a = 10;  //normal variable
	int *p = &a; //a pointer holding address of a
	std::cout<<"The first initial value of a is "<< a <<"\n";
	*p = 30; //assign a new value to a
	std::cout<<"New value of a is "<< a <<"\n";

}//end main
