#include <iostream>
#include <time.h>

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
private:
    int val_, n_;
    ListNode* cur_, *head_;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        val_ = head->val;
        n_ = 1;
        head_ = head;
        cur_ = head->next;
        if (cur_==NULL) cur_ = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
		srand((unsigned)time(NULL));
		val_ = head_->val;
		while(cur_)
		{
			int idx = rand()%(n_+1);
			if (idx < 1)
				val_ = cur_->val;
			cur_ = cur_->next;n_++;
		}
		if (cur_ == NULL) {cur_ = head_; n_ = 1;}
		return val_;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

int main()
{
	ListNode* list = new ListNode(1000);
	ListNode* cur = list;
	int total = 1000, n = 1;
	while(total--)
	{
		cur->next = new ListNode(total);
		cur = cur->next;
	}
	Solution s(list);
	while (1)
	{
		int v = s.getRandom();
		std::cout<<v<<std::endl;
	}
}