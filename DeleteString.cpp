#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getString(const string str);

int main() {
	int T;
	string s;
	cin >> T;
	string insertString = "ABC";

	while (T--) {
		cin >> s;

		int max = s.size();
		int min = s.size();

		string result;

		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < insertString.size(); j++) {
				string str = s.substr(0, i + 1) + insertString[j] + s.substr(i + 1);
				int len = str.size();
				//cout << "Before getString: " << str << endl;
				while (len > ((str = getString(str)).size())) {
					//cout << "After getString " << str << endl;
					len = str.size();
					result = str;
				}
				
				if (min > str.size()) {
					min = str.size();
				}
			}
		}
		//cout << min << endl;
		cout << (max + 1) - min << endl;


		/*string result;
		result = getString(s);
		cout << result;*/
	}

	system("PAUSE");
	return 0;
}

string getString(const string str) {
	int len = str.size();
	if (len <= 1) {
		return str;
	}

	vector<char> v;

	for (int i = 0; i < len; i++) {
		if (str[i] == str[i + 1]) {
			while ((i + 1 < len) && (str[i] == str[i + 1])) {
				i++;
			}
		}
		else {
			v.push_back(str[i]);
		}
	}

	return string(v.begin(), v.end());
}
