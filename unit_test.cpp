#pragma
#include "matrixmath.h"
#include "utils.h"
#include <vector>
#include <iostream>

bool unitTest(){
	std::vector<std::vector<float>> a (3, std::vector<float>(3));
	a[0][0] = 1;
	a[0][1] = 2;
	a[0][2] = -3;
	a[1][0] = 3;
	a[1][1] = 4;
	a[1][2] = -2;
	a[2][0] = 6;
	a[2][1] = 0;
	a[2][2] = -1;
	
	std::vector<std::vector<float>> b (3, std::vector<float>(2));
	b[0][0] = 5;
	b[0][1] = 6;
	b[1][0] = 7;
	b[1][1] = 8;
	b[2][0] = 1;
	b[2][1] = 1;
	
	std::vector<std::vector<float>> ans (3, std::vector<float>(2));
	ans[0][0] = 16;
	ans[0][1] = 19;
	ans[1][0] = 41;
	ans[1][1] = 48;
	ans[2][0] = 29;
	ans[2][1] = 35;
	
	std::cout << "a x b output"  << std::endl;
	std::vector<std::vector<float>> prod;
	
	try {
		prod = matmul(a, b);
	}
	catch (std::exception &e) {
		std::cout<<"Caught exception: "<<e.what()<<"\n";
	}
	
	printVector(prod);
	
	std::cout << "Correct answer verified by SOCK!" << std::endl;
	printVector(ans);
	
	bool check = true;
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[0].size(); j++){
			if(prod[i][j] != ans[i][j]){
				check = false;
			}
		}
	}		
	return check;
}


int main(){
	bool result = unitTest();
	std::cout << result;
	return 0;
}




