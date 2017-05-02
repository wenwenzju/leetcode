#ifndef _ASSIGNMENT_OPERATOR_
#define _ASSIGNMENT_OPERATOR_

#include <string>
class CMyString
{
public:
	explicit CMyString (char* pData = nullptr);
	explicit CMyString (const CMyString& str);
	~CMyString(void);
	CMyString& operator= (const CMyString& str);
private:
	char* m_pData;
};

#endif