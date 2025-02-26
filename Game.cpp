#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int lv1, lv2, lv3, lv4, lv5, lv6, lv7, lv8, lv9 = 0;
const string fp = "E:/zsz/OI/C++/code/日常code/Game code/抽卡游戏/Data/";

void sc(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void rlff() {
	int *levels[] = {&lv1, &lv2, &lv3, &lv4, &lv5, &lv6, &lv7, &lv8, &lv9};
	for (int i = 0; i < 9; ++i) {
		string filename = fp + "lv" + to_string(i + 1) + ".txt";
		FILE *fp = fopen(filename.c_str(), "r");
		if (fp != NULL) {
			fscanf(fp, "%d", levels[i]);
			fclose(fp);
		}
	}
}

void wltf() {
	int levels[] = {lv1, lv2, lv3, lv4, lv5, lv6, lv7, lv8, lv9};
	for (int i = 0; i < 9; ++i) {
		string filename = fp + "lv" + to_string(i + 1) + ".txt";
		FILE *fp = fopen(filename.c_str(), "w");
		if (fp != NULL) {
			fprintf(fp, "%d", levels[i]);
			fclose(fp);
		}
	}
}

int grl() {
	int ans = rand() % 2048 + 1;
	if (ans <= 512)
		return 1;
	if (ans <= 768)
		return 2;
	if (ans <= 896)
		return 3;
	if (ans <= 960)
		return 4;
	if (ans <= 992)
		return 5;
	if (ans <= 1008)
		return 6;
	if (ans <= 1016)
		return 7;
	if (ans <= 1020)
		return 8;
	if (ans <= 1022)
		return 9;
	return 0;
}

int grl1() {
	int ans = rand() % 1022 + 1;
	if (ans <= 512)
		return 1;
	if (ans <= 768)
		return 2;
	if (ans <= 896)
		return 3;
	if (ans <= 960)
		return 4;
	if (ans <= 992)
		return 5;
	if (ans <= 1008)
		return 6;
	if (ans <= 1016)
		return 7;
	if (ans <= 1020)
		return 8;
	if (ans <= 1022)
		return 9;
}

void showM() {
	sc(14);
	cout << "======================================================\n";
	cout << "|                   抽卡游戏 v1.2.0                  |\n";
	cout << "|====================================================|\n";
	cout << "| [L] 抽卡                                           |\n";
	cout << "| [W] 仓库                                           |\n";
	cout << "| [C] 合成                                           |\n";
	cout << "| [B] 对战                                           |\n";
	cout << "| [T] 说明                                           |\n";
	cout << "| [S] 退出                                           |\n";
	cout << "======================================================\n";
	sc(7);
	cout << "请输入选项：";
}

void showW() {
	sc(11);
	int lv[9] = {lv1, lv2, lv3, lv4, lv5, lv6, lv7, lv8, lv9};
	cout << "======================================================\n";
	cout << "|                   仓库 - 我的卡牌                  |\n";
	cout << "|====================================================|\n";
	for (int i = 1; i <= 9; i++) {
		cout << "| Lv" << i << ": ";
		for (int j = 1; j <= 9; j++) {
			cout << (j <= i ? "★" : "☆");
		}
		cout << "  × " << setw(22) << right << lv[i - 1] << " |\n";
	}
	cout << "======================================================\n";
	sc(7);
	cout << "按 [O] 键返回菜单：";
}

void showT() {
	sc(11);
	int lv[9] = {lv1, lv2, lv3, lv4, lv5, lv6, lv7, lv8, lv9};
	cout << "======================================================\n";
	cout << "|                    说明 - 游戏说明                 |\n";
	cout << "======================================================\n";
	cout << "|这是一个以抽卡和合成为主的游戏，                    |\n";
	cout << "|它会在每一次抽卡结束或合成结束或游戏结束时自动保存，|\n";
	cout << "|想了解更多内容也可以看下面的文档。                  |\n";
	cout << "|====================================================|\n";
	cout << "|抽奖概率：                                          |\n";
	cout << "|未抽中：约1/2    (50.00%)                           |\n";
	cout << "|lv1：   约1/4    (25.00%)                           |\n";
	cout << "|lv2：   约1/8    (12.50%)                           |\n";
	cout << "|lv3：   约1/16   (6.250%)                           |\n";
	cout << "|lv4：   约1/32   (3.125%)                           |\n";
	cout << "|lv5：   约1/64   (1.563%)                           |\n";
	cout << "|lv6：   约1/128  (0.781%)                           |\n";
	cout << "|lv7：   约1/256  (0.391%)                           |\n";
	cout << "|lv8：   约1/512  (0.195%)                           |\n";
	cout << "|lv9：   约1/1024 (0.098%)                           |\n";
	cout << "|====================================================|\n";
	cout << "|抽奖概率：                                          |\n";
	cout << "|未抽中：     约1/2    (50.00%)                      |\n";
	cout << "|lv1->lv2：   约1/4    (25.00%)                      |\n";
	cout << "|lv2->lv3：   约1/8    (12.50%)                      |\n";
	cout << "|lv3->lv4：   约1/16   (6.250%)                      |\n";
	cout << "|lv4->lv5：   约1/32   (3.125%)                      |\n";
	cout << "|lv5->lv6：   约1/64   (1.563%)                      |\n";
	cout << "|lv7->lv8：   约1/256  (0.391%)                      |\n";
	cout << "|lv8->lv9：   约1/512  (0.195%)                      |\n";
	cout << "======================================================\n";
	sc(7);
	cout << "按 [O] 键返回菜单：";
}

void c() {
	system("cls");
	sc(12);
	cout << "======================================================\n";
	cout << "|                       合成模式                     |\n";
	cout << "======================================================\n";
	sc(14);
	cout << "请输入你要合成卡的等级（3张）：";
	int hc;
	cin >> hc;
	system("cls");
	cout << "是否进行批量合成？(y/n): ";
	char bc;
	cin >> bc;
	_sleep(1000);
	system("cls");
	int t = 1;
	if (bc == 'y' || bc == 'Y') {
		cout << "请输入批量合成的次数：";
		cin >> t;
	}
	system("cls");
	cout << "合成中...";
	_sleep(1000);
	system("cls");
	int *rc[] = {&lv1, &lv2, &lv3, &lv4, &lv5, &lv6, &lv7, &lv8};
	int *tc[] = {&lv2, &lv3, &lv4, &lv5, &lv6, &lv7, &lv8, &lv9};
	if (hc < 1 || hc > 8) {
		sc(12);
		cout << "输入的等级无效！" << endl;
	} else {
		for (int i = 0; i < t; ++i) {
			if (*rc[hc - 1] < 3) {
				sc(12);
				cout << "卡片数量不足，无法继续合成！" << endl;
				break;
			}
			int ans = rand() % 1000 + 1;
			if (ans < (1000 / (1 << hc))) {
				*tc[hc - 1] += 1;
				*rc[hc - 1] -= 3;
				sc(10);
				cout << "恭喜合成Lv" << hc + 1 << "卡片1张！" << endl;
			} else {
				int anss = (rand() % 2) + 1;
				*rc[hc - 1] -= (3 - anss);
				sc(7);
				cout << "合成失败，保留了" << anss << "张Lv" << hc << "卡片，损失了" << (3 - anss) << "张..." << endl;
			}
			_sleep(1000);
			system("cls");
		}
	}
	_sleep(1000);
	system("cls");
	wltf();
	cout << "游戏数据已保存！";
	_sleep(1000);
	system("cls");
}

void b() {
	system("cls");
	sc(12);
	cout << "======================================================\n";
	cout << "|                       对战模式                     |\n";
	cout << "|====================================================|\n";
	cout << "|请选择你要派出的卡牌等级（1-9）：                   |\n";
	sc(12);
	cout << "======================================================\n";
	int userLevel;
	cin >> userLevel;
	if (userLevel < 1 || userLevel > 9) {
		sc(12);
		cout << "输入的等级无效！\n";
		sc(7);
		_sleep(1000);
		return;
	}
	int *userCardCount[] = {&lv1, &lv2, &lv3, &lv4, &lv5, &lv6, &lv7, &lv8, &lv9};
	if (*userCardCount[userLevel - 1] < 1) {
		sc(12);
		cout << "你没有足够的卡牌进行对战！\n";
		sc(7);
		_sleep(1000);
		return;
	}
	int enemyLevel = grl1();
	sc(10);
	cout << "对手派出了Lv" << enemyLevel << "卡牌！\n";
	_sleep(1000);
	int levelDiff = userLevel - enemyLevel;
	double winRate = 0.0;
	if (levelDiff <= -3)
		winRate = 0.0;
	else if (levelDiff == -2)
		winRate = 0.25;
	else if (levelDiff == -1)
		winRate = 1.0 / 3.0;
	else if (levelDiff == 0)
		winRate = 0.5;
	else if (levelDiff == 1)
		winRate = 2.0 / 3.0;
	else if (levelDiff == 2)
		winRate = 0.75;
	else if (levelDiff >= 3)
		winRate = 1.0;
	int result = rand() % 100;
	system("cls");
	sc(12);
	cout << "======================================================\n";
	cout << "|                       对战模式                     |\n";
	cout << "|====================================================|\n";
	if (result < winRate * 100) {
		sc(10);
		cout << "你赢得了对战！获得了Lv" << enemyLevel << "卡牌1张！\n";
		*userCardCount[enemyLevel - 1] += 1;
	} else {
		sc(12);
		cout << "你输掉了对战！失去了Lv" << userLevel << "卡牌1张！\n";
		*userCardCount[userLevel - 1] -= 1;
	}
	_sleep(1000);
	wltf();
}

int main() {
	rlff();
	srand(time(0));
	bool gr = true;
	sc(14);
	cout << "欢迎回来！\n";
	_sleep(1000);
	system("cls");
	while (gr) {
		showM();
		char input;
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (tolower(input)) {
			case 'l':
				system("cls");
				sc(12);
				cout << "======================================================\n";
				cout << "|                      抽卡模式                      |\n";
				cout << "|====================================================|\n";
				sc(14);
				cout << "抽卡中...\n";
				_sleep(1000);
				system("cls");
				sc(12);
				cout << "======================================================\n";
				cout << "|                      抽卡模式                      |\n";
				cout << "|====================================================|\n";
				{

					int level = grl();
					if (level == 0) {
						sc(12);
						cout << "没有抽中哦...\n";
					} else {
						sc(10);
						cout << "恭喜抽中Lv" << level << "卡牌1张！\n";
						switch (level) {
							case 1:
								lv1++;
								break;
							case 2:
								lv2++;
								break;
							case 3:
								lv3++;
								break;
							case 4:
								lv4++;
								break;
							case 5:
								lv5++;
								break;
							case 6:
								lv6++;
								break;
							case 7:
								lv7++;
								break;
							case 8:
								lv8++;
								break;
							case 9:
								lv9++;
								break;
						}
					}
				}
				_sleep(1000);
				system("cls");
				wltf();
				break;
			case 'w':
				system("cls");
				showW();
				{
					char inputW;
					cin >> inputW;
					if (tolower(inputW) == 'o')
						system("cls");
				}
				break;
			case 'c':
				c();
				break;
			case 'b':
				b();
				break;
			case 't':
				system("cls");
				showT();
				{
					char inputW;
					cin >> inputW;
					if (tolower(inputW) == 'o')
						system("cls");
				}
				break;
			case 's':
				gr = false;
				break;
			default:
				sc(12);
				cout << "输入无效！请按提示输入选项。\n";
				_sleep(1000);
				system("cls");
				break;
		}
	}
	system("cls");
	sc(14);
	cout << "游戏数据已保存！\n";
	_sleep(1000);
}
