//�L���d�ݕt���O���t���疳���d�ݕt���O���t�ɕϊ�����, ���łɎ}�̏d�����Ȃ�����, txt�t�@�C���ɏo�͂���v���O����
#include<iostream>
#include<vector>
#include<set>
#include<fstream>
#include<string>

using namespace std;

int main() {
	long long int n, m;//���_��,�}��
	long long int new_m = 0;//��蒼���������O���t�̎}��
	vector<set<long long int>> G;//�o�͂������O���t

	//���͊J�n.
	ifstream ifs1("moreno_hens.txt");

	if (!ifs1) {
		std::cout << "Errer!";
		return 1;
	}

	string s;
	long long int count = 0;
	long long int x = 0;
	long long int y = 0;

	while (getline(ifs1, s, ' ')) {     // �X�y�[�X�i' '�j�ŋ�؂��āC�i�[
		cout << "count:" << count << endl;
		if (count == 0) {//���_��
			n = stoll(s);
			G.resize(n); //�O���t�̑傫���m��
			count++;
		}
		else if (count == 1) {//�}��
			m = stoll(s);
			count++;
		}
		else if (count > 1&& count<2+3*m && count % 3 == 2) {//�O���t�̎}�̒[�_
			x = stoll(s);
			x--;
			count++;
		}
		else if (count > 1 &&count<2+3*m&& count % 3 == 0) {//�O���t�̎}�̂�����̒[�_
			y = stoll(s);
			y--;
			count++;
			if (x < y) {
				G[x].insert(y);
			}
			else if (y < x) {
				G[y].insert(x);
			}
		}
		else if (count > 1 &&count<2+3*m &&count % 3 == 1) {//�d�ݕ�����΂�
			count++;
		}
	}
	ifs1.close();

	for (int i = 0; i < G.size(); i++) {
		for (auto itr = G[i].begin(); itr != G[i].end(); ++itr) {
			new_m++;
		}
	}

	ofstream outputfile("graph.txt");
	outputfile << n << " " << new_m << " " << endl;
	for (int i = 0; i < G.size(); i++) {
		for (auto itr = G[i].begin(); itr != G[i].end(); ++itr) {
			outputfile << i + 1 << " " << *itr + 1 << " " << endl;
		}
	}
	outputfile.close();
}