#pragma once

//#include "utils.hpp"
#include "matrixmath.hpp"
#include <time.h>
#include <ctime>
#include <cstdlib>

class NeuralNetwork{
  private:
	int input_size;
	int num_classes;
  	float learning_rate;
	std::vector<std::vector<float>> weights;
	std::vector<std::vector<float>> biases;

  public:
	NeuralNetwork(float lr, int i_size, int n_classes);
	std::vector<int> predict(std::vector<std::vector<float>> dataset);
	std::vector<std::vector<float>> get_weights();
	std::vector<std::vector<float>> get_biases();
	void update_weights();
	void train(int epochs, std::vector<std::vector<float>> dataset, std::vector<uint8_t> labels);
};

NeuralNetwork::NeuralNetwork(float lr, int i_size, int n_classes) {
	learning_rate = lr;
	input_size = i_size;
	num_classes = n_classes;
	srand( (unsigned)time( NULL ) );
	
	std::vector<std::vector<float>> init_weights (i_size, std::vector<float>(n_classes));
	for (int i = 0; i < i_size; i++){
		for (int j = 0; j < n_classes; j++){
			init_weights[i][j] = ((float) rand() / (RAND_MAX));
		}
	}
	weights = init_weights;
	
	std::vector<std::vector<float>> init_biases (1, std::vector<float>(n_classes));
	for (int j = 0; j < n_classes; j++){
		init_biases[0][j] = ((float) rand() / (RAND_MAX));
	}
	biases = init_biases;
}

std::vector<int> NeuralNetwork::predict(std::vector<std::vector<float>> dataset){
	auto prod = matmul(dataset, weights);
	
	auto sum = matadd_bias(prod, biases); // (60,000 x 10) + (1 x 10) = 
	
	auto soft = softmax(sum);
	
	auto ans = argmax(soft);
	
	return ans;
}

// multiple dataset with weights
// add biases to each row
// find max_val of each row
// subtract max_val of each row by the row
// run softmax
// for each row do the gradient step
// sum the gradient for each row and then average it
// adjust the weights
// add each row to each other than divide total# of rows for biases
// 

void NeuralNetwork::train(int epochs, std::vector<std::vector<float>> dataset, std::vector<uint8_t> labels) {
	// TODO shuffle 2D dataset (syncronoushly with labels) every epoch
	std::vector<std::vector<float>> temp;
	for (int i = 0; i < epochs; i++) {
		std::cout << "Episode " << i << " Running" << std::endl;
		for (int j = 0; j < dataset.size(); j++) {
			std::cout << "On image " << j << std::endl;
			temp.clear();
			temp.push_back(dataset[j]); // 1 x 784
			auto prod = matmul(temp, weights); // (1x784) x (784x10) = (1x10)
			auto sum = matadd(prod, biases);
			auto max_val = max(sum);
			sum = matsub(sum, max_val);
			auto soft = softmax(sum);
			
			soft[0][unsigned(labels[j])] -= 1;
			auto deltaW = matmul(transpose(temp), soft); // (784 x 1) x (1 x 10) = (784 x 10)
			auto deltaB = soft;
			auto scaled_deltaW = matmul(deltaW, learning_rate);
			auto scaled_deltaB = matmul(deltaB, learning_rate);
			weights = matsub(weights, scaled_deltaW);
			biases = matsub(biases, deltaB);
		}
	}
}

std::vector<std::vector<float>> NeuralNetwork::get_weights() {
	return weights;
}

std::vector<std::vector<float>> NeuralNetwork::get_biases() {
	return biases;
}
