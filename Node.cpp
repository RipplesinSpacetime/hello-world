#include "Node.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

#if 0	//虚函数也必须有实现，要么在.h。文件中实现{}；要么在其他地方实现
Node::~Node()
{

}
#endif

BinaryNode::~BinaryNode()
{
	delete left_;
	delete right_;
}

UnaryNode::~UnaryNode()
{
	delete child_;
}

double NumberNode::Calc() const
{
	return number_;
}

double AddNode::Calc() const
{
	return left_->Calc() + right_->Calc();
}

double SubNode::Calc() const
{
	return left_->Calc() - right_->Calc();
}

double MultiplyNode::Calc() const
{
	return left_->Calc() * right_->Calc();
}

double DevideNode::Calc() const
{
	double divisor = right_->Calc();
	if (divisor != 0.0)
	{
		return left_->Calc() / right_->Calc();
	}
	else
	{
		cout << "Error: Divisor by zero"<<endl;
		return -1;
	}

}

double UMinusNode::Calc() const
{
	return -child_->Calc();
}

MultipleNode::~MultipleNode()
{
	vector<Node*>::const_iterator it;
	for(it = childs_.begin(); it != childs_.end(); ++it)
	{
		delete *it;
	}
}

double SumNode::Calc() const
{
	double result = 0.0;
	vector<Node*>::const_iterator childIt = childs_.begin();
	vector<bool> ::const_iterator positiveIt = positive_.begin();

	for(; childIt != childs_.end(); ++childIt, ++positiveIt)
	{
		assert(positiveIt != positive_.end());
		double val = (*childIt)->Calc();
		if(*positiveIt)
			result += val;
		else
			result -= val;
	}
	assert(positiveIt == positive_.end());
	return result;
}

double ProductNode::Calc() const
{
	double result = 1.0;
	vector<Node*>::const_iterator childIt = childs_.begin();
	vector<bool> ::const_iterator positiveIt = positive_.begin();

	for(; childIt != childs_.end(); ++childIt, ++positiveIt)
	{
		assert(positiveIt != positive_.end());
		double val = (*childIt)->Calc();
		if(*positiveIt)
			result *= val;
		else if(val != 0.0)
			result /= val;
		else
			return HUGE_VAL;
	}
	assert(positiveIt == positive_.end());
	return result;
}
