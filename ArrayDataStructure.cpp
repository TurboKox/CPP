#include <iostream>

template<typename Array>
class ArrayIterator
{
public:
	using ValueType = typename Array::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;
public:
	ArrayIterator(PointerType ptr)
		: m_Ptr(ptr) {}

	ArrayIterator& operator++()
	{
		m_Ptr++;
		return *this;
	}

	ArrayIterator& operator++(int)
	{
		ArrayIterator iterator = *this;
		++m_Ptr;
		return iterator;
	}

	ArrayIterator& operator--()
	{
		m_Ptr--;
		return *this;
	}

	ArrayIterator& operator--(int)
	{
		ArrayIterator iterator = *this;
		--m_Ptr;
		return iterator;
	}

	ReferenceType operator[](size_t index)
	{
		return m_Ptr + index;
	}

	ReferenceType operator*()
	{
		return *m_Ptr;
	}
	
	PointerType operator->()
	{
		return m_Ptr;
	}

	bool operator==(const ArrayIterator& other)
	{
		return m_Ptr == other.m_Ptr;
	}

	bool operator!=(const ArrayIterator& other)
	{
		return !(*this == other);
	}

private:
	PointerType m_Ptr;
};

template<typename T, size_t S>
class Array
{
public:
	using Iterator = ArrayIterator<Array<T, S>>;
	using ValueType = T;

	constexpr size_t Size() const { return S; }

	T& operator[](size_t index)
	{
#ifdef DEBUG_MODE
		if (index >= S)
		{
			__debugbreak();
		}
#endif
		return m_Data[index];
	}

	Iterator begin()
	{
		return Iterator(m_Data);
	}

	Iterator end()
	{
		return Iterator(m_Data + S);
	}

	const T& operator[](size_t index) const { return m_Data[index]; }

	T* Data() { return m_Data; }
	const T* Data() const { return m_Data; }

private:
	T m_Data[S];
};

int main()
{
	Array<int, 5> data;

	static_assert(data.Size() < 10, "Size is too large!");

	memset(data.Data(), 0, data.Size() * sizeof(int));

	data[1] = 5;
	data[4] = 8;

	const auto& refData = data;

	std::cout << "Basic for loop: \n";

	for (size_t i = 0; i < data.Size(); i++)
	{
		std::cout << "[" << i << "] = " << refData[i] << std::endl;
	}

	std::cout << "Range-based for loop\n";

	for (auto& i : data)
	{
		std::cout << i << std::endl;
	}

	std::cout << "Iterator for loop: \n";

	for (Array<int, 5>::Iterator it = data.begin(); it != data.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}
