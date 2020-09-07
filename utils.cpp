#include "util.h"
#include "model.h"
#include <vector>
#include <iostream>


void printVector(std::vector<unsigned char> vec, bool convertToInt){
	for(int i = 0; i < vec.size(); i++){
		if (convertToInt == true) {
			std::cout << (int) vec[i] << "\t";
		} else {
			std::cout << vec[i] << "\t";
		}
	}
}

void printVector(std::vector<float> vec){
	for(int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << "\t";
	}
}

void printVector(std::vector<int> vec){
	for(int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << "\t";
	}
}

void printVector(std::vector<std::vector<int>> vec){
	for(int i = 0; i < vec.size(); i++){
		for(int j = 0; j < vec[0].size(); j++){
			std::cout << "" << vec[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}


void printVector(std::vector<std::vector<float>> vec){
	for(int i = 0; i < vec.size(); i++){
		for(int j = 0; j < vec[0].size(); j++){
			std::cout << "" << vec[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

// TODO
// float accuracy(NeuralNetwork model, std::vector<std::vector<float>> data, ? labels) {
// 	std::vector<int> pred;
// 	float accuracy;
// 	pred = NeuralNetwork::predict(data);
// 	int num_correct = 0;
// 	for(int i = 0; i < pred.size(); i++){
// 		if(pred[i] == labels[i])
// 			num_correct++;
// 	}
// 	accuracy = num_correct / pred.size();
// 	return accuracy;
// }
