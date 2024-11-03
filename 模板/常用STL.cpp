//优先队列
//不写后面两个参数默认为vector，less
priority_queue<int> pq1;
//建立一个优先级队列(大堆)，数据类型是int，利用vector容器实现，less实现大堆 
priority_queue<int, vector<int>, less<int>> pq2;
//建立一个优先级队列(小堆)，数据类型是int，利用vector容器实现，greater小堆 
priority_queue<int, vector<int>, greater<int>> pq3;
//自定义类型
typedef pair<int, int> PII;
priority_queue<PII, vector<PII>, greater<PII>>  pq4;
//自定义比较函数 
class CustomCompare {  
public:  
    bool operator()(int a, int b) {  
        // 这里定义比较规则，例如：小的优先级高  
        return a > b; // 小堆  greater 
    }  
}; 


//unordered_map存储数据是无序的
//key为键， T为值 
unordered_map<key, T>  omap;
//遍历操作
for (auto it = map.begin(); it != map.end(); ++it) {
    std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
}
//插入、删除
omap.insert(make_pair(key, value));
omap.erase(key); 
//直接访问
omap[key]=value;


//map存储有序的数据 
