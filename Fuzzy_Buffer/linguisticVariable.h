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
		std::list<MembershipFunction*> m_mf;
	};
}

#endif