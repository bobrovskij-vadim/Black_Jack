#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Card
{
public:
	enum rank { ACE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 11, QUEEN = 12, KING = 13 };
	enum suit { SPADE = 0, HEART, CLUB, DIAMOND };

	Card(rank r = ACE, suit s = SPADE, bool ifu = true) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
	{}

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

class GenericPlayer : public Hand 
{
	friend ostream& operator <<(ostream& os, const GenericPlayer& aGenericPlayer);

public:
	GenericPlayer(const string& name = " "): m_Name(name) {

	}

	virtual ~GenericPlayer(){}

	virtual bool IsHitting() const = 0;

	bool IsBoosted() const { return (GetTotal() > 21); }
	void Bust() const { cout << m_Name << "Bust. \n"; }

protected:
	string m_Name;

};

ostream& operator << (ostream& os, const GenericPlayer& aGenericPlayer) {
	os << aGenericPlayer.m_Name << ":\t";

	vector <Card*>::const_iterator pCard;
	if (!aGenericPlayer.m_Cards.empty())
	{
		for (pCard = aGenericPlayer.m_Cards.begin();
			pCard != aGenericPlayer.m_Cards.end();
			++pCard) {
			os << *(*pCard) << "\t";
		}

		if (aGenericPlayer.GetTotal() != 0) {
			cout << "(" << aGenericPlayer.GetTotal() << ")";
		}
	}
	else {
		os << "<empty>";
	}
	return os;
}

class Player : public GenericPlayer
{
public:
	Player(const string& name = " ");

	virtual ~Player();

	virtual bool IsHitting() const {
		cout << m_Name << ", do you want a hit? (Y/N): ";
		char response;
		cin >> response;
		return (response == 'y' || response == 'Y');
	}

	void Win() const {
		cout << m_Name << " wins.\n";
	}
	void Lose() const {
		cout << m_Name << " loses.\n";
	}
	void Push() const {
		cout << m_Name << " pushes.\n";
	}
};

class House : GenericPlayer 
{
public:
	House(const string& name = "House");

	virtual ~House();

	virtual bool IsHitting() const {
		return (GetTotal() <= 16);
	}
	void FlipFirstCard() {
		if (!(m_Cards.empty())) {
			m_Cards[0]->Flip();
		}
		else {
			cout << "No card to flip! \n";
		}
	}

};



int main()
{

}