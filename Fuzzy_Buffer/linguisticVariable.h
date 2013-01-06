#ifndef _FUZZY_LINGUISTICVARIABLE_H_
#define _FUZZY_LINGUISTICVARIABLE_H_

#include "membershipFunction.h"
#include <list>
#include <string>
#include <map>

namespace Fuzzy
{
	class LinguisticVariable
	{
	public:
		void Fuzzify(float input);
		float Defuzzify();
		//MembershipFunction* AddMF(type, params);

		std::string GetName();
		MembershipFunction* GetMF(std::string name);

	private:
		std::map<std::string, MembershipFunction*> m_mapMF;
		std::string m_name;
		float m_minRange;
		float m_maxRange;
		std::list<MembershipFunction*> m_mf;
	};
}

#endif