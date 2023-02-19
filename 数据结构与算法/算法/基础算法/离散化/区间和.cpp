//https://www.acwing.com/problem/content/804/

//��ɢ����ֻ���±꣬��Ҫ���������������Ҳ��ɢ��
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

int n, m;

//a����洢������������ֵ��s����洢a�����ǰ׺��
int a[N], s[N];

//alls�洢���д���ɢ����ֵ����Ԫ����������
vector<int> alls;
//add�洢x��c��query�洢��ѯ�����������±�
vector<PII> add, query;

//alls��Ԫ���±��0��ʼ
//�ҵ�alls�б�x��ĵ�һ��ֵ��Ӧ���±꣬
//���൱���ҵ�����ȥ�غ�x��alls�ж�Ӧ���±꣬��ʹ��+1
//����ӳ��������Ԫ���±���С��1������ǰ׺��
int find (int x)
{
    int l = 0, r = alls.size() - 1;
    
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    
    //�˴�����ɢ���ӳ���ֵ��+1����֤�����±��1��ʼ
    return r + 1;
}

int main ()
{
    cin >> n >> m;
    
    //������¼��
    while (n--)
    {
        int x, c;
        cin >> x >> c;
        
        add.push_back({x, c});
        
        //�˴�ֻ������±꼴�ɣ�c���ò���
        alls.push_back(x);
    }
    
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        
        query.push_back({l, r});
        
        alls.push_back(l);
        alls.push_back(r);
    }
    
    //�����򣬺�ȥ��
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    
    //ִ�и��Ĳ���
    for (auto item : add)
    {
        int x = find(item.first);
        a[x] += item.second;
    }
    
    //ά��ǰ׺������
    int len = alls.size();
    for (int i = 1; i <= len; i++ ) s[i] = s[i-1] + a[i];
    
    //ִ�в�ѯ����
    for (auto item : query)
    {
        int l = find(item.first);
        int r = find(item.second);
        
        cout << s[r] - s[l-1] << endl;
    }
    
    return 0;
}

//map����
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define pii pair<int, int>
const int inf = 1e9 + 5;
vector<pii> a;
map<int, int> mp;

int main()
{
    int n, m;
    cin >> n >> m;
    while(n --)
    {
        int x, c;
        cin >> x >> c;
        if(mp.find(x) == mp.end()) mp[x] = c;  //xδ���ֹ�
        else mp[x] += c;  //x���ֹ�
    }
    //��Щ������ɹ���map�Ѿ��Զ�������Ԫ��ȥ�ز����ź�����

    int sum = 0;
    for(pii x : mp)  //����ǰ׺��
    {
        a.push_back({x.first, sum});  //�����sum������x.first�ϵ�ֵ������ʹ��upper_bound()
        sum += x.second;
    }
    a.push_back({inf, sum});  //����һ�������ĵ㣬���㴦��
    //��Ϊmp������ģ�����a�������
    while(m --)
    {
        int l, r;
        cin >> l >> r;
        
        //�˴�Ҫע�⣬pair������ԭ������ȱȽϵ�һ��Ԫ�صĴ�С��ϵ��Ȼ���ٱȽϵڶ���Ԫ�صĴ�С��ϵ
        //lower_bound �ҵ����ڵĵ�
        //pair�еڶ���Ԫ�أ�Ҳ����ǰ׺�ͣ����ǽ�����Ϊ����С�����Ա�֤�ҵ���һ�����ڵ���l�ĵ�
        //ͬ�������еڶ���Ԫ����Ϊ����󣬾Ϳ��Ա�֤������һ������r�ĵ�
        auto p1 = lower_bound(a.begin(), a.end(), (pii){l , -inf}); 
        auto p2 = lower_bound(a.begin(), a.end(), (pii){r , inf});  

        //��ǰ׺�͵ķ�ʽ��������Ҫs[r] - s[l - 1]����������a��k�±��Ӧ��ǰ׺�Ͳ�����k��
        //���������ڽ���lower_bound����ʱ�ҵ������� l �� r + 1
        //���� a[l] = c[0] + c[1] + ���� + c[l - 1]
        //a[r + 1] = c[0] + ���� + c[r]�������������������ͬ��
        cout << p2 -> second - p1 -> second << endl;
    }
    return 0;
}
