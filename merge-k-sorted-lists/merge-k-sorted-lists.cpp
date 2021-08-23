/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> sol;
        for(auto lis:lists){
            while(lis){
                sol.push_back(lis->val);
                lis=lis->next;
            }
            
        }
        sort(sol.begin(),sol.end());
        for(int i=0;i<sol.size();i++){
                cout<<sol[i]<<" ";
        }
        cout<<endl;
        ListNode dummy(INT_MIN);
        ListNode *head = &dummy;
        for(int i=0;i<sol.size();i++){
            ListNode* tt=new ListNode(sol[i]);
            head->next=tt;
            head=head->next;
        }
        // head->next=NULL;
        return dummy.next;
    }
};