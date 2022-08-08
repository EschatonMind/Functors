#include <iostream>
using namespace std;

struct Test {

	virtual bool operator()(string& text) = 0;

	virtual ~Test(){};
};
//functor
struct matchtest : public Test {
	// looks like a function ( overloaded function ) but is not one
	virtual bool operator()(string& text) {

		return text.size() >= 3;
	}

};

void check(string text, Test& test) {

	if (test(text)) {
		cout << " Match found " << endl;
	}
	else {
		cout << " No match found " << endl;
	}
}

int main() {

	matchtest M1;
	string value = "Hi";
	check(value, M1);
	return 0;
}