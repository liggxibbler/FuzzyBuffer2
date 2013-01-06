#include "rule.h"

using namespace Fuzzy;

Rule::Rule()
{
}

Rule::Rule(const Rule& other)
{
}

Rule::~Rule()
{
}

void Rule::SetBuffers(Buffer* i1, Buffer* i2, Buffer* o1)
{
	m_input1 = i1;
	m_input2 = i2;
	m_output = o1;
}

bool Rule::Fire()
{
	float in1, in2, out;
	
	if(!m_input1 || !m_input2 || !m_output)
	{
		return false;
	}

	in1 = m_input1->Read();
	in2 = m_input2->Read();
	out = in1 > in2 ? in1 : in2;
	m_output->Max(out);	

	return true;
}