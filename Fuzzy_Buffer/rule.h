#ifndef _FUZZY_RULE_H_
#define _FUZZY_RULE_H_

#include "buffer.h"

namespace Fuzzy
{
	class Rule
	{
	public:
		Rule();
		Rule(const Rule&);
		~Rule();

		bool Fire();

	private:
		Buffer* m_input1;
		Buffer* m_input2;
		Buffer* m_output;
	};
}

#endif