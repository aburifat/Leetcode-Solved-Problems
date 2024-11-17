interface ColorPos {
    color: number,
    index: number
}
function maxDistance(colors: number[]): number {
    let colorPoses: ColorPos[] = [{
        color: colors[0],
        index: 0
    } as ColorPos];
    let ans: number = 0;
    for (let i = 1; i < colors.length; i++) {
        let ck: boolean = false;
        colorPoses.forEach((colorPos) => {
            if (colorPos.color != colors[i]) {
                ans = Math.max(ans, i - colorPos.index);
                ck = true;
                return;
            }
        });
        if (ck && colorPoses.length < 2) {
            colorPoses.push({
                color: colors[i],
                index: i
            } as ColorPos);
        }
    }
    return ans;
};
