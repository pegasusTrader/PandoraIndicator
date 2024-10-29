#include "cwEMA.h"

namespace cwPandoraIndicator
{
	cwEMA::cwEMA(int iSize)
		: m_PriceDequeSize(iSize)
		, m_PriceYesterdayEMA(0.0)
		, m_PriceTodayEMA(0.0)
	{
		m_PriceAlpha = 2.0 / (m_PriceDequeSize + 1);
	}


	cwEMA::~cwEMA()
	{
	}

	void cwEMA::Reset(int iSize)
	{
		m_PriceEMADeque.clear();

		SetPriceSize(iSize);
	}

	void cwEMA::SetPriceSize(int iSize)
	{
		if (iSize <= 0)
		{
			m_PriceDequeSize = 0;
			m_PriceAlpha = 0;
		}
		else
		{
			m_PriceDequeSize = iSize;

			m_PriceAlpha = 2.0 / (m_PriceDequeSize + 1);
		}
	}

	double cwEMA::Update(double price)
	{
		if (m_PriceEMADeque.size() == 0)
		{
			m_PriceYesterdayEMA = m_PriceTodayEMA = price;
		}
		else
		{
			m_PriceTodayEMA = m_PriceAlpha * (price - m_PriceYesterdayEMA) + m_PriceYesterdayEMA;
			m_PriceYesterdayEMA = m_PriceTodayEMA;
		}

		m_PriceEMADeque.push_back(m_PriceTodayEMA);

		return m_PriceTodayEMA;
	}

	double cwEMA::Try(double price)
	{
		if (m_PriceEMADeque.size() == 0)
		{
			return price;
		}
		else
		{
			return m_PriceAlpha * (price - m_PriceYesterdayEMA) + m_PriceYesterdayEMA;
		}
	}
	double cwEMA::Get()
	{
		return m_PriceTodayEMA;
	}
	double cwEMA::Get(int iLastIndex)
	{
		if (iLastIndex < 0)
		{
			return Get();
		}

		if (iLastIndex >= (int)m_PriceEMADeque.size())
		{
			iLastIndex = int(m_PriceEMADeque.size() - 1);
		}

		return m_PriceEMADeque.at(m_PriceEMADeque.size() - 1 - iLastIndex);
	}
}