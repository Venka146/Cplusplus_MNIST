#pragma once

#include <vector>

class NeuralNetwork{
  private:
	int input_size;
	int num_classes;
  	float learning_rate;
	std::vector<std::vector<float>> weights;
	std::vector<std::vector<float>> biases;

  public:
	std::vector<int> predict(std::vector<std::vector<float>>);
	void update_weights();
	void train(int, std::vector<std::vector<float>>);
	NeuralNetwork(float lr, int i_size, int n_classes);
};
