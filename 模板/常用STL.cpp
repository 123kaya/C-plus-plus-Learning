//���ȶ���
//��д������������Ĭ��Ϊvector��less
priority_queue<int> pq1;
//����һ�����ȼ�����(���)������������int������vector����ʵ�֣�lessʵ�ִ�� 
priority_queue<int, vector<int>, less<int>> pq2;
//����һ�����ȼ�����(С��)������������int������vector����ʵ�֣�greaterС�� 
priority_queue<int, vector<int>, greater<int>> pq3;
//�Զ�������
typedef pair<int, int> PII;
priority_queue<PII, vector<PII>, greater<PII>>  pq4;
//�Զ���ȽϺ��� 
class CustomCompare {  
public:  
    bool operator()(int a, int b) {  
        // ���ﶨ��ȽϹ������磺С�����ȼ���  
        return a > b; // С��  greater 
    }  
}; 


//unordered_map�洢�����������
//keyΪ���� TΪֵ 
unordered_map<key, T>  omap;
//��������
for (auto it = map.begin(); it != map.end(); ++it) {
    std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
}
//���롢ɾ��
omap.insert(make_pair(key, value));
omap.erase(key); 
//ֱ�ӷ���
omap[key]=value;


//map�洢��������� 
