#include <iostream>
#include <string>

int main()
{
	int arr[26] = { 0, };
	std::string word;

	std::cin >> word;

	for (int i = 0; i<int(word.length()); i++) {
		arr[word[i] - 'a'] += 1;
	}

	for (int i = 0; i < 26; i++) {
		std::cout << arr[i] << " ";
	}

	return 0;
}