#include <iostream>
#include "heap.hpp"
using namespace std;

int main(void) {
	Heap* heap = new Heap();
	char op;
	int input, ind;
	do {
		cout << "Op: ";
		cin >> op;
		switch (op) {
			// case 's':
			// 	cin >> input;
			// 	cout << "Is there " << input << "? " << heap->search(input) << endl;
			// 	break;
			case 'i':
				cin >> input;
				heap->insert(input);
				break;
			// case 'r':
			// 	cin >> input;
			// 	heap->remove(input);
			// 	break;
			case 'p':
				heap->print();
				break;
			case 'x':
				cout << "Exiting" << endl;
				break;
			default:
				cout << "Invalid operation" << endl;
		}
	} while (op != 'x');

	return 0;
}