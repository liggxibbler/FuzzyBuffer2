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

bool Rule::Fire()
{
	float in1, in2, out;
	
	if(m_input1)
	{
		in1 = m_input1->Read();
	}
	else
	{
		return false;
	}

	if(m_input2)
	{
		in2 = m_input2->Read();
	}
	else
	{
		return false;
	}

	out = in1 > in2 ? in1 : in2;

	if(m_output)
	{
		m_output->Max(out);
	}
	else
	{
		return false;
	}

	return true;
}