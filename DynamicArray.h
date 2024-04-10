#pragma once
#include <stdexcept>

template<typename ElementType>
class DynamicArray {
private:
	ElementType* elems{};
	size_t capacity;
	size_t dim;

	/**
	 * \brief Allocates more space for array
	 */
	void resize() {
		this->capacity *= 2;
		ElementType* temp_array = new ElementType[this->capacity];

		for(size_t i = 0; i < this->dim; ++i) {
			temp_array[i] = elems[i];
		}
		delete[] elems;
		elems = temp_array;
	}
public:
	/**
	 * \brief Constructor
	 */
	DynamicArray(const int& capacity) {
		this->capacity = (capacity <= 0) ? 2 : capacity;
		elems = new ElementType[this->capacity];
		dim = 0;
	}

	DynamicArray() {
		this->capacity = 2;
		elems = new ElementType[this->capacity];
		dim = 0;
	}

	/**
	 * \brief Destructor
	 */
	~DynamicArray() {
		delete[] elems;
	}

	DynamicArray(const DynamicArray<ElementType>& other) {
		this->capacity = other.capacity;
		this->dim = other.dim;
		elems = new ElementType[this->capacity];
		this->elems = other.elems;
	}

	/**
	 * \brief Adds new element at the end of array
	 * \param e element to add
	 */
	void push_back(const ElementType& e) {
		if(this->dim == this->capacity) {
			this->resize();
		}

		this->elems[dim++] = e;
	}

	/**
	 * \brief Returns the size of array
	 * \return size of array
	 */
	size_t size() const noexcept{
		return this->dim;
	}

	/**
	 * \brief Returns element found at given index
	 * \param index index of element to get
	 * \return element found at given index
	 */
	ElementType& at(const int& index) const {
		if(index >= this->dim || index < 0) {
			throw std::out_of_range("Index out of range");
		}
		return this->elems[index];
	}

	void erase(size_t index) {
		if (index >= this->dim) {
			throw std::out_of_range("Index out of range");
		}

		for(size_t i = index; i < this->dim - 1; ++i) {
			this->elems[i] = this->elems[i + 1];
		}

		--this->dim;
	}
};
