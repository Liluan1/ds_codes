#include <iostream>
#include <string.h> 
using namespace std; 
const int MAX_N = 10000;  // Trie ���ϵ��������
const int MAX_C = 26;  // ÿ�������ӽ���������
struct Trie {
    int *ch[MAX_N];  // ch ������ÿ������ 26 �����ܵ��ӽ���ţ�26 ��Ӧ�� 26 ��Сд��ĸ��Ҳ����˵��������ַ���ȫ����Сд��ĸ��ɡ���ʼȫ��Ϊ -1
    int tot;  // �ܽ���������������㣩����ʼΪ 0
    int cnt[MAX_N];  // �Ե�ǰ���Ϊ�ն˽��� Trie ���е��ַ�������

    void init() {  // ��ʼ�� Trie �����������ʼ��Ϊ 0
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(ch, -1, sizeof(ch));
    }

    void insert(char *str) {
        int p = 0;  // �Ӹ���㣨0������
        if(ch[p]==NULL){
        	ch[p] = new int[MAX_C];
        	memset(ch[p],-1,sizeof(int)*MAX_C);
		}
        for (int i = 0; str[i]; ++i) {
            if (ch[p][str[i] - 'a'] == -1) {  // ���ӽ�㲻����
                ch[p][str[i] - 'a'] = ++tot;  // �������
            } 
            p = ch[p][str[i] - 'a'];  // �� Trie ���ϼ��������ַ��� str
        }
        cnt[p]++;
    }

    int find(char *str) {  // �����ַ��� str �ĳ��ִ���
        int p = 0;
        for (int i = 0; str[i]; ++i) {
            if (ch[p][str[i] - 'a'] == -1) {
                return 0;
            }
            p = ch[p][str[i] - 'a'];
        }
        return cnt[p];
    }
};
int main()
{
	Trie a;
	a.init();
	a.insert("jige");
	a.insert("jige");
	cout<<a.find("jige");
	return 0;
}
