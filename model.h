#include <vector>

class NeuralNetwork{
  private:
	int input_size;
	int num_classes;
  	float learning_rate;
	std::vector<std::vector<float>> weights;
	std::vector<std::vector<float>> biases;
<<<<<<< HEAD
	float learning_rate;
	int input_size;
	int num_classes;  
	NeuralNetwork(float lr, int i_size, int n_classes);
	std::vector<int> predict(std::vector<std::vector<float>>);
	
}

//std::vector<int> NeuralNetwork::predict(std::vector<std::vector<float>> dataset);

//void NeuralNetwork::update_weights();

//void NeuralNetwork::train(int epochs, std::vector<std::vector<float>> dataset);
=======
  public:
	std::vector<int> predict(std::vector<std::vector<float>>);
	void update_weights();
	void train(int, std::vector<std::vector<float>>);
	NeuralNetwork(float lr, int i_size, int n_classes);
};
>>>>>>> 37ef928fc14dab3ba7868abf963b0a3ab4ba9a41
