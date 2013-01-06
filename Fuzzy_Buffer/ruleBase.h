#ifndef _FUZZY_RULEBASE_H_
#define _FUZZY_RULEBASE_H_

#include "rule.h"
#include <list>

namespace Fuzzy
{
	class RuleBase
	{
	public:
		void Fire();
		bool AddRule(Buffer* i1, Buffer* i2, Buffer* o1);

	private:
		std::list<Rule*> m_rules;
	};
}

#endif