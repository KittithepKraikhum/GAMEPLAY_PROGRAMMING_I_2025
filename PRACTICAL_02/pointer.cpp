#include <iostream>

int main(){
	int a = 10;  //normal variable
	int *p = &a; //a pointer holding address of a

	std::cout<<"Value of a: "<<*p<<"\n";
	std::cout<<"Address of a: "<<p<<"\n";
	std::cout<<"Pointer p points to "<<&a<<"\n";
	std::cout<<"Value pointed by p: "<<*p<<"\n";
	return 0;

}//end main
