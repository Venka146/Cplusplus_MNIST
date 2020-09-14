#pragma once

#include "model.hpp"
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

float accuracy(NeuralNetwork model, std::vector<std::vector<float>> data, std::vector<uint8_t> labels) {
 	auto pred = model.predict(data);
 	int num_correct = 0;
 	for(int i = 0; i < pred.size(); i++){
 		if(pred[i] == unsigned(labels[i])) {
 			num_correct++;
		}
 	}
 	float accuracy = float(num_correct) / pred.size();
 	return accuracy;
}
