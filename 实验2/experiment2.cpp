#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include "dataStruct.h"
#include "algorithm.h"
using namespace std;

int mode = 0;
//mode=1:演示模式，ID从0开始增加，洪泛时间间隔始终为4
//mode=0:运行模式，ID随机，洪泛时间随机
void run_main(int mode, int interval) {
	if (mode) {
		srand(time(0));
		int n = 0, begin = 1;
		printf("请输入开始结点:");
		cin>>begin;
		memset(dis, INFIN, sizeof dis);
		memset(vis, false, sizeof vis);
		memset(harsh, 0, sizeof harsh);
		int ID = 1;
		int randTime = 1;
		while (1) {
			n = get_n("data.txt");
			n++;
			adj_list.resize(n);
			randTime = interval;
			printf("下一次洪泛时间：%d秒之后\n", randTime);
			std::this_thread::sleep_for(std::chrono::seconds(randTime));
			if (complete(n)) {
				Dijkstra(begin, n);
				print_result(begin, n);
			} else {
				if (harsh[ID]) {
					continue;
				} else {
					Flooding("data.txt", ID);
					harsh[ID] = 1;
				}
			}
			printHarsh(n);
			printf("选中节点编号：%d\n", ID);
			printf("当前矩阵\n");
			print_adj(n);
			ID < n - 1 ? ID++ : ID = 1;
		}
//		Dijkstra(begin, n);
//		print_result(begin, n);

	} else {
		srand(time(0));
		int n = 0, begin = 1;
		memset(dis, INFIN, sizeof dis);
		memset(vis, false, sizeof vis);
		memset(harsh, 0, sizeof harsh);
		int ID = 1;
		int randTime = 1;
		printf("请输入开始结点:");
		cin>>begin;
		while (1) {
			n = get_n("data.txt");
			n++;
			adj_list.resize(n);
			ID = rand() % (n - 1) + 1;
			randTime = rand() % 100;
			printf("下一次洪泛时间：%d秒之后\n", randTime);
			std::this_thread::sleep_for(std::chrono::seconds(randTime));
			if (complete(n)) {
				Dijkstra(begin, n);
				print_result(begin, n);
			} else {
				if (harsh[ID]) {
					continue;
				} else {
					Flooding("data.txt", ID);
					harsh[ID] = 1;
				}
			}
			//printHarsh(n);
			printf("选中节点编号：%d\n", ID);
			printf("当前矩阵\n");
			print_adj(n);
			//ID++;
		}
//		Dijkstra(begin, n);
//		print_result(begin, n);
	}

}
int main() {
	//mode=1:演示模式，ID从0开始增加，洪泛时间间隔始终为interval
	//mode=0:运行模式，ID随机，洪泛时间随机
	mode = 1;
	int interval = 1;
	run_main(mode, interval);
	return 0;
}

