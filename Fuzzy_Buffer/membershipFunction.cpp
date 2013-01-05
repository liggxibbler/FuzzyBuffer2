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
}

float MembershipFunction::Defuzzify()
{
}

bool MembershipFunction::Initialize()
{
	bool result;
	m_buffer = new Buffer();
	if(!m_buffer)
	{
		return false;
	}
	return true;
}