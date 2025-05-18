func maxArea(height []int) int {
    l, r := 0, len(height) - 1
    area := 0
    for l < r {
        tmp := min(height[l], height[r]) * (r - l);

        if tmp > area {
            area = tmp
        }

        if height[l] > height[r] {
            r = r - 1
        } else {
            l = l + 1
        }
    }

    return area
}
