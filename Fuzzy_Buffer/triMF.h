#ifndef _FUZZY_TRIMF_H_
#define _FUZZY_TRIMF_H_

#include "membershipFunction.h"

namespace Fuzzy
{
	class TriMF : public MembershipFunction
	{
	public:
		virtual bool Initialize(float* params);
		virtual float Centroid();
	protected:
		virtual float Evaluate(float input);
	private:
		void CalculateCentroid();
		float m_centroid;
		float m_left;
		float m_mid;
		float m_right;
	};
}

#endif