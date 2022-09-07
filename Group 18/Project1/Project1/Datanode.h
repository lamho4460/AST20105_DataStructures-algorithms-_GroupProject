#ifndef DATANODE_H
#define DATANODE_H
#include <string>
#include <iostream>
using namespace std;
class Node {
public:
	string ID;
	string job;
	string email;
	string lastname;
	string firstname;
	string phone;
	string skills;
	string country;

	Node* left;
	Node* right;
	int height;
	int* key;

public:
	Node(string ID, string job, string email, string lastname, string firstname, string phone,
		string skills, string country) {
		this->ID = ID;
		this->job = job;
		this->email = email;
		this->lastname = lastname;
		this->firstname = firstname;
		this->phone = phone;
		this->skills = skills;
		this->country = country;

		key = new int(ID.size());
		for (int i = 0; i < ID.size(); i++) {
			key[i] = ID[i];
		}
		this->left = NULL;
		this->right = NULL;
		this->height = 1;
	}

	int findheight(Node* node) {
		if (node == nullptr) {
			return 0;
		}
		else
		{
			return node->height;
		}
	}

	int max(int x, int y) {
		return (x > y) ? x : y;
	}

	Node* rightrotate(Node* node) {
		Node* newhead = node->left;
		Node* x = newhead->right;

		newhead->right = node;
		node->left = x;

		node->height = max(findheight(node->left), findheight(node->right)) + 1;
		newhead->height = max(findheight(newhead->left), findheight(newhead->right)) + 1;

		return newhead;
	}

	Node* leftrotate(Node* node) {
		Node* newhead = node->right;
		Node* x = newhead->left;

		newhead->left = node;
		node->right = x;

		node->height = max(findheight(node->left), findheight(node->right)) + 1;
		newhead->height = max(findheight(newhead->left), findheight(newhead->right)) + 1;

		return newhead;
	}

	int Balance(Node* node) {
		if (node == NULL)
			return 0;
		return findheight(node->left) - findheight(node->right);
	}

	Node* insert(Node* node, Node* newnode) {
		if (node == NULL)
			return newnode;

		for (int i = 0; node->key[i] = newnode->key[i]; i++) {
			if (newnode->key[i] < node->key[i])
				node->left = insert(node->left, newnode);
			else if (newnode->key[i] > node->key[i])
				node->right = insert(node->right, newnode);
		}
		node->height = 1 + max(findheight(node->left), findheight(node->right));

		if (node->left != nullptr) {
			for (int i = 0; node->left->key[i] = newnode->key[i]; i++) {
				if (Balance(node) > 1 && newnode->key[i] < node->left->key[i])
					return rightrotate(node);
			}
		}

		if (node->right != nullptr) {
			for (int i = 0; node->right->key[i] = newnode->key[i]; i++) {
				if (Balance(node) < -1 && newnode->key[i] > node->right->key[i])
					return leftrotate(node);
			}
		}

		if (node->left != nullptr) {
			for (int i = 0; node->left->key[i] = newnode->key[i]; i++) {
				if (Balance(node) > 1 && newnode->key[i] > node->left->key[i]) {
					node->left = leftrotate(node->left);
					return rightrotate(node);
				}
			}
		}

		if (node->right != nullptr) {
			for (int i = 0; node->right->key[i] = newnode->key[i]; i++) {
				if (Balance(node) < -1 && newnode->key[i] < node->right->key[i]) {
					node->right = rightrotate(node->right);
					return leftrotate(node);
				}
			}
		}
		return node;
	}

	void searchphobe(Node* node, string phone) {
		if (node != NULL) {
			if (node->phone == phone) {
				cout << node->ID << " " << node->job << " " << node->email << " " << node->lastname << " "
					<< node->firstname << " " << node->phone << " " << node->skills << " " << node->country
					<< endl;
				searchphobe(node->left, phone);
				searchphobe(node->right, phone);
			}
		}
	}

	void searchskills(Node* node, string skills) {
		if (node != NULL) {
			if (node->skills == skills) {
				cout << node->ID << " " << node->job << " " << node->email << " " << node->lastname << " "
					<< node->firstname << " " << node->phone << " " << node->skills << " " << node->country
					<< endl;
				searchphobe(node->left, skills);
				searchphobe(node->right, skills);
			}
		}
	}

	void searchjob(Node* node, string job) {
		if (node != NULL) {
			if (node->job == job) {
				cout << node->ID << " " << node->job << " " << node->email << " " << node->lastname << " "
					<< node->firstname << " " << node->phone << " " << node->skills << " " << node->country
					<< endl;
				searchphobe(node->left, job);
				searchphobe(node->right, job);
			}
		}
	}

	void searchcountry(Node* node, string country) {
		if (node != NULL) {
			if (node->country == country) {
				cout << node->ID << " " << node->job << " " << node->email << " " << node->lastname << " "
					<< node->firstname << " " << node->phone << " " << node->skills << " " << node->country
					<< endl;
				searchphobe(node->left, country);
				searchphobe(node->right, country);
			}
		}
	}
};


#endif // !DATANODE_H
