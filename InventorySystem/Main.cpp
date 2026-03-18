#pragma once
#include <iostream>
#include <iomanip>
#include "Inventory.h"

class TestItem : public ItemBase {
public:
	TestItem() : ItemBase("TestItem", 0) {}
	TestItem(std::string name) : ItemBase(name, 0) {}
	TestItem(std::string name, uint32_t price) : ItemBase(name, price) {}

	virtual ~TestItem() {
	}

	void PrintInfo() const override {
		std::cout << "[이름: " << name_ << ", 가격: " << std::setw(4) << price_ << "G]" << std::endl;
	}
};

int main() {
	TestItem item01 = TestItem("빨강 포션", 50);
	TestItem item02 = TestItem("주황 포션", 110);
	TestItem item03 = TestItem("파란 포션", 40);
	TestItem item04 = TestItem("하양 포션", 170);

	// 인벤토리 생성
	Inventory<TestItem> inventory = Inventory<TestItem>({item01, item02});

	// 출력 테스트
	inventory.PrintAllItems();

	// 아이템 추가 테스트
	inventory.AddItem(item03);
	inventory.AddItem(item04);
	inventory.PrintAllItems();

	// 복사 테스트
	Inventory<TestItem> cpy = Inventory<TestItem>(inventory);
	inventory.AddItem(TestItem("파워엘릭서", 8192));
	cpy.PrintAllItems();

	// 정렬 테스트
	inventory.SortItems();
	inventory.PrintAllItems();
	return 0;
}