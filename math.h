#ifndef math_h
#define math_h

#include <vector>
#include <iostream>

// Any matrix multiplication;
// Need a try catch when using.

std::vector<std::vector<float>> matmul(std::vector<std::vector<float>> vecA, std::vector<std::vector<float>> vecB){
	if(vecA[0].size() != vecB.size())
		throw std::runtime_error("Invalid matrix dimensions!");
	
	std::vector<std::vector<float>> prod (vecA.size(), std::vector<float>(vecB[0].size()));
	for(float r = 0; r < vecA.size(); r++){
		for(float c = 0; c < vecA.size(); c++){
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