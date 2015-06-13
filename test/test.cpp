#include<iostream>
using namespace std;
class Scores
{
public:
	Scores();
	Scores(const Scores&right);
	~Scores();
	void print_score();
	double final_score();
private:
	double *scores;
};

Scores::Scores()
{
	scores = new double[8];
	//��ʼ��Ϊ0
	for (int i = 0; i < 8; i++) scores[i] = 0;
}

Scores::Scores(const Scores &right) {
	scores = new double[8];
	for (int i = 0; i < 8; i++) scores[i] = right.scores[i];
}

Scores::~Scores()
{
	delete[]scores;
}

void Scores::print_score() {
	//��ӡ����
	for (int i = 0; i < 8; i++) {
		cout << scores[i] << endl;
	}
}

double Scores::final_score() {
	double min = scores[0], max = scores[0], sum = scores[0];
	for (int i = 1; i < 8; i++) {
		sum += scores[i];
		if (min > scores[i]) min = scores[i];
		if (max < scores[i]) max = scores[i];
	}
	sum = sum - min - max;
	return sum / 6;
}
int main(void)	{
	Scores sc;
	//(1)��ʾsc�������ϸ��Ϣ
	sc.print_score();
	//(2)�������յ÷�
	cout << sc.final_score() << endl;
	//(3)��ȫ�������������
	Scores anotherScores(sc);
	anotherScores.print_score();
	return 0;
}