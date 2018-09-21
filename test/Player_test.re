open Mocha;
open Chai;

describe("Player", () => {
    let player = Player.create((0.0, 0.0));

    describe(".go_north()", () => {
        let result = player->Player.go_north;

        it("sets the velocity to 1", () => {
            expect(result.velocity)->toEqual(1.0);
        });

        it("sets the direction to 0", () => {
            expect(result.direction)->toEqual(Js.Math._PI +. (Js.Math._PI /. 2.0));
        });
    });

    describe(".go_east()", () => {
        let result = player->Player.go_east;

        it("sets the velocity to 1", () => {
            expect(result.velocity)->toEqual(1.0);
        });

        it("sets the direction to 2 * pi / 4", () => {
            expect(result.direction)->toEqual(0.0);
        });
    });

    describe(".go_south()", () => {
        let result = player->Player.go_south;

        it("sets the velocity to 1", () => {
            expect(result.velocity)->toEqual(1.0);
        });

        it("sets the direction to pi / 2", () => {
            expect(result.direction)->toEqual(Js.Math._PI /. 2.0);
        });
    });

    describe(".go_west()", () => {
        let result = player->Player.go_west;

        it("sets the velocity to 1", () => {
            expect(result.velocity)->toEqual(1.0);
        });

        it("sets the direction to 3 * pi / 4", () => {
            expect(result.direction)->toEqual(Js.Math._PI);
        });
    });
});
