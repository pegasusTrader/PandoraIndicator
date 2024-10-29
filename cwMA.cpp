#include "cwMA.h"

#ifndef _MSC_VER
#include <sys/types.h>
#endif // !_MSC_VER


namespace cwPandoraIndicator
{

	cwMA::cwMA()
		: m_PriceDequeSize(5)
		, m_PriceSum(0)
		, m_PriceMa(0)
		, m_bNeedMADeque(false)
	{
	}

	cwMA::cwMA(int iSize, bool bNeedMADeque)
		: m_PriceDequeSize(iSize)
		, m_PriceSum(0)
		, m_PriceMa(0)
		, m_bNeedMADeque(bNeedMADeque)
	{
	}


	cwMA::~cwMA()
	{
	}

	void cwMA::Reset(unsigned int iSize, bool bNeedMADeque)
	{
		m_PriceDequeSize = iSize;

		m_PriceSum = 0.0;
		m_PriceMa = 0.0;

		m_PriceDeque.clear();

		m_bNeedMADeque = bNeedMADeque;
		m_PriceMADeque.clear();
	}

	double cwMA::Update(double price)
	{
		while (m_PriceDeque.size() < (size_t)m_PriceDequeSize)
		{
			m_PriceDeque.push_back(price);
			m_PriceSum += price;
		}
		m_PriceDeque.push_back(price);
		m_PriceSum += price;

		m_PriceSum -= m_PriceDeque.front();
		m_PriceDeque.pop_front();


		if (m_PriceDequeSize == 0)
		{
			m_PriceMa = 0.0;
		}
		else
		{
			m_PriceMa = m_PriceSum / m_PriceDequeSize;
		}

		if (m_bNeedMADeque)
		{
			m_PriceMADeque.push_back(m_PriceMa);
		}

		return m_PriceMa;
	}

	double cwMA::Try(double price)
	{
		double dTempSum = m_PriceSum;
		double dPriceMA = 0;

		for (int i = 0; i + m_PriceDeque.size() < (size_t)m_PriceDequeSize; i++)
		{
			dTempSum += price;
		}
		dTempSum += price;

		if (m_PriceDeque.size() > 0)
		{
			dTempSum -= m_PriceDeque.front();
		}
		else
		{
			dTempSum -= price;
		}

		if (m_PriceDequeSize == 0)
		{
			dPriceMA = 0.0;
		}
		else
		{
			dPriceMA = dTempSum / m_PriceDequeSize;
		}

		return dPriceMA;
	}

	void cwMA::SetPriceSize(unsigned int iSize)
	{
		m_PriceDequeSize = iSize;
	}

	double cwMA::Get(int iLastIndex)
	{
		if (!m_bNeedMADeque
			|| iLastIndex < 0)
		{
			return Get();
		}

		if (iLastIndex >= (int)m_PriceMADeque.size())
		{
			iLastIndex = (int)m_PriceMADeque.size() - 1;
		}

		return m_PriceMADeque.at(m_PriceMADeque.size() - 1 - iLastIndex);
	}
}