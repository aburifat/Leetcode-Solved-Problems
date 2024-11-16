function largestInteger(num: number): number {
    const oddDigits: number[] = [];
    const evenDigits: number[] = [];
    const reservation: boolean[] = [];

    while (num > 0) {
        const mod = Math.floor(num % 10);
        if (Math.floor(mod % 2) === 0) {
            evenDigits.push(mod);
            reservation.push(true);
        }
        else {
            oddDigits.push(mod);
            reservation.push(false);
        }
        num = Math.floor(num / 10);
    }
    evenDigits.sort();
    evenDigits.reverse();
    oddDigits.sort();
    oddDigits.reverse();
    reservation.reverse();
    let oddIdx = 0, evenIdx = 0;
    num = 0;
    for (let i = 0; i < reservation.length; i++) {
        num *= 10;
        if (reservation[i]) {
            num += evenDigits[evenIdx++];
        }
        else {
            num += oddDigits[oddIdx++];
        }
    }
    return num;
};
