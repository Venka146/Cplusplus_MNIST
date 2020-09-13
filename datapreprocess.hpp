#pragma once

#include <vector>

std::vector<std::vector<float>> prepare_dataset(std::vector<std::vector<uint8_t>> vec){
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