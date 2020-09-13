#pragma once

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
	auto soft = softmax(prod);
	auto ans = argmax(soft);
	return ans;
}

void NeuralNetwork::train(int epochs, std::vector<std::vector<float>> dataset, std::vector<uint8_t> labels) {
	// TODO shuffle 2D dataset (syncronoushly with labels) every epoch
	for (int i = 0; i < epochs; i++) {
		std::cout << "Episode " << i << " Running" << std::endl;
		for (int j = 0; j < dataset.size(); j++) {
			std::cout << "On image " << j << std::endl;
			std::vector<std::vector<float>> temp;
			temp.push_back(dataset[j]);
			auto prod = matmul(temp, weights);
			auto soft = softmax(prod);
			soft[0][labels[j]] -= 1;
			
			auto deltaW = matmul(transpose(temp), soft);
			auto scaled_deltaW = matmul(deltaW, learning_rate);
			weights = matsub(weights, scaled_deltaW);
		}
	}
}

std::vector<std::vector<float>> NeuralNetwork::get_weights() {
	return weights;
}
