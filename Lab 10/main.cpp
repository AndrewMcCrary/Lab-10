#pragma once
#include "table.h"
#include "part.h"
#include <string>
#include <iostream>
#include <vector>
#include "chainedTable.h"

using namespace std;

int main(void) {

	table<Part> hashtable = table<Part>();

	bool connectionTerminated = false;
	while (!connectionTerminated) {
		std::cout << "Function Testing Menu\n\n [1] AddItem\n [2] GetItem (removes from list)\n [3] IsInList\n [4] IsEmpty\n" <<
			" [5] Size\n [6] SeeNext\n [7] SeePrev\n [8] SeeAt\n [9] Reset\n\n";
		int choice = 0;
		std::cin >> choice;
		bool correct = true;
		switch (choice) {
		case 1:
			while (correct) {
				int sku, quantity, leadTime;
				double price;
				std::string description, units;

				std::cout << "\nYou selected [1] AddItem. The following data will need to be provided:\n" <<
					"Stock Keeping Number | Description\n" <<
					"               Price | Unit of Measure\n" <<
					"    Quantity on Hand | Lead Time (hours)\n\n";
				std::cout << "Please provide the following data in order (one entry, no commas): SKU, Price, Quantity, Lead Time\n";
				std::cin >> sku >> price >> quantity >> leadTime;
				std::cout << "\n     SKU: " << sku << "\n   Price: " << price << "\nQuantity: " << quantity;

				std::cout << "\nPlease provide the following data in order (separate entries): Description, Units, Lead Time\n";
				cin.ignore();
				std::getline(std::cin, description);
				std::getline(std::cin, units);
				std::cout << "\nDescription: " << description << "\n      Units: " << units << "\n  Lead Time: " << leadTime;

				std::cout << "\nIs your item correct? [0]: yes / [1]: no | ";
				std::cin >> correct;

				if (!correct) { 
					Part* party = new Part(sku, description, price, units, quantity, leadTime); 
					hashtable.addItem(party);
				}
			}
			break;
		case 2:
			while (correct) {
				int sku;
				std::cout << "\nYou selected [2] GetItem. Please provide a Stock Keeping Number (SKU): ";
				std::cin >> sku;
			
				std::cout << "\nYou entered: " << sku << ". Is this correct? [0]: yes / [1]: no | ";
				std::cin >> correct;
				if (!correct) { 
					if (hashtable.getItem(Part(sku, "0", 0, "0")) == nullptr) {
						std::cout << "\nItem may not be in hash table\n";
					}
					else {
						hashtable.getItem(Part(sku, "0", 0, "0"))->asciiART();
						hashtable.removeItem(*(hashtable.getItem(Part(sku, "0", 0, "0"))));
					}
				}
			}
			break;
		case 3:
			int sku;
			std::cout << "\nYou selected [3] IsInList. Please provide a Stock Keeping Number (SKU): ";
			std::cin >> sku;
			if (hashtable.getItem(Part(sku, 0, 0, 0)) == nullptr) {
				std::cout << sku << " is NOT in list." << endl;
			}
			else {
				std::cout << sku << " is in list." << endl;
			}
			break;
		case 4:
			std::cout << "\nYou selected [4] IsEmpty." << endl;
			if (hashtable.getTheNumberOfThingsForRicky() != 0) {
				std::cout << "List is NOT empty." << endl;
			}
			else {
				std::cout << "List is empty." << endl;
			}
			break;
		case 5:
			std::cout << "\nYou selected [5] Size. | Size is: " << hashtable.getTheNumberOfThingsForRicky() << endl;
			break;
		case 6:
			std::cout << "\nYou selected [6] SeeNext. | \n";
			hashtable.setTheCurrentSpotForRicky(hashtable.getTheCurrentSpotForRicky() + 1);
			hashtable.getTheCurrentItemForRicky()->asciiART();
			break;
		case 7:
			std::cout << "\nYou selected [7] SeePrev. | \n";
			hashtable.setTheCurrentSpotForRicky(hashtable.getTheCurrentSpotForRicky() + 1);
			hashtable.getTheCurrentItemForRicky()->asciiART();
			break;
		case 8:
			int viewIndex;
			std::cout << "\nYou selected [8] SeeAt. Please provide an index to view: ";
			std::cin >> viewIndex;
			hashtable.setTheCurrentSpotForRicky(viewIndex);
			hashtable.getTheCurrentItemForRicky()->asciiART();
			break;
		case 9:
			while (correct) {
				std::cout << "\nYou selected [9] Reset. Are you sure? [0]: yes / [1]: no";
				std::cin >> correct;
				if (!correct) { 
					table<Part> temp = hashtable;
					hashtable = table<Part>();
					delete& temp;
				}
			}
			break;
		default:
			continue;
		};
	
		std::cout << "\nContinue? [0 = yes/1 = no]: ";
		std::cin >> connectionTerminated;
	
	}	

	return 0;
}


int fmain(void) {
	vector<Part*> parts;

	srand(time(NULL));

	for (int i = 0; i < 650; i++) {
		parts.push_back(new Part((rand() % 1000) + 1));
	}
	

	table<Part> t1;
	chainedTable<Part> ct1;
	for (int i = 0; i < 50; i++) {
		t1.addItem(parts[i]);
		ct1.addItem(parts[i]);
	}
	cout << t1.comparisons << "	" << ct1.comparisons << endl;

	table<Part> t2;
	chainedTable<Part> ct2;
	for (int i = 0; i < 150; i++) {
		t1.addItem(parts[i]);
		ct1.addItem(parts[i]);
	}
	cout << t1.comparisons << "	" << ct1.comparisons << endl;

	table<Part> t3;
	chainedTable<Part> ct3;
	for (int i = 0; i < 200; i++) {
		t1.addItem(parts[i]);
		ct1.addItem(parts[i]);
	}
	cout << t1.comparisons << "	" << ct1.comparisons << endl;

	table<Part> t4;
	chainedTable<Part> ct4;
	for (int i = 0; i < 250; i++) {
		t1.addItem(parts[i]);
		ct1.addItem(parts[i]);
	}
	cout << t1.comparisons << "	" << ct1.comparisons << endl;


	for (auto i : parts)
		delete i;

	return 0;
}