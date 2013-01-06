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
	return 0.0f;
}

std::string LinguisticVariable::GetName()
{
	return m_name;
}

MembershipFunction* LinguisticVariable::GetMF(std::string name)
{
	return m_mapMF[name];
}