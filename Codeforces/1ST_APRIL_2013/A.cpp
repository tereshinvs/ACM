#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> data = {
	"Washington",
	"Adams",
	"Jefferson",
	"Madison",
	"Monroe",
	"Adams",
	"Jackson",
	"Van Buren",
	"Harrison",
	"Tyler",
	"Polk",
	"Taylor",
	"Fillmore",
	"Pierce",
	"Buchanan",
	"Lincoln",
	"Johnson",
	"Grant",
	"Hayes",
	"Garfield",
	"Arthur",
	"Cleveland",
	"Harrison",
	"Cleveland",
	"McKinley",
	"Roosevelt",
	"Taft",
	"Wilson",
	"Harding",
	"Coolidge",
	"Hoover",
	"Roosevelt",
	"Truman",
	"Eisenhower",
	"Kennedy",
	"Johnson",
	"Nixon",
	"Ford",
	"Carter",
	"Reagan"
};

int main() {
	int n;
	cin >> n;
	cout << data[n - 1] << endl;
}