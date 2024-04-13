#include<iostream>
#include<stdio.h>
#include<queue>
#include <cstdlib>
#include <ctime>
#include "parameters.h"

/**  
* @brief 迪杰斯特拉算法  
 *  
 * 使用迪杰斯特拉算法计算从指定起点到所有其他节点的最短路径。  
 *  
 * @param begin 起点节点编号  
 * @param n 节点总数  
 */  
void Dijkstra(int begin, int n) {  
	dis[begin] = 0; // 设置起点到自身的距离为0  
	for (int i = 1; i <= n; ++i) {  
		int min_node = 0, min_dis = INFIN; // 初始化最小节点和最小距离  
		for (int j = 1; j <= n; ++j) {  
			// 寻找未访问过的节点中距离最小的节点  
			if (!vis[j] && dis[j] < min_dis) {  
				min_node = j;  
				min_dis = dis[j];  
			}  
		}  
		vis[min_node] = true; // 标记当前最小节点为已访问  
		for (auto &edge : adj_list[min_node]) { // 遍历当前最小节点的邻接边  
			int old_dis = dis[edge.to], new_dis = dis[min_node] + edge.weight; // 旧的距离和新的距离  
			if (old_dis > new_dis) { // 如果新的距离更短  
				dis[edge.to] = new_dis; // 更新最短距离  
				pre[edge.to] = min_node; // 更新前驱节点  
			}  
		}  
	}  
}  

/**  
 * @brief 打印迪杰斯特拉算法结果  
 *  
 * 根据起点 begin、节点数量 n、最短距离数组 dis、前驱节点数组 pre，  
 * 打印出从起点到各个节点的最短路径及其长度。  
 * 如果某个节点与起点不可达，则打印 "No path from node begin to node i"。  
 *  
 * @param begin 起点节点编号  
 * @param n 节点数量  
 */  
void print_result(int begin, int n) {  
	for (int i = 1; i < n; ++i) {  
		if (dis[i] == INFIN) {  
			cout << "No path from node " << begin << " to node " << i << endl;  
		} else {  
			vector<int> path;  
			int dest = i;  
			while (dest != begin) {  
				path.push_back(dest);  
				dest = pre[dest];  
			}  
			path.push_back(begin);  
			
			cout << "Shortest path from node " << begin << " to node " << i << ": ";  
			for (int j = path.size() - 1; j >= 0; --j) {  
				cout << path[j];  
				if (j > 0) cout << " -> ";  
			}  
			cout << ". Distance: " << dis[i] << endl;  
		}  
	}  
}  


/**  
 * @brief Flooding算法  
 *  
 * 从指定的文件中读取边信息，并构建邻接表。仅添加与指定路由ID相关的边。  
 *  
 * @param path_file 文件路径  
 * @param routeId 路由ID  
 */  
void Flooding(const char* path_file, int routeId) {  
	FILE* fp = NULL;  
	int n;  
	if (fp = fopen(path_file, "r")) { // 打开文件  
		fscanf(fp, "%d", &n); // 读取节点数量  
		while (!feof(fp)) { // 循环读取文件直到末尾  
			int node1, node2, distance; // 定义节点和距离变量  
			fscanf(fp, "%d %d %d", &node1, &node2, &distance); // 读取边的信息  
			if (node1 == routeId) { // 如果边的起点是指定的路由ID  
				adj_list[node1].push_back(Edge(node2, distance)); // 添加正向边到邻接表  
				adj_list[node2].push_back(Edge(node1, distance)); // 添加反向边到邻接表  
			}  
		}  
	} else {  
		cout << "无法打开文件: " << path_file << endl;  
		exit(1); // 文件打开失败，退出程序  
	}  
}
