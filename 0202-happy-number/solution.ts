function isHappy(n: number): boolean {
    const map = new Map<number, boolean>();
    while(!map.get(n)) {
        if(n === 1) return true;
        map.set(n, true);
        let tmp = 0;
        while(n > 0) {
            const rem = (n % 10);
            tmp += (rem * rem);
            n = 0 | (n / 10);
        }
        n = tmp;
    }
    return false;
};
