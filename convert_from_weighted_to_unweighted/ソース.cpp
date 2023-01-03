//有向重み付きタイムスタンプありグラフから無向重み無しタイムスタンプ無しグラフに変換して, ついでに枝の重複もなくして, txtファイルに出力するプログラム
#include<iostream>
#include<vector>
#include<set>
#include<fstream>
#include<string>

using namespace std;

int main() {
	long long int n, m;//頂点数,枝数
	long long int new_m = 0;//作り直した無向グラフの枝数
	vector<set<long long int>> G;//出力したいグラフ

	//入力開始.
	ifstream ifs1("Infectious.txt");

	if (!ifs1) {
		std::cout << "Errer!";
		return 1;
	}

	string s;
	long long int count = 0;
	long long int x = 0;
	long long int y = 0;

	while (getline(ifs1, s, ' ')) {     // スペース（' '）で区切って，格納
		cout << "count:" << count << endl;
		if (count == 0) {//頂点数
			n = stoll(s);
			G.resize(n); //グラフの大きさ確保
			count++;
		}
		else if (count == 1) {//枝数
			m = stoll(s);
			count++;
		}
		else if (count > 1 && count % 4 == 2) {//グラフの枝の端点
			x = stoll(s);
			x--;
			count++;
		}
		else if (count > 1 && count % 4 == 3) {//グラフの枝のもう一つの端点
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
		else if (count > 1 &&(count % 4 == 1 || count % 4 == 0)) {//重み部分,タイムスタンプ飛ばす
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