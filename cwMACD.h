//////////////////////////////////////////////////////////////////////////////////
//*******************************************************************************
//---
//---	author: Wu Chang Sheng
//---
//--	Copyright (c) by Wu Chang Sheng. All rights reserved.
//--    Consult your license regarding permissions and restrictions.
//--
//*******************************************************************************
//////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "cwEMA.h"
#include <deque>

namespace cwPandoraIndicator
{
	class cwMACD
	{
	public:
		cwMACD(bool bNeedDataQueue = false);
		~cwMACD();

		//Interface
		void		SetMacdParameter(int ShortPeriod = 12, int LongPeriod = 26, int M = 9);

		void		SetDataQueue(bool bNeedDataQueue = false);

		double		Update(double price);
		double		Try(double price);

		cwEMA		m_ShortEMA;
		cwEMA	    m_LongEMA;

		double		m_dDiff;			//ShortEMA - LOngEMA
		cwEMA		m_DEA;				//EMA(DIFF,M)
		double		m_dMacd;			//2 * (Diff - DEA)

		bool						m_bNeedDataDeque;
		std::deque<double>			m_DiffDeque;
		std::deque<double>			m_MacdDeque;
	private:
		int			m_iShortPeriod = 12;
		int			m_iLongPeriod = 26;
		int			m_iMean = 9;


	};
}
