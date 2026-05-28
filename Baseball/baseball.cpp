#include <string>
#include <stdexcept>
using std::string;

class Baseball {
public:
	void guess(const string& string) {
		throw std::length_error("Must be three letters.");
	}
};