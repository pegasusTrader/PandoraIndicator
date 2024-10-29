#include "cwSummation.h"
namespace cwPandoraIndicator
{
	cwSummation::cwSummation()
		: m_PriceDequeSize(5)
	{
	}

	cwSummation::cwSummation(unsigned int iSize)
		: m_PriceDequeSize(iSize)
	{
	}

	double cwSummation::Update(double price)
	{
		m_PriceDeque.push_back(price);
		m_PriceSum += price;

		if (m_PriceDeque.size() > m_PriceDequeSize)
		{
			m_PriceSum -= m_PriceDeque.front();
			m_PriceDeque.pop_front();
		}
		return m_PriceSum;
	}

	double cwSummation::Try(double price)
	{
		double sum = m_PriceSum + price;
		if (m_PriceDeque.size() >= m_PriceDequeSize
			&& m_PriceDeque.size() > 0)
		{
			sum -= m_PriceDeque.front();
		}
		return sum;
	}

	void cwSummation::Reset(unsigned int iSize)
	{
		m_PriceDequeSize = iSize;

		m_PriceSum = 0.0;
		m_PriceDeque.clear();
	}

	void cwSummation::SetPriceSize(unsigned int iSize)
	{
		m_PriceDequeSize = iSize;
	}

}