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

		void SetBuffers(Buffer* i1, Buffer* i2, Buffer* o1);

		bool Fire();

	private:
		Buffer* m_input1;
		Buffer* m_input2;
		Buffer* m_output;
	};
}

#endif