#include "ItemBase.h"
#include <iostream>

bool compareItemsByPrice(const ItemBase& left, const ItemBase& right) {
	return  left.GetPrice() < right.GetPrice();
}

uint32_t ItemBase::GetPrice() const {
	return price_;
}

std::string ItemBase::GetName() const {
	return name_;
}

void ItemBase::SetPrice(uint32_t price) {
	this->price_ = price;
}

void ItemBase::SetName(std::string name) {
	this->name_ = name;
}

void ItemBase::PrintInfo() const {
	std::cout << typeid(this).name() << " [ name : " << name_ << " , price : " << price_ << " ]" << std::endl;
}
