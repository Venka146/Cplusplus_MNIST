#pragma once

//#include "model.h"
#include <vector>
#include <iostream>

void printVector(std::vector<unsigned char> vec, bool convertToInt);

void printVector(std::vector<float> vec);

void printVector(std::vector<int> vec);

void printVector(std::vector<std::vector<int>> vec);

void printVector(std::vector<std::vector<float>> vec);

//float accuracy(NeuralNetwork model, std::vector<std::vector<float>> data, std::vector<int> labels);