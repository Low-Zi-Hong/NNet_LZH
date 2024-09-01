#pragma once
#include <fstream>

#include "AI/AI.h"

namespace OTHER {

	bool Check_Old_Network();

	N_Net::Neuron_Network Load_N_Net_From_File();

	int Save_N_Net_To_File(N_Net::Neuron_Network m_net);



}