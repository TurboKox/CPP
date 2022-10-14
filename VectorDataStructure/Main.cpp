#include <iostream>
#include <vector>
#include "Vector.h"

struct Vector3
{
	float x = 0.0f, y = 0.0f, z = 0.0f;
	int* m_MemoryBlock = nullptr;

	Vector3() { m_MemoryBlock = new int[5]; }
	Vector3(float scalar)
		: x(scalar), y(scalar), z(scalar) {
		m_MemoryBlock = new int[5];
	}
	Vector3(float x, float y, float z)
		: x(x), y(y), z(z) {
		m_MemoryBlock = new int[5];
	}

	Vector3(const Vector3& other) = delete;

	Vector3(Vector3&& other) noexcept
		: x(other.x), y(other.y), z(other.z)
	{
		m_MemoryBlock = other.m_MemoryBlock;
		other.m_MemoryBlock = nullptr;
		std::cout << "Move\n";
	}

	~Vector3()
	{
		std::cout << "Destroy\n";
		delete[] m_MemoryBlock;
	}

	Vector3& operator=(const Vector3& other) = delete;

	Vector3& operator=(Vector3&& other) noexcept
	{
		std::cout << "Moved\n";
		x = other.x;
		y = other.y;
		z = other.z;
		m_MemoryBlock = other.m_MemoryBlock;
		other.m_MemoryBlock = nullptr;
		return *this;
	}
};

template<typename T>
void PrintVector(const Vector<T>& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
	{
		std::cout << vector[i] << std::endl;
	}
	std::cout << "----------------------------\n";
}

template<>
void PrintVector(const Vector<Vector3>& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
	{
		std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;
	}
	std::cout << "----------------------------\n";
}

int main()
{
	{
		Vector<Vector3> vector;
		vector.EmplaceBack(1.0f);
		vector.EmplaceBack(2.f, 3.f, 4.f);
		vector.EmplaceBack(4.f, 6.f, 7.f);
		vector.EmplaceBack();
		PrintVector(vector);
		vector.PopBack();
		vector.PopBack();
		PrintVector(vector);
		vector.EmplaceBack(3.f, 4.f, 1.f);
		vector.EmplaceBack(5.f, 6.f, 2.f);
		vector.EmplaceBack(5.f, 6.f, 2.f);
		vector.EmplaceBack(5.f, 6.f, 2.f);
		vector.EmplaceBack(5.f, 6.f, 2.f);
		vector.EmplaceBack(5.f, 6.f, 2.f);
		vector.EmplaceBack(5.f, 6.f, 2.f);
		vector.EmplaceBack(5.f, 6.f, 2.f);
		vector.EmplaceBack(5.f, 6.f, 2.f);
		PrintVector(vector);

		vector.Clear();
		PrintVector(vector);
		vector.EmplaceBack(3.f, 4.f, 1.f);
		vector.EmplaceBack(5.f, 6.f, 2.f);

		PrintVector(vector);
	}

	Vector<int> intVector;
	intVector.PushBack(5);
	intVector.EmplaceBack(2);
	intVector.EmplaceBack(2);
	intVector.EmplaceBack(2);
	intVector.EmplaceBack(2);
	intVector.EmplaceBack(6);
	PrintVector(intVector);
	intVector.PopBack();
	PrintVector(intVector);
	intVector.Clear();
}
