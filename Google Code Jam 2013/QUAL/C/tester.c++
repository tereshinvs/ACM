#include <iostream>

int main() {
	std::cout << 1000 << std::endl;
	for (int q = 0; q < 1000; q++) {
		std::cout << 1 << " 1";
		for (int i = 0; i < 100; i++)
			std::cout << 0;
		std::cout << std::endl;
	}
}