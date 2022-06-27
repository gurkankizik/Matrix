#include <iostream>
using namespace std;

int main()
{
	int K = 2, L = 5;
	int** matrix = new int* [K];

	for (int k = 0; k < K; k++)
	{
		matrix[k] = new int[L];

		for (int l = 0; l < L; l++)
		{
			matrix[k][l] = k + 1;
		}
	}

	int M = 4;
	int** matrix2 = new int* [M];

	for (int l = 0; l < L; l++)
	{
		matrix2[l] = new int[M];

		for (int m = 0; m < M; m++)
		{
			matrix2[l][m] = m + 1;
		}
	}

	// Printing matrix
	cout << "Matrix 1: \n";
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < L; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	// Printing matrix2
	cout << "Matrix 2: \n";
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << matrix2[i][j] << " ";
		}
		cout << endl;
	}

	int mult[10][10];

	// Initializing elements of matrix mult to 0.
	for (int i = 0; i < K; ++i)
		for (int j = 0; j < M; ++j)
		{
			mult[i][j] = 0;
		}

	// Multiplying matrix1 and 2 and storing in array mult.
	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j < L; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				mult[i][j] += matrix[i][k] * matrix2[k][j];
			}
		}
	}

	// Displaying the multiplication of two matrix.
	cout << endl << "Multiplication: " << endl;
	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << " " << mult[i][j];
		}
		cout << endl;
	}

	return 0;
}

#include <iostream>
#define PI 3.14159

class MyCircle {
private:
    double x;
    double y;
    double radius;
    std::string color;
    double getArea() const;
    double getPerimeter() const;

public:
    MyCircle();
    ~MyCircle();
    void setX(double x);
    void setY(double y);
    void setRadius(double radius);
    void setColor(std::string color);
    void display() const;

};

MyCircle::MyCircle() {
    this->x = 0.0;
    this->y = 0.0;
    this->radius = 1.0;
    this->color = "blue";
}

MyCircle::~MyCircle() {
    std::cout << "Object destroyed" << std::endl;
}

void MyCircle::setX(double x) {
    if (x >= -100 && x <= 100)
        this->x = x;

    else
        std::cout << "Invalid coordinate !!!" << std::endl;
}

void MyCircle::setY(double y) {
    if (y >= -100 && y <= 100)
        this->y = y;

    else
        std::cout << "Invalid coordinate !!!" << std::endl;
}

void MyCircle::setRadius(double radius) {
    if (radius >= 0 && radius <= 100)
        this->radius = radius;

    else
        std::cout << "Invalid radius !!!" << std::endl;
}

void MyCircle::setColor(std::string color) {

    this->color = color;
}

void MyCircle::display() const {
    std::cout << '(' << this->x << ',' << this->y << ") radius: " << this->radius << "  color: " << this->color << "  area: " << this->getArea() << "  perimeter: " << this->getPerimeter() << std::endl;
}

double MyCircle::getArea() const {
    return PI * this->radius * this->radius;
}

double MyCircle::getPerimeter() const {
    return 2 * PI * this->radius;
}

int main()
{
    MyCircle c1;
    c1.display();

    c1.setRadius(5.2);
    c1.setX(10);
    c1.setColor("red");
    c1.display();
    
    MyCircle* cPtr = new MyCircle;
    cPtr->display();

    return 0;
}

#include <iostream>

class Date {
private:
	int day, month, year, hour, minute;

public:
	Date();
	Date(int, int, int, int, int);
	void displayDate();
};

Date::Date() {
	this->day = 1;
	this->month = 1;
	this->year = 1970;
	this->hour = 0;
	this->minute = 0;
}

Date::Date(int day, int month, int year, int hour, int minute) {
	this->day = day;
	this->month = month;
	this->year = year;
	this->hour = hour;
	this->minute = minute;
}

void Date::displayDate() {
	std::cout << this->day << "/" << this->month << "/" << this->year << " " << this->hour << "." << this->minute << std::endl;
}

class Tweet {
private:
	unsigned int id;
	unsigned int userId;
	std::string text;
	Date date;

public:
	Tweet();
	Tweet(int, int, std::string, Date date);
	Tweet(const Tweet&);
	void display();
};

Tweet::Tweet() {
	this->id = 1;
	this->userId = 1;
	this->text = "Hello World!";
	this->date = date;
}

Tweet::Tweet(int id, int userId, std::string text, Date date) {
	this->id = id;
	this->userId = userId;
	this->text = text;
	this->date = date;
}

Tweet::Tweet(const Tweet& t) {
	id = t.id;
	userId = t.userId;
	text = t.text;
	date = t.date;
}

void Tweet::display() {
	std::cout << "Tweet Id:" << this->id << std::endl;
	std::cout << "Tweet User Id:" << this->id << std::endl;
	std::cout << "Text:" << this->text << std::endl;
	std::cout << "Date:"; date.displayDate();
	std::cout << " " << std::endl;
}

int main() {
	Tweet t;
	Date();
	Tweet t2(2, 2, "Hello World! #World", Date(12, 06, 2022, 18, 30));
	Tweet t3{ t };
	t.display();
	t2.display();
	t3.display();

	return 0;
}

#include <iostream>
using namespace std;

class Card {
private:
	int suitValue;
	int faceValue;
	const static string suit[4];
	const static string face[13];
public:
	void set(int suitValue, int faceValue) {
		this->suitValue = suitValue;
		this->faceValue = faceValue;
	}

	string toString() {
		return Card::face[this->faceValue] + " of " + Card::suit[this->suitValue];
	}
};

const string Card::suit[4] = { "Diamonds", "Hearts", "Clubs", "Spades" };
const string Card::face[13] = { "Ace","2","3", "4", "5", "6","7", "8", "9", "10", "Jack", "Queen", "King" };

class CardDeck {
private:
	Card cards[52];
	int currentCard;
public:
	CardDeck();
	void dealNext();
	void reset();
	void shuffle();
	bool isEmpty() const;
};

CardDeck::CardDeck() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			cards[13 * i + j].set(i, j);
		}
	}
	reset();
}

void CardDeck::reset() {
	this->currentCard = 52;
}

bool CardDeck::isEmpty() const {
	if (this->currentCard == 0) return true;
	else return false;
}

void CardDeck::dealNext() {
	if (isEmpty()) {
		cout << "Deck is empty" << endl;
	}
	cout << cards[--this->currentCard].toString() << endl;
}

void CardDeck::shuffle() {
	int randomCard;
	Card temp;
	for (int i = 0; i < 52; i++) {
		randomCard = rand() % 52;
		temp = cards[i];
		cards[i] = cards[randomCard];
		cards[randomCard] = temp;
	}
}

int main() {
	CardDeck deck;

	for (int i = 0; i < 5; i++) {
		deck.dealNext();
	}
    deck.reset();
	cout << endl;
	
	deck.shuffle();
	for (int i = 0; i < 5; i++) {
		deck.dealNext();
	}

	return 0;
}
