#include <iostream>
#include <string.h> 
using namespace std; 
const int MAX_N = 10000;  // Trie 树上的最大结点数
const int MAX_C = 26;  // 每个结点的子结点个数上限
struct Trie {
    int *ch[MAX_N];  // ch 保存了每个结点的 26 个可能的子结点编号，26 对应着 26 种小写字母，也就是说，插入的字符串全部由小写字母组成。初始全部为 -1
    int tot;  // 总结点个数（不含根结点），初始为 0
    int cnt[MAX_N];  // 以当前结点为终端结点的 Trie 树中的字符串个数

    void init() {  // 初始化 Trie 树，根结点编号始终为 0
        tot = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(ch, -1, sizeof(ch));
    }

    void insert(char *str) {
        int p = 0;  // 从根结点（0）出发
        if(ch[p]==NULL){
        	ch[p] = new int[MAX_C];
        	memset(ch[p],-1,sizeof(int)*MAX_C);
		}
        for (int i = 0; str[i]; ++i) {
            if (ch[p][str[i] - 'a'] == -1) {  // 该子结点不存在
                ch[p][str[i] - 'a'] = ++tot;  // 新增结点
            } 
            p = ch[p][str[i] - 'a'];  // 在 Trie 树上继续插入字符串 str
        }
        cnt[p]++;
    }

    int find(char *str) {  // 返回字符串 str 的出现次数
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
