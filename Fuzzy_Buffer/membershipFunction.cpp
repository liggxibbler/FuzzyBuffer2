#include "membershipFunction.h"

using namespace Fuzzy;

MembershipFunction::MembershipFunction()
{
	m_buffer = 0;
}

MembershipFunction::MembershipFunction(const MembershipFunction& other)
{
}

MembershipFunction::~MembershipFunction()
{
}

Buffer* MembershipFunction::GetBuffer()
{
	return m_buffer;
}

float MembershipFunction::Fuzzify(float input)
{
	float output = 0;
	m_buffer->Write(output);
	return output;
}

float MembershipFunction::Defuzzify()
{
	return 0.0f;
}

bool MembershipFunction::Initialize()
{
	m_buffer = new Buffer();
	if(!m_buffer)
	{
		return false;
	}
	return true;
}