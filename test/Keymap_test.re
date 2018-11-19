open Mocha;
open Chai;

describe("Keymap", () => {
    let keymap = Keymap.empty;

    describe(".empty", () => {
        it("returns an empty list", () => {
            let expected : list ((int, bool)) = [];

            expect(keymap)->t->deep->equal(expected);
        })
    });

    describe(".insert()", () => {
        context("given an empty array", () => {
            it("sets the value to the list", () => {
                let result = Keymap.insert(42, true, Keymap.empty);

                let expected = [(42, true)];

                expect(result)->t->deep->equal(expected);
            });
        });
    });

    describe(".lookup()", () => {
        context("given [(42, true)] and look up 42", () => {
            it("returns true", () => {
                let result = Keymap.lookup(42);

                expect(result)->t->equal(true);
            });
        });
    });
});
