#pragma once
#include <string>
#include <list>
using namespace std;

class Score
{
private:
	int id;
	string user;
	float score;
	int longueur_test;


public:
	Score(int, string, float, int);
	~Score (void);

	int getId();
	string getUser();
	float getScore();
	int getLongueur_test();

	void setId(int);
	void setUser(string);
	void setScore(float);
	void setLongueur_test(int);


};

