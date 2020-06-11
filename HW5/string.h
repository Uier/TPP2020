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
		str_ = new char[obj.size_]();
		strcpy(str_, obj.str_);
		size_ = obj.size_;
		capacity_ = obj.size_;
	}

	// 3. constructor with one parameter with type const char *
	String(const char *obj) {
		str_ = new char[strlen(obj)]();
		strcpy(str_, obj);
		size_ = strlen(obj);
		capacity_ = strlen(obj);
	}

	// 4. destructor
	~String() = default;

	// 5. size()
	size_t size() const { return size_; }

	// 6. c_str()
	const char * c_str() const { return str_; }

	// 7. operator []
	char & operator [] (size_t i) const {
		return str_[i];
	}

	// 8. operator +=
	String & operator += (const String &obj) {
		if ( capacity_ < size_ + obj.size_ ) {
			char *temp = new char[size_ + obj.size_]();
			capacity_ = size_ + obj.size_;
			strcpy(temp, str_);
			delete[] str_;
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
	String & operator = (const String &obj) {
		if ( capacity_ < obj.size_ ) {
			delete[] str_;
			str_ = new char[obj.size_]();
			capacity_ = obj.size_;
		}
		strcpy(str_, obj.str_);
		size_ = obj.size_;
		return *this;
	}

	// 11. swap()
	void swap(String &obj) {
		std::swap(str_, obj.str_);
		std::swap(size_, obj.size_);
		std::swap(capacity_, obj.capacity_);
	}

	// C. operator +
	const String operator + (const String &obj) {
		String temp = *this;
		temp += obj;
		return temp;
	}

private:
	char *str_ = nullptr;
	size_t size_ = 0;
	size_t capacity_ = 0;
};

// A. relational operators (<, >, <=, >=, ==, !=)
bool operator < (const String &obj1, const String &obj2) {
	int minimum_length = std::min(obj1.size(), obj2.size());
	for ( int i=0; i<minimum_length; ++i )
		if ( obj1[i] != obj2[i] )
			return obj1[i] < obj2[i];

	// if they have the same prefix, the shorter, the smaller
	return obj1.size() < obj2.size();
}
bool operator > (const String &obj1, const String &obj2) {
	int minimum_length = std::min(obj1.size(), obj2.size());
	for ( int i=0; i<minimum_length; ++i )
		if ( obj1[i] != obj2[i] )
			return obj1[i] > obj2[i];

	// if they have the same prefix, the longer, the larger
	return obj1.size() > obj2.size();
}
bool operator <= (const String &obj1, const String &obj2) {
	int minimum_length = std::min(obj1.size(), obj2.size());
	for ( int i=0; i<minimum_length; ++i )
		if ( obj1[i] != obj2[i] )
			return obj1[i] <= obj2[i];

	// if they have the same prefix, compare the length of them
	return obj1.size() <= obj2.size();
}
bool operator >= (const String &obj1, const String &obj2) {
	int minimum_length = std::min(obj1.size(), obj2.size());
	for ( int i=0; i<minimum_length; ++i )
		if ( obj1[i] != obj2[i] )
			return obj1[i] >= obj2[i];

	// if they have the same prefix, compare the length of them
	return obj1.size() >= obj2.size();
}
bool operator == (const String &obj1, const String &obj2) {
	// different length impies they're different
	if ( obj1.size() != obj2.size() )	return false;	
	for ( int i=0; i<obj1.size(); ++i )
		if ( obj1[i] != obj2[i] )
			return false;
	return true;
}
bool operator != (const String &obj1, const String &obj2) {
	// different length impies they're different
	if ( obj1.size() != obj2.size() )	return true;
	int minimum_length = std::min(obj1.size(), obj2.size());
	for ( int i=0; i<obj1.size(); ++i )
		if ( obj1[i] != obj2[i] )
			return true;
	return false;
}


// B. operator <<, >>
std::ostream & operator << (std::ostream &os, const String &obj) {
	os << obj.str_;
	return os;
}
std::istream & operator >> (std::istream &is, String &obj) {
	char *str = new char[is.gcount()]();
	is >> str;
	String temp(str);
	obj = temp;
	return is;
}
