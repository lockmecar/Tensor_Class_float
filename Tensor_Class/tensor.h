#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>

union ftoul
{
	float input;
	unsigned output;
};

class Ten2D
{
private:
	std::string name;// ��� ������� ������
	int size_x;
	int size_y;      // ������ �������
	float** matrix;  // ��������� ������������ ������
	size_t& count(); // ������� ��������
	int rand_seed = 1;

public:
	Ten2D(int size_x, int size_y, std::string name, char mode); // ����������� � ����� �������� ('0' - �������� ������, 'r' - �������� ���������)
	Ten2D(int size_x, int size_y, std::string name);            // ����������� � ��������� �������
	Ten2D(const Ten2D& copied_obj);                             // ����������� �����������
	~Ten2D();                                                   // ����������
	void print();                                               // ����� �� �������
	void set_object_of_matrix(int x, int y, float value);       // ������ ��� ����������� �������� � �������
	void clear();

	void ElemFunc(float (*func)(float));       // ������������ ������� ��� ������ ���������

	float operator() (unsigned x, unsigned y); // ������ ��� ����������� �������� � �������

	std::vector<float> matrix_to_vector();

	Ten2D operator+ (const Ten2D& b) const;
	Ten2D& operator+= (const Ten2D& b);

	Ten2D& operator = (const Ten2D& b);

	Ten2D operator- (const Ten2D& b)const;
	Ten2D& operator-= (const Ten2D& b) ;

	Ten2D operator* (const Ten2D& b) const;
	Ten2D& operator*= (const Ten2D& b);

	Ten2D operator^ (const float& b) const;
	Ten2D& operator^= (const float& b);

	Ten2D transp();            // ����������������
	Ten2D abs();               // ������ (�������� �� �����)
	Ten2D sqrt();              // ���������� ������
	void fileout10(std::string NameOfFile);           
	void fileout16(std::string NameOfFile);
};

class Ten3D
{
private:
	std::string name; // ��� ������� ������
	int size_x;
	int size_y;       // ������ �������
	int size_z;
	float*** matrix;  // ���������� ������������ ������
	size_t& count();  // ������� ��������
	int rand_seed = 1;

public:
	Ten3D(int size_x, int size_y, int size_z, std::string name);            // ����������� � ��������� �������
	Ten3D(const Ten3D& copied_obj);                                         // ����������� �����������
	Ten3D(int size_x, int size_y, int size_z, std::string name, char mode); // ����������� � ����� �������� ('0' - �������� ������, 'r' - �������� ���������)
	~Ten3D();

	void print();
	void set_object_of_matrix(int x, int y, int z, float value);
	void clear();

	std::vector<float> matrix_to_vector();

	float operator() (unsigned x, unsigned y, unsigned z);

	Ten3D operator+ (const Ten3D& b) const;
	Ten3D& operator+= (const Ten3D& b);

	Ten3D& operator = (const Ten3D& b);

	Ten3D operator- (const Ten3D& b)const;
	Ten3D& operator-= (const Ten3D& b);

	Ten3D operator* (const Ten3D& b) const;
	Ten3D& operator*= (const Ten3D& b);

	Ten3D operator^ (const float& b) const;
	Ten3D& operator^= (const float& b);

	void fileout10(std::string NameOfFile);
	void fileout16(std::string NameOfFile);

};