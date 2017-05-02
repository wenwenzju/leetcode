#include "assignment_operator.h"

CMyString::CMyString(char* pData /* = nullptr */)
{
	if (pData == nullptr) {m_pData = nullptr; return;}
	m_pData = new char[std::strlen(pData)+1];
	std::strcpy(m_pData, pData);
}

CMyString::CMyString(const CMyString& str)
{
	m_pData = new char[std::strlen(str.m_pData)];
	std::strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(void)
{
	delete [] m_pData;
	m_pData = nullptr;
}

CMyString& CMyString::operator=(const CMyString& str)
{
	if (this != &str)
	{
		CMyString strTmp(str);
		std::swap(m_pData, strTmp.m_pData);
	}
	return *this;
}