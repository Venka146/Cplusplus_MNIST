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

std::vector<std::vector<float>> softmax(std::vector<std::vector<float>> result) {
	// TODO make this work for a (60,000 x 784) example (add for loop)
	std::vector<std::vector<float>> pred_vec (result.size()), std::vector<float>(result[0].size());
	std::vector<float> sum (result.size());
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[0].size(); j++){
			pred_vec[i][j] = std::exp(result[i][j]);
			sum[i] += pred_vec[i][j];
		}
	}
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[0].size(); j++){
			pred_vec[i][j] = pred_vec[i][j] / sum[i];
		}
	}
	return pred_vec;
	// 1 x 10 -> [10 30 29 30 184 2 4 50 10 10]
	// [10 30 29 30 184 2 4 50 10 10] -> [e^10/sum, e^30/sum, etc) where sum is the sum of all the e^x in the matrix]
}

std::vector<int> argmax(std::vector<std::vector<float>> result) {
	// TODO (60,000 x 10)
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