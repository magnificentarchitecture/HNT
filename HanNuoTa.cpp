#include "HanNuoTa.h"
#include <malloc.h>
#include <iostream>
using namespace std;
HanNuoTa::HanNuoTa(int N)
{
	int second;
	int third;

	if (N % 2 == 0)
	{
		second = 2;
		third = 3;
	}
	else {
		third = 2;
		second = 3;
	}
	line = new Link(1,NULL);
	HNT_next = (HanNuoTa*)malloc(sizeof(HanNuoTa));
	HNT_next->line = new Link(second, NULL);
	HNT_next->HNT_next = (HanNuoTa*)malloc(sizeof(HanNuoTa));
	HNT_next->HNT_next->line = new Link(third,NULL);
	HNT_next->HNT_next->HNT_next = this;
}
int HanNuoTa::type_HanNuoTa()
{
	return this->line->data_;
}
bool HanNuoTa::IsEmpty()
{
	if (line->next_ == NULL)
	{
		return true;
	}
	return false;
}
void HanNuoTa::show_HanNuoTa()
{
	line = line->next_;
	while (line != NULL)
	{
		cout << line->data_ << " ";
		line = line->next_;
   }
}
void HanNuoTa::push(int data)
{
    HanNuoTa::Link* node = new HanNuoTa::Link(data, this->line->next_);
	this->line->next_ = node;
}
bool HanNuoTa::IsLarge(HanNuoTa* node)
{
	if (node->IsEmpty())
	{
		return true;
	}
	else {
		Link* tmp_node = node->line->next_;
		Link* tmp_this = this->line->next_;
		if (tmp_this->data_ < tmp_node->data_)
		{
			return true;
		}
		else {
			return false;
		}
	}
}
int Pop_line(HanNuoTa::Link* line)
{
	int data;
	HanNuoTa::Link* tmp = line;
	line = line->next_;
	tmp->next_ = line->next_;
	data = line->data_;
	delete line;
	return data;
}
HanNuoTa* HanNuoTa::Next()
{
	return this->HNT_next;
}
int HanNuoTa::Pop(HanNuoTa* node)
{
	int data = Pop_line(this->line);
	return data;
}