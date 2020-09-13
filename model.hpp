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
	void update_weights();
	void train(int epochs, std::vector<std::vector<float>> dataset);
};

NeuralNetwork::NeuralNetwork(float lr, int i_size, int n_classes) {
	learning_rate = lr;
	input_size = i_size;
	num_classes = n_classes;
	srand( (unsigned)time( NULL ) );
	
	std::vector<std::vector<float>> init_weights (i_size, std::vector<float>(n_classes));
	for (int i = 0; i < i_size; i++){
		for (int j = 0; j < n_classes; j++){
			init_weights[i][j] = (float) rand()/RAND_MAX; // TODO verify between 0 and 1, not at 0 or 1
		}
	}
	weights = init_weights;
	
	std::vector<std::vector<float>> init_biases (1, std::vector<float>(n_classes));
	for (int j = 0; j < n_classes; j++){
			init_biases[0][j] = (float) rand()/RAND_MAX;
	}
	biases = init_biases;	
	
	// TODO initialize weights vector (i_size by n_classes matrix) with random numbers from 0 to 1)
	// TODO initialize biases vector (1 by n_classes matrix) wirh random numbers from 0 to 1)
	// one image:(1 x 784) matmul weights (784 x 10) -> (1 x 10) + bias (1 x 10) = (1 x 10)
	// result (1x10) -> softmax -> (1 x 10) -> pick index with highest value -> that's the prediction
	
	// backprop -> TODO to be explained last
}

std::vector<int> NeuralNetwork::predict(std::vector<std::vector<float>> dataset){
	// TODO
	std::vector<int> ans;
	std::vector<std::vector<float>> prod;
	std::vector<std::vector<float>> sum;
	std::vector<std::vector<float>> soft;
	std::cout << "start matmul" << std::endl;
	prod = matmul(dataset, weights); // (60,000 x 784) x (784 x 10) -> (60,000 x 10)
	// sum = matadd(prod, biases);
	// TODO support bias
	std::cout << "start softmax" << std::endl;
	soft = softmax(prod);
	std::cout << "start argmax" << std::endl;
	ans = argmax(soft);
	return ans;
}

void NeuralNetwork::update_weights() {
	// TODO last thing to do
}

void NeuralNetwork::train(int epochs, std::vector<std::vector<float>> dataset) {
	// TODO how to shuffle a 2D matrix (know how to do this)
}
