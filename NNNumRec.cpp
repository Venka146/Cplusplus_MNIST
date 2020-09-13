#include "datapreprocess.hpp"
#include "model.hpp"

#include "mnist/mnist_reader_less.hpp"
#include "mnist/mnist_utils.hpp"

#include "utils.hpp"

#include <vector>
#include <iostream>
#include <typeinfo>

int main()
{
	auto dataset = mnist::read_dataset<uint8_t, uint8_t>();
	//std::vector<std::vector<float>> p_train_date = prepare_dataset(dataset.training_images);
	std::vector<std::vector<float>> p_test_data = prepare_dataset(dataset.test_images);
	
	auto model = NeuralNetwork(0.01, 784, 10);

	//float acc = accuracy(model, p_test_data, dataset.test_labels);
	//std::cout << "The accuracy of the model data is " << acc << std::endl;

	model.train(1, p_test_data, dataset.test_labels);
	float acc = accuracy(model, p_test_data, dataset.test_labels);	
	
	std::cout << "The accuracy of the model data is after training " << acc << std::endl;
	std::cout << "Success!";
	return 0;
}
