#ifndef _FUZZY_INFERENCESYSTEM_H_
#define _FUZZY_INFERENCESYSTEM_H_

#include "linguisticVariable.h"
#include "ruleBase.h"
#include <list>
#include <map>

namespace Fuzzy
{
	class InferenceSystem
	{
	public:

		float Evaluate(float input1, float input2);

		bool AddRule(std::string var1, std::string val1, std::string var2, std::string val2, std::string out, std::string valOut);
		//bool AddRule(std::string* input, std::string* inputVal, std::string* output, std::string outputVal);

	private:
		std::map<std::string, LinguisticVariable*> m_mapVar;
		std::list<LinguisticVariable*> m_input;
		std::list<LinguisticVariable*> m_output;
		RuleBase* m_ruleBase;
	};
}

#endif