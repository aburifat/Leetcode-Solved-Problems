type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};

function expect(val: any): ToBeOrNotToBe {
    return {
        toBe: (valToBe: any) => {
            if (val !== valToBe) throw new Error("Not Equal");
            return true;
        },
        notToBe: (valNotToBe: any) => {
            if (val === valNotToBe) throw new Error("Equal");
            return true;
        }
    } satisfies ToBeOrNotToBe;
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
