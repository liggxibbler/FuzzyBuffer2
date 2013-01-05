#ifndef _FUZZY_INFERENCESYSTEM_H_
#define _FUZZY_INFERENCESYSTEM_H_

#include "linguisticVariable.h"
#include "ruleBase.h"
#include <list>

namespace Fuzzy
{
	class InferenceSystem
	{
	public:

		float Evaluate(float input1, float input2);

	private:
		std::list<LinguisticVariable*> m_input;
		std::list<LinguisticVariable*> m_output;
		RuleBase* m_ruleBase;
	};
}

#endif