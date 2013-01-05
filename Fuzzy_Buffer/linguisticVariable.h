#ifndef _FUZZY_LINGUISTICVARIABLE_H_
#define _FUZZY_LINGUISTICVARIABLE_H_

#include "membershipFunction.h"
#include <list>

namespace Fuzzy
{
	class LinguisticVariable
	{
	public:
		void Fuzzify(float input);
		float Defuzzify();
	private:
		float m_minRange;
		float m_maxRange;
		std::list<MembershipFunction*> m_mf;
	};
}

#endif