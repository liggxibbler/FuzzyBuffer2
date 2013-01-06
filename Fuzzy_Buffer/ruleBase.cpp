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

bool RuleBase::AddRule(Buffer* i1, Buffer* i2, Buffer* o1)
{
	Rule* rule = new Rule;
	if(!rule)
	{
		return false;
	}
	
	rule->SetBuffers(i1, i2, o1);
	m_rules.push_back(rule);
	
	return true;
}