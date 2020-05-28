#pragma once
#ifndef POINTER_H
#define POINTER_H

class String;

//智能指针：对指针使用进行计数
class Pointer {
public:
	Pointer();
	Pointer(String const& n);
	~Pointer();

	String& operator*();
	String* operator->();

private:
	String* ptr;
	static String errorMessage;
};

#endif
