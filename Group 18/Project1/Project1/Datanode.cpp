#include"Datanode.h"
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>

void deletemem(Node* node) {
	Node* curr = node;
	Node* left = NULL;
	Node* right = NULL;
	if (curr != NULL) {
		left = curr->left;
		right = curr->right;
		delete curr;
		deletemem(left);
		deletemem(right);
	}
}

using namespace std;
int main() {
	Node* tree = NULL;
	string data;
	string* array = new string[8];
	string filename;
	cout << "Inpue txt file name: ";
	cin >> filename;
	ifstream file(filename);

	while (!file.good()) {
		cout << "Wrong file name, input again please: ";
		cin >> filename;
		file.open(filename);
	}
	do {
		getline(file, data, '\t');
		for (int i = 0; i < 8; i++) {
			if (i == 0)
				array[i] = data;
			else if (i > 0 && i < 7) {
				getline(file, data, '\t');
				array[i] = data;
			}
			else {
				getline(file, data);
				array[i] = data;
				Node* node = new Node(array[0], array[1], array[2], array[3], array[4], array[5],
					array[6], array[7]);
				tree = tree->insert(tree, node);

			}
		}
		getline(file, data);
	} while (!file.eof());
	cout << tree->ID;
	system("pause");
	deletemem(tree);
	return 0;
}