#include <iostream>

template<typename T, size_t S>
class Array
{
public:
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

	const auto& arrayRef = data;

	for (size_t i = 0; i < data.Size(); i++)
	{
		std::cout << "[" << i << "] = " << arrayRef[i] << std::endl;
	}
}
