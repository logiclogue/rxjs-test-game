open GameState;
open Mocha;
open Chai;

describe("GameState", () => {
    describe(".tick()", () => {
        context("given player moving forward", () => {
            let player = Stubs.forward_entity;
            let input = {
                GameState.player: player,
                GameState.entities: []
            };
            let expected = {
                GameState.player: Entity.tick(player),
                GameState.entities: []
            };
            let result = tick(input);

            it("ticks that player", () => {
                expect(result)->t->deep->equal(expected);
            });
        });
    });
});
