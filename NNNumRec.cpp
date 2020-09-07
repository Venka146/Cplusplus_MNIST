#pragma

#include "matrixmath.h"
#include "utils.h"
#include "datapreprocess.h"
#include "model.h"
#include "mnist/mnist_reader_less.hpp"
#include "mnist/mnist_utils.hpp"

#include <vector>
#include <iostream>
#include <typeinfo>

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
	std::cout << typeid(train_labels).name();
	//printVector(test_labels, true);
	// << " " << dataset[0].size();
	std::vector<std::vector<float>> p_train_data = prepare_dataset(train_data);
	printVector(p_train_data[0]);
	/*
	std::vector<std::vector<float>> a (2, std::vector<float>(2));
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;
	std::vector<std::vector<float>> b (3, std::vector<float>(2));
	b[0][0] = 5;
	b[0][1] = 6;
	b[2][0] = 1;
	b[1][0] = 7;
	b[1][1] = 8;
	b[2][1] = 1;
	
	// Check if you can assign vectors like so.
	std::vector<std::vector<float>> c;
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




