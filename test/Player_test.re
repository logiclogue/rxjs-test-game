open Mocha;
open Chai;

describe("Player", () => {
    let player = Player.create((0.0, 0.0));

    describe(".goNorth()", () => {
        let result = player->Player.goNorth;

        it("sets the velocity to 1", () => {
            expect(result.velocity)->toEqual(1);
        });

        it("sets the direction to 0", () => {
            expect(result.direction)->toEqual(0.0);
        });
    });

    describe(".goEast()", () => {
        let result = player->Player.goEast;

        it("sets the velocity to 1", () => {
            expect(result.velocity)->toEqual(1);
        });

        it("sets the direction to pi / 4", () => {
            expect(result.direction)->toEqual(Js_math._PI /. 4.0);
        });
    });

    describe(".goSouth()", () => {
        let result = player->Player.goSouth;

        it("sets the velocity to 1", () => {
            expect(result.velocity)->toEqual(1);
        });

        it("sets the direction to pi / 2", () => {
            expect(result.direction)->toEqual(Js_math._PI /. 2.0);
        });
    });

    describe(".goWest()", () => {
        let result = player->Player.goWest;

        it("sets the velocity to 1", () => {
            expect(result.velocity)->toEqual(1);
        });

        it("sets the direction to 3 * pi / 4", () => {
            expect(result.direction)->toEqual((3.0 *. Js_math._PI) /. 4.0);
        });
    });
});
