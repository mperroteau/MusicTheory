#include "Score.h"

Score::Score(int _id, string _user, float _score, int _longueur_test)
{
	id = _id;
	user = _user;
	score = _score;
	longueur_test = _longueur_test;

}

Score::~Score (void)
{

}
	
int Score::getId()
{
	return id;
}

string Score::getUser()
{
	return user;
}

float Score::getScore()
{
	return score;
}

int Score::getLongueur_test()
{
	return longueur_test;
}

void Score::setId(int _id)
{
	id = _id;
}

void Score::setUser(string _user)
{
	user=_user;
}

void Score::setScore(float _score)
{
	score = _score;
}

void Score::setLongueur_test(int _longueur_test)
{
	longueur_test = _longueur_test;
}
