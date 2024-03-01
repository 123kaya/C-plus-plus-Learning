/*����
����->����*/
#include<iostream>
using namespace std;
struct TreeNode {
	char ch;
	TreeNode* left;
	TreeNode* right;
	TreeNode() {
		ch = ' ';
		left = NULL;
		right = NULL;
	}
};

typedef TreeNode* tree;
int len;
string mid = "";
string rear = "";

void builtTree(tree& root, string mid1, string rear1) {
	/*�������õ�ԭ��
	�޸�root��ָ�����rootΪ�β�
	��ô�޸ĺ󲢲��ᱣ�棬���Դ������ã�
	��������ܴ�ӡ���*/ 
	if(mid1.length() <= 0 ) {
		return;
	}
	tree node = new TreeNode();
	char ch = rear1[rear1.length()-1];
	int k = mid1.find(ch);
	node->ch = ch;
	root = node;
	string mid2 = "";
	string rear2 = "";
	string mid3 = "";
	string rear3 = "";
	for(int i = 0; i < k; i++) {
		mid2.push_back(mid1[i]);
	}

	for(int i = k+1; i < mid1.length(); i++) {
		mid3.push_back(mid1[i]);
	}

	for(int i = 0; i < rear1.length()-1; i++) {
		if(mid2.find(rear1[i]) != -1) {
			rear2.push_back(rear1[i]);
		} else
			rear3.push_back(rear1[i]);
	}
	builtTree(node->left,mid2,rear2);
	builtTree(node->right,mid3,rear3);
}

void print(TreeNode* root) {
	if(root == NULL) {
		return;
	}
	cout << root->ch;
	print(root->left);
	print(root->right);
}
int main() {
	cin >> mid >> rear;
	len = rear.length();
	tree root;
	builtTree(root,mid,rear);
	print(root);
	cout << endl;
}
