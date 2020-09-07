#include <vector>

class NeuralNetwork{
  public:
	std::vector<std::vector<float>> weights;
	std::vector<std::vector<float>> biases;
	float learning_rate;
	int input_size;
	int num_classes;  
	NeuralNetwork(float lr, int i_size, int n_classes);
	std::vector<int> predict(std::vector<std::vector<float>>);
	
}

//std::vector<int> NeuralNetwork::predict(std::vector<std::vector<float>> dataset);

//void NeuralNetwork::update_weights();

//void NeuralNetwork::train(int epochs, std::vector<std::vector<float>> dataset);