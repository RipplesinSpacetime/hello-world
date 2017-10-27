#ifndef _SCANER_H
#define _SCANER_H
#include <string>

enum EToken{
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_MULTIPLY,
	TOKEN_DIVIDE,
	TOKEN_LPARENTHESIS,
	TOKEN_RPARENTHESIS,
	TOKEN_NUMBER,
	TOKEN_END,
	TOKEN_ERROR,
};

class Scanner{
public:
	Scanner(const std::string& buf);
	void Accept();	
	EToken Token() const;
	double Number() const;
private:
	void SkipWhite();
	const std::string buf_;
	double number_;
	EToken token_;
	unsigned int curPos_;
};

#endif



