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

		virtual float Fuzzify(float input);
		virtual float Defuzzify();
		bool Initialize();

		Buffer* GetBuffer();
		std::string GetID();

	private:
		std::string m_id;
		Buffer* m_buffer;
	};
}

#endif