#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <random>
#include "table.h"
#include "part.h"
#include "chainedTable.h"

using namespace std;

int fmain(void) {

	table<Part> hashtable = table<Part>();

	bool connectionTerminated = false;
	while (!connectionTerminated) {
		std::cout << "HashTable Function Testing Menu\n\n [1] AddItem\n [2] GetItem (removes from list)\n [3] IsInList\n [4] IsEmpty\n" <<
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
					Part party = Part(sku, description, price, units, quantity, leadTime); 
					hashtable.insert(party);
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
					if (hashtable.get(Part(sku, "0", 0, "0")) == nullptr) {
						std::cout << "\nItem may not be in hash table\n";
					}
					else {
						hashtable.get(Part(sku, "0", 0, "0"))->asciiART();
						hashtable.remove(*(hashtable.get(Part(sku))));
					}
				}
			}
			break;
		case 3:
			int sku;
			std::cout << "\nYou selected [3] IsInList. Please provide a Stock Keeping Number (SKU): ";
			std::cin >> sku;
			if (hashtable.get(Part(sku)) == nullptr) {
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
			hashtable.setTheCurrentSpotForRicky(hashtable.getTheNextSpotForRicky());
			hashtable.getTheCurrentItemForRicky().asciiART();
			break;
		case 7:
			std::cout << "\nYou selected [7] SeePrev. | \n";
			hashtable.setTheCurrentSpotForRicky(hashtable.getThePrevSpotForRicky());
			hashtable.getTheCurrentItemForRicky().asciiART();
			break;
		case 8:
			int viewIndex;
			std::cout << "\nYou selected [8] SeeAt. Please provide an index to view: ";
			std::cin >> viewIndex;
			hashtable.setTheCurrentSpotForRicky(viewIndex);
			hashtable.getTheCurrentItemForRicky().asciiART();
			break;
		case 9:
			while (correct) {
				std::cout << "\nYou selected [9] Reset. Are you sure? [0]: yes / [1]: no";
				std::cin >> correct;
				if (!correct) { 
					table<Part> temp = hashtable;
					hashtable = table<Part>();
				}
			}
			break;
		default:
			continue;
		};
	
		std::cout << "\nContinue? [0 = yes/1 = no]: ";
		std::cin >> connectionTerminated;
	
	}	

	chainedTable<Part> chaintable;

	connectionTerminated = false;
	while (!connectionTerminated) {
		std::cout << "ChainedTable Function Testing Menu\n\n [1] AddItem\n [2] GetItem (removes from list)\n [3] IsInList\n [4] IsEmpty\n" <<
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
					Part party = Part(sku, description, price, units, quantity, leadTime);
					chaintable.insert(party);
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
					if (chaintable.get(Part(sku)) == nullptr) {
						std::cout << "\nItem may not be in hash table\n";
					}
					else {
						chaintable.get(Part(sku))->asciiART();
						chaintable.remove(*(chaintable.get(Part(sku))));
					}
				}
			}
			break;
		case 3:
			int sku;
			std::cout << "\nYou selected [3] IsInList. Please provide a Stock Keeping Number (SKU): ";
			std::cin >> sku;
			if (chaintable.get(Part(sku)) == nullptr) {
				std::cout << sku << " is NOT in list." << endl;
			}
			else {
				std::cout << sku << " is in list." << endl;
			}
			break;
		case 4:
			std::cout << "\nYou selected [4] IsEmpty." << endl;
			if (chaintable.getTheNumberOfThingsForRicky() != 0) {
				std::cout << "List is NOT empty." << endl;
			}
			else {
				std::cout << "List is empty." << endl;
			}
			break;
		case 5:
			std::cout << "\nYou selected [5] Size. | Size is: " << chaintable.getTheNumberOfThingsForRicky() << endl;
			break;
		case 6:
			std::cout << "\nYou selected [6] SeeNext. | \n";
			chaintable.next()->asciiART();
			break;
		case 7:
			std::cout << "\nYou selected [7] SeePrev. | \n";
			chaintable.prev()->asciiART();
			break;
		case 8:
			int viewIndex;
			std::cout << "\nYou selected [8] SeeAt. Please provide an index to view: ";
			std::cin >> viewIndex;
			if (chaintable.peekAt(viewIndex) != nullptr)
				chaintable.peekAt(viewIndex)->asciiART();
			else cout << "No item at that index\n";
			break;
		case 9:
			while (correct) {
				std::cout << "\nYou selected [9] Reset. Are you sure? [0]: yes / [1]: no ";
				std::cin >> correct;
				if (!correct) {
					chaintable = chainedTable<Part>();
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


int main(void) {
	vector<Part> parts;

	// Used uniform int distribution rather than rand
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> dist1000(1, 1000);

	for (int i = 0; i < 650; i++)
		parts.push_back(Part(dist1000(rng)));

	cout << "Table	Chained" << endl;
	table<Part> t1;
	chainedTable<Part> ct1;
	for (int i = 0; i < 50; i++) {
		t1.insert(parts[i]);
		ct1.insert(parts[i]);
	}

	for (int i = 0; i < 50; i++) {
		t1.get(parts[i]);
		ct1.get(parts[i]);
	}
	cout << t1.comparisons << "	" << ct1.comparisons << endl;

	table<Part> t2 = table<Part>(150);
	chainedTable<Part> ct2;
	for (int i = 50; i < 200; i++) {
		t2.insert(parts[i]);
		ct2.insert(parts[i]);
	}

	for (int i = 50; i < 200; i++) {
		t2.get(parts[i]);
		ct2.get(parts[i]);
	}
	cout << t2.comparisons << "	" << ct2.comparisons << endl;

	table<Part> t3 = table<Part>(200);
	chainedTable<Part> ct3;
	for (int i = 200; i < 400; i++) {
		t3.insert(parts[i]);
		ct3.insert(parts[i]);
	}

	for (int i = 200; i < 400; i++) {
		t3.get(parts[i]);
		ct3.get(parts[i]);
	}
	cout << t3.comparisons << "	" << ct3.comparisons << endl;

	table<Part> t4 = table<Part>(250);
	chainedTable<Part> ct4;
	for (int i = 400; i < 650; i++) {
		t4.insert(parts[i]);
		ct4.insert(parts[i]);
	}

	for (int i = 400; i < 650; i++) {
		t4.get(parts[i]);
		ct4.get(parts[i]);
	}
	cout << t4.comparisons << "	" << ct4.comparisons << endl;

	return 0;
}


//int main(void) { // This is an Andrew thing, not a part of the project
//	for (int j = 100; j <= 10000; j += 100) {
//		vector<int> parts;
//
//		// Used uniform int distribution rather than rand
//		//random_device dev;
//		//mt19937 rng(dev());
//		//uniform_int_distribution<mt19937::result_type> dist1000(1, 10000);
//		srand(time(NULL));
//		int comparisons = 0;
//		int max = 50;
//		for (int a = 0; a < max; a++) {
//			for (int i = 0; i < j; i++)
//				parts.push_back((rand() % 10000) + 1);
//
//			table<Part> t1 = table<Part>(j);
//			for (int i = 0; i < j; i++) {
//				t1.insert(parts[i]);
//			}
//
//			for (int i = 0; i < j; i++) {
//				t1.get(parts[i]);
//			}
//			comparisons += t1.comparisons;
//			parts.clear();
//		}
//		cout << comparisons / (float)j / (float)max << endl;
//	}
//
//	return 0;
//}