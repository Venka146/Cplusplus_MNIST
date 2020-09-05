// matrix of weights
// matrix of biases
// learning rate (float)
// predict()
// update_weights()
// train(epochs)

class model{
	std::vector<std::vector<float>> weights;
	std::vector<std::vector<float>> biases;
  public:
	float learning_rate();
	void predict();
	void update_weights();
	void train (auto epochs);	
}




