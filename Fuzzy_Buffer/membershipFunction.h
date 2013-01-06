#ifndef _FUZZY_MEMBERSHIPFUNCTION_H_
#define _FUZZY_MEMBERSHIPFUNCTION_H_

#include "buffer.h"
#include <string>

namespace Fuzzy
{
	class MembershipFunction
	{
	public:
		MembershipFunction();
		MembershipFunction(const MembershipFunction& other);
		~MembershipFunction();

		float Fuzzify(float input);
		float Peek(float input);
		bool Initialize();

		Buffer* GetBuffer();
		std::string GetID();

	protected:
		virtual float Evaluate(float input) = 0;
		std::string m_id;
		Buffer* m_buffer;
	};
}

#endif