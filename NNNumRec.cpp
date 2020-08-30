#include "mnist/mnist_reader.hpp"


int main()
{
	auto dataset = mnist::read_dataset<std::vector, std::vector, uint8_t, uint8_t>();
	std::cout << "Success!";
}