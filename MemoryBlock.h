#pragma once
#include <iostream>
class MemoryBlock
{
private:
	size_t _length;
	int* _data;
public:
	//default constructor
	MemoryBlock() :_length(0), _data(nullptr) {}
	//construct memoryblock by size
	explicit MemoryBlock(size_t length) : _length(length), _data(new int[length])
	{
		std::cout << "In MemoryBlock(size_t).length = "
			<< _length << "." << std::endl;
	}
	//destuctor
	~MemoryBlock() 
	{
		std::cout << "In ~MemoryBlock().length = " 
			<< _length << ".";
		if (_data != nullptr) {
			std::cout << "Delete source";
			delete[]_data;
		}
		std::cout << std::endl;
	}

	//copy intializer
	MemoryBlock(const MemoryBlock& mb) :_length(mb._length), _data(new int[mb._length])
	{
		std::cout << "In MemoryBlock(const MemoryBlock&).length = "
			<< _length << ".copy resource" << std::endl;
		std::copy(mb._data, mb._data + _length, _data);
	}

	//copy operator
	MemoryBlock& operator=(const MemoryBlock& other)
	{
		std::cout << "In &operator=(const MemoryBlock&).length = " 
			<< _length << ".Copy source" << std::endl;
		if (this != &other) {
			//free the exiting resource
			delete[]_data;

			_length = other._length;
			_data = new int[_length];
			std::copy(other._data, other._data + _length, _data);
		}
		return *this;
	}

	//retrive the lenth of resource
	size_t length() const
	{
		return _length;
	}

	//move initialize
	MemoryBlock(MemoryBlock&& other) :_length(0), _data(nullptr)
	{
		std::cout << "Move initialize" << std::endl;
		//move the length and resource
		_data = other._data;
		_length = other._length;
		//free the other
		other._length = 0;
		other._data = nullptr;
	}

	//move operator=
	MemoryBlock& operator=(MemoryBlock&& other)
	{
		if (this != &other) {
			std::cout << "Move operator=" <<std::endl;
			//free resource
			delete[]_data;
			//move the length and resource
			_length = other._length;
			_data = other._data;
			//empty other
			other._length = 0;
			other._data = nullptr;
		}
		return *this;
	}
};