#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char* T1 = "/home/";			// "/home"
const char* T2 = "/a/./b/../../c/";	// "/c"
const char* T3 = "/../";			// "/"
const char* T4 = "/home//foo/";		// "/home/foo"

int IsSlash(const char* pc) {
	if (pc == NULL) return 0;
	if (*pc == '/') return 1;
	return 0;
}

int IsDot(const char* pc) {
	if (pc == NULL) return 0;
	if (*pc == '.') return 1;
	return 0;
}

void ResetVector(vector<char>& v) {
	if (v.size() <= 1) return;
	while (v.size() > 1) {
		v.pop_back();
	}
}

void PrintResult(vector<char>& v) {
	int vector_size = v.size();
	if (vector_size <= 0) {
		cout << "Nothing" << endl;
		return;
	}
	if (vector_size > 1 && IsSlash(&v[vector_size-1])) {
		v.pop_back();
	}
	vector<char>::iterator iter;
	for (iter=v.begin(); iter!=v.end(); ++iter) {
		cout << *iter;
	}
	cout << endl;
	return;
}

int TEST(const char* test_path) {
	int ret = -1;
	vector<char> result;
	int current_slash_num = 0;

	while (*test_path) {
		if (IsSlash(test_path)) break;
		++test_path;
	}
	while (*test_path) {
		if (IsSlash(test_path)) {
			if (current_slash_num == 0) {
				result.push_back(*test_path);
				++current_slash_num;
				++test_path;
			} else {
				++test_path;
			}
		} else if (IsDot(test_path)) {
			vector<char>& rv = result;
			ResetVector(rv);
			++test_path;
		} else {
			current_slash_num = 0;
			result.push_back(*test_path);
			++test_path;
		}
	}
	PrintResult(result);
	return ret;
}

int main() {
	TEST(T1);
	TEST(T2);
	TEST(T3);
	TEST(T4);
	return 0;
}
