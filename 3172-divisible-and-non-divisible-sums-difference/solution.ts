function differenceOfSums(n: number, m: number): number {
    const step: number = Math.floor(n / m);
    const num2: number = (step * (step + 1) / 2) * m;
    const num1: number = (n * (n + 1) / 2) - num2;
    return Math.floor(num1 - num2);
};
