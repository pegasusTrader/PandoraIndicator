//////////////////////////////////////////////////////////////////////////////////
//*******************************************************************************
//---
//---	author: Wu Chang Sheng
//---
//---	CreateTime:	2016/12/12
//---
//---	VerifyTime:	2016/12/12
//---
//*******************************************************************************
//////////////////////////////////////////////////////////////////////////////////


#pragma once
#include <deque>

namespace cwPandoraIndicator
{
	//移动平均 Moving Average 简称MA
	class cwMA
	{
	public:
		cwMA();
		cwMA(int iSize, bool bNeedMADeque = false);
		~cwMA();

		//Interface
		double						Update(double price);
		double						Try(double price);

		//Reset 会清掉之前历史数据
		void						Reset(unsigned int iSize = 5, bool bNeedMADeque = false);
		//SetPriceSize只会更新m_PriceDequeSize ，需在第一次调用Update之前调用
		void						SetPriceSize(unsigned int iSize = 5);

		inline double				Get() { return m_PriceMa; }
		double						Get(int iLastIndex);

		std::deque<double>			m_PriceMADeque;
	protected:
		std::deque<double>			m_PriceDeque;
		unsigned int				m_PriceDequeSize;
		double						m_PriceSum;
		double						m_PriceMa;

		bool						m_bNeedMADeque;
	};

}