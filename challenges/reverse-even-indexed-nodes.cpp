SinglyLinkedListNode* extractAndAppendSponsoredNodes(SinglyLinkedListNode* head) {

    if (!head || !head->next) return head;

    SinglyLinkedListNode *oddHead = NULL, *oddTail = NULL;
    SinglyLinkedListNode *evenRevHead = NULL;

    SinglyLinkedListNode* curr = head;
    int index = 0;

    while (curr) {
        SinglyLinkedListNode* nextNode = curr->next;

        if (index % 2 == 0) {
            curr->next = evenRevHead;
            evenRevHead = curr;
        } else {
            if (!oddHead) {
                oddHead = curr;
                oddTail = curr;
                oddTail->next = NULL;
            } else {
                oddTail->next = curr;
                oddTail = curr;
                oddTail->next = NULL;
            }
        }

        curr = nextNode;
        index++;
    }

    if (!oddHead) return evenRevHead;

    oddTail->next = evenRevHead;

    return oddHead;
}
