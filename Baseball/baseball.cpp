#include <string>
#include <stdexcept>
using std::string;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question) 
		: question(question){
	}
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);

		int ball_cnt = 0;
		int strike_cnt = 0;

		for (int i = 0; i < 3; i++) {
			if (question[i] == guessNumber[i]) {
				strike_cnt++;
			}
			else if (question.find(guessNumber[i]) != std::string::npos) {
				ball_cnt++;
			}
		}
		return { (strike_cnt == 3), strike_cnt, ball_cnt };
	}
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw std::length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw std::invalid_argument("Must be number");
		}

		if (isDuplicateNumber(guessNumber)) {
			throw std::invalid_argument("Must not have the same number");
		}
	}
	bool isDuplicateNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

private:
	string question;
};