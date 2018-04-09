#include<iostream>

struct Node {
	std::string data;
	struct Node *left, *right;
};

struct Node *newNode(std::string word) {
	struct Node *temp = new Node;
	temp->data = word;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

std::string reportsmallest(struct Node *node) {
	struct Node *curr = node;

	while (curr->left != NULL) {
		curr = curr->left;
	}
	
	return curr->data;
}


struct Node *forgetsmallest(struct Node *node, std::string s1) {
	if (node == NULL) 
		return node;
	
	if (s1 < node->data)
		node->left = forgetsmallest(node->left, s1);

	else if (s1 > node->data)
		node->right = forgetsmallest(node->right, s1);

	else {
		
		if (node->right == NULL) {
			struct Node *temp = node->left;
			delete node;
			return temp;
		}
		else if (node->left == NULL) {
			struct Node *temp = node->right;
			delete node;
			return temp;
		}
		
		else{
		std::string s2 =  reportsmallest(node->right);
		node->data = s2;

		node->right = forgetsmallest(node->right, s2);
	
		}
	}
	return node;
}

struct Node *learn(struct Node *node, std::string word) {
	

	if (node == NULL) return newNode(word);

	std::string temp = node->data;
	if (word < node->data)
		node->left = learn(node->left, word);

	else if (word > temp)
		node->right = learn(node->right, word);
	
	return node;
}

int main() {
	int n,i;
	std::string temp1,temp2;
	struct Node *root= new Node;
	root = NULL;
	std::cin >> n;

	for (i = 0; i < n; i++) {
		std::cin >> temp1;

		if (temp1 == "learn") {
			std::cin >> temp2;
			root = learn(root, temp2);
		}
		else if (temp1 == "reportsmallest") {
			std::cout<< reportsmallest(root) << "\n";
		}
		
		else if (temp1 == "forgetsmallest") {
			std::string s1 = reportsmallest(root);
			std::cout << s1 << "\n" ;
			root = forgetsmallest(root,s1);
		}
		else {
			std::cout << "Invalid Input";
		}
		
	}
}