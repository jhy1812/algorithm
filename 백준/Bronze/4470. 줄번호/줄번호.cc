#include <iostream>
#include <string>

int main() 
{
	int N; 
    std::string input;
	std::cin >> N;

	for (int i = 0; i <= N; ++i)
	{
		getline(std::cin, input);
        if (i == 0) {
            continue;
        }
		std::cout << i << ". " << input << std::endl;
	}
}