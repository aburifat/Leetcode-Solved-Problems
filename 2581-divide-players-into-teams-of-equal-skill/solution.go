func dividePlayers(skill []int) int64 {
    var ans int64 = 0
    sort.Ints(skill)
    validSkill := skill[0] + skill[len(skill) - 1]
    for i, j := 0, len(skill) - 1; i < j; i, j = i + 1, j - 1 {
        if skill[i] + skill[j] != validSkill {
            return -1
        }
        ans += int64(skill[i] * skill[j])
    }
    return ans
}
