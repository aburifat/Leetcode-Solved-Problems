func GetNextNode(head *ListNode) (int, *ListNode) {
    if head.Next == nil {
        return head.Val, head
    }
    mx, next := GetNextNode(head.Next)
    if mx > head.Val {
        return mx, next
    }
    head.Next = next
    return head.Val, head
}

func removeNodes(head *ListNode) *ListNode {
    _, head = GetNextNode(head)
    return head
}
