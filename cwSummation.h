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
	//��� Summation
	//�������㷽��
	class cwSummation
	{
	public:
		cwSummation();
		cwSummation(unsigned int iSize);

		//Interface
		double						Update(double price);
		double						Try(double price);

		//Reset �����֮ǰ��ʷ����
		void						Reset(unsigned int iSize = 5);
		//SetPriceSizeֻ�����m_PriceDequeSize �����ڵ�һ�ε���Update֮ǰ����
		void						SetPriceSize(unsigned int iSize = 5);

		inline double				Get() { return m_PriceSum; }
	protected:

		std::deque<double>			m_PriceDeque;
		unsigned int				m_PriceDequeSize;
		double						m_PriceSum;
	};

}