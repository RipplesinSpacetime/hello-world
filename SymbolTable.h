#ifndef _SYMBOL_TABLE_H_H
#define _SYMBOL_TABLE_H_H

#include <map>
#include <string>

class SymbolTable{
	enum{ IDNOTFOUND = 0xffffffff };
public:
	SymbolTable(): curID_(0){}
	unsigned int Add(const string& str);
	unsigned int Find(const string& str) const;
	void Clear();
	std::string GetSymbolName(unsigned int id) const;

private:
	std::map<const std::string, unsigned int> dictionary_;
	unsigned int curID_;
};


#endif
