#ifndef _HANNUOTA_H_
#define _HANNUOTA_H_

class HanNuoTa {
	struct Link {
		int data_;
	    Link* next_;
		Link(int data,Link* next) : data_(data), next_(next)
		{

		}
	};
public:
	HanNuoTa(int N);
	int Pop(HanNuoTa* node);
	HanNuoTa* Next();
	void push(int data);
	bool IsLarge(HanNuoTa* node);
	int type_HanNuoTa();
	void show_HanNuoTa();
	friend int Pop_line(Link* line);
	bool IsEmpty();
	
private:
    Link* line;
	HanNuoTa* HNT_next;
};

#endif

