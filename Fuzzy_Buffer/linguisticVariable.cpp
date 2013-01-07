#include "linguisticVariable.h"

using namespace Fuzzy;

LinguisticVariable::LinguisticVariable()
{
}
LinguisticVariable::LinguisticVariable(std::string name, float min, float max)
{
	m_name = name;
	m_minRange = min;
	m_maxRange = max;
}
LinguisticVariable::LinguisticVariable(const LinguisticVariable& other)
{
}

LinguisticVariable::~LinguisticVariable()
{
}

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
			return WeightedMF();
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

MembershipFunction* LinguisticVariable::AddTriMF(std::string name, float* params)
{
	TriMF* mf = new TriMF(m_minRange, m_maxRange);
	mf->Initialize(params);
	
	m_mapMF[name] = (MembershipFunction*)mf;
	m_mf.push_back((MembershipFunction*)mf);

	return mf;
}

void LinguisticVariable::ClearBuffers()
{
	MembershipFunction* mf;
	std::list<MembershipFunction*>::iterator iter;
	for(iter=m_mf.begin(); iter!=m_mf.end(); iter++)
	{
		mf = *iter;
		mf->GetBuffer()->Clear();
	}
}