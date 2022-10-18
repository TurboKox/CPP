#include <iostream>
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
	Vector<std::string> values;
	values.EmplaceBack("1");
	values.EmplaceBack("2");
	values.EmplaceBack("3");
	values.EmplaceBack("Szymon");
	values.EmplaceBack("4");
	values.EmplaceBack("5");

	std::cout << "Not using iterators:\n";
	for (int i = 0; i < values.Size(); i++)
	{
		std::cout << values[i] << std::endl;
	}

	std::cout << "Ranged-based for loop:\n";
	for (auto& value : values)
	{
		std::cout << value << std::endl;
	}

	std::cout << "Iterator:\n";
	for (Vector<std::string>::Iterator it = values.begin(); it != values.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}
