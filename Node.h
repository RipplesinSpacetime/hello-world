#ifndef _NODE_H
#define _NODE_H
#include <vector>

using namespace std;

class Noncopyable{
protected:
	Noncopyable(){}
	~Noncopyable(){};
private:
	Noncopyable(const Noncopyable&);
	const Noncopyable& operator= (const Noncopyable&);
};

class Node : private Noncopyable{
public:
	virtual double Calc() const = 0;
	virtual ~Node(){};
};

class NumberNode : public Node
{
public:
	NumberNode(double number) : number_(number){}
	double Calc() const;
private:
	const double number_;
};

class BinaryNode : public Node
{
public:
	BinaryNode(Node* left, Node* right):left_(left),right_(right){}
	~BinaryNode();
protected:
	Node* const left_;
	Node* const right_;
};

class UnaryNode : public Node
{
public:
	UnaryNode(Node* child): child_(child){}
	~UnaryNode();
protected:
	Node* const child_;
};

class AddNode : public BinaryNode
{
public:
	AddNode(Node* left, Node* right):BinaryNode(left, right){}
	double Calc() const;
};

class SubNode : public BinaryNode
{
public:
	SubNode(Node* left, Node* right):BinaryNode(left, right){}
	double Calc() const;
};

class MultiplyNode : public BinaryNode
{
public:
	MultiplyNode(Node* left, Node* right):BinaryNode(left, right){}
	double Calc() const;
};

class DevideNode : public BinaryNode
{
public:
	DevideNode(Node* left, Node* right):BinaryNode(left, right){}
	double Calc() const;
};

class UMinusNode : public UnaryNode
{
public:
	UMinusNode(Node* child) : UnaryNode(child){}
	double Calc() const;
};

class MultipleNode : public Node
{
public:
	MultipleNode(Node* node)
	{
		AppendChild(node, true);
	}
	void AppendChild(Node* node, bool positive)
	{
		childs_.push_back(node);
		positive_.push_back(positive);
	}
	~MultipleNode();
protected:
	vector<Node*> childs_;
	vector<bool> positive_;
};

class SumNode : public MultipleNode
{
public:
	SumNode(Node* node): MultipleNode(node){}
	double Calc() const;
};

class ProductNode : public MultipleNode
{
public:
	ProductNode(Node* node): MultipleNode(node){}
	double Calc() const;
};

#endif
