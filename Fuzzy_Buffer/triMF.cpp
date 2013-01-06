#include "triMF.h"

using namespace Fuzzy;

bool TriMF::Initialize(float* params)
{
	if(!params)
	{
		return false;
	}
	
	m_left = params[0];
	m_mid = params[1];
	m_right = params[2];
	
	CalculateCentroid();

	return true;
}

float TriMF::Evaluate(float input)
{
	float m;

	if(input >= m_minRange && input < m_left)
	{
		return 0;
	}
	if(input >= m_left && input < m_mid)
	{
		m = 1 / (m_mid - m_left); // slope of left side line segment
		return m * (input - m_left); // line equation
	}
	if(input >= m_mid && input < m_right)
	{
		m = (-1) / (m_right - m_mid); // slope of right side line segment
		return m * (input - m_mid); // line equation
	}
	if(input >= m_right && input < m_maxRange)
	{
		return 0;
	}
	
	return -1;
}

void TriMF::CalculateCentroid()
{
	// Returns the centroid of the triangular MF
	// 

	float l3, m3, r3; // store the cubes
	float d1, d2; // store denominators
	float n1, n2; // store numerators
	float result;

	l3 = m_left * m_left * m_left;
	m3 = m_mid * m_mid * m_mid;
	r3 = m_right * m_right * m_right;

	d1 = 6 * (m_mid - m_left);
	d2 = 6 * (m_mid - m_right);

	n1 = 2*m3 - 3*m_left*m_mid*m_mid + l3;
	n2 = 2*r3 - 3*m_mid*m_right*m_right + m3;

	result = n1/d1 + n2/d2;
	m_centroid = result;
}

float TriMF::Centroid()
{
	return m_centroid;
}