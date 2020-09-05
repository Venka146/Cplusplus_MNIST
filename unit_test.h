#include <vector>
#include <iostream>
#include "math.h"
#include "utils.h"

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
	
	std::vector<std::vector<float>> c (3, std::vector<float>(2));
	c[0][0] = 16;
	c[0][1] = 19;
	c[1][0] = 41;
	c[1][1] = 48;
	c[2][0] = 29;
	c[2][1] = 35;
	
	std::cout << "a x b output";
	std::vector<std::vector<float>> d (3, std::vector<float>(2));
	d = matmul(a, b);
	print2DVectorf(d);
	
	std::cout << "Correct answer verified by SOCK!";
	print2DVectorf(c);
	
	bool sock;
	for(int i = 0; i < c.size(); i++)
		for(int j = 0; j < c[0].size(); j++)
			if(d[i][j] != c[i][j])
				sock = false;
		
	return sock;
}

