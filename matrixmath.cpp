#include "matrixmath.h"
#include <math.h>
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

std::vector<std::vector<float>> matadd(std::vector<std::vector<float>> vecA, std::vector<std::vector<float>> vecB){
	if(vecA.size() != vecB.size() || vecA[0].size() != vecB[0].size())
		throw std::runtime_error("Invalid matrix dimensions!");
	
	std::vector<std::vector<float>> sum (vecA.size(), std::vector<float>(vecB[0].size()));
	for(int r = 0; r < vecA.size(); r++){
		for(int c = 0; c < vecA[0].size(); c++){
			sum[r][c] = vecA[r][c] + vecB[r][c];
		}
	}
	
	return sum;
}

std::vector<std::vector<float>> matsub(std::vector<std::vector<float>> vecA, std::vector<std::vector<float>> vecB){
	if(vecA.size() != vecB.size() || vecA[0].size() != vecB[0].size())
		throw std::runtime_error("Invalid matrix dimensions!");
	
	std::vector<std::vector<float>> dif (vecA.size(), std::vector<float>(vecB[0].size()));
	for(int r = 0; r < vecA.size(); r++){
		for(int c = 0; c < vecA[0].size(); c++){
			dif[r][c] = vecA[r][c] - vecB[r][c];
		}
	}
	
	return dif;
}

std::vector<std::vector<float>> matadd(std::vector<std::vector<float>> vecA, float cons){
	std::vector<std::vector<float>> sum (vecA.size(), std::vector<float>(vecA[0].size()));
	for(int r = 0; r < vecA.size(); r++){
		for(int c = 0; c < vecA[0].size(); c++){
			sum[r][c] = vecA[r][c] + cons;
		}
	}
	
	return sum;
}

std::vector<std::vector<float>> matmul(std::vector<std::vector<float>> vecA, float cons){
	std::vector<std::vector<float>> prod (vecA.size(), std::vector<float>(vecA[0].size()));
	for(int r = 0; r < vecA.size(); r++){
		for(int c = 0; c < vecA[0].size(); c++){
			prod[r][c] = vecA[r][c] * cons;
		}
	}
	
	return prod;
}

std::vector<std::vector<float>> softmax(std::vector<std::vector<float>> result) {
	std::vector<std::vector<float>> pred_vec (result.size(), std::vector<float>(result[0].size()));
	std::vector<float> sum (result.size());
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[0].size(); j++){
			pred_vec[i][j] = exp(result[i][j]);
			sum[i] += pred_vec[i][j];
		}
	}
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[0].size(); j++){
			pred_vec[i][j] = pred_vec[i][j] / sum[i];
		}
	}
	return pred_vec;
}

std::vector<int> argmax(std::vector<std::vector<float>> result) {
	std::vector<int> index (result.size());
	float max;
	for(int i = 0; i < result.size(); i++){
		max = -1;
		for(int j = 0; j < result[0].size(); j++){
			if(max < result[i][j]){
				max = result[i][j];
				index[i] = j;
			}
		}
	}
	return index;
}

