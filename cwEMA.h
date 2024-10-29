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
	//ָ���ƶ�ƽ��ֵ Exponential Moving Average ���EMA,��EXPMA ָ��
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

		//Reset �����֮ǰ��ʷ����
		void		Reset(int iSize = 12);
		//SetPriceSizeֻ�����m_PriceDequeSize �����ڵ�һ�ε���Update֮ǰ����
		void		SetPriceSize(int iSize = 12);

		//Data
		int				   m_PriceDequeSize;
		double			   m_PriceYesterdayEMA;
		double			   m_PriceTodayEMA;
		double			   m_PriceAlpha;

		std::deque<double>			m_PriceEMADeque;
	};
}