open Mocha;
open Chai;

describe("Keymap", () => {
    let keymap = Keymap.default;

    describe(".default", () => {
        it("returns an empty list", () => {
            let expected : list ((int, bool)) = [];

            expect(keymap)->t->deep->equal(expected);
        })
    });
});
