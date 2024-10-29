#include "cwMACD.h"


namespace cwPandoraIndicator
{
	cwMACD::cwMACD(bool bNeedDataQueue)
		: m_bNeedDataDeque(bNeedDataQueue)
	{
	}


	cwMACD::~cwMACD()
	{
	}

	void cwMACD::SetMacdParameter(int ShortPeriod, int LongPeriod, int M)
	{
		m_ShortEMA.SetPriceSize(ShortPeriod);

		m_LongEMA.SetPriceSize(LongPeriod);

		m_DEA.SetPriceSize(M);
	}

	void cwMACD::SetDataQueue(bool bNeedDataQueue)
	{
		m_bNeedDataDeque = bNeedDataQueue;
	}

	double cwMACD::Update(double price)
	{
		m_dDiff = m_ShortEMA.Update(price) - m_LongEMA.Update(price);
		m_dMacd = 2 * (m_dDiff - m_DEA.Update(m_dDiff));

		if (m_bNeedDataDeque)
		{
			m_DiffDeque.push_back(m_dDiff);
			m_MacdDeque.push_back(m_dMacd);
		}

		return m_dMacd;
	}

	double cwMACD::Try(double price)
	{
		double dDiff = m_ShortEMA.Try(price) - m_LongEMA.Try(price);
		return 2 * (dDiff - m_DEA.Try(dDiff));
	}
}