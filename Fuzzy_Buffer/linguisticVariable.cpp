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

float LinguisticVariable::Defuzzify(DEFUZZ_METHOD dm, int numPoints)
{
	switch(dm)
	{
		case DEFUZZ_METHOD_CENTROID:
			return Centroid(numPoints);
		case DEFUZZ_METHOD_WEIGHTED_MF:
			return 0.0;
		default:
			return 0.0;
	}
}

std::string LinguisticVariable::GetName()
{
	return m_name;
}

MembershipFunction* LinguisticVariable::GetMF(std::string name)
{
	return m_mapMF[name];
}

float LinguisticVariable::Centroid(int numPoints)
{
	MembershipFunction* mf;
	float numerator, denominator;

	std::list<MembershipFunction*>::iterator iter;
	for(iter = m_mf.begin(); iter !=m_mf.end(); iter++)
	{
	}
	return 0.0f;
}

float LinguisticVariable::WeightedMF()
{
	MembershipFunction* mf;
	float result, buffer;
	
	result = 0;

	std::list<MembershipFunction*>::iterator iter;
	for(iter = m_mf.begin(); iter != m_mf.end(); iter++)
	{
		mf = *iter;
		buffer = mf->GetBuffer()->Read();
		result += buffer * mf->Centroid();
	}

	return result;
}