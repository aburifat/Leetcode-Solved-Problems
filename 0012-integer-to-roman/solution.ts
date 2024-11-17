const values: number[] = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
const symbols: string[] = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"];
function intToRoman(num: number): string {
    let roman: string = "";
    for (let i = 0; i < values.length; i++) {
        while (values[i] <= num) {
            roman += symbols[i];
            num -= values[i];
        }
    }
    return roman;
};
