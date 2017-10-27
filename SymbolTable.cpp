#include "SymbolTable.h"

unsigned int SymbolTable::Add(const std::string& str)
{
	dictionary_[str] = curId_;
	return curID_++;
}


unsigned int SymbolTable::Find(const string& str) 
{
	map<const std::string, unsigned int>::const_iterator it;
	it = dictionary_.find(str);
	if(it != dictionary_.end())
	{
		return it->second;
	}
	else
	{
		return IDNOTFOUND;
	}
}

void SymbolTable::Clear()
{
	dictionary_.clear();
	curID_ = 0;
}

class IsEqualID
{
public:
	bool operator()(const std::pair<const string, unsigned int>& it) const
	{
		return it.second == id_;
	}
private:
	unsigned int id_;
}

std::string GetSymbolName(unsigned int id) const
{
	map<const std::string, unsigned>::const_iterator it;
	it = find_if(dictionary_.begin(), dictionary_.end(), IsEqualID(id));

    if(it != dictionary_.end())
        return it->first;
}


#endif
