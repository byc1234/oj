    ListNode* oddEvenList(ListNode* head) {
        if (head != nullptr){
            ListNode* odd = head;
            ListNode* even = head->next;
            ListNode* p = even;
    
            while (odd->next != nullptr && even->next != nullptr){
                odd->next = even->next;
                odd = odd->next;
                even->next = odd->next;
                even = even->next;
            }
            odd->next = p;
        }
        return head;
    }

