#include <string.h>
#include <math.h>
using namespace std;
class String {
public:
	// 1. default constructor
	// 2. copy constructor
	// 3. constructor with one parameter with type const char *
	String(const char *str): size_(strlen(str)) {
		str_ = new char[size_]
		capacity_ = max(capacity_, size_+1);
		strcpy(str, str_);
	}
	// 4. destructor
	// 5. size()
	// 6. c_str()
	// 7. operator []
	// 8. operator +=
	// 9. clear()
	// 10. operator =
	// 11. swap()
private:
	char *str_ = nullptr;
	size_t size_ = 0, capacity_ = 0;
};
// A. relational operators (<, >, <=, >=, ==, !=)
// B. operator <<, >>
// C. operators +=, +