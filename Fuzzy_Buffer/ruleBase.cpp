#include "ruleBase.h"

using namespace Fuzzy;

void RuleBase::Fire()
{
	Rule* rule;
	std::list<Rule*>::iterator iter;

	for(iter = m_rules.begin(); iter != m_rules.end(); iter++)
	{
		rule = *iter;
		rule->Fire();
	}
}
