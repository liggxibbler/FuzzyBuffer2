#include "linguisticVariable.h"

using namespace Fuzzy;

void LinguisticVariable::Fuzzify(float input)
{
	MembershipFunction* mf;

	std::list<MembershipFunction*>::iterator iter;
	for(iter = m_mf.begin() ; iter != m_mf.end(); iter++)
	{
		mf = *iter;
		mf->Fuzzify(input);
	}

	return;
}

float LinguisticVariable::Defuzzify()
{
}