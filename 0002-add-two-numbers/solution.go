func ins(rem int, sum *ListNode) (int, *ListNode) {
    curr := &ListNode{}
    sum.Next = curr
    if rem < 10 {
        curr.Val = rem
        rem = 0
    } else {
        curr.Val = (rem % 10)
        rem /= 10
    }
    return rem, curr
}

func result(rem int, l1 *ListNode, l2 *ListNode, sum *ListNode) {
    if l1 == nil && l2 == nil {
        if rem != 0 {
            rem, curr := ins(rem, sum)
            result(rem, l1, l2, curr)
        }
    } else if l1 == nil {
        rem = rem + l2.Val
        rem, curr := ins(rem, sum)
        result(rem, l1, l2.Next, curr)
    } else if l2 == nil {
        rem = rem + l1.Val
        rem, curr := ins(rem, sum)
        result(rem, l1.Next, l2, curr)
    } else {
        rem = rem + l1.Val + l2.Val
        rem, curr := ins(rem, sum)
        result(rem, l1.Next, l2.Next, curr)
    }
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    sum := &ListNode{}
    result(0, l1,l2, sum)
    return sum.Next
}
