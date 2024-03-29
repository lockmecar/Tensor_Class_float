#include <iostream>
#include "tensor.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		Ten3D a(3, 3, 3, "a",'r');
		a.fileout10("out10_3d");
		a.fileout16("out16_3d");
	}
	catch(length_error& ex) 
	{
		cout << "Length error: " << ex.what() << endl;
	}

	return 0;
}