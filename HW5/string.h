#include <iostream>
#include <string.h>

class String {

friend std::ostream & operator << (std::ostream &os, const String &obj);
friend std::istream & operator >> (std::istream &is, String &obj);

public:
	
	// 1. default constructor
	String() = default;

	// 2. copy constructor
	String(const String &obj) {
		str_ = new char[obj.size_];
		size_ = obj.size_;
		capacity_ = obj.size_;
		strncpy(str_, obj.str_, size_);
	}

	// 3. constructor with one parameter with type const char *
	String(const char *obj) {
		str_ = new char[strlen(obj)];
		size_ = strlen(obj);
		capacity_ = strlen(obj);
		strncpy(str_, obj, size_);
	}

	// 4. destructor
	~String() = default;

	// 5. size()
	size_t size() const { return size_; }

	// 6. c_str()
	const char * c_str() const { return str_; }

	// 7. operator []
	char & operator [] (size_t i) const { return str_[i]; }

	// 8. operator +=
	String & operator += (const String &obj) {
		if ( capacity_ < size_ + obj.size_ ) {
			char *temp = new char[size_ + obj.size_];
			capacity_ = size_ + obj.size_;
			if ( str_ ) {
				strcpy(temp, str_);
				delete[] str_;
			}
			str_ = temp;
		}
		strcat(str_, obj.str_);
		size_ += obj.size_;
		return *this;
	}

	// 9. clear()
	void clear() {
		if ( !str_ )	return;
		str_[0] = '\0';
		size_ = 0;
	}

	// 10. operator =
	String & operator = (String obj) {
		this->swap(obj);
		return *this;
	}

	// 11. swap()
	void swap(String &obj) {
		using std::swap;
		swap(str_, obj.str_);
		swap(size_, obj.size_);
		swap(capacity_, obj.capacity_);
	}

private:
	char *str_ = nullptr;
	size_t size_ = 0;
	size_t capacity_ = 0;
};

// A. relational operators (<, >, <=, >=, ==, !=)
bool operator < (const String &obj1, const String &obj2) {
	return strcmp(obj1.c_str(), obj2.c_str()) < 0;
}
bool operator > (const String &obj1, const String &obj2) {
	return strcmp(obj1.c_str(), obj2.c_str()) > 0;
}
bool operator <= (const String &obj1, const String &obj2) {
	return strcmp(obj1.c_str(), obj2.c_str()) <= 0;
}
bool operator >= (const String &obj1, const String &obj2) {
	return strcmp(obj1.c_str(), obj2.c_str()) >= 0;
}
bool operator == (const String &obj1, const String &obj2) {
	return strcmp(obj1.c_str(), obj2.c_str()) == 0;
}
bool operator != (const String &obj1, const String &obj2) {
	return strcmp(obj1.c_str(), obj2.c_str()) != 0;
}

// B. operator <<, >>
std::ostream & operator << (std::ostream &os, const String &obj) {
	char *str = new char[obj.size_+1];
	strncpy(str, obj.str_, obj.size_);
	str[obj.size_] = '\0';
	os << str;
	delete[] str;
	return os;
}
std::istream & operator >> (std::istream &is, String &obj) {
	char *str = new char[is.gcount()];
	is >> str;
	String temp(str);
	obj = temp;
	delete[] str;
	return is;
}

// C. operator +
const String operator + (const String &obj1, const String &obj2) {
	String temp = obj1;
	temp += obj2;
	return temp;
}