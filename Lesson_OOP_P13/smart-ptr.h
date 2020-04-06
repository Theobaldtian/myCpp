#pragma once
class U_Ptr {
	friend class BHasPtr;
private:
	int* ip;
	size_t use;	//计数
	U_Ptr(int* p) :ip(p), use(1) {}
	~U_Ptr() { delete ip; }		//此处还是有问题
};

class BHasPtr {
public:
	BHasPtr(int* p, int i) :ptr(new U_Ptr(p)), val(i) {}

	BHasPtr(const BHasPtr& orig):ptr(orig.ptr),val(orig.val) {
		++ptr->use;
	}

	BHasPtr& operator = (const BHasPtr&);

	~BHasPtr() {
		if (--ptr->use == 0)	delete ptr;
	}

	int* get_ptr() const { return ptr->ip; }
	int get_int() const { return val; }

	void set_ptr(int* p) { ptr->ip = p; }
	void set_int(int i) { val = i; }

	int get_ptr_val() const { return *ptr->ip; }
	void set_ptr_val(int val) { *ptr->ip = val; }

private:
	int val;
	//int* ptr;
	U_Ptr *ptr;
};

BHasPtr& BHasPtr::operator = (const BHasPtr& rhs) {
	++rhs.ptr->use;		//右边的++
	if (--ptr->use == 0) delete ptr;	//左边的--

	ptr = rhs.ptr;
	val = rhs.val;
	return *this;
}
