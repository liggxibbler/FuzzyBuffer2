#include "inferenceSystem.h"

using namespace Fuzzy;

float InferenceSystem::Evaluate(float input1, float input2)
{
	LinguisticVariable* lv;
	std::list<LinguisticVariable*>::iterator iter;
	float output;

	/*
	int index = 0;
	for(iter = m_input.begin(); iter != m_input.end(); iter++)
	{
		lv = *iter;
		lv->Fuzzify(input[index++]);
	}*/

	iter = m_input.begin();
	lv = *iter;
	lv->Fuzzify(input1);

	iter++;
	lv = *iter;
	lv->Fuzzify(input2);

	m_ruleBase->Fire();

	iter = m_output.begin();
	lv = *iter;
	output = lv->Defuzzify();

	return output;
}