#include "pointer.h"
#include "string.h"

Pointer::Pointer():ptr(0){}

Pointer::Pointer(String const& n) {
	ptr = new String(n);
}

Pointer::~Pointer() {
	delete ptr;
}

String Pointer::errorMessage("Uninitialized Pointer");

String& Pointer::operator*() {
	if (!ptr)
		throw errorMessage;
	return* ptr;
}

String* Pointer::operator->() {
	if (!ptr)
		throw errorMessage;
	return ptr;

}
