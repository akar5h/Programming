#include<iostream>
#include<vector>

void heapify(std::vector <std::string>A,int i ) {

}

void heapsort(std::vector <std::string>A) {

}
int Search(std::vector <string> A, std::string data) {

}

int Forget(std::vector <string> A, std::string data) {

}
int main() {
	int n;
	std::cin >> n;
	std::string temp1, temp2;
	
	std::vector <string>A;

	for (i = 0; i < n; i++) {
		std::cin >> temp1;
		std::cin >> temp2;

		if (temp1 == "learn") {
			A.push_back(temp2);
			heapsort(A);
		}

		else if (temp1 == "forget") {
			Forget(A, temp2);
		}
		else if (temp1 == "findrank") {
			Search(A, temp2, 0, A.size());
		}
	}
}