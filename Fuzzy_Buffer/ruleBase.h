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

	private:
		std::list<Rule*> m_rules;
	};
}

#endif