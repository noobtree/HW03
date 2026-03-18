#pragma once
#include <iostream>
#include <initializer_list>
#include <algorithm>
#include "ItemBase.h"

template <typename TItem>
class Inventory
{
public:
	Inventory(int capacity = 10) : size_(0) {
		capacity_ = capacity < 0 ? 1 : capacity;
		pItems_ = new TItem[capacity_];
	}
	Inventory(std::initializer_list<TItem> items) : Inventory(items.size()) {
		for (const TItem& item : items) {
			pItems_[size_++] = item;
		}
	}

	Inventory(const Inventory<TItem>& other) : Inventory(other.capacity_) {
		for (; size_ < other.size_; ++size_) {
			pItems_[size_] = other.pItems_[size_];
		}
	}

	virtual ~Inventory() {
		if (pItems_ != nullptr) {
			delete[] pItems_;
			pItems_ = nullptr;
		}
	}

	void AddItem(const TItem& item) {
		//if (size_ < capacity_) {
		//	pItems_[size_++] = item;
		//	return;
		//}
		//std::cout << "인벤토리가 꽉 찼습니다!" << std::endl;

		EnsureCapacity(size_ + 1);

		pItems_[size_++] = item;
		return;
	}
	void RemoveLastItem() {
		if (size_ > 0) {
			--size_;
			return;
		}
		std::cout << "인벤토리가 비어있습니다." << std::endl;
		return;
	}

	void Assign(const Inventory<TItem>& other) {
		if (pItems_ != nullptr) {
			delete[] pItems_;
		}

		this->capacity_ = other.capacity_;
		this->size_ = 0;
		this->pItems_ = new TItem[capacity_];

		for (; size_ < other.size_; ++size_) {
			this->pItems_[size_] = other.pItems_[size_];
		}
	}

	void Resize(int newCapacity) {
		EnsureCapacity(newCapacity);
	}

	void SortItems() {
		std::sort(pItems_, pItems_ + size_, compareItemsByPrice);
	}
	
	void PrintAllItems() {
		std::cout << "----------------------------------------------------------" << std::endl;
		if (size_ > 0) {
			for (int i = 0; i < size_; ++i) {
				pItems_[i].PrintInfo();
			}
		}
		else {
			std::cout << "비어있음" << std::endl;
		}
		std::cout << "----------------------------------------------------------" << std::endl;
		return;
	}

	int GetCapacity()const {
		return capacity_;
	}
	int GetSize() const {
		return size_;
	}

private:
	TItem* pItems_;
	int capacity_;
	int size_;

	void SetCapacity(int value) {
		if (size_ < value) {
			TItem* arr = new TItem[value];

			if (size_ > 0) {
				std::copy(pItems_, pItems_ + size_, arr);
			}

			delete[] pItems_;
			pItems_ = arr;

			capacity_ = value;
		}
		return;
	}

	void EnsureCapacity(int capacity) {
		if (capacity_ < capacity) {
			if (capacity_ == 0) {
				capacity = capacity < 4 ? 4 : capacity;
			}
			else {
				capacity = capacity < 2 * capacity_ ? 2 * capacity_ : capacity;
			}

			SetCapacity(capacity);
		}
		return;
	}
};

