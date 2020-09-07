<<<<<<< HEAD:math.h
// Need a try catch when using.
#include <vector>

=======
>>>>>>> 37ef928fc14dab3ba7868abf963b0a3ab4ba9a41:matrixmath.h
std::vector<std::vector<float>> matmul(std::vector<std::vector<float>> vecA, std::vector<std::vector<float>> vecB);

std::vector<std::vector<float>> softmax(std::vector<std::vector<float>> result);

std::vector<int> argmax(std::vector<std::vector<float>> result);

std::vector<std::vector<float>> matadd(std::vector<std::vector<float>> vecA, std::vector<std::vector<float>> vecB);

std::vector<std::vector<float>> matsub(std::vector<std::vector<float>> vecA, std::vector<std::vector<float>> vecB);

std::vector<std::vector<float>> matadd(std::vector<std::vector<float>> vecA, float cons);

std::vector<std::vector<float>> matmul(std::vector<std::vector<float>> vecA, float cons);