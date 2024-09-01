#include <iostream>
#include <vector>

#include "MATH/math.h"

std::vector<std::vector<float>> MATH::Matrix_Multiplication(std::vector<std::vector<float>> matrix_A, std::vector<std::vector<float>> matrix_B)
{
	//this one is the heart of calculation matrix multiplication

	std::vector<std::vector<float>> _buffer;
	/*
		matrix_A x matrix_B
		[	1 2	]	x	[	5 6	]	=	[ans]
		[	3 4	]		[	7 8	]
	*/

	if (matrix_A[0].size() == matrix_B.size())
	{
		_buffer.resize(matrix_A.size(), std::vector<float>(matrix_B[0].size()));
		for (int i = 0; i < _buffer[0].size(); i++)	//each column
		{
			for (int o = 0; o < _buffer.size(); o++)	//each row
			{
				for (int p = 0; p < matrix_A[o].size() ; p++)	//each element
				{
					_buffer[o][i] += matrix_A[o][p] * matrix_B[p][i];	//add together
				}
			}
		}
		//seems complicating but it work really well lol. One shot let's goooooooooooooooo
	}
	else {
		return _buffer;
		//error return null;
	}

	return _buffer;
}

std::vector<std::vector<float>> MATH::Matrix_Addition(std::vector<std::vector<float>> matrix_A, std::vector<std::vector<float>> matrix_B)
{
	//Add two matrix together
	std::vector<std::vector<float>> _buffer;
	
	if (matrix_A.size() == matrix_B.size() && matrix_A[0].size() == matrix_B[0].size())
	{
		_buffer.resize(matrix_A.size(), std::vector<float>(matrix_A[0].size()));
		for (int i = 0; i < matrix_A.size(); i++)//row
		{
			for (int o = 0; o < matrix_A[0].size(); o++)//column
			{
				_buffer[i][o] = matrix_A[i][o] + matrix_B[i][o];
			}
		}
	}
	else
	{
		return _buffer;
		//cannot add two together
	}
	return _buffer;
	// One shot again let's goooooooooooooooooooooooooooooooo
}

std::vector<std::vector<float>> MATH::Transpose_hori_to_vert_matrix(std::vector<float> input)
{
	std::vector<std::vector<float>> _buffer;

	_buffer.resize(input.size(), std::vector<float>(0));

	for (int i = 0; i < input.size(); i++)
	{
		_buffer[i][0] = input[i];
	}

	return _buffer;
}