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
#include <deque>

namespace cwPandoraIndicator
{
	//指数移动平均值 Exponential Moving Average 简称EMA,或EXPMA 指标
	class cwEMA
	{
	public:
		cwEMA(int iSize = 12);
		~cwEMA();

		//Interface
		double		Update(double price);
		double		Try(double price);

		double		Get();
		double		Get(int iLastIndex);

		//Reset 会清掉之前历史数据
		void		Reset(int iSize = 12);
		//SetPriceSize只会更新m_PriceDequeSize ，需在第一次调用Update之前调用
		void		SetPriceSize(int iSize = 12);

		//Data
		int				   m_PriceDequeSize;
		double			   m_PriceYesterdayEMA;
		double			   m_PriceTodayEMA;
		double			   m_PriceAlpha;

		std::deque<double>			m_PriceEMADeque;
	};
}