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
	std::vector<std::vector<float>> p_train_data = prepare_dataset(dataset.training_images);
	std::vector<std::vector<float>> p_test_data = prepare_dataset(dataset.test_images);
	
	auto model = NeuralNetwork(0.01, 784, 10);

	// model = Keras()
	// model_layers = {Dense(784), Dense(10)}
	// model.fit(data)
	

	//float acc = accuracy(model, p_test_data, dataset.test_labels);
	//std::cout << "The accuracy of the model data is " << acc << std::endl;

	model.train(1, p_train_data, dataset.training_labels);
	float acc_train = accuracy(model, p_train_data, dataset.training_labels);
	float acc_test = accuracy(model, p_test_data, dataset.test_labels);	
	
	std::cout << "Train acc " << acc_train << std::endl;
	std::cout << "Test acc " << acc_test << std::endl;

	return 0;
}
