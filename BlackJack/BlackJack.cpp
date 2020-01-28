#include <iostream>
#include <string>
using namespace std;

class Card
{
public:
	enum m_RANK
	{
		TWO = 2,
		THREE = 3,
		FOUR = 4,
		FIVE = 5,
		SIX = 6,
		SEVEN = 7,
		EIGHT = 8,
		NINE = 9,
		TEN = 10,
		JACK = 10,
		QUEEN = 10,
		KING = 10,
		ACE = 1
	};
	enum m_SUIT
	{
		Spades,
		Hearts,
		Diamonds,
		Clubs
	};

	bool FaceUP = true;
	bool FaceDown = false;

	void Flip() {

	}
	int GetValue() {

	}
};

int main()
{

    
}
