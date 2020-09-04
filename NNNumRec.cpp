#include "mnist/mnist_reader_less.hpp"
#include "mnist/mnist_utils.hpp"
#include <vector>
#include <iostream>
#include <typeinfo>

void printVector(std::vector<unsigned char> vec, bool convertToInt){
	for(int i = 0; i < vec.size(); i++){
		if (convertToInt == true) {
			std::cout << (int) vec[i] << "\t";
		} else {
			std::cout << vec[i] << "\t";
		}
	}
}

void printVectorf(std::vector<float> vec){
	for(int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << "\t";
	}
}

void print2DVector(std::vector<std::vector<int>> vec){
	for(int i = 0; i < vec.size(); i++){
		for(int j = 0; j < vec[0].size(); j++){
			std::cout << "" << vec[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}
 
// check if pointer was used correctly
std::vector<std::vector<float>> prepare_dataset(std::vector<std::vector<unsigned char>> &vec){
	std::vector<std::vector<float>> processed_dataset;
	for (int i = 0; i < vec.size(); i++) {
		std::vector<float> vect;
		for(int j = 0; j < vec[0].size(); j++){
			vect.push_back(((int) vec[i][j]) / 255.0);
		}
		processed_dataset.push_back(vect);
	}
	return processed_dataset;
}
 
// Any matrix multiplication;
// Change the int to float

std::vector<std::vector<int>> matmul(std::vector<std::vector<int>> vecA, std::vector<std::vector<int>> vecB){
	if(vecA[0].size() != vecB.size())
		throw std::runtime_error("Invalid matrix dimensions!");
	
	std::vector<std::vector<int>> prod (vecA.size(), std::vector<int>(vecB[0].size()));
	for(int r = 0; r < vecA.size(); r++){
		for(int c = 0; c < vecA.size(); c++){
			prod[r][c] = 0;
		}
	}
	for(int r = 0; r < vecA.size(); r++){
		for(int c = 0; c < vecB[0].size(); c++){
			for (int k = 0; k < vecA[0].size(); k++){
				prod[r][c] += vecA[r][k] * vecB[k][c];
			}
		}
	}
	return prod;
}

// TODO want to separate into multiple files
// math.cpp -> stores matmul and other math functions
// datapreprocess.cpp -> preprocessing of datasets
// utils.cpp -> print functionality
// unit_test.cpp -> write test cases for matmul, etc
	// bool validMatmul() { // verfiy matmul works as expected }

int main()
{
	// 1) learn how to use the vector datatype in C++ -- Done
	// 2) learn the back propogation technique (DL)
	// 3) Apply your knowledge and get a NN working!
	auto dataset = mnist::read_dataset<uint8_t, uint8_t>();
	// binarize_dataset(dataset);
	auto train_data = dataset.training_images;
	auto test_data = dataset.test_images;
	auto train_labels = dataset.training_labels;
	auto test_labels  = dataset.test_labels;
	//std::cout << typeid(train_data).name();
	//printVector(test_labels, true);
	// << " " << dataset[0].size();
	std::vector<std::vector<float>> p_train_data = prepare_dataset(train_data);
	printVectorf(p_train_data[0]);
	/*
	std::vector<std::vector<int>> a (2, std::vector<int>(2));
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;
	std::vector<std::vector<int>> b (3, std::vector<int>(2));
	b[0][0] = 5;
	b[0][1] = 6;
	b[2][0] = 1;
	b[1][0] = 7;
	b[1][1] = 8;
	b[2][1] = 1;
	
	// Check if you can assign vectors like so.
	std::vector<std::vector<int>> c;
	try {
		c = matmul(a, b);
	}
	catch (std::exception &e) {
		std::cout<<"Caught exception: "<<e.what()<<"\n";
	}
	print2DVector(c);
	*/
	
	
	//printVector(train_data, false);
	std::cout << "Success!";
}




