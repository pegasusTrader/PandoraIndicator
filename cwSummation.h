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
	//求和 Summation
	//增量计算方法
	class cwSummation
	{
	public:
		cwSummation();
		cwSummation(unsigned int iSize);

		//Interface
		double						Update(double price);
		double						Try(double price);

		//Reset 会清掉之前历史数据
		void						Reset(unsigned int iSize = 5);
		//SetPriceSize只会更新m_PriceDequeSize ，需在第一次调用Update之前调用
		void						SetPriceSize(unsigned int iSize = 5);

		inline double				Get() { return m_PriceSum; }
	protected:

		std::deque<double>			m_PriceDeque;
		unsigned int				m_PriceDequeSize;
		double						m_PriceSum;
	};

}