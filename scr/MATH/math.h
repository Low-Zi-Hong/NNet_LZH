#pragma once
#include <iostream>
#include <vector>

namespace MATH
{

	std::vector<std::vector<float>> Matrix_Multiplication(std::vector<std::vector<float>> matrix_A, std::vector<std::vector<float>> matrix_B);

	std::vector<std::vector<float>> Matrix_Addition(std::vector<std::vector<float>> matrix_A, std::vector<std::vector<float>> matrix_B);

	std::vector<std::vector<float>> Transpose_hori_to_vert_matrix(std::vector<float> input);


}