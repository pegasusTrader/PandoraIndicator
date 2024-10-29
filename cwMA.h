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
	//�ƶ�ƽ�� Moving Average ���MA
	class cwMA
	{
	public:
		cwMA();
		cwMA(int iSize, bool bNeedMADeque = false);
		~cwMA();

		//Interface
		double						Update(double price);
		double						Try(double price);

		//Reset �����֮ǰ��ʷ����
		void						Reset(unsigned int iSize = 5, bool bNeedMADeque = false);
		//SetPriceSizeֻ�����m_PriceDequeSize �����ڵ�һ�ε���Update֮ǰ����
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