#pragma once
#include <string>

class ItemBase {
public:
	ItemBase() : ItemBase("", 0) {}
	ItemBase(std::string name) : ItemBase(name, 0) {}
	ItemBase(std::string name, uint32_t price) : name_(name), price_(price) {}

	virtual uint32_t GetPrice() const;
	virtual std::string GetName()const;

	virtual void SetPrice(uint32_t price);
	virtual void SetName(std::string name);

	virtual void PrintInfo() const;
protected:
	std::string name_;
	uint32_t price_;
};

bool compareItemsByPrice(const ItemBase& left, const ItemBase& right);

