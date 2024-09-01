#include "AI/AI.h"

#include <fstream>
#include "other.h"

#ifdef _DEBUG
	#define address "C:/Users/lozho/OneDrive/Desktop/cpp/AI/Ai_V1/Debug"
#else
	#define address "C:/Users/lozho/OneDrive/Desktop/cpp/AI/Ai_V1"
#endif


bool OTHER::Check_Old_Network()
{
	//here is to check whether there are any old file exists

	return true;
}

N_Net::Neuron_Network OTHER::Load_N_Net_From_File()
{
	N_Net::Neuron_Network _buffer;
	std::cout << address << std::endl;
	//here is to load the old network from file

	return _buffer;
}

int OTHER::Save_N_Net_To_File(N_Net::Neuron_Network m_net)
{
	//here is the save the generates / updated network to file


	return 1;
}