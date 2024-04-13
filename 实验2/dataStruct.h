#include<iostream>
#include<queue>
#include "parameters.h"
using namespace std;
struct Edge {
	int to, weight;
	Edge(int t, int w) : to(t), weight(w) {}
};
		
vector<vector<Edge>> adj_list;
int dis[SIZE], vis[SIZE], pre[SIZE];
bool harsh[SIZE];


/**  
 * @brief 检查哈希表是否完整  
 *  
 * 遍历哈希表数组，检查每个元素是否都已标记为已处理（非零值）。  
 * 如果存在未处理的元素，则返回 false；否则返回 true。  
 *  
 * @param n 哈希表的大小  
 *  
 * @return 如果哈希表完整则返回 true，否则返回 false  
 */  
bool complete(int n) {  
	for (int i = 1; i < n; i++) {  
		if (harsh[i] == 0) {  
			return false;  
		}  
	}  
	return true;  
}  

/**  
 * @brief 打印哈希表内容  
 *  
 * 遍历哈希表数组，并依次打印每个元素的值。  
 *  
 * @param n 哈希表的大小  
 */  
void printHarsh(int n) {  
	for (int i = 1; i < n; i++) {  
		printf("%d", harsh[i]);  
	}  
	printf("\n");  
}  

/**  
 * @brief 打印邻接矩阵  
 *  
 * 根据邻接表 adj_list，打印出对应的邻接矩阵。  
 * 如果边的权重小于10，则前面加一个空格；否则直接打印权重。  
 * 如果两个节点之间没有边相连，则打印 "INF"。  
 *  
 * @param n 节点数量  
 */  
void print_adj(int n) {  
	for (int i = 1; i < n; i++) {  
		for (int j = 1; j < n; j++) {  
			bool found = false;  
			for (auto &edge : adj_list[i]) {  
				if (edge.to == j) {  
					if (edge.weight < 10) {  
						printf(" %d  ", edge.weight);  
					} else {  
						printf("%d  ", edge.weight);  
					}  
					found = true;  
					break;  
				}  
			}  
			if (!found) {  
				printf("INF ");  
			}  
		}  
		printf("\n");  
	}  
}  


/**  
 * @brief 获取当前节点个数  
 *  
 * 从指定的文件路径 path_file 中读取节点个数，并返回该值。  
 * 如果文件无法打开，则输出错误信息并退出程序。  
 *  
 * @param path_file 文件路径  
 *  
 * @return 节点个数  
 */  
int get_n(const char* path_file) {  
	FILE* f = NULL;  
	int n;  
	if (f = fopen(path_file, "r")) {  
		fscanf(f, "%d", &n);  
	} else {  
		cout << "can't open the file: " << path_file << endl;  
		exit(1);  
	}  
	return n;  
}
