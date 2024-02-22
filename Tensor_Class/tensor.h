#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

class tensor
{
private:
	std::string name;// ��� ������� ������
	int size_x;
	int size_y;      // ������ �������
	float** matrix;  // ��������� ������������ ������
	size_t& count(); // ������� ��������
	int rand_seed = 1;

public:
	tensor(int size_x, int size_y, std::string name, char mode);
	tensor(int size_x, int size_y, std::string name); // ����������� � ��������� �������
	tensor(const tensor& copied_obj);   // ����������� �����������
	~tensor();                          // ����������
	void print();                       // ����� �� �������
	void set_object_of_matrix(int x, int y, float value); // ������ ��� ����������� �������� � �������
	void clear();

	float operator() (unsigned x, unsigned y); // ������ ��� ����������� �������� � �������

	tensor operator+ (const tensor& b) const;
	tensor& operator+= (const tensor& b);

	tensor& operator = (const tensor& b);

	tensor operator- (const tensor& b)const;
	tensor& operator-= (const tensor& b) ;

	tensor operator* (const tensor& b) const;
	tensor& operator*= (const tensor& b);

	tensor operator^ (const float& b) const;
	tensor& operator^= (const float& b);// ��������� ????

	tensor transp(); // ����������������
	tensor abs();    // ������ (�������� �� �����)
	tensor sqrt();//
};