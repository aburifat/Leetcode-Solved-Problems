func solve(left, right *TreeNode, parity bool) {
    if left == nil { return }
    if parity { left.Val, right.Val = right.Val, left.Val }
    solve(left.Left, right.Right, !parity)
    solve(left.Right, right.Left, !parity)
}

func reverseOddLevels(root *TreeNode) *TreeNode {
    solve(root.Left, root.Right, true)
    return root
}
