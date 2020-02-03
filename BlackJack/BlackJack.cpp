#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Card
{
public:
	enum rank { ACE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 11, QUEEN = 12, KING = 13 };
	enum suit { SPADE = 0, HEART, CLUB, DIAMOND };
	
	void Flip() {
		m_IsFaceUp = !(m_IsFaceUp);
	}
	int GetValue() const {
		int value = 0;
		if (m_IsFaceUp) {
			value = m_Rank;
			if (value > 10) {
				value = 10;
			}
		}
		return value;
	}
private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};

class Hand 
{
public:

	void Add(Card* pCard) {
		m_Cards.push_back(pCard);
	}
	void Clear() {
		vector<Card*>::iterator iter = m_Cards.begin();
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
			delete* iter;
			*iter = 0;
		}
		m_Cards.clear();
	}
	int GetTotal() const {
		if (m_Cards.empty()) {
			return 0;
		}
		if (m_Cards[0]->GetValue() == 0) {
			return 0;
		}
		if (m_Cards[0]->GetValue() == 0) {
			return 0;
		}
		int total = 0;
		vector<Card*>::const_iterator iter;
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
			total += (*iter)->GetValue();
		}
		bool containsAce = false;
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
			if ((*iter)->GetValue() == Card::ACE) {
				containsAce = true;
			}
		}
		if (containsAce && total <= 11) {
			total += 10;
		}
		return total;
	}

protected:
	vector<Card*> m_Cards;
};

int main()
{

}
